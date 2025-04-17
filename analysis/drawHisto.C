#include <TFile.h>
#include <TTree.h>
#include <iostream>

void drawHisto(TString file_name = "output0.root") {
    
    // Apri il file ROOT
    TFile* file = TFile::Open(file_name, "READ");
    if (!file || file->IsZombie()) {
        std::cerr << "Errore nell'aprire il file!" << std::endl;
        return;
    }

    // Prendi l'albero dal file
    TTree* tree_channels = (TTree*)file->Get("Events");
    if (!tree_channels) {
        std::cerr << "Errore nel trovare l'albero!" << std::endl;
        file->Close();
        return;
    }

    // Variabili per leggere i rami
    Double_t eini;

    // Collega i rami alle variabili
    tree_channels->SetBranchAddress("eini", &eini);
    
    Int_t nBinX = 1500;
    Float_t startX = -.5;
    Float_t endX = 1499.5;
    TH1F *hEini = new TH1F("hEini","Initial e- energy",nBinX,startX,endX);
    hEini->GetXaxis()->SetTitle("Energy (keV)");
    hEini->GetYaxis()->SetTitle("Counts / keV");

    // Loop sugli eventi
    Long64_t nEntries = tree_channels->GetEntries();
    for (Long64_t i = 0; i < nEntries; ++i) {
        tree_channels->GetEntry(i);
    	hEini->Fill(eini);
    }
    
	cout << "hEini integral \t" << hEini->Integral() << endl;
    
    TCanvas *c2 = new TCanvas("c2","c2");
    c2->cd();
	hEini->SetStats(kTRUE);
    hEini->Draw("");
	c2->SaveAs("hEini.png");
    
    // Chiudi il file
//     file->Close();
    return;
}
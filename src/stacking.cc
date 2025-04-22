#include "stacking.hh"

MyStackingAction::MyStackingAction()
{
	G4cout << "MyStackingAction::MyStackingAction" << G4endl;

    counter = 0;
}

MyStackingAction::~MyStackingAction() {}

G4ClassificationOfNewTrack MyStackingAction::ClassifyNewTrack(
	const G4Track* aTrack)
{
	// G4cout << "MyStackingAction::ClassifyNewTrack" << G4endl;
	// G4cout << "Particle: " << aTrack->GetParticleDefinition()->GetParticleName() << ", ";
		// G4cout << "Kinetic energy: " << aTrack->GetKineticEnergy() / keV << " keV" << ", ";
		
    const G4VProcess *aProcess = aTrack->GetCreatorProcess();
    G4String aProcessName = "none";
    if (aProcess)
        aProcessName = aProcess->GetProcessName();
    
    //G4cout << aTrack->GetDefinition()->GetParticleName() << " of " << aTrack->GetKineticEnergy()/keV << " keV from " << aProcessName << G4endl;
    G4AnalysisManager *man = G4AnalysisManager::Instance();
    
    // particle is beta-
    //if(aTrack->GetDefinition() == G4Electron::Definition() && aProcessName == "RadioactiveDecayBase")
        //return fKill;

    if(aTrack->GetDefinition() == G4Electron::Definition())
    {
        man->FillNtupleDColumn(0, 0, aTrack->GetKineticEnergy() / keV);
        return fKill;
    }
    
    // particle is anti_nu_e
    if(aTrack->GetDefinition() == G4AntiNeutrinoE::Definition())
        return fKill;
	
	// return fUrgent;
	return fUrgent;
}
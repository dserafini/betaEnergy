// https://www.youtube.com/watch?v=yFOIrxoForI&list=PLLybgCU6QCGWgzNYOV0SKen9vqg4KXeVL&index=6
// c++ inclusions
#include <iostream>

// Geant4 inclusions
#include "G4RunManager.hh"
#include "G4UIExecutive.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"

// my inclusions
#include "construction.hh"
#include "physics.hh"
#include "action.hh"
#include "generator.hh"

int main(int argc, char** argv)
{
	// the hearth of Geant is the G4RunManager, it takes care of everything
	G4RunManager *runManager = new G4RunManager();

	// everything that we want to add later we have to add to this runmanager
	runManager->SetUserInitialization(new MyDetectorConstruction());
	runManager->SetUserInitialization(new MyPhysicsList());
	runManager->SetUserInitialization(new MyActionInitialization());

	// but you need detector, physics, track and step information

	// we need for user interface
	G4UIExecutive *ui = nullptr;
	if(argc == 1)
	{
		ui = new G4UIExecutive(argc, argv);
	}

	// we need visualization manager
	G4VisManager *visManager = new G4VisExecutive();

	// initialize the visualization manager
	visManager->Initialize();

	G4UImanager *UImanager = G4UImanager::GetUIpointer();

	if(ui)
	{
	// tell Geant4 to run vis.mac
	UImanager->ApplyCommand("/control/execute vis.mac");

	// start the session from G4UIExecutive
	ui->SessionStart();
	}
	else
	{
		G4String command = "/control/execute ";
		G4String fileName = argv[1];
		UImanager->ApplyCommand(command+fileName);
	}

	return 0;
}

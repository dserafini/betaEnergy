#include "physics.hh"
#include "G4EmStandardPhysics.hh"
#include "G4EmPenelopePhysics.hh"
#include "G4EmStandardPhysics_option4.hh"
#include "G4RadioactiveDecayPhysics.hh"

MyPhysicsList::MyPhysicsList()
{
	// the aim here is to produce Cerenkov effect
	// so we need two interactions
	// he advises to use only the physics that is required for your application
	// the more physics you implement the longer it takes for calculations
	RegisterPhysics (new G4EmStandardPhysics());
	// G4EmStandardPhysics G4EmPenelopePhysics G4EmStandardPhysics_option4
	RegisterPhysics (new G4RadioactiveDecayPhysics());
}

MyPhysicsList::~MyPhysicsList()
{}

void MyPhysicsList::SetCuts()
{
    // SetCutValue(0.01*mm, "gamma");
    SetCutValue(1*mm, "e-");
    // SetCutValue(0.01*mm, "e+");

	// come fatto nell'esempio B3a
	// G4VUserPhysicsList::SetCuts();
}
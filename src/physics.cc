#include "physics.hh"
#include "G4EmStandardPhysics.hh"
#include "G4EmPenelopePhysics.hh"
#include "G4EmStandardPhysics_option4.hh"
#include "G4RadioactiveDecayPhysics.hh"
#include "G4DecayPhysics.hh"
#include "G4EmParameters.hh"

MyPhysicsList::MyPhysicsList()
{
	// the aim here is to produce Cerenkov effect
	// so we need two interactions
	// he advises to use only the physics that is required for your application
	// the more physics you implement the longer it takes for calculations
	RegisterPhysics (new G4EmStandardPhysics());
	// G4EmStandardPhysics G4EmPenelopePhysics G4EmStandardPhysics_option4
	RegisterPhysics (new G4RadioactiveDecayPhysics());
	// RegisterPhysics (new G4DecayPhysics());

	// G4EmParameters::Instance()->SetFluo(true);
	// G4EmParameters::Instance()->SetAuger(true);
}

MyPhysicsList::~MyPhysicsList()
{}

void MyPhysicsList::SetCuts()
{
    // SetCutValue(1*eV, "gamma");
    // SetCutValue(1*eV, "e-");
    // SetCutValue(1*eV, "e+");

	// come fatto nell'esempio B3a
	// G4VUserPhysicsList::SetCuts();
}
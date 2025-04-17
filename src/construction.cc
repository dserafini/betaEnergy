#include "construction.hh"

MyDetectorConstruction::MyDetectorConstruction()
{}

MyDetectorConstruction::~MyDetectorConstruction()
{}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
	// do not reinvent the wheel (materials)
	G4NistManager *nist = G4NistManager::Instance();
	G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");
	// all physics happens within a boundary called world volume
	// the world volume is what we have to return at the end of this method so it is necessary
	
	G4Box *solidWorld = new G4Box("solidWorld", .5*m, .5*m, .5*m);
	
	G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
	
	// we want the world to be centered in the origin of our coordinate system
	// always check for overlaps in the last argument
	G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "PhysWorld", 0, false, 0, true);
	
	return physWorld;
}

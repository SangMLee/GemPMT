#include "GasGapSensitiveDetector.hh"
#include "GPMAnalysis.hh"
#include "GasGapHit.hh"

#include "G4Step.hh"
#include "G4Track.hh"
#include "G4TouchableHistory.hh"
#include "G4HCofThisEvent.hh"
#include "G4HCtable.hh"
#include "G4VProcess.hh"

#include "G4String.hh"
#include "G4ThreeVector.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"

GasGapSensitiveDetector::GasGapSensitiveDetector(G4String SDname) :
   G4SensitiveDetector(SDname),
   charge(0),
   primaryene(0.), 
   zinteraction(0) 
{
   G4cout << "**************************************" << G4endl;
   G4cout << "** Creating SD With name " << SDname << "**" << G4endl;
   G4cout << "**************************************" << G4endl;

   G4String myCollectionName = "GasGapHitCollection";
   collectionName.insert(myCollectionName)
}

GasGapSensitiveDetector::~GasGapSensitiveDetector() {
}





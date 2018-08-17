#include "SteppingAction.hh"
#include "EventAction.hh"
#include "DetectorConstruction.hh"

#include "G4Step.hh"
#include "G4Event.hh"
#include "G4String.hh"
#include "G4RunManager.hh"

SteppingAction::SteppingAction(const DetectorConstruction* detectorConstruction, EventAction* eventAction) :
   G4UserSteppingAction(),
   fEventAction(eventAction),
   fDetConstruction(detectorConstruction) {
}

SteppingAction::~SteppingAction() {
}

void SteppingAction::UserSteppingAction(const G4Step* step) {
   //get volume of current step 
   auto volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume();
   G4String volName = volume->GetName();
   //Energy Deposit
   auto edep = step->GetTotalEnergyDeposit();

   //step length
   G4double stepLength = 0;
   if (step->GetTrack()->GetDefinition()->GetPDGCharge() != 0.) {
      stepLength = step->GetStepLength();
   }

   if (isAbsorber(volName)) {
      fEventAction->AddAbs(edep);
   } else {
      fEventAction->AddGap(edep);
   }
}

bool SteppingAction::isAbsorber(G4String volumeName) {
     
   if (volumeName.find("Gas") != G4String::npos) {
      return false;
   } else {
      return true;
   }
}


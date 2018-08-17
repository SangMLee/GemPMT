#include "ActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "DetectorConstruction.hh"
#include "SteppingAction.hh"

ActionInitialization::ActionInitialization(DetectorConstruction* detConstruction) :
   G4VUserActionInitialization(),
   fDetConstruction(detConstruction) {
}

ActionInitialization::~ActionInitialization() {
}

void ActionInitialization::BuildForMaster() const {
   SetUserAction(new RunAction);   
}

void ActionInitialization::Build() const {
   SetUserAction(new PrimaryGeneratorAction);
   SetUserAction(new RunAction);
   auto eventAction = new EventAction;
   SetUserAction(eventAction);
   SetUserAction(new SteppingAction(fDetConstruction, eventAction));
}

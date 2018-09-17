#include "ActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "DetectorConstruction.hh"
#include "SteppingAction.hh"
#include "StackingAction.hh"

ActionInitialization::ActionInitialization() :
   G4VUserActionInitialization() 
{}
 //  fDetConstruction(detConstruction) {


ActionInitialization::~ActionInitialization() 
{}

void ActionInitialization::Build() const 
{
   SetUserAction(new PrimaryGeneratorAction);
   SetUserAction(new RunAction);
   SetUserAction(new EventAction);
   SetUserAction(new SteppingAction);
   SetUserAction(new StackingAction);
}
/*
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
*/

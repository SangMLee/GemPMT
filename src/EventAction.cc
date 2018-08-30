#include "EventAction.hh"
#include "GPMAnalysis.hh"

#include "G4Event.hh"
#include "G4EventManager.hh"
#include "G4TrajectoryContainer.hh"
#include "G4Trajectory.hh"
#include "G4ios.hh"

EventAction::EventAction() {
}

EventAction::~EventAction() {
}

void EventAction::BeginOfEventAction(const G4Event* anEvent) {
   G4int event_id = anEvent->GetEventID();
   if (event_id % 1000 == 0) {
      G4cout <<"Starting Event : "<< event_id << G4endl;
   }

   GPMAnalysis::GetInstance()->PrepareNewEvent(anEvent);
}

void EventAction::EndOfEventAction(const G4Event* anEvent) {
   GPMAnalysis::GetInstance()->EndOfEvent(anEvent);
}

#ifndef SteppingAction_h
#define SteppingAction_h 1

#include "G4UserSteppingAction.hh"
#include "G4String.hh"

class DetectorConstruction;
class EventAction;

class SteppingAction : public G4UserSteppingAction
{
   public:
      SteppingAction(const DetectorConstruction* detectorConstruction, EventAction* eventAction);
      bool isAbsorber(G4String volumeName);

      virtual ~SteppingAction();

      virtual void UserSteppingAction(const G4Step* step);

   private:
      const DetectorConstruction* fDetConstruction;
      EventAction* fEventAction;
};

#endif

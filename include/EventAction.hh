#ifndef EventAction_h
#define EventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"

class G4Event;
class RunAction;

class EventAction : public G4UserEventAction
{
   public:
      EventAction();
      virtual ~EventAction();
      virtual void BeginOfEventAction(const G4Event* anEvent);
      virtual void EndOfEventAction(const G4Event* anEvent);

      void AddAbs(G4double de);
      void AddGap(G4double de);
  
   private:
      G4double fEnergyAbs;
      G4double fEnergyGap;
};

inline void EventAction::AddAbs(G4double de) 
{
   fEnergyAbs += de;
}
inline void EventAction::AddGap(G4double de) 
{
   fEnergyGap += de;
}
#endif

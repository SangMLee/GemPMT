#ifndef SteppingAction_h
#define SteppingAction_h 1

#include "G4UserSteppingAction.hh"

class SteppingAction : public G4UserSteppingAction
{
  public:
    SteppingAction();
   ~SteppingAction(){};

    void UserSteppingAction(const G4Step*);
};


#endif

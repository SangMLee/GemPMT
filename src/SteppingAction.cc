#include "SteppingAction.hh"
#include "GPMAnalysis.hh"
#include "G4Track.hh"

#include "G4SteppingManager.hh"

SteppingAction::SteppingAction() {
}

void SteppingAction::UserSteppingAction(const G4Step* aStep) {

   const G4VTouchable* touchable = aStep->GetPreStepPoint()->GetTouchable();
   G4Track* track = aStep->GetTrack();  

   auto volume = touchable->GetVolume();
   G4String volumeName = volume->GetName();

   G4String processName = aStep->GetPostStepPoint()->GetProcessDefinedStep()->GetProcessName();

   G4int parentID = track->GetParentID();

   if (parentID == 0) {
     // G4cout << "Parent process name : "<< processName << G4endl;
   } 
  
  G4double edep(0.);
  edep = aStep->GetTotalEnergyDeposit();

  if (volumeName.find("Scint") == G4String::npos) {
     GPMAnalysis::GetInstance()->AddScintEDep(edep);
  }
  if (parentID != 0) {
     G4String V_volname = track->GetLogicalVolumeAtVertex()->GetName();
     G4int PDGID = track->GetParticleDefinition()->GetPDGEncoding(); 
     G4int trackIndex = track->GetTrackID();
     GPMAnalysis::GetInstance()->ScintPCProd(PDGID, V_volname, volumeName, trackIndex); 
  } 
}

#include "RunAction.hh"
#include "GPMAnalysis.hh"

#include "G4Run.hh"

RunAction::RunAction() {
}

RunAction::~RunAction() {
}

void RunAction::BeginOfRunAction(const G4Run* aRun) {
   G4cout << "Run number " << aRun->GetRunID() << " start." << G4endl;
   GPMAnalysis::GetInstance()->PrepareNewRun(aRun);
}

void RunAction::EndOfRunAction(const G4Run* aRun) {
   GPMAnalysis::GetInstance()->EndOfRun(aRun);
   G4cout << "Run number " << aRun->GetRunID() << " End." << G4endl;
}

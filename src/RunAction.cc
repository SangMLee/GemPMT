#include "RunAction.hh"
#include "Analysis.hh"

#include "G4RunManager.hh"
#include "G4Run.hh"
#include "Randomize.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4String.hh"

RunAction::RunAction() :
   G4UserRunAction() {
   G4RunManager::GetRunManager()->SetPrintProgress(1);
   auto analysisManager = G4AnalysisManager::Instance();
   G4cout << "Using " << analysisManager->GetType() << G4endl;

   analysisManager->SetVerboseLevel(1);
   analysisManager->SetNtupleMerging(true);

   analysisManager->CreateH1("Edep","Total E Depot", 100, 0., 100*MeV);
   analysisManager->CreateNtuple("EDep", "Edep");
   analysisManager->CreateNtupleDColumn("TotalEdep");
   analysisManager->FinishNtuple();
}

RunAction::~RunAction() {
   delete G4AnalysisManager::Instance();
}

void RunAction::BeginOfRunAction(const G4Run*) {

   auto analysisManager = G4AnalysisManager::Instance();
   G4String fileName = "EDep";
   analysisManager->OpenFile(fileName);
}

void RunAction::EndOfRunAction(const G4Run*) {

   auto analysisManager = G4AnalysisManager::Instance();
   if (analysisManager->GetH1(0) ) {
      G4cout << G4endl << " ----> print histogram Statistics ";
      if (isMaster) {
         G4cout << " for the entire run" << G4endl << G4endl;
      } else {  
         G4cout << " for the local thread" << G4endl << G4endl;
      }
      G4cout << "total Edep : mean = "
         << G4BestUnit(analysisManager->GetH1(0)->mean(), "Energy")
         <<" rms = "
         << G4BestUnit(analysisManager->GetH1(0)->rms(), "Energy")<< G4endl;
   }
      
   analysisManager->Write();
   analysisManager->CloseFile();
}


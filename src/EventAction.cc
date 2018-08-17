#include "EventAction.hh"
#include "Analysis.hh"

#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4EventManager.hh"
#include "G4VHitsCollection.hh"
#include "G4UnitsTable.hh"
#include "G4ios.hh"

EventAction::EventAction() :
   G4UserEventAction(),
   fEnergyAbs(0.),
   fEnergyGap(0.)
{}

EventAction::~EventAction()
{}

void EventAction::BeginOfEventAction(const G4Event* anEvent)
{
   fEnergyAbs = 0.;
   fEnergyGap = 0.;
   //EventAction::GetInstance()->PrepareNewEvent(anEvent);
}  

void EventAction::EndOfEventAction(const G4Event* anEvent)
{
   //Getting analysis Manager
   auto analysisManager = G4AnalysisManager::Instance();
   
   G4double edepTotal = fEnergyAbs + fEnergyGap;
   G4cout << "Total Edep : " << edepTotal << G4endl;
   //Filling histograms and ntuples
   analysisManager->FillH1(0, edepTotal);
   analysisManager->FillNtupleDColumn(0, edepTotal);
   analysisManager->AddNtupleRow();

   auto eventID = anEvent->GetEventID();
   auto printModul = G4RunManager::GetRunManager()->GetPrintProgress();
   if ((printModul > 0) && (eventID % printModul ==0)) {
      G4cout << "---> End of Event: " <<eventID << G4endl;
      G4cout << "    Total Edep: " << std::setw(7)
                                   << G4BestUnit(edepTotal, "Energy") << G4endl;
   }
}

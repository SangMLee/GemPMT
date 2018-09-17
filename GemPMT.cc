#include "G4UImanager.hh"
//#ifdef G4MULTITHREADED
//#include "G4MTRunManager.hh"
//#else
#include "G4RunManager.hh"
//#endif

#include "FTFP_BERT.hh"
#include "PhysicsList.hh"
#include "DetectorConstruction.hh"
#include "ActionInitialization.hh"
#include "G4UIExecutive.hh"
#include "G4VisExecutive.hh"

#include "Randomize.hh"

int main(int argc, char** argv) {

   G4UIExecutive* ui = 0;
   if (argc == 1) {
      ui = new G4UIExecutive(argc, argv);
   }

   G4Random::setTheEngine(new CLHEP::RanecuEngine());
   G4Random::setTheSeed(time(NULL)+38999008.);      
//#ifdef G4MULTITHREADED
//   G4MTRunManager * runManager = new G4MTRunManager;
//#else 
   G4RunManager * runManager = new G4RunManager;
//#endif
   
   DetectorConstruction* fDetectorConstruction = new DetectorConstruction();
   runManager->SetUserInitialization(fDetectorConstruction);
   auto physicsList = new PhysicsList();
   physicsList->SetVerbose(1);
   runManager->SetUserInitialization(physicsList);
   runManager->SetUserInitialization(new ActionInitialization());

   G4VisManager* visManager = new G4VisExecutive;
   visManager->Initialize();
   
   G4UImanager* UImanager = G4UImanager::GetUIpointer();

   if (!ui) {
      G4String command = "/control/execute ";
      G4String fileName = argv[1];
      UImanager->ApplyCommand(command+fileName);
   }
   else {
      UImanager->ApplyCommand("/control/execute init_vis.mac");
      ui->SessionStart();
      delete ui;
   }

   delete visManager;  
   delete runManager;
}



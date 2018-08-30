#include "GPMAnalysis.hh"
#include "G4Event.hh"
#include "G4Run.hh"
#include "G4String.hh"

#include "G4Electron.hh"
#include "G4Positron.hh"
#include "G4Gamma.hh"

#include "G4ParticleDefinition.hh"
#include "G4Track.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"

#include <TROOT.h>
#include <TFile.h>
#include <TH1D.h>
#include <TNtuple.h>

GPMAnalysis* GPMAnalysis::singleton = 0;

GPMAnalysis* GPMAnalysis::GetInstance() {
   if (singleton == 0) {
      static GPMAnalysis analysis;
      singleton = &analysis;
   }
   return singleton;
}

GPMAnalysis::~GPMAnalysis() {
}

GPMAnalysis::GPMAnalysis() {
   m_ROOT_file = 0;
}

void GPMAnalysis::PrepareNewRun(const G4Run*) {
   
   eventCounter = 0;
   n_gamma = 0;
   n_electron = 0;
   n_positron = 0;

   G4cout << "Enter GPM Analysis" << G4endl;
   //create root file 
   m_ROOT_file = new TFile("PMTOut.root", "RECREATE");
   if (m_ROOT_file) {
      G4cout << "ROOT file (PMTOut.root) made" << G4endl;
   } else {
      G4cout << "ROOT file (PMTOut.root) not made" << G4endl;
   }
   

   //Create Histograms 
   m_ROOT_histo1 = new TH1D("Sil_Edep","Energy Deposition in Scint",100,0,20);
   //Create tree and Branch 
   t = new TTree("Event", "Simulated Event Data");
   t->Branch("ScintEdep", &scintEdep, "sintEdep/D");
   t->Branch("nGammaScint", &nGammaScint, "nGammaScint/I");
   t->Branch("nElecPC", &nElecPC, "nElecPC/I");
   t->Branch("nElecGasGap1", &nElec_GasGap1, "nElec_GasGap1/I");
   // stuff
   g = new TTree("Garfield", "Variables for Garfield");
   // stuff

}

void GPMAnalysis::PrepareNewEvent(const G4Event*) {
   isNewEvent = true;
   //Clearing stuff branch
   scintEdep = 0;
   nElecPC = 0;
   nElec_GasGap1 = 0;
   nGammaScint = 0;
   newTrack = true;
   EindexId.clear();
   GindexId.clear();
}

void GPMAnalysis::EndOfEvent(const G4Event*) {
   //fill histograms and branches 
   
   t->Fill();
   g->Fill();
}

void GPMAnalysis::EndOfRun(const G4Run* aRun) {
   // Write / close root files
   G4int numEvents = aRun->GetNumberOfEvent();

   m_ROOT_file->cd();
   t->Write();
   g->Write();
   G4cout << "Writing ROOT files ..." << G4endl;
   m_ROOT_file->Write();
   G4cout << "Closing ROOT files ..." << G4endl;
   m_ROOT_file->Close();
   delete m_ROOT_file;
}

void GPMAnalysis::AddSecondary(const G4ParticleDefinition* part) {
   if (part == G4Gamma::Gamma())            { ++n_gamma; }
   else if (part == G4Electron::Electron()) { ++n_electron; }
   else if (part == G4Positron::Positron()) { ++n_positron; }
}

void GPMAnalysis::AddGapSecondary(const G4ParticleDefinition* part, G4int gapNum) {
   gapNum-- ; 
   if (part == G4Gamma::Gamma())            { ++n_gapGamma[gapNum]; }
   else if (part == G4Electron::Electron()) { ++n_gapElectron[gapNum]; }
   else if (part == G4Positron::Positron()) { ++n_gapPositron[gapNum]; }
}

void GPMAnalysis::AddScintEDep(G4double edep) {
  scintEdep += edep;
  m_ROOT_histo1->Fill(edep);
}

void GPMAnalysis::ScintPCProd(G4int PDG, G4String V_volumeName, G4String C_volumeName, G4int trackIndex) {
   if (PDG == 11 || PDG == -11) {
      Eit = std::find(EindexId.begin(), EindexId.end(), trackIndex);
      if (Eit != EindexId.end()) {
         newTrack = false;
      } else { 
         newTrack = true;
         EindexId.push_back(trackIndex);
      }
   } else if (PDG == 22) {
      Git = std::find(GindexId.begin(), GindexId.end(), trackIndex);
      if (Git != GindexId.end()) {
         newTrack = false;
      } else {  
         GindexId.push_back(trackIndex);
         newTrack = true;
      }
   }
   if ((PDG == 11 || PDG == -11) && (V_volumeName.find("PhotoCathode") == G4String::npos) && (newTrack == true)) {
      nElecPC += 1;       
   }
   if ((PDG == 11 || PDG == -11) && (C_volumeName.find("GasGap1") == G4String::npos) && (V_volumeName.find("PhotoCathode") == G4String::npos) && (newTrack == true)) {
      nElec_GasGap1 += 1;       
   } else if ((PDG == 22) && (C_volumeName.find("PhotoCathode") == G4String::npos) && (V_volumeName.find("Scint") == G4String::npos) && (newTrack == true)) {
      nGammaScint += 1;
   }
}

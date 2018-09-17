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

GPMAnalysis* GPMAnalysis::GetInstance() 
{
   if (singleton == 0) {
      static GPMAnalysis analysis;
      singleton = &analysis;
   }
   return singleton;
}

GPMAnalysis::~GPMAnalysis() 
{}

GPMAnalysis::GPMAnalysis() 
{
   m_ROOT_file = 0;
}

void GPMAnalysis::PrepareNewRun(const G4Run*) 
{   
   eventCounter = 0;
   n_gamma = 0;
   n_electron = 0;
   n_positron = 0;

   G4cout << "Enter GPM Analysis" << G4endl;
   //create root file 
   m_ROOT_file = new TFile("GPMOut.root", "RECREATE");
   if (m_ROOT_file) {
      G4cout << "ROOT file (GPMOut.root) made" << G4endl;
   } else {
      G4cout << "ROOT file (GPMOut.root) not made" << G4endl;
   }
   

   //Create Histograms 
   m_ROOT_histo1 = new TH1D("Sil_Edep","Energy Deposition in Scint",100,0,20);
   //Create tree and Branch 
   t = new TTree("Event", "Simulated Event Data");
   t->Branch("nScint_Op", &Op_Scint, "Op_Scint/I");
   t->Branch("nCer_Op", &Op_Cer, "Op_Cer/I");
   t->Branch("ScintEdep", &scintEdep, "sintEdep/D");
   t->Branch("nGammaScint", &nGammaScint, "nGammaScint/I");
   t->Branch("nElecGasGap1", &nElec_GasGap1, "nElec_GasGap1/I");
   t->Branch("edep", &edep);
   t->Branch("edepI", &edepI);
   t->Branch("edepTime", &edepTime);
   t->Branch("primaryEne", &primaryEne, "primaryEne/D");
   t->Branch("zInteraction", &zInteraction, "zInteraction/D");
   
   t->Branch("EleGap", &eleGap, "EleGap/I");
   t->Branch("PosGap", &posGap, "PosGap/I");
   t->Branch("ChargeGap", &chargeGap, "ChargeGap/I");

   t->Branch("gapTrackPart", &gapTrackPart);
   t->Branch("gapTrackCharge", &gapTrackCharge);
   t->Branch("gapTrackGeneration", &gapTrackGeneration);
   t->Branch("gapTrackEne", &gapTrackEne);
   // stuff
   g = new TTree("Garfield", "Variables for Garfield");
   g->Branch("pdgCode",&pdgCode);
   g->Branch("kineticEnergy",&kineticEnergy);
   g->Branch("positionX",&positionX);
   g->Branch("positionY",&positionY);
   g->Branch("positionZ",&positionZ);
   g->Branch("momentumX",&momentumX);
   g->Branch("momentumY",&momentumY);
   g->Branch("momentumZ",&momentumZ);
   // stuff
}

void GPMAnalysis::PrepareNewEvent(const G4Event*) 
{
   isNewEvent = true;
   //Clearing stuff branch
   scintEdep = 0;
   nElec_GasGap1 = 0;
   nGammaScint = 0;
   
   Op_Cer = 0;
   Op_Scint = 0;
   edep.clear();
   edepI.clear();
   edepTime.clear();

   newTrack = true;
   EindexId.clear();
   GindexId.clear();
   
   eleGap = 0;
   posGap = 0;
   chargeGap = 0;
  
   pdgCode.clear();
   kineticEnergy.clear();
   positionX.clear();
   positionY.clear();
   positionZ.clear();
   momentumX.clear();
   momentumY.clear();
   momentumZ.clear();
   
   gapTrackPart.clear();
   gapTrackCharge.clear();
   gapTrackGeneration.clear();
   gapTrackGenZ.clear();
   gapTrackEne.clear();
}

void GPMAnalysis::EndOfEvent(const G4Event*) 
{
   //fill histograms and branches 
   
   t->Fill();
   g->Fill();
}

void GPMAnalysis::EndOfRun(const G4Run* aRun) 
{
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

void GPMAnalysis::AddSecondary(const G4ParticleDefinition* part) 
{
   if (part == G4Gamma::Gamma())            { ++n_gamma; }
   else if (part == G4Electron::Electron()) { ++n_electron; }
   else if (part == G4Positron::Positron()) { ++n_positron; }
}

void GPMAnalysis::AddGapSecondary(const G4ParticleDefinition* part, G4int gapNum) 
{
   gapNum-- ; 
   if (part == G4Gamma::Gamma())            { ++n_gapGamma[gapNum]; }
   else if (part == G4Electron::Electron()) { ++n_gapElectron[gapNum]; }
   else if (part == G4Positron::Positron()) { ++n_gapPositron[gapNum]; }
}

void GPMAnalysis::AddScintEDep(G4double Sedep) 
{
  scintEdep += Sedep;
  m_ROOT_histo1->Fill(Sedep);
}

void GPMAnalysis::SetEnergyDeposition(std::string someVolume, G4double someEdep, G4double someEdepI, G4double someTime)
{
   edep.push_back(someEdep);
   edepI.push_back(someEdepI);
   edepTime.push_back(someTime);
}

void GPMAnalysis::ScintPCProd(G4int PDG, G4String V_volumeName, G4String C_volumeName, G4int trackIndex) 
{
   if ((PDG == 11 || PDG == -11) && (C_volumeName == "GasGap1") && (V_volumeName == "PhotoCathodeLog")) {
      Eit = std::find(EindexId.begin(), EindexId.end(), trackIndex);
      if (Eit == EindexId.end()) {
         EindexId.push_back(trackIndex);
         nElec_GasGap1 += 1;
      }
   } else if ((PDG == 22) && (C_volumeName == "PhotoCathode") && (V_volumeName == "ScintillatorLog")) {
      Git = std::find(GindexId.begin(), GindexId.end(), trackIndex);
      if (Git == GindexId.end()) {
         GindexId.push_back(trackIndex);
         nGammaScint += 1;
      }
   }
}

void GPMAnalysis::OpPhoton(G4String p_Name)
{
   if (p_Name == "Scintillation") Op_Scint++;
   if (p_Name == "Cerenkov") Op_Cer++;
}


void GPMAnalysis::SaveGarfieldQuantities(
      G4int aPdgCode,
      G4double aKineticEnergy,
      G4double aPositionX,
      G4double aPositionY,
      G4double aPositionZ,
      G4double aMomentumX,
      G4double aMomentumY,
      G4double aMomentumZ) 
{

   pdgCode.push_back(aPdgCode);
   kineticEnergy.push_back(aKineticEnergy);
   positionX.push_back(aPositionX);
   positionY.push_back(aPositionY);
   positionZ.push_back(aPositionZ);
   momentumX.push_back(aMomentumX);
   momentumY.push_back(aMomentumY);
   momentumZ.push_back(aMomentumZ);
}

void GPMAnalysis::SavePrimary(G4double primaryene, G4double zinteraction) 
{
   primaryEne = primaryene;
   zInteraction = zinteraction; 
}

void GPMAnalysis::SaveGapTrack(
      G4int gapPart,
      G4int gapCharge,
      G4int generation,
      std::string genprocess,
      std::string genvolume,
      G4double genz,
      std::string volname,
      G4double kinene) 
{
   if (genprocess == "primary") return;
   if (gapCharge != 0) chargeGap = 1;
   if (gapPart == 11) eleGap = 1;
   if (gapPart == -11) posGap = 1;

   gapTrackPart.push_back(gapPart);
   gapTrackCharge.push_back(gapCharge);
   gapTrackGeneration.push_back(generation);
   gapTrackGenZ.push_back(genz);
   gapTrackEne.push_back(kinene);
}


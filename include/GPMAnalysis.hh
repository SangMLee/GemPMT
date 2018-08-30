#ifndef GPMAnalysis_hh
#define GPMAnalysis_hh 1

#include "globals.hh"
#include <vector>

class G4Run;
class G4Event;
class G4ParticleDefinition;
class TFile;
class TTree;
class TH1D;
class G4Track; 

class GPMAnalysis {
   public: 
      static GPMAnalysis* GetInstance();
      ~GPMAnalysis();

      void PrepareNewRun(const G4Run* aRun);
      void PrepareNewEvent(const G4Event* anEvent);
      void EndOfEvent(const G4Event* anEvent);
      void EndOfRun(const G4Run* aRun);
      void AddSecondary(const G4ParticleDefinition* part); 
      void AddGapSecondary(const G4ParticleDefinition* part, G4int gapNum); 
      void AddScintEDep(G4double edep);
      void ScintPCProd(G4int PDG, G4String V_volumName, G4String C_volumeName, G4int trackIndex);

   private:
      GPMAnalysis();
      static GPMAnalysis* singleton;
       
      bool isNewEvent;
      G4int eventCounter;

      G4double scintEdep;
      std::vector<G4int> EindexId;
      std::vector<G4int> GindexId;
      std::vector<G4int>::iterator Eit;
      std::vector<G4int>::iterator Git;
      bool newTrack;
      //Counters 
      G4int n_gamma, n_electron, n_positron, n_gapGamma[4], n_gapElectron[4], n_gapPositron[4];
      G4int nElecPC, nGammaScint, nElec_GasGap1;
 
      // ROOT OBJECTS 
      TFile* m_ROOT_file;
      TH1D* m_ROOT_histo1;

      TTree* t;
      TTree* g;
};

#endif

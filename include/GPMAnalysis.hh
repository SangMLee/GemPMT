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
      void AddScintEDep(G4double Sedep);
      void ScintPCProd(G4int PDG, G4String V_volumName, G4String C_volumeName, G4int trackIndex);
      void SavePrimary(G4double primaryene, G4double zinteraction);
      void SaveGarfieldQuantities(G4int aPdgcode,
                                  G4double aKineticEnergy,
                                  G4double aPositionX,
                                  G4double aPositionY,
                                  G4double aPositionZ,
                                  G4double aMomentumX,
                                  G4double aMomentumY,
                                  G4double aMomentumZ);
      void SaveGapTrack(G4int gapPart,
                        G4int gapCharge,
                        G4int generation,
                        std::string genprocess,
                        std::string genvolume,
                        G4double genz,
                        std::string volname,
                        G4double kinene);
      void SetEnergyDeposition(std::string someVolume, G4double someEdep, G4double someEdepI, G4double someTime);

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

      G4double primaryEne;
      G4double zInteraction;

      //Counters 
      G4int n_gamma, n_electron, n_positron, n_gapGamma[4], n_gapElectron[4], n_gapPositron[4];
      G4int nGammaScint, nElec_GasGap1;
      G4int chargeGap, eleGap, posGap;
      
      //////
      std::vector<G4double> edep;
      std::vector<G4double> edepI;
      std::vector<G4double> edepTime;
      //////
      std::vector<G4int> pdgCode;
      std::vector<G4double> kineticEnergy;
      /////

      std::vector<G4int> gapTrackPart ;
      std::vector<G4int> gapTrackCharge ;
      std::vector<G4int> gapTrackGeneration ;
      std::vector<std::string> gapTrackName ;
      std::vector<std::string> gapTrackGenProcess ;
      std::vector<std::string> gapTrackVolume ;
      std::vector<G4double> gapTrackGenZ ;
      std::vector<std::string> gapTrackGap ;
      std::vector<G4double> gapTrackEne ;

      std::vector<G4double> positionX;
      std::vector<G4double> positionY;
      std::vector<G4double> positionZ;
      //////
      std::vector<G4double> momentumX;
      std::vector<G4double> momentumY;
      std::vector<G4double> momentumZ;
      // ROOT OBJECTS 
      TFile* m_ROOT_file;
      TH1D* m_ROOT_histo1;

      TTree* t;
      TTree* g;
};

#endif

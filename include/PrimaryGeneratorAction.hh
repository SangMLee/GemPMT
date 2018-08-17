#ifndef PrimaryGeneratorAction01_h
#define PrimaryGeneratorAction01_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ThreeVector.hh"
#include "globals.hh"

class G4ParticleGun;
class G4Event; 
class G4Box;

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction {
   public:
      PrimaryGeneratorAction();
      virtual ~PrimaryGeneratorAction();
      virtual void GeneratePrimaries(G4Event*);

      const G4ParticleGun* GetParticleGun() const { return fParticleGun; }

   private : 
      G4ParticleGun* fParticleGun;
      G4Box* fWorldBox;

};

#endif

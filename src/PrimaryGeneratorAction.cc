#include "PrimaryGeneratorAction.hh"

#include "G4RunManager.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"

PrimaryGeneratorAction::PrimaryGeneratorAction()
: G4VUserPrimaryGeneratorAction(),
  fParticleGun(0)
{
   G4int nofParticles = 1;
   fParticleGun = new G4ParticleGun(nofParticles);

   // default particle kinematices //
   G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
   G4String particleName;

   G4ParticleDefinition* particle 
      = particleTable->FindParticle(particleName = "gamma");
   fParticleGun->SetParticleDefinition(particle);
   fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0., 0., 1.));
   fParticleGun->SetParticleMomentum(10*MeV);
}

PrimaryGeneratorAction::~PrimaryGeneratorAction() {
   delete fParticleGun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent) {
   G4double worldSizeXYZ = 1.*m;
   /*if (!fWorldBox) {
      G4LogicalVolume* logicalWorld 
         = G4LogicalVolumeStore::GetInstance()->GetVolume("World");

      fWorldBox = dynamic_cast<G4Box*>(logicalWorld->GetSolid());
   }

   if (fWorldBox) {
      worldSizeXYZ = fWorldBox->GetXHalfLength()*2;
   }*/
   G4double z0 = -0.5*worldSizeXYZ;
   fParticleGun->SetParticlePosition(G4ThreeVector(0.,0.,z0));

   fParticleGun->GeneratePrimaryVertex(anEvent);
}




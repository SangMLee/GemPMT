#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "G4Box.hh"
#include "G4ThreeVector.hh"
#include "globals.hh"

#include <vector>

class G4PhyscialVolume;
class G4LogicalVolume;
class G4Material;
class G4Element;

class DetectorConstruction : public G4VUserDetectorConstruction {
   public :
      DetectorConstruction(); 
      virtual ~DetectorConstruction();

      void DefineMaterials();
      G4VPhysicalVolume* Construct();
      void PlaceGeometry(G4ThreeVector tlate, G4LogicalVolume *pMotherLogical);

   private :
      G4Material* fCuMat;
      G4Material* fKapMat;
      G4Material* fFR4Mat;
      G4Material* fGasMat;
      G4Material* fPCMat;
      G4Material* fScintMat;
      G4Material* fVacMat;
      G4Material* fGlassMat;
      G4double    tripleGemThinBase;
      G4double    tripleGemLargeBase;
      G4double    tripleGemHeight;
      
      std::vector<G4Box*> gemCollection;
      std::vector<G4LogicalVolume*> gemLogCollection;
};


#endif

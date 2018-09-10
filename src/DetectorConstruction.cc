#include <cstdio>
#include "DetectorConstruction.hh"
#include "GasGapSensitiveDetector.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4SDManager.hh"

#include "G4Element.hh"
#include "G4Material.hh"
#include "G4Box.hh"

#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4PVPlacement.hh"

#include "G4SystemOfUnits.hh"
#include "G4VisAttributes.hh"

DetectorConstruction::DetectorConstruction() :
   G4VUserDetectorConstruction()
{}

DetectorConstruction::~DetectorConstruction() 
{}

void DetectorConstruction::DefineMaterials() {
    
   G4NistManager* manager = G4NistManager::Instance();
   
   G4Element* elSi = manager->FindOrBuildElement(14);
   G4Element* elH = manager->FindOrBuildElement(1);
   G4Element* elO = manager->FindOrBuildElement(8);
   G4Element* elC = manager->FindOrBuildElement(6);
   G4Element* elRb = manager->FindOrBuildElement(37);
   G4Element* elCs = manager->FindOrBuildElement(55);
   G4Element* elSb = manager->FindOrBuildElement(51);

   G4Material* Vaccum = manager->FindOrBuildMaterial("G4_Galactic");
   G4Material* Argon = manager->FindOrBuildMaterial("G4_Ar");
   G4Material* CarbonDioxide = manager->FindOrBuildMaterial("G4_CARBON_DIOXIDE");
   G4Material* Copper = manager->FindOrBuildMaterial("G4_Cu");
   G4Material* Kapton = manager->FindOrBuildMaterial("G4_KAPTON");
   G4Material* CsI = manager->FindOrBuildMaterial("G4_CESIUM_IODIDE");
   G4Material* BaF2 = manager->FindOrBuildMaterial("G4_BARIUM_FLUORIDE");
   G4Material* Anthracene = manager->FindOrBuildMaterial("G4_ANTHRACENE");
   G4Material* NaI = manager->FindOrBuildMaterial("G4_SODIUM_IODIDE");
   G4Material* PbWO4 = manager->FindOrBuildMaterial("G4_PbWO4");
   G4Material* Glass = manager->FindOrBuildMaterial("G4_Pyrex_Glass");
   G4Material* GaAs = manager->FindOrBuildMaterial("G4_GALLIUM_ARSENIDE");
  
   G4double density(0.), fractionMass(0.);
   G4int numel(0), natoms(0);
   
   G4Material* RbCsSb = new G4Material("bialkiali", density , numel=3);
   RbCsSb->AddElement(elRB, natoms=1);
   RbCsSb->AddElement(elCs, natoms=1);
   RbCsSb->AddElement(elSb, natoms=1);
   
   density = 2.200*g/cm3
   G4Material* SiO2 =  new G4Material("quartz",density, numel=2);
   SiO2->AddElement(elSi, natoms=1);
   SiO2->AddElement(elO , natoms=2);

   density = 1.2*g/cm3;
   G4Material* Epoxy = new G4Material("Epoxy" , density, numel=2);
   Epoxy->AddElement(elH, natoms=2);
   Epoxy->AddElement(elC, natoms=2);

   //FR4 (Glass + Epoxy)
   density = 1.86*g/cm3; 
   G4Material* FR4 = new G4Material("FR4"  , density, numel=2);
   FR4->AddMaterial(Epoxy, fractionMass=0.472);
   FR4->AddMaterial(SiO2, fractionMass=0.528);
   fFR4Mat = FR4;

   G4double mixtureDensity = (Argon->GetDensity() * 70/100.0 + CarbonDioxide->GetDensity()* 30/100.0);
   G4Material *ArCO2 = new G4Material("Ar/CO2", mixtureDensity, 2);
   ArCO2->AddMaterial(Argon, 0.7);
   ArCO2->AddMaterial(CarbonDioxide, 0.3);

   fGasMat = ArCO2;
   fGlassMat = SiO2; 
   fVacMat = Vaccum;
   fCuMat = Copper;
   fKapMat = Kapton;
   fPCMat = GaAs;
   fScintMat = PbWO4;
}

G4VPhysicalVolume* DetectorConstruction::Construct() {
   
   DefineMaterials(); 

   G4SDManager* sdman = G4SDManager::GetSDMpointer();  

   G4bool checkOverlaps = true;

   G4double worldSizeXYZ = 1*m;
   G4double gemSizeXY = 10*cm;

   //Visual 
   
   G4VisAttributes *cathodeAttributes = new G4VisAttributes(G4Color::Grey()) ;
   cathodeAttributes->SetForceWireframe(true) ;
   G4VisAttributes *g10Attributes = new G4VisAttributes(G4Color::White()) ;
   g10Attributes->SetForceWireframe(true) ;
   G4VisAttributes *gasAttributes = new G4VisAttributes(G4Color::Red()) ;
   gasAttributes->SetForceWireframe(true) ;
   G4VisAttributes *gemAttributes = new G4VisAttributes(G4Color::Green()) ;
   gemAttributes->SetForceWireframe(true) ;
   G4VisAttributes *insAttributes = new G4VisAttributes(G4Color::Blue()) ;
   insAttributes->SetForceWireframe(true) ;

   //Build World 

   G4Box* solidWorld =
      new G4Box("World", 0.5*worldSizeXYZ, 0.5*worldSizeXYZ, 0.5*worldSizeXYZ);

   G4LogicalVolume* logicWorld =
      new G4LogicalVolume(solidWorld, fVacMat, "World");
    
   G4VisAttributes *worldAttributes = new G4VisAttributes;
   worldAttributes->SetVisibility(true);
   logicWorld->SetVisAttributes(worldAttributes);    

   G4VPhysicalVolume* physWorld = 
      new G4PVPlacement(0, G4ThreeVector(), logicWorld, "World", 0, false, 0, checkOverlaps);

// === Gem Creation ================================================================================ //
   
   std::string layerName[24] = 
   {
      "Scintillator",
    //  "PhotoCathode", "Glass",
      "PhotoCathode" , " Glass",
      "FakeBottom",
      "DriftCopper1", "DriftBoard", "DriftCopper2",
      "GasGap1",
      "Gem1Copper1", "Gem1", "Gem1Copper2",
      "GasGap2",
      "Gem2Copper1", "Gem2", "Gem2Copper2",
      "GasGap3",
      "Gem3Copper1", "Gem3", "Gem3Copper2",
      "GasGap4",
      "ReadCopper1", "ReadoutBoard", "ReadCopper2",
      "FakeTop"
   };

   std::string layerNameLog[24];

   for (size_t i=0; i<24; i++) {
      layerNameLog[i]=layerName[i]+"Log";
   }

   G4Material* layerComp[24]=
   {
     fScintMat,                  //Scintillator
   //  fPCMat, fGlassMat,          //PhotoCathode, Glass 
     fGlassMat, fPCMat,
     fGasMat,                    //Drift Gap
     fCuMat,fFR4Mat,fCuMat,      //Drift Board
     fGasMat,                    //Drift Gap
     fCuMat,fKapMat,fCuMat,      //gem1
     fGasMat,                    //Transfer I Gap
     fCuMat,fKapMat,fCuMat,      //gem2
     fGasMat,                    //Transfer II Gap
     fCuMat,fKapMat,fCuMat,      //gem3
     fGasMat,                    //Induction Gap
     fCuMat,fFR4Mat,fCuMat,      //Readout Board
     fVacMat                    //Fake
   };

   G4double gemSizeZ[24] = 
   {
     0.052*m,                    //Scintillator  
  //   130.0*nm, 3.0*mm,           //PhotoCathode
     3.0*mm, 130.0*nm,
     5.0*mm,                    //Fake
     35.*um,3.2*mm,35.*um,      //Drift Board
     3.*mm,                     //Drift Gap
     5.*um,50*um,5.*um,         //gem1
     1.*mm,                     //Transfer I Gap
     5.*um,50*um,5.*um,         //gem2
     2.*mm,                     //Transfer II Gap
     5.*um,50.*um,5.*um,        //gem3
     1.*mm,                     //Induction Gap
     35.*um,3.2*mm,35.*um,      //Readout Board
     0.1*mm                     //Fake
   };

   GasGapSensitiveDetector* sensitive = new GasGapSensitiveDetector("/GasGap");
   sdman->AddNewDetector(sensitive);

   G4Box* SolidGem;
   G4LogicalVolume * LogicGem;

   for (G4int lyr=0; lyr<24; lyr++) {
      SolidGem = new G4Box(layerName[lyr], gemSizeXY, gemSizeXY, gemSizeZ[lyr]);
      LogicGem = new G4LogicalVolume(SolidGem, layerComp[lyr], layerNameLog[lyr]);
      if (LogicGem->GetName() == "PhotoCathodeLog") {
         LogicGem->SetVisAttributes(new G4VisAttributes(*insAttributes));
      } else {
         LogicGem->SetVisAttributes(new G4VisAttributes(*gemAttributes));
      }
      gemCollection.push_back(SolidGem);
      gemLogCollection.push_back(LogicGem);
      gemLogCollection[lyr]->SetSensitiveDetector(sensitive);
   }

   PlaceGeometry(G4ThreeVector(0.,0.,0.), logicWorld); 

   return physWorld;
}

void DetectorConstruction::PlaceGeometry(G4ThreeVector tlate, G4LogicalVolume* pMotherLogical) {

   G4double ZTranslation = 0;
   
   for (size_t i=0; i<gemCollection.size(); i++) {
      ZTranslation += gemCollection.at(i)->GetZHalfLength();
      G4ThreeVector position = tlate + G4ThreeVector(0,0,ZTranslation);
      new G4PVPlacement(0, 
                        position, 
                        gemLogCollection.at(i), 
                        gemCollection.at(i)->GetName(),
                        pMotherLogical,
                        false,
                        i); 
      ZTranslation += gemCollection.at(i)->GetZHalfLength(); 
   }
} 

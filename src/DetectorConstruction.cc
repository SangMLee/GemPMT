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
#include "G4OpticalSurface.hh"

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
   RbCsSb->AddElement(elRb, natoms=1);
   RbCsSb->AddElement(elCs, natoms=1);
   RbCsSb->AddElement(elSb, natoms=1);
   
   density = 2.200*g/cm3;
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
   fGlassMat = Glass; 
   fVacMat = Vaccum;
   fCuMat = Copper;
   fKapMat = Kapton;
   fPCMat = GaAs;
   fScintMat = CsI;
  /* 
   // -- Scint -- //
   G4double photonEnergy[] = 
                  { 2.99*eV };

   G4int nEntries = sizeof(photonEnergy)/sizeof(G4double);
   
   G4double refractiveIndex_scint[] = 
                  { 1.85 };
   assert(sizeof(refractiveIndex_scint) == sizeof(photonEnergy));

   G4double absorption_scint[] = 
                  { 0.0259*m };
   assert(sizeof(absorrption_scint) == sizeof(photonEnergy));

   G4MaterialPropertiesTable* myScint = new G4MaterialPropertiesTable();
   
   myScint->AddProperty("RINDEX",  photonEnergy, refractiveIndex_scint, nEntries);
   myScint->AddProperty("ABSLENGTH",  photonEnergy, absorption_scint,   nEntries);
   myScint->AddConstProperty("RESOLUTIONSCALE", 1.0);
   myScint->AddConstProperty("SCINTILLATIONYIELD" , 14000./MeV);
   myScint->AddConstProperty("FASTTIMECONSTANT", 250.*ns);
   
   G4cout << "Scint G4MaterialPropertiesTable" << G4endl;
   myScint->DumpTable();
   fScintMat->SetMaterialPropertiesTable(myScint);

   //Probably want to check this 
   fScintMat->GetIonisation()->SetBirksConstant(0.126*mm/MeV);
  */
   
    const G4int CSI_NUMENTRIES = 8;
    G4double CSI_Crystal_PP[CSI_NUMENTRIES] = {3.37*eV, 3.62*eV, 3.71*eV, 3.77*eV,
        4.02*eV, 4.07*eV, 4.19*eV, 4.42*eV};
        //h_Planck*c_light/lambda_max, h_Planck*c_light/lambda_min};//6.6*eV, 7.4*eV };
    G4double CSI_Crystal_FAST[CSI_NUMENTRIES] = {0.23, 0.62, 0.77, 0.95, 0.97, 0.92, 0.63, 0.27};
    G4double CSI_Crystal_RINDEX[CSI_NUMENTRIES] = { 1.78, 1.78, 1.78, 1.78, 1.78, 1.78, 1.78, 1.78};
    G4double CSI_Crystal_absorption[CSI_NUMENTRIES] = {40*cm, 40*cm, 40*cm, 40*cm, 40*cm, 40*cm, 40*cm, 40*cm};
    
    G4MaterialPropertiesTable* CSI_Crystal_MPT = new G4MaterialPropertiesTable();
    CSI_Crystal_MPT->AddProperty("FASTCOMPONENT", CSI_Crystal_PP, CSI_Crystal_FAST, CSI_NUMENTRIES);
    CSI_Crystal_MPT->AddProperty("ABSLENGTH", CSI_Crystal_PP, CSI_Crystal_absorption,CSI_NUMENTRIES);
    CSI_Crystal_MPT->AddProperty("RINDEX", CSI_Crystal_PP, CSI_Crystal_RINDEX, CSI_NUMENTRIES);
    CSI_Crystal_MPT->AddConstProperty("SCINTILLATIONYIELD", 54000./MeV);        
    CSI_Crystal_MPT->AddConstProperty("RESOLUTIONSCALE", 1.);            
    CSI_Crystal_MPT->AddConstProperty("FASTTIMECONSTANT", 0.6*us);
    fScintMat->SetMaterialPropertiesTable(CSI_Crystal_MPT);
    fScintMat->GetIonisation()->SetBirksConstant(0.*mm/MeV);

   // -- Pyrex Glass -- //

   const G4int nEntries = 2;
   G4double photonEnergy_glass[nEntries] = 
         { 1.0*eV,  6.0*eV };
   G4double refractiveIndex_glass[nEntries] = 
         { 1.52, 1.52 };
   G4double absorbption_glass[nEntries] = 
         { 10*m, 10*m };

   G4MaterialPropertiesTable* myGlass = new G4MaterialPropertiesTable();
   myGlass->AddProperty("RINDEX", photonEnergy_glass, refractiveIndex_glass, nEntries);
   myGlass->AddProperty("ABSLENGTH", photonEnergy_glass, absorbption_glass, nEntries);

   fGlassMat->SetMaterialPropertiesTable(myGlass);

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
      "Glass", "PhotoCathode",
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

#include "GasGapHit.hh"
#include "G4UnitsTable.hh"

G4Allocator<GasGapHit> GasGapHitAllocator;

GasGapHit::GasGapHit(const G4int layer) : 
   layerNumber(layer),
   eDep(0.) {
}

GasGapHit::~GasGapHit() {
}

void GasGapHit::Print() {

   G4cout << "GasGapHit : Layer = "<< layerNumber << " Edep = " << G4BestUnit(eDep, "Energy") << G4endl;
}

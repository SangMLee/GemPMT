#ifndef GasGapHit_h
#define GasGapHit_h 1

#include "G4VHit.hh"
#include "G4Allocator.hh"
#include "G4THitsCollection.hh"

class GasGapHit : public G4VHit {
   public:
      GasGapHit(const G4int layer);

      ~GasGapHit();

      void Print();

   public:
      inline void *operator new(size_t);
      inline void operator delete(void *aHit);

   public:
      void     AddEdep(const double e)  { eDep += e;}
      G4double GetEdep()          const {return eDep;}
      G4int    GetLayerNumber()   const {return layerNumber;}

   private:
      const G4int layerNumber;
      G4double    eDep;
}; 

typedef G4THitsCollection<GasGapHit> GasGapHitCollection;

extern G4Allocator<GasGapHit> GasGapHitAllocator;

inline void* GasGapHit::operator new(size_t) {
   void *aHit;
   aHit = (void *) GasGapHitAllocator.MallocSingle();
   return aHit;
}

inline void GasGapHit::operator delete(void *aHit) {
   GasGapHitAllocator.FreeSingle((GasGapHit*) aHit);
}

#endif


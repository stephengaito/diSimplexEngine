#ifndef DISITT_INLINES_H
#define DISITT_INLINES_H

#include <cUtils/varArray.h>
#include "diSimplexEngine/diSitt.h"

inline DiSITT::DiSITT(void) {
  diStructures = new BlockAllocator( (1<<5)*sizeof(DiStructure) );

  // create the initial and final structures
  initialStruct =
    (DiStructure*)diStructures->allocateNewStructure(sizeof(DiStructure));
  ASSERT(initialStruct);

  finalStruct =
    (DiStructure*)diStructures->allocateNewStructure(sizeof(DiStructure));
  ASSERT(finalStruct);
}

inline DiSITT::~DiSITT(void) {
  initialStruct = NULL;  // initialStruct owned by diStructures
  finalStruct   = NULL;  // finalStruct   owned by diStrcutures

  if (diStructures)  delete diStructures;
}

inline DiSITT *DiSITT::getUniverse(void) {
  if (!theUniverse) theUniverse = new DiSITT();
  return theUniverse;
}

inline void DiSITT::cleanUpUniverse(void) {
  if (theUniverse) delete theUniverse;
  theUniverse = new DiSITT();
}

inline DiStructure *DiSITT::getInitialStructure(void) {
  ASSERT(initialStruct);
  return initialStruct;
}

inline DiStructure *DiSITT::getFinalStructure(void) {
  ASSERT(finalStruct);
  return finalStruct;
}

//inline DiSimplex DiSITT::getFinalSimplexDim(dim_t aDimension) {
//  if (!ref->ensureFinalSimplexOfDimExists(aDimension)) {
//    ASSERT_MESSAGE(false,
//      "Could not allocate simplicies of correct dimension");
//  }
//  return DiSimplex(aDimension, 0);
//}

//inline DiSimplex DiSITT::getSimplex(DiStructure label,
//                                    DiSimplexList &someSimplicies) {
//  return theUniverse->getSimplex(label, someSimplicies);
//}

//inline DiStructureImpl *DiSITTimpl::getNewStructure(void) {
//  strucId_t newStructureId = diStructures->allocateNewStructure();
//  ASSERT(newStructureId != 0);
//  ASSERT(newStructureId != 1);
//  return diStructures->getStructurePtr(newStructureId);
//}

#endif

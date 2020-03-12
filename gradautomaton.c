// ============ GRADAUTOMATON.C ================

// ================= Include =================

#include "gradautomaton.h"
#if BUILDMODE == 0
#include "gradautomaton-inline.c"
#endif

// ------------- GradAutomaton

// ================ Functions declaration ====================

// ================ Functions implementation ====================

// Create a new GrACellShort with a status vector of dimension 'dim'
GrACellShort* GrACellCreateShort(const long dim) {

  // Allocate memory
  GrACellShort* that =
    PBErrMalloc(
      GradAutomatonErr,
      sizeof(GrACellShort));

  // Initialise properties
  that->_status[0] = VecShortCreate(dim);
  that->_status[1] = VecShortCreate(dim);
  that->_iStatus = 0;

  // Return the new GrACellShort
  return that;

}

// Create a new GrACellFloat with a status vector of dimension 'dim'
GrACellFloat* GrACellCreateFloat(const long dim) {

  // Allocate memory
  GrACellFloat* that =
    PBErrMalloc(
      GradAutomatonErr,
      sizeof(GrACellFloat));

  // Initialise properties
  that->_status[0] = VecFloatCreate(dim);
  that->_status[1] = VecFloatCreate(dim);
  that->_iStatus = 0;

  // Return the new GrACellFloat
  return that;

}

// Free the memory used by the GrACellShort 'that'
void _GrACellShortFree(GrACellShort** that) {

  // If that is null
  if (that == NULL || *that == NULL) {

    // Do nothing
    return;

  }

  // Free memory
  VecFree(&((*that)->_status[0]));
  VecFree(&((*that)->_status[1]));
  free(*that);
  *that = NULL;

}

// Free the memory used by the GrACellFloat 'that'
void _GrACellFloatFree(GrACellFloat** that) {

  // If that is null
  if (that == NULL || *that == NULL) {

    // Do nothing
    return;

  }

  // Free memory
  VecFree(&((*that)->_status[0]));
  VecFree(&((*that)->_status[1]));
  free(*that);
  *that = NULL;

}

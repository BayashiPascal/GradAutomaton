// ============ GRADAUTOMATON.H ================

#ifndef GRADAUTOMATON_H
#define GRADAUTOMATON_H

// ================= Include =================

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "pberr.h"
#include "pbmath.h"
#include "gset.h"
#include "grad.h"

// -------------- GrACell

// ================= Define ==================

// ================= Data structure ===================

typedef struct GrACellShort {

  // Double buffered status of the cell
  VecShort* _status[2];

  // Index of the current status of the cell
  unsigned char _iStatus;

} GrACellShort;

typedef struct GrACellFloat {

  // Double buffered status of the cell
  VecFloat* _status[2];

  // Index of the current status of the cell
  unsigned char _iStatus;

} GrACellFloat;

// ================ Functions declaration ====================

// Create a new GrACellShort with a status vector of dimension 'dim'
GrACellShort* GrACellCreateShort(const long dim);

// Create a new GrACellFloat with a status vector of dimension 'dim'
GrACellFloat* GrACellCreateFloat(const long dim);

// Free the memory used by the GrACellShort 'that'
void _GrACellShortFree(GrACellShort** that);

// Free the memory used by the GrACellFloat 'that'
void _GrACellFloatFree(GrACellFloat** that);

// ================= Polymorphism ==================

#define GrACellFree(G) _Generic(G, \
  GrACellShort**: _GrACellShortFree, \
  GrACellFloat**: _GrACellFloatFree, \
  default: PBErrInvalidPolymorphism)(G)

// -------------- GrAFun

// ================= Define ==================

// ================= Data structure ===================

// ================ Functions declaration ====================

// ================= Polymorphism ==================

// -------------- GradAutomaton

// ================= Define ==================

// ================= Data structure ===================

// ================ Functions declaration ====================

// ================= Polymorphism ==================

// ================ static inliner ====================

#if BUILDMODE != 0
#include "gradautomaton-inline.c"
#endif

#endif

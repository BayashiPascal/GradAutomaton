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
  VecShort* status[2];

  // Index of the current status of the cell
  unsigned char curStatus;

} GrACellShort;

typedef struct GrACellFloat {

  // Double buffered status of the cell
  VecFloat* status[2];

  // Index of the current status of the cell
  unsigned char curStatus;

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

// Switch the current status of the GrACellShort 'that'
#if BUILDMODE != 0
static inline
#endif
void _GrACellShortSwitchStatus(GrACellShort* const that);

// Switch the current status of the GrACellFloat 'that'
#if BUILDMODE != 0
static inline
#endif
void _GrACellFloatSwitchStatus(GrACellFloat* const that);

// Return the current status of the GrACellShort 'that'
#if BUILDMODE != 0
static inline
#endif
VecShort* _GrACellShortCurStatus(const GrACellShort* const that);

// Return the current status of the GrACellFloat 'that'
#if BUILDMODE != 0
static inline
#endif
VecFloat* _GrACellFloatCurStatus(const GrACellFloat* const that);

// Return the previous status of the GrACellShort 'that'
#if BUILDMODE != 0
static inline
#endif
VecShort* _GrACellShortPrevStatus(const GrACellShort* const that);

// Return the previous status of the GrACellFloat 'that'
#if BUILDMODE != 0
static inline
#endif
VecFloat* _GrACellFloatPrevStatus(const GrACellFloat* const that);

// ================= Polymorphism ==================

#define GrACellFree(G) _Generic(G, \
  GrACellShort**: _GrACellShortFree, \
  GrACellFloat**: _GrACellFloatFree, \
  default: PBErrInvalidPolymorphism)(G)

#define GrACellSwitchStatus(G) _Generic(G, \
  GrACellShort*: _GrACellShortSwitchStatus, \
  GrACellFloat*: _GrACellFloatSwitchStatus, \
  default: PBErrInvalidPolymorphism)(G)

#define GrACellCurStatus(G) _Generic(G, \
  GrACellShort*: _GrACellShortCurStatus, \
  GrACellFloat*: _GrACellFloatCurStatus, \
  default: PBErrInvalidPolymorphism)(G)

#define GrACellPrevStatus(G) _Generic(G, \
  GrACellShort*: _GrACellShortPrevStatus, \
  GrACellFloat*: _GrACellFloatPrevStatus, \
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

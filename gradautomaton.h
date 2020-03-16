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
  const GrACellShort*: _GrACellShortSwitchStatus, \
  GrACellFloat*: _GrACellFloatSwitchStatus, \
  const GrACellFloat*: _GrACellFloatSwitchStatus, \
  default: PBErrInvalidPolymorphism)(G)

#define GrACellCurStatus(G) _Generic(G, \
  GrACellShort*: _GrACellShortCurStatus, \
  const GrACellShort*: _GrACellShortCurStatus, \
  GrACellFloat*: _GrACellFloatCurStatus, \
  const GrACellFloat*: _GrACellFloatCurStatus, \
  default: PBErrInvalidPolymorphism)(G)

#define GrACellPrevStatus(G) _Generic(G, \
  GrACellShort*: _GrACellShortPrevStatus, \
  const GrACellShort*: _GrACellShortPrevStatus, \
  GrACellFloat*: _GrACellFloatPrevStatus, \
  const GrACellFloat*: _GrACellFloatPrevStatus, \
  default: PBErrInvalidPolymorphism)(G)

// -------------- GrAFun

// ================= Define ==================

// ================= Data structure ===================

typedef enum GrAFunType {

  GrAFunTypeDummy

} GrAFunType;

typedef struct GrAFun {

  // Type of GrAFun
  GrAFunType type;

} GrAFun;

typedef struct GrAFunDummy {

  // GrAFun
  GrAFun grAFun;

} GrAFunDummy;

// ================ Functions declaration ====================

// Create a static GrAFun with type 'type'
GrAFun GrAFunCreateStatic(const GrAFunType type);

// Free the memory used by the GrAFun 'that'
void _GrAFunFreeStatic(GrAFun* that);

// Create a new GrAFunDummy
GrAFunDummy* GrAFunCreateDummy(void);

// Free the memory used by the GrAFunDummy 'that'
void _GrAFunDummyFree(GrAFunDummy** that);

// Return the type of the GrAFun 'that'
#if BUILDMODE != 0
static inline
#endif
GrAFunType _GrAFunGetType(const GrAFun* const that);

// ================= Polymorphism ==================

#define GrAFunFree(G) _Generic(G, \
  GrAFun*: _GrAFunFreeStatic, \
  GrAFunDummy**: _GrAFunDummyFree, \
  default: PBErrInvalidPolymorphism)((G))

#define GrAFunGetType(G) _Generic(G, \
  GrAFun*: _GrAFunGetType, \
  const GrAFun*: _GrAFunGetType, \
  GrAFunDummy*: _GrAFunGetType, \
  const GrAFunDummy*: _GrAFunGetType, \
  default: PBErrInvalidPolymorphism)((const GrAFun*)(G))

// -------------- GradAutomaton

// ================= Define ==================

// ================= Data structure ===================

typedef enum GradAutomatonType {

  GradAutomatonTypeDummy

} GradAutomatonType;

typedef struct GradAutomaton {

  // Type of the GradAutomaton
  GradAutomatonType type;

  // Dimension of the status vector of each cell
  long dim;

  // Grad
  Grad* grad;

  // GrAFun
  GrAFun* fun;

} GradAutomaton;

// GradSquare (2x2, no diag), GraFunDummy, GrACellShort dimension 1
typedef struct GradAutomatonDummy {

  // Parent GradAutomaton
  GradAutomaton gradAutomaton;

} GradAutomatonDummy;

// ================ Functions declaration ====================

// Create a new static GradAutomaton
GradAutomaton GradAutomatonCreateStatic(
  const GradAutomatonType type,
  Grad* const grad,
  GrAFun* const fun);

// Create a new GradAutomatonDummy
GradAutomatonDummy* GradAutomatonCreateDummy();

// Free the memory used by the GradAutomatonDummy 'that'
void GradAutomatonDummyFree(GradAutomatonDummy** that);

// Step the GradAutomatonDummyStep
void _GradAutomatonDummyStep(GradAutomatonDummy* const that);

// Return the Grad of the GradAutomatonDummy 'that'
#if BUILDMODE != 0
static inline
#endif
GradSquare* _GradAutomatonDummyGrad(GradAutomatonDummy* const that);

// Return the GrAFun of the GradAutomatonDummy 'that'
#if BUILDMODE != 0
static inline
#endif
GrAFunDummy* _GradAutomatonDummyFun(GradAutomatonDummy* const that);

// ================= Polymorphism ==================

#define GradAutomatonStep(G) _Generic(G, \
  GradAutomatonDummy* : _GradAutomatonDummyStep, \
  default: PBErrInvalidPolymorphism)(G)

#define GradAutomatonGrad(G) _Generic(G, \
  GradAutomatonDummy* : _GradAutomatonDummyGrad, \
  default: PBErrInvalidPolymorphism)(G)

#define GradAutomatonFun(G) _Generic(G, \
  GradAutomatonDummy* : _GradAutomatonDummyFun, \
  default: PBErrInvalidPolymorphism)(G)

// ================ static inliner ====================

#if BUILDMODE != 0
#include "gradautomaton-inline.c"
#endif

#endif

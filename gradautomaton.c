// ============ GRADAUTOMATON.C ================

// ================= Include =================

#include "gradautomaton.h"
#if BUILDMODE == 0
#include "gradautomaton-inline.c"
#endif

// -------------- GrACell

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
  that->status[0] = VecShortCreate(dim);
  that->status[1] = VecShortCreate(dim);
  that->curStatus = 0;

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
  that->status[0] = VecFloatCreate(dim);
  that->status[1] = VecFloatCreate(dim);
  that->curStatus = 0;

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
  VecFree(&((*that)->status[0]));
  VecFree(&((*that)->status[1]));
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
  VecFree(&((*that)->status[0]));
  VecFree(&((*that)->status[1]));
  free(*that);
  *that = NULL;

}

// -------------- GrAFun

// ================ Functions declaration ====================

// ================ Functions implementation ====================

// Create a static GrAFun with type 'type'
GrAFun GrAFunCreateStatic(const GrAFunType type) {

  // Declare the new GrAFun
  GrAFun that;

  // Set properties
  that.type = type;

  // Return the new GrAFun
  return that;

}

// Free the memory used by the GrAFun 'that'
void _GrAFunFreeStatic(GrAFun* that) {

  // If that is null
  if (that == NULL) {

    // Do nothing
    return;

  }

}

// Create a new GrAFunDummy
GrAFunDummy* GrAFunCreateDummy(void) {

  // Declare the new GrAFun
  GrAFunDummy* that =
    PBErrMalloc(
      GradAutomatonErr,
      sizeof(GrAFunDummy));

  // Set properties
  that->grAFun = GrAFunCreateStatic(GrAFunTypeDummy);

  // Return the new GrAFun
  return that;

}

// Free the memory used by the GrAFunDummy 'that'
void _GrAFunDummyFree(GrAFunDummy** that) {

  // If that is null
  if (that == NULL || *that == NULL) {

    // Do nothing
    return;

  }

  // Free memory
  _GrAFunFreeStatic((GrAFun*)(*that));
  free(*that);
  *that = NULL;

}

// ------------- GradAutomaton

// Create a new static GradAutomaton
GradAutomaton GradAutomatonCreateStatic(
  const GradAutomatonType type,
  Grad* const grad,
  GrAFun* const fun) {

#if BUILDMODE == 0
  if (grad == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'grad' is null");
    PBErrCatch(GradAutomatonErr);

  }

  if (fun == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'fun' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  // Declare the new GradAutomaton
  GradAutomaton that;

  // Set the properties
  that.type = type;
  that.grad = grad;
  that.fun = fun;

  // Return the new GradAutomaton
  return that;

}

// Create a new GradAutomatonDummy
GradAutomatonDummy* GradAutomatonCreateDummy() {

  // Allocate memory for the new GradAutomatonDummy
  GradAutomatonDummy* that =
    PBErrMalloc(
      GradAutomatonErr,
      sizeof(GradAutomatonDummy));

  // Create the associated Grad and GrAFun
  bool diagLink = false;
  VecShort2D dim = VecShortCreateStatic2D();
  VecSet(
    &dim,
    0,
    2);
  VecSet(
    &dim,
    1,
    2);
  Grad* grad =
    (Grad*)GradSquareCreate(
      &dim,
      diagLink);
  GrAFun* fun = (GrAFun*)GrAFunCreateDummy();

  // Initialize the properties
  that->gradAutomaton =
    GradAutomatonCreateStatic(
      GradAutomatonTypeDummy,
      grad,
      fun);

  // Add a GrACell to each cell of the Grad
  VecShort2D pos = VecShortCreateStatic2D();
  bool flag = true;
  do {

    GradCell* cell =
      GradCellAt(
        grad,
        &pos);

    GrACellShort* cellStatus =
      GrACellCreateShort(1);

    GradCellSetData(
      cell,
      cellStatus);

    flag =
      VecStep(
        &pos,
        &dim);

  } while(flag);

  // Return the new GradAutomatonDummy
  return that;

}

// Free the memory used by the GradAutomatonDummy 'that'
void GradAutomatonDummyFree(GradAutomatonDummy** that) {

  // If that is null
  if (that == NULL || *that == NULL) {

    // Do nothing
    return;

  }

  // Free the GrACell attached to the cells of the Grad
  VecShort2D pos = VecShortCreateStatic2D();
  bool flag = true;
  do {

    GradCell* cell =
      GradCellAt(
        GradAutomatonGrad(*that),
        &pos);

    GrACellShort* cellStatus = GradCellData(cell);

    GrACellFree(&cellStatus);

    flag =
      VecStep(
        &pos,
        GradDim(GradAutomatonGrad(*that)));

  } while(flag);

  // Free memory
  GradSquareFree((GradSquare**)&((*that)->gradAutomaton.grad));
  _GrAFunDummyFree((GrAFunDummy**)&((*that)->gradAutomaton.fun));
  free(*that);
  *that = NULL;

}

// Step the GradAutomatonDummyStep
void _GradAutomatonDummyStep(GradAutomatonDummy* const that) {

#if BUILDMODE == 0
  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  (void)that;

}

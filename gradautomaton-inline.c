// ============ GRADAUTOMATON_INLINE.C ================

// -------------- GrACell

// ================ Functions implementation ====================

// Switch the current status of the GrACellShort 'that'
#if BUILDMODE != 0
static inline
#endif
void _GrACellShortSwitchStatus(GrACellShort* const that) {

#if BUILDMODE == 0
  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  that->curStatus = 1 - that->curStatus;

}

// Switch the current status of the GrACellFloat 'that'
#if BUILDMODE != 0
static inline
#endif
void _GrACellFloatSwitchStatus(GrACellFloat* const that) {

#if BUILDMODE == 0
  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  that->curStatus = 1 - that->curStatus;

}

// Return the current status of the GrACellShort 'that'
#if BUILDMODE != 0
static inline
#endif
VecShort* _GrACellShortCurStatus(const GrACellShort* const that) {

#if BUILDMODE == 0
  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  return that->status[that->curStatus];

}

// Return the current status of the GrACellFloat 'that'
#if BUILDMODE != 0
static inline
#endif
VecFloat* _GrACellFloatCurStatus(const GrACellFloat* const that) {

#if BUILDMODE == 0
  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  return that->status[that->curStatus];

}

// Return the previous status of the GrACellShort 'that'
#if BUILDMODE != 0
static inline
#endif
VecShort* _GrACellShortPrevStatus(const GrACellShort* const that) {

#if BUILDMODE == 0
  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  return that->status[1 - that->curStatus];

}

// Return the previous status of the GrACellFloat 'that'
#if BUILDMODE != 0
static inline
#endif
VecFloat* _GrACellFloatPrevStatus(const GrACellFloat* const that) {

#if BUILDMODE == 0
  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  return that->status[1 - that->curStatus];

}

// -------------- GrAFun

// ================ Functions implementation ====================

// Return the type of the GrAFun 'that'
#if BUILDMODE != 0
static inline
#endif
GrAFunType _GrAFunGetType(const GrAFun* const that) {

#if BUILDMODE == 0
  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  return that->type;

}

// -------------- GradAutomaton

// ================ Functions implementation ====================

// Return the Grad of the GradAutomatonDummy 'that'
#if BUILDMODE != 0
static inline
#endif
GradSquare* _GradAutomatonDummyGrad(GradAutomatonDummy* const that) {

#if BUILDMODE == 0
  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  // Return the Grad
  return ((GradSquare*)((GradAutomaton*)that)->grad);

}

// Return the GrAFun of the GradAutomatonDummy 'that'
#if BUILDMODE != 0
static inline
#endif
GrAFunDummy* _GradAutomatonDummyFun(GradAutomatonDummy* const that) {

#if BUILDMODE == 0
  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  // Return the GrAFun
  return ((GrAFunDummy*)((GradAutomaton*)that)->fun);

}

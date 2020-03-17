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

// Return the 'iVal'-th value of the previous status of the
// GrACellShort 'that'
#if BUILDMODE != 0
static inline
#endif
short _GrACellShortGetPrevStatus(
  const GrACellShort* const that,
  const unsigned long iVal) {

#if BUILDMODE == 0
  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  return VecGet(
    GrACellPrevStatus(that),
    iVal);

}

// Return the 'iVal'-th value of the previous status of the
// GrACellFloat 'that'
#if BUILDMODE != 0
static inline
#endif
float _GrACellFloatGetPrevStatus(
  const GrACellFloat* const that,
  const unsigned long iVal) {

#if BUILDMODE == 0
  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  return VecGet(
    GrACellPrevStatus(that),
    iVal);

}

// Set the 'iVal'-th value of the previous status of the
// GrACellShort 'that' to 'val'
#if BUILDMODE != 0
static inline
#endif
void _GrACellShortSetPrevStatus(
  const GrACellShort* const that,
  const unsigned long iVal,
  const short val) {

#if BUILDMODE == 0
  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  VecSet(
    GrACellPrevStatus(that),
    iVal,
    val);

}

// Set the 'iVal'-th value of the previous status of the
// GrACellFloat 'that' to 'val'
#if BUILDMODE != 0
static inline
#endif
void _GrACellFloatSetPrevStatus(
  const GrACellFloat* const that,
  const unsigned long iVal,
  const float val) {

#if BUILDMODE == 0
  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  VecSet(
    GrACellPrevStatus(that),
    iVal,
    val);

}

// Return the 'iVal'-th value of the current status of the
// GrACellShort 'that'
#if BUILDMODE != 0
static inline
#endif
short _GrACellShortGetCurStatus(
  const GrACellShort* const that,
  const unsigned long iVal) {

#if BUILDMODE == 0
  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  return VecGet(
    GrACellCurStatus(that),
    iVal);

}

// Return the 'iVal'-th value of the current status of the
// GrACellFloat 'that'
#if BUILDMODE != 0
static inline
#endif
float _GrACellFloatGetCurStatus(
  const GrACellFloat* const that,
  const unsigned long iVal) {

#if BUILDMODE == 0
  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  return VecGet(
    GrACellCurStatus(that),
    iVal);

}

// Set the 'iVal'-th value of the current status of the
// GrACellShort 'that' to 'val'
#if BUILDMODE != 0
static inline
#endif
void _GrACellShortSetCurStatus(
  const GrACellShort* const that,
  const unsigned long iVal,
  const short val) {

#if BUILDMODE == 0
  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  VecSet(
    GrACellCurStatus(that),
    iVal,
    val);

}

// Set the 'iVal'-th value of the current status of the
// GrACellFloat 'that' to 'val'
#if BUILDMODE != 0
static inline
#endif
void _GrACellFloatSetCurStatus(
  const GrACellFloat* const that,
  const unsigned long iVal,
  const float val) {

#if BUILDMODE == 0
  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  VecSet(
    GrACellCurStatus(that),
    iVal,
    val);

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

// -------------- GradAutomatonDummy

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

// -------------- GradAutomatonWolframOriginal

// ================ Functions implementation ====================

// Return the Grad of the GradAutomatonWolframOriginal 'that'
#if BUILDMODE != 0
static inline
#endif
GradSquare* _GradAutomatonWolframOriginalGrad(
  GradAutomatonWolframOriginal* const that) {

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

// Return the GrAFun of the GradAutomatonWolframOriginal 'that'
#if BUILDMODE != 0
static inline
#endif
GrAFunWolframOriginal* _GradAutomatonWolframOriginalFun(
  GradAutomatonWolframOriginal* const that) {

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
  return ((GrAFunWolframOriginal*)((GradAutomaton*)that)->fun);

}

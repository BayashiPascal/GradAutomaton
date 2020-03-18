// ============ GRADAUTOMATON_INLINE.C ================

// -------------- GrACell

// ================ Functions implementation ====================

// Switch the current status of the GrACell 'that'
#if BUILDMODE != 0
static inline
#endif
void _GrACellSwitchStatus(GrACell* const that) {

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

  return that->status[that->gradAutomatonCell.curStatus];

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

  return that->status[that->gradAutomatonCell.curStatus];

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

  return that->status[1 - that->gradAutomatonCell.curStatus];

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

  return that->status[1 - that->gradAutomatonCell.curStatus];

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

// Return the GradCell of the GrACellShort 'that'
#if BUILDMODE != 0
static inline
#endif
GradCell* _GrACellShortGradCell(const GrACellShort* const that) {

#if BUILDMODE == 0
  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  return that->gradAutomatonCell.gradCell;

}

// Return the GradCell of the GrACellFloat 'that'
#if BUILDMODE != 0
static inline
#endif
GradCell* _GrACellFloatGradCell(const GrACellFloat* const that) {

#if BUILDMODE == 0
  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  return that->gradAutomatonCell.gradCell;

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

// -------------- GrAFunWolframOriginal

// ================ Functions implementation ====================

// Return the rule of the GrAFunWolframOriginal 'that'
#if BUILDMODE != 0
static inline
#endif
unsigned char GrAFunWolFramOriginalGetRule(
  GrAFunWolframOriginal* const that) {

#if BUILDMODE == 0
  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  return that->rule;

}

// -------------- GradAutomaton

// ================ Functions implementation ====================

// Return the Grad of the GradAutomaton 'that'
#if BUILDMODE != 0
static inline
#endif
Grad* _GradAutomatonGrad(GradAutomaton* const that) {

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
  return that->grad;

}

// Return the GrACellShort at position 'pos' for the
// GradAutomaton 'that'
#if BUILDMODE != 0
static inline
#endif
GrACell* _GradAutomatonCellPos(
  GradAutomaton* const that,
  const VecShort2D* const pos) {

#if BUILDMODE == 0
  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

  if (pos == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'pos' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  // Get the GradCell at the requested position
  GradCell* cell =
    GradCellAt(
      GradAutomatonGrad(that),
      pos);

  // Return the GrACellShort associated to the cell
  return (GrACell*)GradCellData(cell);

}

// Return the GrACellShort at index 'iCell' for the GradAutomaton 'that'
#if BUILDMODE != 0
static inline
#endif
GrACell* _GradAutomatonCellIndex(
  GradAutomaton* const that,
  const int iCell) {

#if BUILDMODE == 0
  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  // Get the GradCell at the requested position
  GradCell* cell =
    GradCellAt(
      GradAutomatonGrad(that),
      iCell);

  // Return the GrACellShort associated to the cell
  return (GrACell*)GradCellData(cell);

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
  return (GradSquare*)(((GradAutomaton*)that)->grad);

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
  return (GrAFunDummy*)(((GradAutomaton*)that)->fun);

}

// Return the GrACellShort at position 'pos' for the
// GradAutomatonDummy 'that'
#if BUILDMODE != 0
static inline
#endif
GrACellShort* _GradAutomatonDummyCellPos(
  GradAutomatonDummy* const that,
  const VecShort2D* const pos) {

#if BUILDMODE == 0
  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

  if (pos == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'pos' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  // Get the GradCell at the requested position
  GradCell* cell =
    GradCellAt(
      GradAutomatonGrad(that),
      pos);

  // Return the GrACellShort associated to the cell
  return (GrACellShort*)GradCellData(cell);

}

// Return the GrACellShort at index 'iCell' for the
// GradAutomatonDummy 'that'
#if BUILDMODE != 0
static inline
#endif
GrACellShort* _GradAutomatonDummyCellIndex(
  GradAutomatonDummy* const that,
  const int iCell) {

#if BUILDMODE == 0
  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  // Get the GradCell at the requested position
  GradCell* cell =
    GradCellAt(
      GradAutomatonGrad(that),
      iCell);

  // Return the GrACellShort associated to the cell
  return (GrACellShort*)GradCellData(cell);

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
  return (GradSquare*)(((GradAutomaton*)that)->grad);

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
  return (GrAFunWolframOriginal*)(((GradAutomaton*)that)->fun);

}

// Return the GrACellShort at position 'pos' for the
// GradAutomatonWolframOriginal 'that'
#if BUILDMODE != 0
static inline
#endif
GrACellShort* _GradAutomatonWolframOriginalCellPos(
  GradAutomatonWolframOriginal* const that,
  const VecShort2D* const pos) {

#if BUILDMODE == 0
  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

  if (pos == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'pos' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  // Get the GradCell at the requested position
  GradCell* cell =
    GradCellAt(
      GradAutomatonGrad(that),
      pos);

  // Return the GrACellShort associated to the cell
  return (GrACellShort*)GradCellData(cell);

}

// Return the GrACellShort at index 'iCell' for the
// GradAutomatonWolframOriginal 'that'
#if BUILDMODE != 0
static inline
#endif
GrACellShort* _GradAutomatonWolframOriginalCellIndex(
  GradAutomatonWolframOriginal* const that,
  const int iCell) {

#if BUILDMODE == 0
  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  // Get the GradCell at the requested position
  GradCell* cell =
    GradCellAt(
      GradAutomatonGrad(that),
      iCell);

  // Return the GrACellShort associated to the cell
  return (GrACellShort*)GradCellData(cell);

}

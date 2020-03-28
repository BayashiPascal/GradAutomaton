// ============ GRADAUTOMATON.C ================

// ================= Include =================

#include "gradautomaton.h"
#if BUILDMODE == 0
#include "gradautomaton-inline.c"
#endif

// -------------- GrACell

// ================ Functions declaration ====================

// ================ Functions implementation ====================

// Create a new static GrACell
GrACell GradAutomatonCellCreateStatic(
  GradCell* const gradCell) {

  // Create the new GradAutomatonCell
  GrACell cell;

  // Set the properties
  cell.curStatus = 0;
  cell.gradCell = gradCell;

  // Return the new GradAutomatonCell
  return cell;

}

// Create a new GrACellShort with a status vector of dimension 'dim'
// for the GradCell 'gradCell'
GrACellShort* GrACellCreateShort(
       const long dim,
  GradCell* const gradCell) {

  // Allocate memory
  GrACellShort* that =
    PBErrMalloc(
      GradAutomatonErr,
      sizeof(GrACellShort));

  // Initialise properties
  that->status[0] = VecShortCreate(dim);
  that->status[1] = VecShortCreate(dim);
  that->gradAutomatonCell = GradAutomatonCellCreateStatic(gradCell);

  // Return the new GrACellShort
  return that;

}

// Create a new GrACellFloat with a status vector of dimension 'dim'
// for the GradCell 'gradCell'
GrACellFloat* GrACellCreateFloat(
       const long dim,
  GradCell* const gradCell) {

  // Allocate memory
  GrACellFloat* that =
    PBErrMalloc(
      GradAutomatonErr,
      sizeof(GrACellFloat));

  // Initialise properties
  that->status[0] = VecFloatCreate(dim);
  that->status[1] = VecFloatCreate(dim);
  that->gradAutomatonCell = GradAutomatonCellCreateStatic(gradCell);

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

// -------------- GrAFunDummy

// ================ Functions declaration ====================

// ================ Functions implementation ====================

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

// -------------- GrAFunWolframOriginal

// ================ Functions declaration ====================

// ================ Functions implementation ====================

// Create a new GrAFunWolframOriginal
GrAFunWolframOriginal* GrAFunCreateWolframOriginal(
  const unsigned char rule) {

  // Declare the new GrAFun
  GrAFunWolframOriginal* that =
    PBErrMalloc(
      GradAutomatonErr,
      sizeof(GrAFunWolframOriginal));

  // Set properties
  that->grAFun = GrAFunCreateStatic(GrAFunTypeWolframOriginal);
  that->rule = rule;

  // Return the new GrAFun
  return that;

}

// Free the memory used by the GrAFunWolframOriginal 'that'
void _GrAFunWolframOriginalFree(GrAFunWolframOriginal** that) {

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

// Apply the step function for the GrAFunWolframOriginal 'that'
// to the GrACellShort 'cell' in the GradSquare 'grad'
void _GrAFunWolframOriginalApply(
  GrAFunWolframOriginal* const that,
             GradSquare* const grad,
           GrACellShort* const cell) {

#if BUILDMODE == 0
  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

  if (grad == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'grad' is null");
    PBErrCatch(GradAutomatonErr);

  }

  if (cell == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'cell' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  // Declare a variable to memorize the current status of the
  // cell and its neighbour
  short status[3] = {0, 0, 0};

  // Get the current status of the left cell
  long leftLink =
    GradCellGetLink(
      GrACellGradCell(cell),
      GradSquareDirW);
  if (leftLink != -1) {

    GradCell* leftNeighbour =
      GradCellNeighbour(
        grad,
        GrACellGradCell(cell),
        GradSquareDirW);
    GrACellShort* leftCell =
      (GrACellShort*)GradCellData(leftNeighbour);
    status[0] =
      VecGet(
        GrACellCurStatus(leftCell),
        0);

  }

  // Get the current status of the cell
  status[1] =
    VecGet(
      GrACellCurStatus(cell),
      0);

  // Get the current status of the right cell
  long rightLink =
    GradCellGetLink(
      GrACellGradCell(cell),
      GradSquareDirE);
  if (rightLink != -1) {

    GradCell* rightNeighbour =
      GradCellNeighbour(
        grad,
        GrACellGradCell(cell),
        GradSquareDirE);
    GrACellShort* rightCell =
      (GrACellShort*)GradCellData(rightNeighbour);
    status[2] =
      VecGet(
        GrACellCurStatus(rightCell),
        0);

  }

  // Get the corresponding mask in the rule
  unsigned char mask =
    powi(
      2,
      ((status[0] * 2) + status[1]) * 2 + status[2]);

  // Get the new status of the cell
  short newStatus = 0;
  if (GrAFunWolframOriginalGetRule(that) & mask) {

    newStatus = 1;

  }

  // Update the previous status with the new status
  // (it will be switch later)
  GrACellSetPrevStatus(
    cell,
    0,
    newStatus);

}

// -------------- GrAFunNeuraNet

// ================ Functions declaration ====================

// ================ Functions implementation ====================

// Create a new GrAFunNeuraNet
GrAFunNeuraNet* GrAFunCreateNeuraNet(
             const int nbIn,
             const int nbOut,
  const VecLong* const hiddenLayers) {

  // Declare the new GrAFun
  GrAFunNeuraNet* that =
    PBErrMalloc(
      GradAutomatonErr,
      sizeof(GrAFunNeuraNet));

  // Set properties
  that->grAFun = GrAFunCreateStatic(GrAFunTypeNeuraNet);
  that->nn =
    NeuraNetCreateFullyConnected(
      nbIn,
      nbOut,
      hiddenLayers);

  // Return the new GrAFunNeuraNet
  return that;

}

// Free the memory used by the GrAFunNeuraNet 'that'
void _GrAFunNeuraNetFree(GrAFunNeuraNet** that) {

  // If that is null
  if (that == NULL || *that == NULL) {

    // Do nothing
    return;

  }

  // Free memory
  NeuraNetFree(&((*that)->nn));
  _GrAFunFreeStatic((GrAFun*)(*that));
  free(*that);
  *that = NULL;

}

// Apply the step function for the GrAFunNeuraNet 'that'
// to the GrACellShort 'cell' in the GradSquare 'grad'
void _GrAFunNeuraNetApply(
  GrAFunNeuraNet* const that,
            Grad* const grad,
    GrACellFloat* const cell) {

#if BUILDMODE == 0
  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

  if (grad == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'grad' is null");
    PBErrCatch(GradAutomatonErr);

  }

  if (cell == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'cell' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  // Get the number of links of the cell
  int nbLinks = GradCellGetNbLink(GrACellGradCell(cell));

  // Get the dimension of the input vector for the NeuraNet
  long dimInput = (nbLinks + 1) * VecGetDim(GrACellCurStatus(cell));

  // Declare a variable to memorize the input of the NeuraNet
  VecFloat* input = VecFloatCreate(dimInput);

  // Declare a variable to memorize the output of the NeuraNet
  VecFloat* output = VecFloatCreate(VecGetDim(GrACellCurStatus(cell)));

  // Set the current status of the cell in the input vector
  for (
    long iDim = VecGetDim(output);
    iDim--;) {

    float val =
      GrACellGetCurStatus(
        cell,
        iDim);

    VecSet(
      input,
      iDim,
      val);

  }

  // Loop on the links toward neighbour cells
  for (
    long iLink = nbLinks;
    iLink--;) {

    // Get the link
    long link =
      GradCellGetLink(
        GrACellGradCell(cell),
        iLink);

    // If the link is active
    if (link != -1) {

      // Get the neighbour cell and its status
      GradCell* neighbour =
        GradCellNeighbour(
          grad,
          GrACellGradCell(cell),
          iLink);
      GrACellFloat* neighbourCell =
        (GrACellFloat*)GradCellData(neighbour);

      // Set the current status of the neighbour cell in the
      // input vector
      for (
        long iDim = VecGetDim(output);
        iDim--;) {

        float val =
          GrACellGetCurStatus(
            neighbourCell,
            iDim);

        VecSet(
          input,
          (link + 1) * VecGetDim(output) + iDim,
          val);

      }

    }

  }

  // Apply the NeuraNet
  NNEval(
    GrAFunNeuraNetNN(that),
    input,
    output);

  // Update the previous status with the output of the NeuraNet
  // (it will be switch later)
  for (
    long iDim = VecGetDim(output);
    iDim--;) {

    float val =
      VecGet(
        output,
        iDim);

    GrACellSetPrevStatus(
      cell,
      iDim,
      val);

  }

  // Free memory
  VecFree(&input);
  VecFree(&output);

}

// ------------- GradAutomaton

// Create a new static GradAutomaton
GradAutomaton GradAutomatonCreateStatic(
  const GradAutomatonType type,
              Grad* const grad,
            GrAFun* const fun,
               const long dimStatus) {

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
  that.dimStatus = dimStatus;

  // Return the new GradAutomaton
  return that;

}

// Switch the status of all the cells of the GradAutomaton 'that'
void _GradAutomatonSwitchAllStatus(GradAutomaton* const that) {

#if BUILDMODE == 0
  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  // Get the number of cells in the grad
  long nbCell = GradGetArea(GradAutomatonGrad(that));

  // Loop on the cell
  for (
    long iCell = nbCell;
    iCell--;) {

    // Get the cell
    GrACell* cell =
      GradAutomatonCell(
        that,
        iCell);

    // Switch the status of the cell
    GrACellSwitchStatus(cell);

  }

}

// ------------- GradAutomatonDummy

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
  long dimStatus = 1;
  that->gradAutomaton =
    GradAutomatonCreateStatic(
      GradAutomatonTypeDummy,
      grad,
      fun,
      dimStatus);

  // Add a GrACell to each cell of the Grad
  VecShort2D pos = VecShortCreateStatic2D();
  bool flag = true;
  do {

    GradCell* cell =
      GradCellAt(
        grad,
        &pos);

    GrACellShort* cellStatus =
      GrACellCreateShort(
        dimStatus,
        cell);

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

// ------------- GradAutomatonWolframOriginal

// Create a new GradAutomatonWolframOriginal
GradAutomatonWolframOriginal* GradAutomatonCreateWolframOriginal(
  const unsigned char rule,
           const long size) {

  // Allocate memory for the new GradAutomatonWolframOriginal
  GradAutomatonWolframOriginal* that =
    PBErrMalloc(
      GradAutomatonErr,
      sizeof(GradAutomatonWolframOriginal));

  // Create the associated Grad and GrAFun
  bool diagLink = false;
  VecShort2D dim = VecShortCreateStatic2D();
  VecSet(
    &dim,
    0,
    size);
  VecSet(
    &dim,
    1,
    1);
  Grad* grad =
    (Grad*)GradSquareCreate(
      &dim,
      diagLink);
  GrAFun* fun = (GrAFun*)GrAFunCreateWolframOriginal(rule);

  // Initialize the properties
  long dimStatus = 1;
  that->gradAutomaton =
    GradAutomatonCreateStatic(
      GradAutomatonTypeWolframOriginal,
      grad,
      fun,
      dimStatus);

  // Get the index of the cell in th center of the Grad
  long iCellCenter = size / 2;

  // Add a GrACell to each cell of the Grad
  for (
    long iCell = size;
    iCell--;) {

    GradCell* cell =
      GradCellAt(
        grad,
        iCell);

    GrACellShort* cellStatus =
      GrACellCreateShort(
        dimStatus,
        cell);

    // If it's the cell in the center of the Grad
    if (iCell == iCellCenter) {

      // Initialise the cell value to 1
      long iStatus = 0;
      short val = 1;
      GrACellSetPrevStatus(
        cellStatus,
        iStatus,
        val);
      GrACellSetCurStatus(
        cellStatus,
        iStatus,
        val);

    }

    GradCellSetData(
      cell,
      cellStatus);

  };

  // Return the new GradAutomatonWolframOriginal
  return that;

}

// Free the memory used by the GradAutomatonWolframOriginal 'that'
void GradAutomatonWolframOriginalFree(
  GradAutomatonWolframOriginal** that) {

  // If that is null
  if (that == NULL || *that == NULL) {

    // Do nothing
    return;

  }

  // Get the number of cells in the grad
  long nbCell = GradGetArea(GradAutomatonGrad(*that));

  // Free the GrACell attached to the cells of the Grad
  for (
    long iCell = nbCell;
    iCell--;) {

    GradCell* cell =
      GradCellAt(
        GradAutomatonGrad(*that),
        iCell);

    GrACellShort* cellStatus = GradCellData(cell);

    GrACellFree(&cellStatus);

  }

  // Free memory
  GradSquareFree((GradSquare**)&((*that)->gradAutomaton.grad));
  _GrAFunWolframOriginalFree(
    (GrAFunWolframOriginal**)&((*that)->gradAutomaton.fun));
  free(*that);
  *that = NULL;

}

// Step the GradAutomatonWolframOriginalStep
void _GradAutomatonWolframOriginalStep(
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

  // Get the number of cells in the grad
  long nbCell = GradGetArea(GradAutomatonGrad(that));

  // Loop on the cell
  for (
    long iCell = nbCell;
    iCell--;) {

    // Get the cell
    GrACellShort* cell =
      GradAutomatonCell(
        that,
        iCell);

    // Apply the step function to the cell
    GrAFunApply(
      GradAutomatonFun(that),
      GradAutomatonGrad(that),
      cell);

  }

  // Switch all the cells
  GradAutomatonSwitchAllStatus(that);

}

// Print the GradAutomatonWolframOriginal 'that' on the FILE 'stream'
void _GradAutomatonWolframOriginalPrintln(
  GradAutomatonWolframOriginal* const that,
                                FILE* stream) {

#if BUILDMODE == 0
  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

  if (stream == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'stream' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  // Get the number of cells in the grad
  long nbCell = GradGetArea(GradAutomatonGrad(that));

  fprintf(
    stream,
    "[");

  // Loop on the cell
  for (
    long iCell = 0;
    iCell < nbCell;
    ++iCell) {

    // Get the cell
    GrACellShort* cell =
      GradAutomatonCell(
        that,
        iCell);

    // Get the current status of the cell
    short status =
      VecGet(
        GrACellCurStatus(cell),
        0);

    // Print the status
    if (status == 0) {

      fprintf(
        stream,
        " ");

    } else {

      fprintf(
        stream,
        "*");

    }

  }

  fprintf(
    stream,
    "]\n");

}

// JSON encoding of GradAutomatonWolframOriginal 'that'
JSONNode* _GradAutomatonWolframOriginalEncodeAsJSON(
  const GradAutomatonWolframOriginal* const that) {

#if BUILDMODE == 0

  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  // Create the JSON structure
  JSONNode* json = JSONCreate();

  // Declare a buffer to convert value into string
  char val[100];

  // Encode the rule
  unsigned char rule =
    GrAFunWolframOriginalGetRule(GradAutomatonFun(that));
  sprintf(
    val,
    "%d",
    rule);
  JSONAddProp(
    json,
    "rule",
    val);

  // Encode the size
  const VecShort2D* dim = GradDim(GradAutomatonGrad(that));
  long size =
    VecGet(
      dim,
      0);
  sprintf(
    val,
    "%ld",
    size);
  JSONAddProp(
    json,
    "size",
    val);

  // Return the created JSON
  return json;

}

// Function which decode from JSON encoding 'json' to 'that'
bool _GradAutomatonWolframOriginalDecodeAsJSON(
  GradAutomatonWolframOriginal** that,
           const JSONNode* const json) {

#if BUILDMODE == 0

  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

  if (json == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'json' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  // If 'that' is already allocated
  if (*that != NULL) {

    // Free memory
    GradAutomatonWolframOriginalFree(that);

  }

  // Decode the rule
  JSONNode* prop =
    JSONProperty(
      json,
      "rule");
  if (prop == NULL) {

    return false;

  }

  unsigned char rule = atoi(JSONLblVal(prop));

  // Decode the size
  prop =
    JSONProperty(
      json,
      "size");
  if (prop == NULL) {

    return false;

  }

  long size = atol(JSONLblVal(prop));

  // Create the GradAutomatonWolframOriginal
  *that =
    GradAutomatonCreateWolframOriginal(
      rule,
      size);

  // Return the success code
  return true;

}

// Save the GradAutomatonWolframOriginal 'that' to the stream 'stream'
// If 'compact' equals true it saves in compact form, else it saves in
// readable form
// Return true if the GradAutomatonWolframOriginal could be saved,
// false else
bool _GradAutomatonWolframOriginalSave(
  const GradAutomatonWolframOriginal* const that,
                                FILE* const stream,
                                 const bool compact) {

#if BUILDMODE == 0

  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

  if (stream == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'stream' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  // Get the JSON encoding
  JSONNode* json = GradAutomatonEncodeAsJSON(that);

  // Save the JSON
  bool ret =
    JSONSave(
      json,
      stream,
      compact);

  // Free memory
  JSONFree(&json);

  // Return success code
  return ret;

}

// Load the GradAutomatonWolfraOriginal 'that' from the stream 'stream'
// If 'that' is not null the memory is first freed
// Return true if the GradAutomatonWolframOriginal could be loaded,
// false else
bool _GradAutomatonWolframOriginalLoad(
  GradAutomatonWolframOriginal** that,
                     FILE* const stream) {

#if BUILDMODE == 0

  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

  if (stream == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'stream' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  // Declare a json to load the encoded data
  JSONNode* json = JSONCreate();

  // Load the whole encoded data
  bool ret =
    JSONLoad(
      json,
      stream);

  if (ret == true) {

    // Decode the data from the JSON
    ret =
      GradAutomatonDecodeAsJSON(
        that,
        json);

  }

  // Free the memory used by the JSON
  JSONFree(&json);

  // Return the success code
  return ret;

}

// ------------- GradAutomatonNeuraNet

// Create a new GradAutomatonNeuraNet with a GradSquare
GradAutomatonNeuraNet* GradAutomatonCreateNeuraNetSquare(
               const long dimStatus,
  const VecShort2D* const dimGrad,
               const bool diagLink,
               const long nbHiddenLayers) {

  // Allocate memory for the new GradAutomatonNeuraNet
  GradAutomatonNeuraNet* that =
    PBErrMalloc(
      GradAutomatonErr,
      sizeof(GradAutomatonNeuraNet));

  // Create the associated Grad and GrAFun
  Grad* grad =
    (Grad*)GradSquareCreate(
      dimGrad,
      diagLink);
  int nbIn = 0;
  if (diagLink == true) {

    nbIn = dimStatus * 9;

  } else {

    nbIn = dimStatus * 5;

  }

  int nbOut = dimStatus;
  VecLong* hiddenLayers = VecLongCreate(nbHiddenLayers);
  for (
    int iLayer = nbHiddenLayers;
    iLayer--;) {

    VecSet(
      hiddenLayers,
      iLayer,
      nbIn);

  }

  GrAFun* fun =
    (GrAFun*)GrAFunCreateNeuraNet(
      nbIn,
      nbOut,
      hiddenLayers);

  // Initialize the properties
  that->gradAutomaton =
    GradAutomatonCreateStatic(
      GradAutomatonTypeNeuraNet,
      grad,
      fun,
      dimStatus);

  // Add a GrACell to each cell of the Grad
  long area = GradGetArea(GradAutomatonGrad(that));
  for (
    long iCell = area;
    iCell--;) {

    GradCell* cell =
      GradCellAt(
        grad,
        iCell);

    GrACellFloat* cellStatus =
      GrACellCreateFloat(
        dimStatus,
        cell);

    GradCellSetData(
      cell,
      cellStatus);

  }

  // Return the new GradAutomatonNeuraNet
  return that;

}

// Create a new GradAutomatonNeuraNet with a GradHexa
GradAutomatonNeuraNet* GradAutomatonCreateNeuraNetHexa(
               const long dimStatus,
  const VecShort2D* const dimGrad,
       const GradHexaType gradType,
               const long nbHiddenLayers) {

  // Allocate memory for the new GradAutomatonNeuraNet
  GradAutomatonNeuraNet* that =
    PBErrMalloc(
      GradAutomatonErr,
      sizeof(GradAutomatonNeuraNet));

  // Create the associated Grad and GrAFun
  Grad* grad = NULL;
  switch (gradType) {

    case GradHexaTypeEvenQ:
      grad = (Grad*)GradHexaCreateEvenQ(
        dimGrad);
      break;
    case GradHexaTypeEvenR:
      grad = (Grad*)GradHexaCreateEvenR(
        dimGrad);
      break;
    case GradHexaTypeOddQ:
      grad = (Grad*)GradHexaCreateOddQ(
        dimGrad);
      break;
    case GradHexaTypeOddR:
      grad = (Grad*)GradHexaCreateOddR(
        dimGrad);
      break;
    default:
      break;

  }

  int nbIn = dimStatus * 6;
  int nbOut = dimStatus;
  VecLong* hiddenLayers = VecLongCreate(nbHiddenLayers);
  for (
    int iLayer = nbHiddenLayers;
    iLayer--;) {

    VecSet(
      hiddenLayers,
      iLayer,
      nbIn);

  }

  GrAFun* fun =
    (GrAFun*)GrAFunCreateNeuraNet(
      nbIn,
      nbOut,
      hiddenLayers);

  // Initialize the properties
  that->gradAutomaton =
    GradAutomatonCreateStatic(
      GradAutomatonTypeNeuraNet,
      grad,
      fun,
      dimStatus);

  // Add a GrACell to each cell of the Grad
  long area = GradGetArea(GradAutomatonGrad(that));
  for (
    long iCell = area;
    iCell--;) {

    GradCell* cell =
      GradCellAt(
        grad,
        iCell);

    GrACellFloat* cellStatus =
      GrACellCreateFloat(
        dimStatus,
        cell);

    GradCellSetData(
      cell,
      cellStatus);

  }

  // Return the new GradAutomatonNeuraNet
  return that;

}

// Free the memory used by the GradAutomatonNeuraNet 'that'
void GradAutomatonNeuraNetFree(
  GradAutomatonNeuraNet** that) {

  // If that is null
  if (that == NULL || *that == NULL) {

    // Do nothing
    return;

  }

  // Free the GrACell attached to the cells of the Grad
  long area = GradGetArea(GradAutomatonGrad(*that));
  for (
    long iCell = area;
    iCell--;) {

    GradCell* cell =
      GradCellAt(
        GradAutomatonGrad(*that),
        iCell);

    GrACellFloat* cellStatus = GradCellData(cell);

    GrACellFree(&cellStatus);

  }

  // Free memory
  GradSquareFree((GradSquare**)&((*that)->gradAutomaton.grad));
  free(*that);
  *that = NULL;

}

// Step the GradAutomatonNeuraNetStep
void _GradAutomatonNeuraNetStep(GradAutomatonNeuraNet* const that) {

#if BUILDMODE == 0
  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  // Get the number of cells in the grad
  long nbCell = GradGetArea(GradAutomatonGrad(that));

  // Loop on the cell
  for (
    long iCell = nbCell;
    iCell--;) {

    // Get the cell
    GrACellFloat* cell =
      GradAutomatonCell(
        that,
        iCell);

    // Apply the step function to the cell
    GrAFunApply(
      GradAutomatonFun(that),
      GradAutomatonGrad(that),
      cell);

  }

  // Switch all the cells
  GradAutomatonSwitchAllStatus(that);

}

// JSON encoding of GradAutomatonNeuraNet 'that'
JSONNode* _GradAutomatonNeuraNetEncodeAsJSON(
  const GradAutomatonNeuraNet* const that) {

#if BUILDMODE == 0

  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  // Create the JSON structure
  JSONNode* json = JSONCreate();

  // Declare a buffer to convert value into string
  char val[100];

  // Encode the type of the Grad
  GradType typeGrad = GradGetType(GradAutomatonGrad(that));
  sprintf(
    val,
    "%d",
    typeGrad);
  JSONAddProp(
    json,
    "typeGrad",
    val);

  // Encode the dimensions of the Grad
  const VecShort2D* dimGrad = GradDim(GradAutomatonGrad(that));
  JSONNode* dimGradJSON = VecEncodeAsJSON((VecShort*)dimGrad);
  JSONAddProp(
    json,
    "dimGrad",
    dimGradJSON);

  // Return the created JSON
  return json;

}

// Function which decode from JSON encoding 'json' to 'that'
bool _GradAutomatonNeuraNetDecodeAsJSON(
  GradAutomatonNeuraNet** that,
    const JSONNode* const json) {

#if BUILDMODE == 0

  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

  if (json == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'json' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  // If 'that' is already allocated
  if (*that != NULL) {

    // Free memory
    GradAutomatonNeuraNetFree(that);

  }

  // Decode the rule

  // Create the GradAutomatonNeuraNet
  //*that =
  //  GradAutomatonCreateNeuraNet(
  //    rule,
  //    size);
  (void)json;

  // Return the success code
  return true;

}

// Save the GradAutomatonNeuraNet 'that' to the stream 'stream'
// If 'compact' equals true it saves in compact form, else it saves in
// readable form
// Return true if the GradAutomatonNeuraNet could be saved,
// false else
bool _GradAutomatonNeuraNetSave(
  const GradAutomatonNeuraNet* const that,
                         FILE* const stream,
                          const bool compact) {

#if BUILDMODE == 0

  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

  if (stream == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'stream' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  // Get the JSON encoding
  JSONNode* json = GradAutomatonEncodeAsJSON(that);

  // Save the JSON
  bool ret =
    JSONSave(
      json,
      stream,
      compact);

  // Free memory
  JSONFree(&json);

  // Return success code
  return ret;

}

// Load the GradAutomatonWolfraOriginal 'that' from the stream 'stream'
// If 'that' is not null the memory is first freed
// Return true if the GradAutomatonNeuraNet could be loaded,
// false else
bool _GradAutomatonNeuraNetLoad(
  GradAutomatonNeuraNet** that,
              FILE* const stream) {

#if BUILDMODE == 0

  if (that == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'that' is null");
    PBErrCatch(GradAutomatonErr);

  }

  if (stream == NULL) {

    GradAutomatonErr->_type = PBErrTypeNullPointer;
    sprintf(
      GradAutomatonErr->_msg,
      "'stream' is null");
    PBErrCatch(GradAutomatonErr);

  }

#endif

  // Declare a json to load the encoded data
  JSONNode* json = JSONCreate();

  // Load the whole encoded data
  bool ret =
    JSONLoad(
      json,
      stream);

  if (ret == true) {

    // Decode the data from the JSON
    ret =
      GradAutomatonDecodeAsJSON(
        that,
        json);

  }

  // Free the memory used by the JSON
  JSONFree(&json);

  // Return the success code
  return ret;

}

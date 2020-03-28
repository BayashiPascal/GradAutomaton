#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include "pberr.h"
#include "gradautomaton.h"

#define RANDOMSEED 0

void UnitTestGrACellCreateFree(void) {

  int dim = 2;
  GradCell gradCell;
  GrACellShort* cellShort =
    GrACellCreateShort(
      dim,
      &gradCell);
  if (
    cellShort == NULL ||
    VecGetDim(cellShort->status[0]) != dim ||
    VecGetDim(cellShort->status[1]) != dim ||
    cellShort->gradAutomatonCell.curStatus != 0 ||
    cellShort->gradAutomatonCell.gradCell != &gradCell) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GrACellCreateShort failed");
    PBErrCatch(GradAutomatonErr);

  }

  GrACellFree(&cellShort);
  if (cellShort != NULL) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GrACellShortFree failed");
    PBErrCatch(GradAutomatonErr);

  }

  GrACellFloat* cellFloat =
    GrACellCreateFloat(
      dim,
      &gradCell);
  if (
    cellFloat == NULL ||
    VecGetDim(cellFloat->status[0]) != dim ||
    VecGetDim(cellFloat->status[1]) != dim ||
    cellFloat->gradAutomatonCell.curStatus != 0 ||
    cellFloat->gradAutomatonCell.gradCell != &gradCell) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GrACellCreateFloat failed");
    PBErrCatch(GradAutomatonErr);

  }

  GrACellFree(&cellFloat);
  if (cellFloat != NULL) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GrACellFloatFree failed");
    PBErrCatch(GradAutomatonErr);

  }

  printf("UnitTestGrACellCreateFree OK\n");

}

void UnitTestGrACellSwitchStatus(void) {

  int dim = 2;
  GrACellShort* cellShort =
    GrACellCreateShort(
      dim,
      NULL);
  GrACellSwitchStatus(cellShort);
  if (cellShort->gradAutomatonCell.curStatus != 1) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GrACellShortSwitchStatus failed");
    PBErrCatch(GradAutomatonErr);

  }

  GrACellSwitchStatus(cellShort);
  if (cellShort->gradAutomatonCell.curStatus != 0) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GrACellShortSwitchStatus failed");
    PBErrCatch(GradAutomatonErr);

  }

  GrACellFree(&cellShort);

  GrACellFloat* cellFloat =
    GrACellCreateFloat(
      dim,
      NULL);
  GrACellSwitchStatus(cellFloat);
  if (cellFloat->gradAutomatonCell.curStatus != 1) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GrACellFloatSwitchStatus failed");
    PBErrCatch(GradAutomatonErr);

  }

  GrACellSwitchStatus(cellFloat);
  if (cellFloat->gradAutomatonCell.curStatus != 0) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GrACellFloatSwitchStatus failed");
    PBErrCatch(GradAutomatonErr);

  }

  GrACellFree(&cellFloat);

  printf("UnitTestGrACellSwitchStatus OK\n");

}

void UnitTestGrACellCurPrevStatus(void) {

  int dim = 2;
  GrACellShort* cellShort =
    GrACellCreateShort(
      dim,
      NULL);
  if (cellShort->status[0] != GrACellCurStatus(cellShort)) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GrACellShortCurStatus failed");
    PBErrCatch(GradAutomatonErr);

  }

  if (cellShort->status[1] != GrACellPrevStatus(cellShort)) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GrACellShortCurStatus failed");
    PBErrCatch(GradAutomatonErr);

  }

  GrACellFree(&cellShort);

  GrACellFloat* cellFloat =
    GrACellCreateFloat(
      dim,
      NULL);
  if (cellFloat->status[0] != GrACellCurStatus(cellFloat)) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GrACellFloatCurStatus failed");
    PBErrCatch(GradAutomatonErr);

  }

  if (cellFloat->status[1] != GrACellPrevStatus(cellFloat)) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GrACellFloatCurStatus failed");
    PBErrCatch(GradAutomatonErr);

  }

  GrACellFree(&cellFloat);

  printf("UnitTestGrACellCurPrevStatus OK\n");

}

void UnitTestGrACellGetSet(void) {

  int dim = 1;
  GradCell gradCell;
  GrACellShort* cellShort =
    GrACellCreateShort(
      dim,
      &gradCell);
  GrACellSetCurStatus(
    cellShort,
    0,
    1);
  short curStatusS =
    VecGet(
      GrACellCurStatus(cellShort),
      0);
  if (curStatusS != 1) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GrACellShortSetCurStatus failed");
    PBErrCatch(GradAutomatonErr);

  }

  curStatusS =
    GrACellGetCurStatus(
      cellShort,
      0);
  if (curStatusS != 1) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GrACellShortGetCurStatus failed");
    PBErrCatch(GradAutomatonErr);

  }

  GrACellSetPrevStatus(
    cellShort,
    0,
    1);
  short prevStatusS =
    VecGet(
      GrACellPrevStatus(cellShort),
      0);
  if (prevStatusS != 1) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GrACellShortSetPrevStatus failed");
    PBErrCatch(GradAutomatonErr);

  }

  prevStatusS =
    GrACellGetPrevStatus(
      cellShort,
      0);
  if (prevStatusS != 1) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GrACellShortGetPrevStatus failed");
    PBErrCatch(GradAutomatonErr);

  }

  if (GrACellGradCell(cellShort) != &gradCell) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GrACellShortGradCell failed");
    PBErrCatch(GradAutomatonErr);

  }

  GrACellFree(&cellShort);

  GrACellFloat* cellFloat =
    GrACellCreateFloat(
      dim,
      &gradCell);
  GrACellSetCurStatus(
    cellFloat,
    0,
    1);
  float curStatusF =
    VecGet(
      GrACellCurStatus(cellFloat),
      0);
  if (curStatusF != 1) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GrACellFloatSetCurStatus failed");
    PBErrCatch(GradAutomatonErr);

  }

  curStatusF =
    GrACellGetCurStatus(
      cellFloat,
      0);
  if (curStatusF != 1) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GrACellFloatGetCurStatus failed");
    PBErrCatch(GradAutomatonErr);

  }

  GrACellSetPrevStatus(
    cellFloat,
    0,
    1);
  float prevStatusF =
    VecGet(
      GrACellPrevStatus(cellFloat),
      0);
  if (prevStatusF != 1) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GrACellFloatSetPrevStatus failed");
    PBErrCatch(GradAutomatonErr);

  }

  prevStatusF =
    GrACellGetPrevStatus(
      cellFloat,
      0);
  if (prevStatusF != 1) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GrACellFloatGetPrevStatus failed");
    PBErrCatch(GradAutomatonErr);

  }

  if (GrACellGradCell(cellFloat) != &gradCell) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GrACellFloatGradCell failed");
    PBErrCatch(GradAutomatonErr);

  }

  GrACellFree(&cellFloat);

  printf("UnitTestGrACellCurGetSet OK\n");

}

void UnitTestGrACell(void) {

  UnitTestGrACellCreateFree();
  UnitTestGrACellSwitchStatus();
  UnitTestGrACellCurPrevStatus();
  UnitTestGrACellGetSet();
  printf("UnitTestGrACell OK\n");

}

void UnitTestGrAFunDummyCreateFree(void) {

  GrAFunDummy* fun = GrAFunCreateDummy();
  if (
    fun == NULL ||
    fun->grAFun.type != GrAFunTypeDummy) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GrAFunCreateDummy failed");
    PBErrCatch(GradAutomatonErr);

  }

  GrAFunFree(&fun);
  if (fun != NULL) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GrAFunFree failed");
    PBErrCatch(GradAutomatonErr);

  }

  printf("UnitTestGrAFunDummyCreateFree OK\n");

}

void UnitTestGrAFunDummyGetType(void) {

  GrAFunDummy* fun = GrAFunCreateDummy();
  if (GrAFunGetType(fun) != GrAFunTypeDummy) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GrAFunDummyGetType failed");
    PBErrCatch(GradAutomatonErr);

  }

  GrAFunFree(&fun);

  printf("UnitTestGrAFunDummyGetType OK\n");

}

void UnitTestGrAFunDummy(void) {

  UnitTestGrAFunDummyCreateFree();
  UnitTestGrAFunDummyGetType();
  printf("UnitTestGrAFunDummy OK\n");

}

void UnitTestGrAFunWolframOriginalCreateFree(void) {

  unsigned char rule = 42;
  GrAFunWolframOriginal* fun = GrAFunCreateWolframOriginal(rule);
  if (
    fun == NULL ||
    fun->grAFun.type != GrAFunTypeWolframOriginal ||
    fun->rule != rule) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GrAFunCreateWolframOriginal failed");
    PBErrCatch(GradAutomatonErr);

  }

  GrAFunFree(&fun);
  if (fun != NULL) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GrAFunFree failed");
    PBErrCatch(GradAutomatonErr);

  }

  printf("UnitTestGrAFunWolframOriginalCreateFree OK\n");

}

void UnitTestGrAFunWolframOriginalGetType(void) {

  unsigned char rule = 42;
  GrAFunWolframOriginal* fun = GrAFunCreateWolframOriginal(rule);
  if (GrAFunGetType(fun) != GrAFunTypeWolframOriginal) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GrAFunWolframOriginalGetType failed");
    PBErrCatch(GradAutomatonErr);

  }

  GrAFunFree(&fun);

  printf("UnitTestGrAFunWolframOriginalGetType OK\n");

}

void UnitTestGrAFunWolframOriginalGetRule(void) {

  unsigned char rule = 42;
  GrAFunWolframOriginal* fun = GrAFunCreateWolframOriginal(rule);
  if (GrAFunWolframOriginalGetRule(fun) != rule) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GrAFunWolframOriginalGetRule failed");
    PBErrCatch(GradAutomatonErr);

  }

  GrAFunFree(&fun);

  printf("UnitTestGrAFunWolframOriginalGetRule OK\n");

}

void UnitTestGrAFunWolframOriginal(void) {

  UnitTestGrAFunWolframOriginalCreateFree();
  UnitTestGrAFunWolframOriginalGetType();
  UnitTestGrAFunWolframOriginalGetRule();
  printf("UnitTestGrAFunWolframOriginal OK\n");

}

void UnitTestGrAFunNeuraNetCreateFree(void) {

  int nbIn = 1;
  int nbOut = 1;
  VecLong* hiddenLayers = VecLongCreate(1);
  VecSet(
    hiddenLayers,
    0,
    1);
  GrAFunNeuraNet* fun =
    GrAFunCreateNeuraNet(
      nbIn,
      nbOut,
      hiddenLayers);
  if (
    fun == NULL ||
    fun->grAFun.type != GrAFunTypeNeuraNet ||
    NNGetNbInput(fun->nn) != nbIn ||
    NNGetNbOutput(fun->nn) != nbOut) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GrAFunCreateNeuraNet failed");
    PBErrCatch(GradAutomatonErr);

  }

  GrAFunFree(&fun);
  if (fun != NULL) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GrAFunFree failed");
    PBErrCatch(GradAutomatonErr);

  }

  VecFree(&hiddenLayers);

  printf("UnitTestGrAFunNeuraNetCreateFree OK\n");

}

void UnitTestGrAFunNeuraNetGetType(void) {

  int nbIn = 1;
  int nbOut = 1;
  VecLong* hiddenLayers = VecLongCreate(1);
  VecSet(
    hiddenLayers,
    0,
    1);
  GrAFunNeuraNet* fun =
    GrAFunCreateNeuraNet(
      nbIn,
      nbOut,
      hiddenLayers);
  if (GrAFunGetType(fun) != GrAFunTypeNeuraNet) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GrAFunNeuraNetGetType failed");
    PBErrCatch(GradAutomatonErr);

  }

  GrAFunFree(&fun);
  VecFree(&hiddenLayers);

  printf("UnitTestGrAFunNeuraNetGetType OK\n");

}

void UnitTestGrAFunNeuraNetNN(void) {

  int nbIn = 1;
  int nbOut = 1;
  VecLong* hiddenLayers = VecLongCreate(1);
  VecSet(
    hiddenLayers,
    0,
    1);
  GrAFunNeuraNet* fun =
    GrAFunCreateNeuraNet(
      nbIn,
      nbOut,
      hiddenLayers);
  if (GrAFunNeuraNetNN(fun) != fun->nn) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GrAFunNeuraNetNN failed");
    PBErrCatch(GradAutomatonErr);

  }

  GrAFunFree(&fun);
  VecFree(&hiddenLayers);

  printf("UnitTestGrAFunNeuraNetNN OK\n");

}

void UnitTestGrAFunNeuraNet(void) {

  UnitTestGrAFunNeuraNetCreateFree();
  UnitTestGrAFunNeuraNetGetType();
  UnitTestGrAFunNeuraNetNN();
  printf("UnitTestGrAFunNeuraNet OK\n");

}

void UnitTestGrAFun(void) {

  UnitTestGrAFunDummy();
  UnitTestGrAFunWolframOriginal();
  UnitTestGrAFunNeuraNet();
  printf("UnitTestGrAFun OK\n");

}

void UnitTestGradAutomatonDummyCreateFree(void) {

  GradAutomatonDummy* ga = GradAutomatonCreateDummy();
  if (
    ga == NULL ||
    ga->gradAutomaton.grad == NULL ||
    ga->gradAutomaton.fun == NULL ||
    ga->gradAutomaton.type != GradAutomatonTypeDummy) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GradAutomatonCreateDummy failed");
    PBErrCatch(GradAutomatonErr);

  }

  GradAutomatonDummyFree(&ga);
  if (ga != NULL) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GradAutomatonDummyFree failed");
    PBErrCatch(GradAutomatonErr);

  }

  printf("UnitTestGradAutomatonDummyCreateFree OK\n");

}

void UnitTestGradAutomatonDummyGet(void) {

  GradAutomatonDummy* ga = GradAutomatonCreateDummy();
  if (GradAutomatonGrad(ga) != (GradSquare*)(ga->gradAutomaton.grad)) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GradAutomatonDummyGrad failed");
    PBErrCatch(GradAutomatonErr);

  }

  if (GradAutomatonFun(ga) != (GrAFunDummy*)(ga->gradAutomaton.fun)) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GradAutomatonDummyFun failed");
    PBErrCatch(GradAutomatonErr);

  }

  for (
    long i = 0;
    i < 4;
    ++i) {

    void* cellA =
      GradAutomatonCell(
        ga,
        i);
    void* cellB =
      GradCellAt(
        ga->gradAutomaton.grad,
        i);
    if (cellA != GradCellData(cellB)) {

      GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
      sprintf(
        GradAutomatonErr->_msg,
        "GradAutomatonDummyCellIndex failed");
      PBErrCatch(GradAutomatonErr);

    }

  }

  VecShort2D dim = VecShortCreateStatic2D(2);
  VecSet(
    &dim,
    0,
    2);
  VecSet(
    &dim,
    1,
    2);
  VecShort2D pos = VecShortCreateStatic2D(2);
  bool flag = true;
  do {

    void* cellA =
      GradAutomatonCell(
        ga,
        &pos);
    void* cellB =
      GradCellAt(
        ga->gradAutomaton.grad,
        &pos);
    if (cellA != GradCellData(cellB)) {

      GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
      sprintf(
        GradAutomatonErr->_msg,
        "GradAutomatonDummyCellPos failed");
      PBErrCatch(GradAutomatonErr);

    }

    flag =
      VecStep(
        &pos,
        &dim);

  } while(flag);

  GradAutomatonDummyFree(&ga);

  printf("UnitTestGradAutomatonDummyGet OK\n");

}

void UnitTestGradAutomatonDummyStep(void) {

  GradAutomatonDummy* ga = GradAutomatonCreateDummy();

  GradAutomatonStep(ga);

  GradAutomatonDummyFree(&ga);

  printf("UnitTestGradAutomatonDummyStep OK\n");

}

void UnitTestGradAutomatonDummy(void) {

  UnitTestGradAutomatonDummyCreateFree();
  UnitTestGradAutomatonDummyGet();
  UnitTestGradAutomatonDummyStep();
  printf("UnitTestGradAutomatonDummy OK\n");

}

void UnitTestGradAutomatonWolframOriginalCreateFree(void) {

  unsigned char rule = 42;
  long size = 20;
  GradAutomatonWolframOriginal* ga =
    GradAutomatonCreateWolframOriginal(
      rule,
      size);
  if (
    ga == NULL ||
    ga->gradAutomaton.grad == NULL ||
    ga->gradAutomaton.fun == NULL ||
    ga->gradAutomaton.type != GradAutomatonTypeWolframOriginal ||
    ((GrAFunWolframOriginal*)(ga->gradAutomaton.fun))->rule != rule ||
    ga->gradAutomaton.grad->_dim._val[0] != size ||
    ga->gradAutomaton.grad->_dim._val[1] != 1) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GradAutomatonCreateWolframOriginal failed");
    PBErrCatch(GradAutomatonErr);

  }

  GradAutomatonWolframOriginalFree(&ga);
  if (ga != NULL) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GradAutomatonWolframOriginalFree failed");
    PBErrCatch(GradAutomatonErr);

  }

  printf("UnitTestGradAutomatonWolframOriginalCreateFree OK\n");

}

void UnitTestGradAutomatonWolframOriginalGet(void) {

  unsigned char rule = 42;
  long size = 20;
  GradAutomatonWolframOriginal* ga =
    GradAutomatonCreateWolframOriginal(
      rule,
      size);
  if (GradAutomatonGrad(ga) != (GradSquare*)(ga->gradAutomaton.grad)) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GradAutomatonWolframOriginalGrad failed");
    PBErrCatch(GradAutomatonErr);

  }

  if ((void*)GradAutomatonFun(ga) != ga->gradAutomaton.fun) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GradAutomatonWolframOriginalFun failed");
    PBErrCatch(GradAutomatonErr);

  }

  for (
    long i = 0;
    i < 4;
    ++i) {

    void* cellA =
      GradAutomatonCell(
        ga,
        i);
    void* cellB =
      GradCellAt(
        ga->gradAutomaton.grad,
        i);
    if (cellA != GradCellData(cellB)) {

      GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
      sprintf(
        GradAutomatonErr->_msg,
        "GradAutomatonWolframOriginalCellIndex failed");
      PBErrCatch(GradAutomatonErr);

    }

  }

  VecShort2D dim = VecShortCreateStatic2D(2);
  VecSet(
    &dim,
    0,
    size);
  VecSet(
    &dim,
    1,
    1);
  VecShort2D pos = VecShortCreateStatic2D(2);
  bool flag = true;
  do {

    void* cellA =
      GradAutomatonCell(
        ga,
        &pos);
    void* cellB =
      GradCellAt(
        ga->gradAutomaton.grad,
        &pos);
    if (cellA != GradCellData(cellB)) {

      GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
      sprintf(
        GradAutomatonErr->_msg,
        "GradAutomatonWolframOriginalCellPos failed");
      PBErrCatch(GradAutomatonErr);

    }

    flag =
      VecStep(
        &pos,
        &dim);

  } while(flag);

  GradAutomatonWolframOriginalFree(&ga);

  printf("UnitTestGradAutomatonWolframOriginalGet OK\n");

}

void UnitTestGradAutomatonWolframOriginalStepPrintln(void) {

  unsigned char rule = 30;
  long size = 100;
  GradAutomatonWolframOriginal* ga =
    GradAutomatonCreateWolframOriginal(
      rule,
      size);

  GradAutomatonPrintln(
    ga,
    stdout);

  for (
    long iStep = 0;
    iStep < size;
    ++iStep) {

    GradAutomatonStep(ga);

    GradAutomatonPrintln(
      ga,
      stdout);

  }

  GradAutomatonWolframOriginalFree(&ga);

  printf("UnitTestGradAutomatonWolframOriginalStepPrintln OK\n");

}

void UnitTestGradAutomatonWolframOriginalLoadSave(void) {

  unsigned char rule = 30;
  long size = 100;
  GradAutomatonWolframOriginal* ga =
    GradAutomatonCreateWolframOriginal(
      rule,
      size);

  FILE* fp =
    fopen(
      "./unitTestGradAutomatonWolframOriginalSave.json",
      "w");
  bool compact = false;
  bool ret =
    GradAutomatonSave(
      ga,
      fp,
      compact);
  if (ret == false) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GradAutomatonWolframOriginalSave failed");
    PBErrCatch(GradAutomatonErr);

  }

  GradAutomatonWolframOriginalFree(&ga);
  fclose(fp);
  fp =
    fopen(
      "./unitTestGradAutomatonWolframOriginalSave.json",
      "r");

  ret =
    GradAutomatonLoad(
      &ga,
      fp);

  if (
    ret == false ||
    GrAFunWolframOriginalGetRule(GradAutomatonFun(ga)) != rule) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GradAutomatonWolframOriginalLoad failed");
    PBErrCatch(GradAutomatonErr);

  }

  const VecShort2D* dim = GradDim(GradAutomatonGrad(ga));
  long sizeLoaded =
    VecGet(
      dim,
      0);
  if (sizeLoaded != size) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GradAutomatonWolframOriginalLoad failed");
    PBErrCatch(GradAutomatonErr);

  }

  GradAutomatonWolframOriginalFree(&ga);
  fclose(fp);

  printf("UnitTestGradAutomatonWolframOriginalLoadSave OK\n");

}

void UnitTestGradAutomatonWolframOriginal(void) {

  UnitTestGradAutomatonWolframOriginalCreateFree();
  UnitTestGradAutomatonWolframOriginalGet();
  UnitTestGradAutomatonWolframOriginalStepPrintln();
  UnitTestGradAutomatonWolframOriginalLoadSave();
  printf("UnitTestGradAutomatonWolframOriginal OK\n");

}

void UnitTestGradAutomatonNeuraNetCreateFree(void) {

  long dimStatus = 3;
  VecShort2D dimGrad = VecShortCreateStatic2D();
  VecSet(
    &dimGrad,
    0,
    2);
  VecSet(
    &dimGrad,
    1,
    2);
  bool diagLink = true;
  long nbHiddenLayers = 1;
  GradAutomatonNeuraNet* ga =
    GradAutomatonCreateNeuraNetSquare(
      dimStatus,
      &dimGrad,
      diagLink,
      nbHiddenLayers);
  if (
    ga == NULL ||
    ga->gradAutomaton.grad == NULL ||
    ga->gradAutomaton.fun == NULL ||
    ga->gradAutomaton.type != GradAutomatonTypeNeuraNet ||
    ga->gradAutomaton.grad->_type != GradTypeSquare ||
    ga->gradAutomaton.grad->_dim._val[0] != 2 ||
    ga->gradAutomaton.grad->_dim._val[1] != 2) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GradAutomatonCreateNeuraNetSquare failed");
    PBErrCatch(GradAutomatonErr);

  }

  GradAutomatonNeuraNetFree(&ga);
  if (ga != NULL) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GradAutomatonNeuraNetFree failed");
    PBErrCatch(GradAutomatonErr);

  }

  printf("UnitTestGradAutomatonNeuraNetCreateFree OK\n");

}

void UnitTestGradAutomatonNeuraNetGet(void) {

  long dimStatus = 3;
  VecShort2D dimGrad = VecShortCreateStatic2D();
  VecSet(
    &dimGrad,
    0,
    2);
  VecSet(
    &dimGrad,
    1,
    2);
  bool diagLink = true;
  long nbHiddenLayers = 1;
  GradAutomatonNeuraNet* ga =
    GradAutomatonCreateNeuraNetSquare(
      dimStatus,
      &dimGrad,
      diagLink,
      nbHiddenLayers);
  if (GradAutomatonGrad(ga) != ga->gradAutomaton.grad) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GradAutomatonNeuraNetGrad failed");
    PBErrCatch(GradAutomatonErr);

  }

  if (GradAutomatonNeuraNetGetGradType(ga) != GradTypeSquare) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GradAutomatonNeuraNetGradType failed");
    PBErrCatch(GradAutomatonErr);

  }

  if ((void*)GradAutomatonFun(ga) != ga->gradAutomaton.fun) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GradAutomatonNeuraNetFun failed");
    PBErrCatch(GradAutomatonErr);

  }

  for (
    long i = 0;
    i < 4;
    ++i) {

    void* cellA =
      GradAutomatonCell(
        ga,
        i);
    void* cellB =
      GradCellAt(
        ga->gradAutomaton.grad,
        i);
    if (cellA != GradCellData(cellB)) {

      GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
      sprintf(
        GradAutomatonErr->_msg,
        "GradAutomatonNeuraNetCellIndex failed");
      PBErrCatch(GradAutomatonErr);

    }

  }

  VecShort2D pos = VecShortCreateStatic2D(2);
  bool flag = true;
  do {

    void* cellA =
      GradAutomatonCell(
        ga,
        &pos);
    void* cellB =
      GradCellAt(
        ga->gradAutomaton.grad,
        &pos);
    if (cellA != GradCellData(cellB)) {

      GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
      sprintf(
        GradAutomatonErr->_msg,
        "GradAutomatonNeuraNetCellPos failed");
      PBErrCatch(GradAutomatonErr);

    }

    flag =
      VecStep(
        &pos,
        &dimGrad);

  } while(flag);

  GradAutomatonNeuraNetFree(&ga);

  printf("UnitTestGradAutomatonNeuraNetGet OK\n");

}

void UnitTestGradAutomatonNeuraNetStep(void) {

  long dimStatus = 3;
  VecShort2D dimGrad = VecShortCreateStatic2D();
  VecSet(
    &dimGrad,
    0,
    2);
  VecSet(
    &dimGrad,
    1,
    2);
  bool diagLink = true;
  long nbHiddenLayers = 1;
  GradAutomatonNeuraNet* ga =
    GradAutomatonCreateNeuraNetSquare(
      dimStatus,
      &dimGrad,
      diagLink,
      nbHiddenLayers);

  for (
    long iStep = 0;
    iStep < 2;
    ++iStep) {

    GradAutomatonStep(ga);

  }

  GradAutomatonNeuraNetFree(&ga);

  printf("UnitTestGradAutomatonNeuraNetStep OK\n");

}

void UnitTestGradAutomatonNeuraNet(void) {

  UnitTestGradAutomatonNeuraNetCreateFree();
  UnitTestGradAutomatonNeuraNetGet();
  UnitTestGradAutomatonNeuraNetStep();
  printf("UnitTestGradAutomatonNeuraNet OK\n");

}

void UnitTestGradAutomaton(void) {

  UnitTestGradAutomatonDummy();
  UnitTestGradAutomatonWolframOriginal();
  UnitTestGradAutomatonNeuraNet();
  printf("UnitTestGradAutomaton OK\n");

}

void UnitTestAll(void) {

  UnitTestGrACell();
  UnitTestGrAFun();
  UnitTestGradAutomaton();
  printf("UnitTestAll OK\n");

}

int main(void) {

  UnitTestAll();

  // Return success code
  return 0;

}

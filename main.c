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
  if (GrAFunWolFramOriginalGetRule(fun) != rule) {

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

void UnitTestGrAFun(void) {

  UnitTestGrAFunDummy();
  UnitTestGrAFunWolframOriginal();
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
      "GradAutomatonDummyGetGrad failed");
    PBErrCatch(GradAutomatonErr);

  }

  if (GradAutomatonFun(ga) != (GrAFunDummy*)(ga->gradAutomaton.fun)) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GradAutomatonDummyGetFun failed");
    PBErrCatch(GradAutomatonErr);

  }

  for (
    int i = 0;
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
  unsigned long size = 20;
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
    ga->gradAutomaton.grad->_dim._val[0] != (long)size ||
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
  unsigned long size = 20;
  GradAutomatonWolframOriginal* ga =
    GradAutomatonCreateWolframOriginal(
      rule,
      size);
  if (GradAutomatonGrad(ga) != (GradSquare*)(ga->gradAutomaton.grad)) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GradAutomatonWolframOriginalGetGrad failed");
    PBErrCatch(GradAutomatonErr);

  }

  if ((void*)GradAutomatonFun(ga) != ga->gradAutomaton.fun) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GradAutomatonWolframOriginalGetFun failed");
    PBErrCatch(GradAutomatonErr);

  }

  for (
    int i = 0;
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
  unsigned long size = 100;
  GradAutomatonWolframOriginal* ga =
    GradAutomatonCreateWolframOriginal(
      rule,
      size);

  GradAutomatonPrintln(
    ga,
    stdout);

  for (
    unsigned long iStep = 0;
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

void UnitTestGradAutomatonWolframOriginal(void) {

  UnitTestGradAutomatonWolframOriginalCreateFree();
  UnitTestGradAutomatonWolframOriginalGet();
  UnitTestGradAutomatonWolframOriginalStepPrintln();
  printf("UnitTestGradAutomatonWolframOriginal OK\n");

}

void UnitTestAll(void) {

  UnitTestGrACell();
  UnitTestGrAFun();
  UnitTestGradAutomatonDummy();
  UnitTestGradAutomatonWolframOriginal();
  printf("UnitTestAll OK\n");

}

int main(void) {

  UnitTestAll();

  // Return success code
  return 0;

}

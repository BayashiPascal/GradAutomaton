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
  GrACellShort* cellShort = GrACellCreateShort(dim);
  if (
    cellShort == NULL ||
    VecGetDim(cellShort->status[0]) != dim ||
    VecGetDim(cellShort->status[1]) != dim ||
    cellShort->curStatus != 0) {

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

  GrACellFloat* cellFloat = GrACellCreateFloat(dim);
  if (
    cellFloat == NULL ||
    VecGetDim(cellFloat->status[0]) != dim ||
    VecGetDim(cellFloat->status[1]) != dim ||
    cellFloat->curStatus != 0) {

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
  GrACellShort* cellShort = GrACellCreateShort(dim);
  GrACellSwitchStatus(cellShort);
  if (cellShort->curStatus != 1) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GrACellShortSwitchStatus failed");
    PBErrCatch(GradAutomatonErr);

  }

  GrACellSwitchStatus(cellShort);
  if (cellShort->curStatus != 0) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GrACellShortSwitchStatus failed");
    PBErrCatch(GradAutomatonErr);

  }

  GrACellFree(&cellShort);

  GrACellFloat* cellFloat = GrACellCreateFloat(dim);
  GrACellSwitchStatus(cellFloat);
  if (cellFloat->curStatus != 1) {

    GradAutomatonErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradAutomatonErr->_msg,
      "GrACellFloatSwitchStatus failed");
    PBErrCatch(GradAutomatonErr);

  }

  GrACellSwitchStatus(cellFloat);
  if (cellFloat->curStatus != 0) {

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
  GrACellShort* cellShort = GrACellCreateShort(dim);
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

  GrACellFloat* cellFloat = GrACellCreateFloat(dim);
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
  GrACellShort* cellShort = GrACellCreateShort(dim);
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

  GrACellFree(&cellShort);

  GrACellFloat* cellFloat = GrACellCreateFloat(dim);
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

void UnitTestGrAFun(void) {

  UnitTestGrAFunDummyCreateFree();
  UnitTestGrAFunDummyGetType();
  printf("UnitTestGrACell OK\n");

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
  printf("UnitTestGrACell OK\n");

}

void UnitTestAll(void) {

  UnitTestGrACell();
  UnitTestGrAFun();
  UnitTestGradAutomatonDummy();
  printf("UnitTestAll OK\n");

}

int main(void) {

  UnitTestAll();

  // Return success code
  return 0;

}

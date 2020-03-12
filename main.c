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
    VecGetDim(cellShort->_status[0]) != dim ||
    VecGetDim(cellShort->_status[1]) != dim ||
    cellShort->_iStatus != 0) {

    GradErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradErr->_msg,
      "GrACellCreateShort failed");
    PBErrCatch(GradErr);

  }

  GrACellFree(&cellShort);
  if (cellShort != NULL) {

    GradErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradErr->_msg,
      "GrACellShortFree failed");
    PBErrCatch(GradErr);

  }

  GrACellFloat* cellFloat = GrACellCreateFloat(dim);
  if (
    cellFloat == NULL ||
    VecGetDim(cellFloat->_status[0]) != dim ||
    VecGetDim(cellFloat->_status[1]) != dim ||
    cellFloat->_iStatus != 0) {

    GradErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradErr->_msg,
      "GrACellCreateFloat failed");
    PBErrCatch(GradErr);

  }

  GrACellFree(&cellFloat);
  if (cellFloat != NULL) {

    GradErr->_type = PBErrTypeUnitTestFailed;
    sprintf(
      GradErr->_msg,
      "GrACellFloatFree failed");
    PBErrCatch(GradErr);

  }

  printf("UnitTestGrACellCreateFree OK\n");

}

void UnitTestGrACell(void) {

  UnitTestGrACellCreateFree();
  printf("UnitTestGrACell OK\n");

}

void UnitTestAll(void) {

  UnitTestGrACell();
  printf("UnitTestAll OK\n");

}

int main(void) {

  UnitTestAll();

  // Return success code
  return 0;

}

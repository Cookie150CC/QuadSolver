//Global define variables
#define input_length 100
//Imported libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "logPrint.h"
#include "removeSpaces.h"
#include "getSqrt.h"
#include "getInput.h"
#include "getQuadSolutions.h"
#include "checkContinue.h"

int main(void) {
 
  //Variable declaration/ Memory allocation
  char *input = malloc(input_length);
  char **splitInput = malloc(input_length * 3);
  double* abcArray;
  double* solArray;
  int contFlag = 0;
  
  //Brief instructions
  printf("Welcome to Quad Solver!\n\t plug in values for a, b, and c in that order\n\tSeperate the three values by a comma\n");
  logPrint("Program has begun");
  do{
    abcArray  = getInput(input, splitInput);

    solArray = getQuadSolutions(abcArray);

    printf("\nSolution 1: %1f, \nSolution 2: %1f\n",solArray[0], solArray[1]);

    contFlag = checkContinue();
  }while(contFlag==1);

  printf("\nThank You For Using QuadSolver!\n");
  return 0;
}

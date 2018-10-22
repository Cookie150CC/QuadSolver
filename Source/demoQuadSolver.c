//Imported libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

//Global define variables
#define input_length 100

//function declerations
double* getInput (char in[], char *out[]);
double* getSolutions(double *abcArray);
void removeSpaces(char* in);
int checkContinue();

int main(int argc, char const *argv[]) {
  //Variable declaration/ Memory allocation
  char *input = malloc(input_length);
  char **splitInput = malloc(input_length * 3);
  double* abcArray;
  double* solArray;
  int contFlag = 0;
  //Breif instructions
  printf("Welcome to Quad Solver!\n\t plug in values for a, b, and c in that order\n\tSeperate the three values by a comma\n");

  do{
    abcArray  = getInput(input, splitInput);

    solArray = getSolutions(abcArray);

    printf("\nSolution 1: %1f, \nSolution 2: %1f\n",solArray[0], solArray[1]);

    contFlag = checkContinue();
  }while(contFlag==1);

  printf("\nThank You For Using QuadSolver!\n");
  return 0;
}


double* getInput(char in[], char *out[])
{
  int flag = 1;
  char *tok = malloc(input_length);
  int count = 0;
  double* abcArray = malloc(sizeof(double)*3);
  char delimit[] = ",\0";

  do{
    printf("Enter Values >> ");
    fgets(in, input_length, stdin);
    removeSpaces(in);
    //Look for first ","
    tok = strtok(in,delimit);
    //Check if one section was delimited
    if(tok != NULL){
      out[count++] = tok;
      //Check the rest of the string but will not over flow the out array
      while(tok != NULL && count< 3){
        tok = strtok(NULL, delimit);
        out[count++] = tok;
      }
    }else{
      flag = 0;
      printf("Error: not value/delimiter entered\n");
    }
    //Check If three values were entered
    if(out[0] != NULL && out[1] != NULL && out[2] != NULL){
      //seperate
      flag = 1;
      for(int i=0; i<3; i++){
        abcArray[i] = atof(out[i]);
        out[i] = NULL;
      }
    }else{
      flag = 0;
      printf("Error: 3 values not found. Enter 3 values seperated by commas.\n");
    }
    count = 0;
  }while(flag != 1);

 return abcArray;
}

double* getSolutions(double* abcArray)
{
  double * solArray = malloc(sizeof(double)*2);

  solArray[0] = (((-abcArray[1]) + (sqrt((abcArray[1]*abcArray[1])-(4*abcArray[0]*abcArray[2]))))/(2*abcArray[0]));
  solArray[1] = (((-abcArray[1]) - (sqrt((abcArray[1]*abcArray[1])-(4*abcArray[0]*abcArray[2]))))/(2*abcArray[0]));

  return solArray;
}

void removeSpaces(char* in)
{
  int count=0;

  for(int i=0; in[i]; i++){
    if(in[i]!=' '){
      in[count++] = in[i];
    }
  }
  in[count] = '\0';
}

int checkContinue()
{
    int contFlag=0;
    char* input= malloc(input_length);
    char comp = 'n';

    printf("\nWould you like to Continue using QuadSolver?(Y/n):");
    fgets(input, input_length, stdin);
    removeSpaces(input);
    if(input[0] != '\0'){
      comp=input[0];
    }

    if(comp == 'y' || comp == 'Y'){
      contFlag = 1;
    }else{
      contFlag = 0;
    }

    return contFlag;
}

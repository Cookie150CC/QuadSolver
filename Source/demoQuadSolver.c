//Imported libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

//Global define variables
#define input_length 100

//function declerations
char** getInput (char in[], char *out[]);





int main(int argc, char const *argv[]) {
  //Variable declaration/ Memory allocation
  char *input = malloc(input_length);
  char **splitInput = malloc(input_length * 3);
  //Breif instructions
  printf("Welcome to Quad Solver!\n\t plug in values for a, b, and c in that order\n\tSeperate the three values by a comma\n");

  splitInput  = getInput(input, splitInput);


  return 0;
}


char** getInput (char in[], char *out[])
{
  int flag = 1;
  char *tok = malloc(input_length);
  int count = 0;
  double returnValue[3];
  char delimit[] = ",\0";

  do{
    printf("Enter Values >> ");
    scanf("%s", in);

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
    if(out[2] != NULL){
      //seperate
      for(int i=0; i<3; i++){
        returnValue[i] = atof(out[i]);
        printf("%1f\n", returnValue[i]);
      }
    }else{
      flag = 0;
      printf("Error: 3 values not found. Enter 3 values seperated by commas.\n");
    }




  }while(flag != 1);


 return out;
}

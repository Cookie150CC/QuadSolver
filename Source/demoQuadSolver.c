//Imported libraries
#include <stdio.h>

//Global define variables
#define input_length 100

int main(int argc, char const *argv[]) {
  //Variable declaration/ Memory allocation
  char input[input_length];
  //Breif instructions
  printf("Welcome to Quad Solver!\n\t plug in values for a, b, and c in that order\n\tSeperate the three values by a comma or a space\n");
  //prompt
  printf("\nEnter values >> ");
  //get user input
  scanf("%s", input);
  printf("%s", input);


  return 0;
}

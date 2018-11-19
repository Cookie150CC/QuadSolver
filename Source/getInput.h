double* getInput(char in[], char *out[])
{
  int flag = 1;
  char *tok = malloc(input_length);
  char *endptr;
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
		if((abcArray[i] = strtod(out[i], &endptr)) != 0)
		{
        out[i] = NULL;
		}
		else
			printf("Invalid input for conversion.");
      }
    }else{
      flag = 0;
      printf("Error: 3 values not found. Enter 3 values seperated by commas.\n");
    }
    count = 0;
  }while(flag != 1);

 return abcArray;
}


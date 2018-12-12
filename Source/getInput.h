double* getInput(char in[], char *out[])
{
  int flag = 1;
  char *tok = malloc(input_length);
  char *endptr;
  int count = 0;
  double* abcArray = malloc(sizeof(double)*3);
  char delimit[] = ",\0";
  char * inLog = malloc(input_length*3);

  do{
    printf("Enter Values >> ");
    fgets(in, input_length*3, stdin);
    removeSpaces(in);
    strcpy(inLog, in);
    //Look for first ","
    tok = strtok(in,delimit);
    //Check if one section was delimited
    if(tok[0] != '\0'){
      out[count++] = tok;
      //Check the rest of the string but will not over flow the out array
      while(tok != NULL && count< 3){
        tok = strtok(NULL, delimit);
        out[count++] = tok;
      }
    }else{
      flag = 0;
      printf("Error: value/delimiter not entered\n");
      strcat(in,"is invalid input| value/delimeter not entered");
      logPrint(inLog);
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
		else{
			if(out[i][0] != '0'){
				printf("%s: is not a double or a float\n",out[i] );
				strcat(inLog, " is invalid input. 3 double/float values not found.\n");
				logPrint(inLog);
				flag = 0;
			}
		}
      }
    }else{
      flag = 0;
      printf("Error: 3 values not found.\n Enter 3 values seperated by commas.\n");
	strcat(inLog, " is invalid input. 3 double/float values not found.\n");
	logPrint(inLog);

    }
    count = 0;
  }while(flag != 1);

 return abcArray;
}


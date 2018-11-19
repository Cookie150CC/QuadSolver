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


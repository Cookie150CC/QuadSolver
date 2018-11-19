double* getQuadSolutions(double* abcArray)
{
  double * solArray = malloc(sizeof(double)*2);

  solArray[0] = (((-abcArray[1]) + (getSqrt((abcArray[1]*abcArray[1])-(4*abcArray[0]*abcArray[2]))))/(2*abcArray[0]));
  solArray[1] = (((-abcArray[1]) - (getSqrt((abcArray[1]*abcArray[1])-(4*abcArray[0]*abcArray[2]))))/(2*abcArray[0]));

  return solArray;
}


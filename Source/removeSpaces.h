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


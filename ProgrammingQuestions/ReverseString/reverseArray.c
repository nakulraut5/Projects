#include <stdio.h>
#include <cstdlib>
int main() {
  char* mainStr = (char*)calloc(6,sizeof(char));
  if(!mainStr){
      printf("\nERROR:: Failed to allocate memory");
      return 1;
  }
  for(int i=0;i<5;i++){
      mainStr[i]='A'+i;
  }
  mainStr[5]='\0';
  printf("Main Str: %s",mainStr);
  char* revStr = (char*)calloc(6,sizeof(char));
  if(!revStr){
      printf("\nERROR:: Failed to allocate memory");
      return 1;
  }
  int j=0;
  for(int i=4;i>=0;i--){
      revStr[j]=mainStr[i];
      j++;
  }
  revStr[5]='\0';
    printf("\nReverse Str: %s",revStr);
    free(mainStr);
    free(revStr);
    return 0;
}
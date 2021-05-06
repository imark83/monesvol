#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char keyb[3][9]={
  {'Q','W','E','R','T','Y','U','I','L'},
  {'A','S','D','F','G','H','J','K','P'},
  {'Z','X','C','V','B','N','M','O','*'}
};
char abc[]=
  {'A','B','C','D','E','F','G','H','I','J',
   'K','L','M','N','*','O','P','Q','R','S',
   'T','U','V','W','X','Y','Z'};

void getIJ(char c, int *i, int *j) {
  for (*i=0; *i<3; (*i)++) for (*j=0; *j<9; (*j)++) {
    
    if (keyb[*i][*j]==c) return;
  }
  return;
}


int main(int argc, char const *argv[]) {
  int i, j, k;
  int noodle=4;

  char *input="SECRETARIO PARA ELEGIR";
  // LCVDCEKDHA HIVI KPKVOL

  for(k=0;k<strlen(input);++k){
    char c=input[k];

    if(('A'<=c && c <= 'Z') || c=='*') {
      getIJ(c,&i,&j);
      j-=noodle-1;
      printf("%c",abc[(10*i+j)%27]);
    } else {
      noodle++;
      printf(" ");
    }

  }


  return 0;
}
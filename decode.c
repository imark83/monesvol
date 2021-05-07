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
  int k;
  for (k=0; k<27; k++)    
    if (abc[k]==c) break;
  k++;
  *i=k/10;
  *j=k%10-1;
  return;
}


int main(int argc, char const *argv[]) {
  int i, j, k;
  int noodle=1;

  const char *input="CI AY*UA KD MXAP HA RLRCQMX FB UC LQN YA UAWPX";
  //  HIVI KPKVOL


  if(argc>1) input = argv[1];;
  if(argc>2) noodle = atoi(argv[2]);;


  //for(noodle=1;noodle<=9;++noodle) {
    for(k=0;k<strlen(input);++k){
      char c=input[k];

      if(('A'<=c && c <= 'Z') || c=='*') {
        getIJ(c,&i,&j);
        j=(j+((noodle!=0)? noodle : 1)-1)%9;
        i=(i+((noodle!=0)? noodle : 1)-1)%3;
        printf("%c",keyb[i][j]);
      } else {
        noodle = noodle+1;
        if(noodle==10) noodle=0;
        printf(" ");
      }
    }
    printf("\n");
  //}

  return 0;
}
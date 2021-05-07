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
  int noodle=2;

  const char *input="EL LUNES EN HORA DE TUTORIA EN LA QUE "\
      "NO ESTOY PARA EJERCER DE GRAN TUTO ID AL DESPACHO"\
      " DEL SECRETARIO PARA ELEGIR LAS FOTOS PARA LA ORLA"\
      " BASTA QUE VAYAIS SOBRE LAS NUEVE YA SE QUE UN "\
      "LUNES SIN MÍ NO ES LO MISMO";
  // LCVDCEKDHA HIVI KPKVOL


  if(argc>1) noodle = atoi(argv[1]);;


  //for(noodle=1;noodle<=9;++noodle) {
    for(k=0;k<strlen(input);++k){
      char c=input[k];

      if(('A'<=c && c <= 'Z') || c=='*') {
        getIJ(c,&i,&j);
        j=(j+noodle-1)%9;
        i=(i+noodle-1)%3;
        printf("%c",abc[(10*i+j)%27]);
      } else {
        noodle = noodle-1;
        if(!noodle) noodle=9;
        printf(" ");
      }
    }
    printf("\n");
  //}

  return 0;
}
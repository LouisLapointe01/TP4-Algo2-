#include "palindrome.h"
#include "tests.h"
#include "solutions.h"

#include <stdio.h>
#include <assert.h>

int main(int argc, char** argv){

  assert(argc==2);
  int mode = atoi(argv[1]);
  int note=0;
  tableau T;
  char erreur=0;
  for(int i=0; i<M; i++){
    T.taille=sizes[i];
    for(int j=0; j<T.taille; j++){
      T.tab[j]=tests[i][j];
    }
    switch(mode){
    case 0:
      if(palindrome_brute_force(&T) == sols[i]){
	note++;
      }
      else{
	printf("\nErreur sur le tableau test%d.", i);
	erreur =1;
      };
      break;
    case 1:
      if(palindrome_prog_dyn(&T) == sols[i]){
	note++;
      }
      else{
	printf("\nErreur sur le tableau test%d.", i);
	erreur =1;
      };
      break;
    case 2:
      if(palindrome_plateaux(&T) == sols[i]){
	note++;
      }
      else{
	printf("\nErreur sur le tableau test%d.", i);
	erreur =1;
      };
      break;
    default:
      printf("CODE INVALIDE");
      break;
    }
  }
  if(erreur){
    printf("\n");
  }
  fprintf(stderr, "%d", note);
  return 0;
}

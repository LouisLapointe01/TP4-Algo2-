#ifndef PALIN_H
#define PALIN_H

#include <stdlib.h>
#include <time.h>

#define N 1000


typedef struct TABLEAU{
  char tab[N];
  int taille;
} tableau;


int palindrome_brute_force(tableau* T);
int palindrome_prog_dyn(tableau* T);
int palindrome_plateaux(tableau* T);

#endif

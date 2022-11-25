#include <stdio.h>
#include "palindrome.h"

void generation_aleatoire_elements(tableau* T)
{
  /* Generation aleatoire des elements du tableau */
  srand(time(NULL));
  printf("\nT.tab={");
  for(int i = 0; i<T->taille-1; i++){
    T->tab[i]=rand()%10;
    printf("%d, ", T->tab[i]);
  }

  T->tab[T->taille-1]=rand()%10;
  printf("%d}\n", T->tab[T->taille-1]);
}


int palindrome_brute_force(tableau* T)
{

  int pluslongpalindrome = 0;
  int debut=0,fin=1,i,y,ibis,ybis,test; 
  int compteur;


  while(debut<T->taille-1 && fin<T->taille)
  {

    y = 0;
    i = 1;
    ybis = 0;
    ibis = 0;
    test = 0;
    compteur = 0; 
  
    if( T->tab[debut-y] == T->tab[fin+i] ) //palindrome impaire (centre : /debut fin+1)
    {
        while (T->tab[debut-y] == T->tab[fin+i]) 
          {
            compteur+=2;
            test = 1;
            i++;
            y++;
          } 
    }
    else if(T->tab[debut-ybis] == T->tab[fin+ibis]) //Palindrome paire (centre : debut fin /côte a côte)
    {
      while(T->tab[debut-ybis] == T->tab[fin+ibis])
      { 
      compteur+=2;
      test =2;
      ibis++;
      ybis++;
      }
    }
    if(test == 1)
  {
    compteur = compteur + 1;
  }

  if(compteur > pluslongpalindrome)
  {
    pluslongpalindrome = compteur;
  }
  debut++;
  fin++;
  }
  return pluslongpalindrome;
}


int palindrome_prog_dyn(tableau* T)
{

  int D[N][N];
  int pluslongpalindrome = 1; 
  /////PREMIERE PARTIE//////
  for (int i=0; i<T->taille; i++)
  {
  	D[i][i]=1;
  }
  /////SECONDE PARTIE//////
  for (int i=0; i<T->taille-1; i++)
  {
  	if (T->tab[i] == T->tab[i+1])
  	{
  		D[i][i+1]=1;
  		pluslongpalindrome= 2;
  	}
  	else
  		D[i][i+1]=0;
  }
  /////TROISIEME PARTIE//////
    int j = 2;

  	for (int FinDePlateau=3; FinDePlateau<=T->taille;FinDePlateau++)
	  {
  		for (int i=0; i<=T->taille;i++)
		  {
  			j = i-1+FinDePlateau;

  			if (D[i+1][j-1]==1 && T->tab[i]==T->tab[j])
			  {
  				D[i][j]=1;

  				if (FinDePlateau>pluslongpalindrome)
          {
  					pluslongpalindrome=FinDePlateau;
          }
  			}
  			else
        {
  				D[i][j]=0;
        }
  		}
  	}
  return pluslongpalindrome;
}

int palin_impair(tableau *T, int centre)
{

return 0;
}

int palin_pair(tableau *T, int centre_g)
{
	
}

int palindrome_plateaux(tableau* T)
{
}



int __attribute__((weak)) main(){
	/* Declaration du tableau */
	tableau t;
	/* Initialisation du champ taille */
	t.taille = 20;
	generation_aleatoire_elements(&t);

	/* Completer pour tester les fonctions */
	printf("\nPlus long palin methode dynamique: %d\n", palindrome_prog_dyn(&t));
	for (int i=0; i<43;i++){
		printf("%d, ",t.tab[i]);
	}
	printf("\n");
	printf("\n Plus long palindrome premiere methode: %d\n",palindrome_brute_force(&t) );
  printf("\n Plus long palindrome deuxiéme méthode : %d\n",palindrome_prog_dyn(&t));
	printf("\n Plus long palindrome troisieme methode: %d\n",palindrome_plateaux(&t));
  	return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define SIZE 20

int main()
{
    int tab[SIZE] = {0};
    int i = 0, tmp = 0, tri = 0;
    
    srand(time(NULL));

    /* Remplissage du tableau */

    for (i = 0; i < SIZE; i++)
    {
        tab[i] = rand() % 20 + 0;
    }

    printf("Affichage du tableau non triée: \n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ",tab[i]);
    }
    printf("\n");

    /*Tri par Selection échange*/
    int j = 0, indice_min=0;
    for(i=0;i<SIZE;i++)
    {
        for(j=i;j<SIZE;j++){
            indice_min = i ;
            if(tab[i] > tab[j]){
                indice_min = j ;
            }
            
            if(i != indice_min){
                tmp = tab[i];
                tab[i] = tab[indice_min];
                tab[indice_min] = tmp;
            }
        }
    }

    printf("\nAffichage du tableau triée: \n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ",tab[i]);
    }
    printf("\n");

}
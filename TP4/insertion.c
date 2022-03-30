#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20

int main(){

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
    printf("Affichage du tableau non triée: \n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ",tab[i]);
    }
    printf("\n");

    /* Tri par insertion */
    int j = 0, indice_min=0, borne=0, val=0;
    for(i=0; i < SIZE; i++)
    {

        

        val = tab[i];
        for(int j = 0; i-1 < indice_min; j=j-1){
            tab[j+1] = tab[j];
        }
        tab[i] = val;
        
    }
}

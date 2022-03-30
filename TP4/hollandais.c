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
        tab[i] = rand() % 2 + 0;
    }

    printf("Affichage du tableau non triée: \n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ",tab[i]);
    }
    printf("\n");

    while (/* condition */)
    {
        /* code */
    }
    


}
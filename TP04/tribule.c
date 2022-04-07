#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20

int main()
{
    int tab[SIZE] = {0};
    int i = 0, tmp = 0;
    
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

    int tri = 0;
    int borne = SIZE;
    while(tri == 0){
        tri = 1;
        for(i  = 0; i < borne-1; i++)
        {
            if(tab[i] > tab[i+1])
            {
                tmp = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = tmp;
                printf("Echange \n");
                tri = 0;
            }
            else
            {
                printf("Pas d'échange \n");
            }
        }
        borne = borne -1;
    }
    printf("Affichage du tableau triée: \n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ",tab[i]);
    }
    printf("\n");
}
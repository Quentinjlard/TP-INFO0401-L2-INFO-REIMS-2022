/**
 * @file Exercice1.c
 * @author  JUILLIARD Quentin (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-25
 * 
 * @copyright Copyright (c) 2022
 * 
 * 10 valeurs aléatoire entre 5 et 20
 * => Calculer min + max
 *      => moyenne  : reel
 *      => maximun  : entier
 *      => minimun  : entier
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define MAX 20
#define MIN 5


int valeurMax_i(int *tab)
{
    int i = 0;
    int max = 0;
    for(i = 0; i < SIZE; i++)
    {
        if(max < tab[i])
        {
            max = tab[i];
        }
    }

    printf("Voici le max  : %d \n", max);
}

int valeurMin_i(int *tab)
{
    int i = 0;
    int min = 20;
    for(i = 0; i < SIZE; i++)
    {
        if(min > tab[i])
        {
            min = tab[i];
        }
    }

    printf("Voici le min  : %d \n", min);
}

int moyenneTableau_i(int *tab)
{
    int somme = 0;
    int moyenne = 0;
    int i = 0;

    for(i = 0; i < 10 ; i ++)
    {
        somme += tab[i];
    }

    moyenne = somme / 10;

    printf("Voici la moyenne : %d \n", moyenne);
}

double valeurMax_r(double *tab)
{
    int i = 0;
    double max = 0;
    for(i = 0; i < SIZE; i++)
    {
        if(max < tab[i])
        {
            max = tab[i];
        }
    }

    printf("Voici le max  : %f \n", max);
}

double valeurMin_r(double *tab)
{
    int i = 0;
    double min = 20;
    for(i = 0; i < SIZE; i++)
    {
        if(min > tab[i])
        {
            min = tab[i];
        }
    }

    printf("Voici le min  : %f \n", min);
}

double moyenneTableau_r(double *tab)
{
    double somme = 0;
    double moyenne = 0;
    int i = 0;

    for(i = 0; i < 10 ; i ++)
    {
        somme += tab[i];
    }

    moyenne = somme / 10;

    printf("Voici la moyenne : %f \n", moyenne);
}

int rand_i(const int amplitude, const int min){
    
    

    int valeur = 0;

    valeur = rand() % amplitude + min;

    return valeur;
}

double rand_d(const double amplitude, const int min){
    
    return amplitude + (min - amplitude) * rand() / RAND_MAX;
}


int valeurAleatoir()
{
    int tab[SIZE];
    double tab2[SIZE];
    int i = 0;

    for (i = 0; i < SIZE ; i++)
    {
        tab[i] = rand_i(MIN-MAX+1, MIN);
    }

    for (i = 0; i < SIZE ; i++)
    {
        tab2[i] = rand_d(MAX, MIN);
    }

    printf("AFFICHAGE DU TABLEAU  d'entier : ");

    for (i = 0; i < SIZE ; i++)
    {
        printf("%d ", tab[i]);
    }

    printf("\nAFFICHAGE DU TABLEAU  de réeel : ");
    for (i = 0; i < SIZE ; i++)
    {
        printf("%f ", tab2[i]);
    }

    printf("\n");

    valeurMax_i(tab);
    valeurMin_i(tab);
    moyenneTableau_i(tab);
    
    printf("\n");
    
    valeurMax_r(tab2);
    valeurMin_r(tab2);
    moyenneTableau_r(tab2);
}

int main(void)
{
    srand(time(NULL));

    printf("Debut du programme \n");
    valeurAleatoir();
    printf("\nFin du programme \n");
}
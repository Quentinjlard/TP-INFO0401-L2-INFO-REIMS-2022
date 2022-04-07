/**
 * @file Tab1D.c
 * @author JUILLIARD Quentin
 * @brief 
 * @version 0.1
 * @date 2022-01-18
 * 
 * @copyright Copyright (c) 2022
 * 
 * 
 * CONSIGNE :
 *  Tableau 1D 
 *      
 *      - POUR : Remplir / afficher / sommes / nombre de X / max / indice du max
 *      - TQ : Recherche SQ / Recherche dichotomique            
 *          
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
typedef int Tab1D[SIZE];


void remplir(Tab1D t, int nb)
{
    srand(time(NULL));
    for(int i = 0; i < nb; i++)
    {
        t[i] = rand()%(10 - 0) + 10;
    }
}

void afficher(Tab1D t, int nb)
{
    for(int i = 0; i < nb; i++)
    {
        printf("%d ",t[i]);
    }
    printf("\n");
}

void rec(Tab1D t, int nb){
    if(nb > 0){
        rec(t,nb-1);
    }
    
    printf("%d ",t[nb]);
}

void afficherRec(Tab1D t, int nb){
    
    rec(t,nb-1);

    printf("\n");
}


void sommes(Tab1D t, int nb)
{
    int somme = 0;
    for(int i = 0; i < nb; i++)
    {
        somme += t[i];
    }
    printf("Somme : %d \n", somme);
}

void sommmesRec(Tab1D t, int nb){
    int somme;
    if(nb > 0){
        rec(t,nb-1);
    }
    
    somme += t[nb]
}

void NbFoisValeur(Tab1D t, int nb, int valeur)
{
    int present = 0;
    for(int i = 0; i < nb; i++)
    {
        if(t[i] == valeur)
        {
            present ++;
        }
    }
    printf("La valeur %d est present %d fois \n", valeur, present);
}

void valeurMax(Tab1D t, int nb)
{
    int max = 0;
    for(int i = 0; i < nb; i++)
    {
        if(t[i] > max)
        {
            max = t[i];
        }
    }
    printf("La valeur max est %d \n", max);
}

void indiceMax(Tab1D t, int nb)
{
    int max = 0;
    for(int i = 0; i < nb; i++)
    {
        if(t[i] > max)
        {
            max = i;
        }
    }
    printf("L'indice du max est %d \n", max);
}

int main()
{
    Tab1D t;
    int valeurChercher = 0;
    int i = 0;

    printf("-------------------------\n");
    printf("REMPLISSAGE\n");
    printf("-------------------------\n");
    remplir(t,10);
    printf("\n");

    printf("-------------------------\n");
    printf("AFFICHER\n"); 
    printf("-------------------------\n");
    afficher(t,10);
    printf("AFFICHER RECURSIVE\n"); 
    afficherRec(t,10);
    printf("\n");
    printf("\n");

    printf("-------------------------\n");
    printf("SOMMES\n"); 
    printf("-------------------------\n");
    sommes(t,10);
    printf("\n");

    printf("-------------------------\n");
    printf("Merci de saisir la valeur chercher : ");
    scanf("%d",&valeurChercher);
    NbFoisValeur(t,10,valeurChercher);

    valeurMax(t,10);
    indiceMax(t,10);

    return 0;
}

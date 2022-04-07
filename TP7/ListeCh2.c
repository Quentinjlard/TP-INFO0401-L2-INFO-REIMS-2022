#include "Element.h"
#include "Cellule2.h"
#include "ListeCh2.h"
#include <stdlib.h>
#include <stdio.h>

void creerListe(ListeCh* pl)
{
    pl->courant = NULL;
    pl->debut = NULL;
    pl->fin=NULL;
}

int videListe(ListeCh pl)
{
    //printf(" -> Test Vide \n");
    return (pl.debut==NULL);
}

void inserer(ListeCh *pl, Element e)
{
    //printf("Vide : %d ----- Debut : %d ----- Fin : %d \n",videListe(*pl),estDebut(*pl),estFin(*pl));
    Cellule *nc;
    nc = (Cellule *) malloc(sizeof(Cellule));
    nc->val = e;

    Cellule *c = pl->courant;

    if(videListe(*pl))
    {
        //Pas de successeur + modif : debut, fin, couran
        printf("1\n");
        nc->suivant = NULL;
        nc->precedant = NULL;

        pl->debut = nc;
        pl->fin = nc;
        //printf("\tdebut : %d ----- courant : %d ----- fin : %d ----- courant : %d \n",pl->debut->val,pl->courant->val,pl->fin->val,c->val);
    }
    else if(estDebut(*pl))
    {
        //Successeur & précédant : l'ancien premier + modif premier
        printf("2\n");
        
        nc->precedant = NULL;
        nc->suivant = c;
        c->precedant = nc;

        pl->debut = nc;
        //printf("\tdebut : %d ----- courant : %d ----- fin : %d ----- courant : %d \n",pl->debut->val,pl->courant->val,pl->fin->val,c->val);      
    }
    else if(estFin(*pl)){ //C == NULL
        printf("3\n");
        nc->suivant = NULL;
        nc->precedant = pl->fin;
        
        pl->fin->suivant = nc;
        pl->fin = nc;
    }
    else
    {
        //Relier les 2 autours
        printf("4\n");
        nc->suivant = c;
        nc->precedant = c->precedant;

        c->precedant->suivant = nc;
        c->precedant = nc;

        //printf("\tdebut : %d ----- courant : %d ----- fin : %d ----- courant : %d",pl->debut->val,pl->courant->val,pl->fin->val,c->val);      

    }
    //printf("4\n");
    //printf("\n");
}

void supprimer(ListeCh *pl)
{
    Cellule *aSupprimer = pl->courant;

    if (aSupprimer == NULL)
		return;
        
    if(pl->debut == pl->fin)
    {
        pl->debut = NULL;
        pl->courant = NULL; // ++++
        pl->fin = NULL;
    }else if (aSupprimer == pl->debut) { // 1er
        aSupprimer->suivant->precedant = NULL;
        pl->courant = aSupprimer->suivant; //++++
		pl->debut = aSupprimer->suivant;
    }else if(aSupprimer == pl->fin)
    {
        pl->courant = aSupprimer->suivant;
        pl->fin = aSupprimer->precedant;
        pl->fin->suivant = NULL;
    }
	else
    { 
		aSupprimer->precedant->suivant = aSupprimer->suivant;
        aSupprimer->suivant->precedant = aSupprimer->precedant;
        pl->courant = aSupprimer->suivant;
	}  

	free(aSupprimer);
}

Element valeurCourante(ListeCh l)
{
    return (l.courant->val);
}

void allerDebut(ListeCh *l)
{
    l->courant = l->debut;
}

void allerFin(ListeCh *pl)
{
    pl->courant = NULL;
}

void avancer(ListeCh *l)
{
    if(l->courant != NULL)
        l->courant = l->courant->suivant;

}

int estDebut(ListeCh l)
{
    //printf(" -> Test Debut \n");
    return (l.debut == l.courant);
}

int estFin(ListeCh l)
{
    // printf(" -> Test Fin \n");
    return (l.courant == NULL);
}

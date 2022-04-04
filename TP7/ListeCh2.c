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

int listeVide(ListeCh pl)
{
    return (pl.debut==NULL);
}

void inserer(ListeCh *pl, Element e)
{
    
    Cellule* newCl = (Cellule*)malloc(sizeof(Cellule));

    newCl->val = e;
    newCl->suivant = pl->courant;

    if(pl->courant->suivant==NULL)
    {
        newCl->suivant = NULL;
    }
    else
    {
        newCl->suivant = pl->courant;
    }
    if(pl->courant->precedant==NULL)
    {
        newCl->precedant = NULL;
    }
    else
    {
        newCl->precedant = pl->courant->precedant;
    }
}

void supprimer(ListeCh *pl)
{
    if(pl!=NULL)
    {
        Cellule *aSupprimer;
        aSupprimer = pl->courant;

        pl->courant->suivant = aSupprimer->suivant;
        pl->courant->precedant = aSupprimer->precedant;
        
        free(aSupprimer);
    }
}

Element valeurCourante(ListeCh l)
{
    return (l.courant->val);
}

void allerDebut(ListeCh *l)
{
    l->courant = l->debut;
}

void allerFin(ListeCh *l)
{
    l->courant = l->fin;
}

void avancer(ListeCh *l)
{
    if(l->courant->suivant != NULL)
        l->courant = l->courant->suivant;
}

int estDebut(ListeCh l)
{
    return (l.debut == l.courant);
}
int estFin(ListeCh l)
{
    return (l.fin == l.courant);
}
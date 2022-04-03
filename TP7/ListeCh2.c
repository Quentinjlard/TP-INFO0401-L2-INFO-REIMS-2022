#include "Element.h"
#include "Cellule2.h"
#include "ListeCh2.h"
#include <stdlib.h>
#include <stdio.h>

void creerListe(ListeCh l)
{
    l.courant = NULL;
    l.debut = NULL;
    l.fin=NULL;
}

int listeVide(ListeCh *l)
{
    return (l->debut==l->fin);
}

void inserer(ListeCh *l, Element e)
{
    Cellule* newCl = (Cellule*)malloc(sizeof(Cellule));

    newCl->val = e;
    newCl->ptr = l->debut;
    l->debut = newCl;
}

void supprimer(ListeCh *l)
{
    if(l==NULL)
    {
        printf("Liste vide");
        return;
    }
    else
    {
        Cellule *aSupprimer = l->debut;

        l->debut = l->debut->ptr;
        
        free(aSupprimer);
    }
}

Element valeurCourante(ListeCh l)
{
    return (l.courant->val);
}

void allerDebut(ListeCh *l)
{
    if(estDebut(*l) == 0){
        l->courant = l->debut;
    }
}

void allerFin(ListeCh *l)
{
    if(estFin(*l) == 0){
        l->courant = l->fin;
    }
}
void avancer(ListeCh *l)
{
    l->courant = l->courant->ptr;
}

int estDebut(ListeCh l)
{
    return (l.debut == l.courant);
}
int estFin(ListeCh l)
{
    return (l.fin == l.courant);
}
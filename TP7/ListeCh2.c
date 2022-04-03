#include "Element.h"
#include "Cellule2.h"
#include "ListeCh2.h"

void creerListe(ListeCh l)
{
    l.crt == NULL;
    l.deb == NULL;
    l.fin==NULL;
}

int listeVide(ListeCh *l)
{
    return (l->crt == NULL && l->deb == NULL && l->fin==NULL);
}

void inserer(ListeCh *l, Element e)
{
    Cellule* newCl = (Cellule*)malloc(sizeof(Cellule));

    newCl->val = e;
    newCl->ptr = l->deb;
    l->deb = newCl;
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
        Cellule *aSupprimer = l->deb;
        l->deb = l->deb->ptr;
        free(aSupprimer);
    }
}

Element valeurCourante(ListeCh l)
{
    return (l.crt->val);
}

void allerDebut(ListeCh *l)
{
    if(estDebut(*l) == 0){
        l->crt = l->deb;
    }
}

void allerFin(ListeCh *l)
{
    if(estFin(*l) == 0){
        l->crt = l->fin;
    }
}
void avancer(ListeCh *l)
{
    l->crt = l->crt->ptr;
}

int estDebut(ListeCh l)
{
    return (l.deb == l.crt);
}
int estFin(ListeCh l)
{
    return (l.fin == l.crt);
}
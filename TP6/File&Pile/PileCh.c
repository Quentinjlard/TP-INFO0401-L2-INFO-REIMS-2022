#include "PileCh.h"
#include "cellule.h"

void crerPile(PileCh *p)
{
    p->sommet=NULL;
}

int pileVide(PileCh p)
{
    return(p.sommet == NULL);
}

void empiler(PileCh *p, Element c)
{
    Cellule *cl = (Cellule *) malloc(sizeof(Cellule));
    cl->val = c;
    cl->ptr = p->sommet;
    p->sommet=cl;
}

void depiler(PileCh *p)
{
    if(pileVide(*p))
    {
        printf("Impossible la pile est vide");
    }
    else
    {
        Cellule *cl;
        cl = p->sommet;
        p->sommet = p->sommet->ptr;
    }
}

Element sommet(PileCh pile)
{
    return pile.sommet->val;
}
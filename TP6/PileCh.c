#include "PileCh.h"
#include "cellule.h"

void crerPile(PileCh *pile)
{
    pile->cellule=NULL;
}

int pileVider(PileCh pile)
{
    return(pile.cellule == NULL);
}

void empiler(PileCh *pile, Element c)
{
    Cellule *cellule = (Cellule *) malloc(sizeof(Cellule));
    if(cellule != NULL)
    {
        cellule->val = c;
        cellule->ptr = pile->cellule;
        pile->cellule = cellule;
    }
}

void depiler(PileCh *pile)
{
    if(! pileVider(*pile))
    {
        Cellule *c = pile->cellule;
        pile->cellule = pile->cellule->ptr;
        free(c);
    }
}

Element sommet(PileCh pile)
{
    return pile.cellule->val;
}
#include "PileCh.h"
#include "cellule.h"

void crerPile(PileCh *pile)
{
    pile->cellule = 0;
}

int pileVider(PileCh pile)
{
    int estVide;
    if(pile.cellule == NULL) {
        estVide = 0;
    }
    else
    {
        estVide = 1;
    }

    return estVide;
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
    
}

Element sommet(PileCh pile)
{
    int som = 0;
    return som;
}
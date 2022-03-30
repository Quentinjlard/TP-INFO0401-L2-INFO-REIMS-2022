#include "pile.h"
#include "cellule.h"

void crerPile(Pile *pile)
{
    pile->cellule = 0;
    //pile->cellule->element = 0;
}

int pileVider(Pile pile)
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

void empiler(Pile *pile, Element c)
{
    Cellule *cellule = (Cellule *) malloc(sizeof(Cellule));
    if(cellule != NULL)
    {
        cellule->val = c;
        cellule->ptr = pile->cellule;
        pile->cellule = cellule;
    }
}

void depiler(Pile *pile)
{
    
}

Element sommet(Pile pile)
{
    int som = 0;
    return som;
}
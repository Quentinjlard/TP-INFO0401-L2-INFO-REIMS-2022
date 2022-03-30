#ifndef __PILE_H__
#define __PILE_H__

#include "cellule.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    Cellule *cellule;
    
} Pile;

void crerPile(Pile *pile);

int pileVider(Pile pile);

void empiler(Pile *pile, Element c);

void depiler(Pile *pile);

Element sommet(Pile pile);


#endif /* __PILE_H__ */
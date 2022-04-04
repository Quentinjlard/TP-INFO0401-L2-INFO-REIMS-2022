#ifndef __PILECH_H__
#define __PILECH_H__

#include "Cellule.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    Cellule *sommet;
} PileCh;

void crerPile(PileCh *pile);
void empiler(PileCh *pile, Element c);
void depiler(PileCh *pile);
Element sommet(PileCh pile);
int pileVide(PileCh pile);

#endif /* __PILE_H__ */
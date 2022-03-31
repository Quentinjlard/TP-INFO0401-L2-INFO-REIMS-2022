#ifndef __FILETAB_H__
#define __FILETAB_H__

#include "Cellule.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    Cellule *cellule;
    
} PileTab;

void creerpile(PileTab *p);
void empiler(PileTab *p, Element e);
void depiler(PileTab *p);
Element sommet(PileTab p);
int pileVide(PileTab p);



#endif /* __PILE_H__ */
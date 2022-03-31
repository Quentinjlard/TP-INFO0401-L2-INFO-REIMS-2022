#ifndef __FILECH_H__
#define __FILECH_H__

#include "Cellule.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    Cellule *cellule;
    
} FileCh;

void creerFile(FileCh *f);
int fileVide(FileCh f);
Element tete(FileCh f);
void enfier(FileCh *f, Element e);
void defiler(FileCh *f);


#endif /* __PILE_H__ */
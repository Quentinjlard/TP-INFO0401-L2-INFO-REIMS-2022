#ifndef __FILECH_H__
#define __FILECH_H__

#include "Cellule.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    Cellule *tete;
    Cellule *queue;
} FileCh;

void creerFile(FileCh *f);
int fileVide(FileCh f);
Element tete(FileCh f);
void enfiler(FileCh *f, Element e);
void defiler(FileCh *f);


#endif /* __PILE_H__ */
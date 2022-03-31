#ifndef __FILETABC_H__
#define __FILETABC_H__

#include "Cellule.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    Cellule *cellule;
    
} FileTabC;

void creerFile(FileTabC *f);
int fileVide(FileTabC f);
Element tete(FileTabC f);
void enfier(FileTabC *f, Element e);
void defiler(FileTabC *f);


#endif /* __PILE_H__ */
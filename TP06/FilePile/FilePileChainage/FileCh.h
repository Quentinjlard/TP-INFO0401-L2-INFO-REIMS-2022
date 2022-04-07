/**
 * @file FileCh.h
 * @author JUILLIARD Quentin (quentin.juilliard@etudiant.univ-reims.fr)
 * @brief 
 * @version1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef __FILECH_H__
#define __FILECH_H__

#include "Cellule.h"
#include "Element.h"

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
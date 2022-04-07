/**
 * @file FileTabC.h
 * @author JUILLIARD Quentin (quentin.juilliard@etudiant.univ-reims.fr)
 * @brief 
 * @version1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef __FILETABC_H__
#define __FILETABC_H__

#include "Element.h"
#define MAX 100

typedef struct {
    Element t[MAX];
    int tete, queue;
} FileTabC;

void creerFile(FileTabC *f);
int fileVide(FileTabC f);
Element tete(FileTabC f);
void enfiler(FileTabC *f, Element e);
void defiler(FileTabC *f);


#endif /* __PILE_H__ */
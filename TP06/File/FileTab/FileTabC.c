/**
 * @file FileTabC.c
 * @author JUILLIARD Quentin (quentin.juilliard@etudiant.univ-reims.fr)
 * @brief 
 * @version1
 * @date 2022-04-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "FileTabC.h"
#include "Element.h"

#include <stdio.h>
#include <stdlib.h>

void creerFile(FileTabC *f)
{
    f->tete = 1;
    f->queue = 0;
}

int fileVide(FileTabC f)
{
    return (f.tete > f.queue);
}

Element tete(FileTabC f)
{
    return f.t[f.tete];
}

void enfiler(FileTabC *f, Element e)
{
    f->queue = f->queue+1;
    f->queue = f->queue % MAX;
    f->t[f->queue] = e;
}

void defiler(FileTabC *f)
{
    f->tete = f->tete + 1;
    f->tete = f->tete % MAX;
}
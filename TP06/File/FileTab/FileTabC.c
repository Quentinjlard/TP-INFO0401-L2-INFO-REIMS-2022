#include "FileTabC.h"
#include "Element.h"

#include <stdio.h>
#include <stdlib.h>

void creerFile(FileTabC *f)
{
    f->tete = 0;
    f->queue = 0;
}

int fileVide(FileTabC f)
{
    return (f.queue == f.tete);
}

Element tete(FileTabC f)
{
    return f.t[f.tete];
}

void enfiler(FileTabC *f, Element e)
{
    if(fileVide(*f))
    {
        f->t[f->tete] = e;
    }
    else
    {
        f->t[f->queue] = e;
        
    }
    f->queue++;
}

void defiler(FileTabC *f)
{
    f->tete = f->tete+1;
}
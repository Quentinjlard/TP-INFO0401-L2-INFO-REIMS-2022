#include "FileCh.h"

void creerFile(FileCh *f)
{
    f = NULL;
}
int fileVide(FileCh f)
{
    return (f.tete == f.queue);
}

Element tete(FileCh f)
{
    return f.tete;
}

void enfiler(FileCh *f, Element e)
{
    if(f->tete == f->queue+1%e)
    {
        return;
    }
    else
    {
        f->tete->val = e;
        f->tete = f->tete + 1;
    }
}

void defiler(FileCh *f)
{
    if(!fileVide(*f)){
        return;
    }
    else
    {
        Element x;
        x = f->tete;
        f->tete = x + 1;
    }
    
}
#include "FileCh.h"

void creerFile(FileCh *f)
{
    f->queue = NULL;
    f->tete = NULL;
}
int fileVide(FileCh f)
{
    return (f.queue == NULL);
}

Element tete(FileCh f)
{
    return f.tete->val;
}

void enfiler(FileCh *f, Element e)
{
    Cellule* cl = (Cellule*)malloc(sizeof(Cellule));
    cl->val = e;    
    cl->ptr = NULL;    
    if (fileVide(*f))    
    {        
        f->tete = cl;    
    }    
    else    
    {        
        f->queue->ptr = cl;    
    }    
    f->queue = cl;
}

void defiler(FileCh *f)
{
    if(!fileVide(*f)){
        printf("Impossible de defiler");
        return;
    }
    else
    {
        Cellule* cl = &(f->tete);
        Element el = f->tete->val;
        f->tete = f->tete->ptr;

        if (f->tete == NULL)
        {
            f->queue=NULL;
        }

        free(cl);
    }
    
}
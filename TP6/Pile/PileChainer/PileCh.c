/**
 * @file PileCh.c
 * @author JUILLIARD Quentin (quentin.juilliard@etudiant.univ-reims.fr)
 * @brief 
 * @version1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "PileCh.h"
#include "Cellule.h"
#include "Element.h"

#include <stdio.h>
#include <stdlib.h>

void creerPile(PileCh *p)
{
    p->sommet=NULL;
}

int pileVide(PileCh p)
{
    return(p.sommet == NULL);
}

void empiler(PileCh *p, Element e)
{
    Cellule *cl = (Cellule *) malloc(sizeof(Cellule));
    cl->val = e;
    cl->ptr = p->sommet;
    p->sommet=cl;
}

void depiler(PileCh *p)
{
    if(pileVide(*p))
    {
        printf("Impossible la pile est vide");
    }
    else
    {
        Cellule* cl;
        cl = p->sommet;
        p->sommet = p->sommet->ptr;
        free(cl);
    }
}

Element sommet(PileCh pile)
{
    return pile.sommet->val;
}
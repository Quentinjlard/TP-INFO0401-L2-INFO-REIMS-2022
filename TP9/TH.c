/**
 * @file TH.c
 * @author JUILLIARD Quentin
 * @brief 
 * @version 0.1
 * @date 2022-03-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "TH.h"

#include <stdio.h>
#include <stdlib.h>

void TH_creer(TH* px)
{
    Element2p* e = px;
    int taille = e->val;

    for (int i = 0; i<taille ; i++)
        *px = NULL;
}


int TH_vide(TH x)
{
    return (x == NULL);
}

Element2p* TH_rechercher(TH x, int cle)
{

}

void TH_supprimer(TH *x,Element2p* p)
{
    
}

void TH_inserer(TH *x, int cle)
{

}

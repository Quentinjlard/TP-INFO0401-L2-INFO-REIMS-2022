/**
 * @file PileTab.c
 * @author JUILLIARD Quentin (quentin.juilliard@etudiant.univ-reims.fr)
 * @brief 
 * @version1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "PileTab.h"
#include <stdio.h>
#include <stdlib.h>

void creerPile(PileTab *pile)
{
    pile->sommet = 0;
    for(int i = 0; i <MAX;i++)
        pile->t[i]=0;
}
void empiler(PileTab *pile, Element e)
{
    pile->sommet = pile->sommet+1;
    pile->t[pile->sommet] = e;
}
void depiler(PileTab *pile)
{
    pile->sommet = pile->sommet-1;
}
Element sommet(PileTab pile)
{
    return pile.t[pile.sommet];
}
int pileVide(PileTab pile)
{
    return (sommet(pile) == 0);
}
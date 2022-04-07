/**
 * @file PileTab.h
 * @author JUILLIARD Quentin (quentin.juilliard@etudiant.univ-reims.fr)
 * @brief 
 * @version1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef __PILETAB_H__
#define __PILETAB_H__

#include "Element.h"
#define MAX 15

typedef struct {
    Element t[MAX];
    Element sommet;
} PileTab;

void creerPile(PileTab *pile);
void empiler(PileTab *pile, Element e);
void depiler(PileTab *pile);
Element sommet(PileTab pile);
int pileVide(PileTab pile);

#endif 
/* __PILE_H__ */
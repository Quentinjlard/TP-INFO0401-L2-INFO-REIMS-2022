/**
 * @file PileCh.h
 * @author JUILLIARD Quentin (quentin.juilliard@etudiant.univ-reims.fr)
 * @brief 
 * @version1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef __PILECH_H__
#define __PILECH_H__

#include "Cellule.h"
#include "Element.h"

typedef struct {
    Cellule *sommet;
} PileCh;

void creerPile(PileCh *pile);
void empiler(PileCh *pile, Element c);
void depiler(PileCh *pile);
Element sommet(PileCh pile);
int pileVide(PileCh pile);

#endif 
/* __PILE_H__ */

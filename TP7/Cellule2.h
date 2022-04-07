/**
 * @file Cellule2.h
 * @author JUILLIARD Quentin (quentin.juilliard@etudiant.univ-reims.fr)
 * @brief 
 * @version1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef __CELLULE_H__
#define __CELLULE_H__

#include "Element.h"

typedef struct Cellule{
    struct Cellule *precedant;
    Element val;
    struct Cellule *suivant;
} Cellule;

#endif

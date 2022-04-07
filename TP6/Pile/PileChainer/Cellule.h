/**
 * @file Cellule.h
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
    Element val;
    struct Cellule *ptr;
} Cellule;

#endif /* __CELLULE_H__ */
#ifndef __CELLULE_H__
#define __CELLULE_H__

#include "Element.h"

typedef struct Cellule{
    struct Cellule *precedant;
    Element val;
    struct Cellule *suivant;
} Cellule;

#endif
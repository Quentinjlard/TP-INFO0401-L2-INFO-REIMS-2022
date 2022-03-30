#ifndef __CELLULE_H__
#define __CELLULE_H__

#include "element.h"

typedef struct Cellule{
    Element val;
    struct Cellule *ptr;
} Cellule;

#endif
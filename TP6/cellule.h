#ifndef __CELLULE_H__
#define __CELLULE_H__

#include "Element.h"

typedef struct Cellule{
    Element val;
    struct Cellule *ptr;
} Cellule;

#endif /* __CELLULE_H__ */
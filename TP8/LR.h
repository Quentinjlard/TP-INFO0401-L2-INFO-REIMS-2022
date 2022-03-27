#ifndef __LR_H__
#define __LR_H__

typedef struct Element2p{
    struct Element2p* prec;
    int cle;
    struct Element2p* succ;
} Element2p;

typedef Element2p* LR;

/*  typedef  struct { 
        Element2p* Debut;
    } LR;
*/

void LR_creer(LR*);

void LR_inserer(LR*, int);

void LR_supprimer(LR*,Element2p*);

Element2p* LR_rechercher(LR,int);

int LR_vide(LR);

#endif
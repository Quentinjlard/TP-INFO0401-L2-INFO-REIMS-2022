#ifndef __LR_H__
#define __LR_H__

typedef struct Element2p{
    int cle;
    int val;
    struct Element2p* succ;
} Element2p;

typedef Element2p* TH;

void TH_creer(TH*);

void TH_inserer(TH*, int);

void TH_supprimer(TH*,Element2p*);

Element2p* TH_rechercher(TH,int);

int TH_vide(TH);

#endif
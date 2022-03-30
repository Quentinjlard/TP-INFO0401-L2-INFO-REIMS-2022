#ifndef _Terme_H
#define _Terme_H

typedef struct Terme
{
    int nb;
    int elts[]; 
} Terme;

Terme Premier(void);

void afficher(Terme X);

Terme Suivant(Terme X);

double* stats(Terme X);

int coherent(double* tab);
#endif
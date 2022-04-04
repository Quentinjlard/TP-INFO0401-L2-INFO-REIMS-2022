#ifndef __LISTECH_H__
#define __LISTECH_H__

#include "Cellule2.h"
#include "Element.h"

typedef struct {
    Cellule *debut;
    Cellule *courant;
    Cellule *fin;
} ListeCh;

void creerListe(ListeCh*);
int listeVide(ListeCh);
void inserer(ListeCh*, Element);
void supprimer(ListeCh*);
Element valeurCourante(ListeCh );

void allerDebut(ListeCh*);
void allerFin(ListeCh*);
void avancer(ListeCh*);
int estDebut(ListeCh);
int estFin(ListeCh);
#endif
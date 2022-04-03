#ifndef __LISTECH_H__
#define __LISTECH_H__

#include "Cellule2.h"
#include "Element.h"

typedef struct {
    Cellule *deb;
    Cellule *crt;
    Cellule *fin;
} ListeCh;

void creerListe();
int listeVide(ListeCh *l);
void inserer(ListeCh *l, Element e);
void supprimer(ListeCh *l);
Element valeurCourante(ListeCh l);

void allerDebut(ListeCh *l);
void allerFin(ListeCh *l);
void avancer(ListeCh *l);
int estDebut(ListeCh l);
int estFin(ListeCh l);
#endif
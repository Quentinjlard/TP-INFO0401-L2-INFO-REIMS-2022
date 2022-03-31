#ifndef __LISTECH_H__
#define __LISTECH_H__

#include "Cellule.h"
#include "Element.h"

typedef struct {
    Cellule *deb;
    Cellule *crt;
    Cellule *fin;
} listeCh;

void creerListe();
int listeVide(listeCh *l);
void inserer(listeCh *l, Cellule nb);
void supprimer(listeCh *l);
Element valeurCourante(listeCh l);

void allerDebut(listeCh *l);
void allerFin(listeCh *l);
void avancer(listeCh *l, Cellule nb);
int estDebut(listeCh l);
int estFin(listeCh l);
#endif
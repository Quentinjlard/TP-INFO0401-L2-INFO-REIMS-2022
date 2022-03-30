#include "element.h"
#include "cellule.h"
#include "listeCh.h"

void creerListe(listeCh l)
{
    l.crt == NULL;
    l.deb == NULL;
    l.fin==NULL;
}

int listeVide(listeCh *l)
{
    int vide = 0;
    if(l->crt == NULL && l->deb == NULL && l->fin==NULL)
    {
        vide = 1;
    }
    return vide;
}

void inserer(listeCh *l, Cellule nb)
{
    if(listeVide(l) == 1)
    {

    }
}
void supprimer(listeCh *l)
{
    
}
Element valeurCourante(listeCh l)
{
    Element valeur = 0;
    valeur = l.crt->val;
    return valeur;
}
void allerDebut(listeCh *l)
{
    if(estDebut(*l) == 0){
        l->crt = l->deb;
    }
}
void allerFin(listeCh *l)
{
    if(estFin(*l) == 0){
        l->crt = l->fin;
    }
}
void avancer(listeCh *l, Cellule nb)
{
    l->crt = &nb;
}
int estDebut(listeCh l)
{
    if(l.deb == l.crt)
    {
        return 1;
    }
    return 0;
}
int estFin(listeCh l)
{
    if(l.fin == l.crt)
    {
        return 1;
    }
    return 0;
}
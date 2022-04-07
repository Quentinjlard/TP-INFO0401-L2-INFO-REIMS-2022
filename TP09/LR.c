/**
 * @file LR.c
 * @author JUILLIARD Quentin
 * @brief 
 * @version 0.1
 * @date 2022-03-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "LR.h"

#include <stdio.h>
#include <stdlib.h>

void LR_creer(LR* px)
{
    *px = NULL;
}


int LR_vide(LR x)
{
    return (x == NULL);
/*    if (x==NULL) {
        return 1;
    }
    return 0;   
*/
}

Element2p* LR_rechercher(LR x, int cle)
{
/*	int i = 0;
	while ( i < MAX && t[i] != cle )
		i++;
	if (i<MAX) 
		i = -1;
*/	
	Element2p* pos = x;
	while ( pos != NULL && pos->cle != cle )
		pos = pos->succ;
	return pos;

/*    int found =0;
    Element2p* actuel;
    if ( LR_vide(x) ) {//Verifie si la liste est nulle
        return NULL;
    }
    actuel = x;
    
    while ( ! found ) {
        if (actuel->cle==cle) {
            return actuel;
        }
        else {
            if (actuel->succ == NULL) {
                found =1;
            }
            else 
                actuel = actuel->succ;
        }
    }
    
    return NULL;
*/
}

void LR_supprimer(LR *x,Element2p* p)
{
    if (p == NULL)
		return;
		
	Element2p* e = p ;

// partie gauche-droite
	if (p->prec == NULL) { // 1er
		e = p->succ;	// mon succeseur
		// e == NULL ?
		// pb si e==NULL, pour e->prec
		if (e != NULL)
			e->prec = NULL;
		*x = e;
	}
	else{ // il y a qqn a G
		// a D de mon predecesseur il y a mon successeur
		e = p->prec;
		e->succ = p->succ;
	}  

// partie droite-gauche
	if(p->succ != NULL) //il y a qqn a D
	{
		e = p->succ;	// son pred est le mien
		e->prec = p->prec;
	}

// liberation memoire
	free(p);
}

void LR_inserer(LR *x, int cle)
{
// partie factorisable
	Element2p* pelem;
	pelem=(Element2p*)malloc(sizeof(Element2p));
	pelem->prec=NULL;
	pelem->cle=cle;
	pelem->succ = *x;

	if ( ! LR_vide(*x) )
		(*x)->prec = pelem;

	*x = pelem;
/*
    if ( LR_vide(*x) ) { // ==1) { //Si la liste est vide
	// les "==1" ou "== VRAI" peuvent etre enleves
	// et les "toto == 0" (ou "== FAUX") remplaces par " ! toto "
    }
    else { 
            Element2p* ancienElement = *x;
            *x ancienElement->prec = pelem;
            *x = pelem;   
    }
	*/
}

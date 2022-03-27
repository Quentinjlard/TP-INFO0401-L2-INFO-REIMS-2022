/**
 * @file TH.c
 * @author JUILLIARD Quentin
 * @brief 
 * @version 0.1
 * @date 2022-03-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "TH.h"

#include <stdio.h>
#include <stdlib.h>

void TH_creer(TH* px)
{
    *px = NULL;
}


int TH_vide(TH x)
{
    return (x == NULL);
}

Element2p* TH_rechercher(TH x, int cle)
{
    Element2p* pos = x;
	while ( pos != NULL && pos->cle != cle )
		pos = pos->succ;
	return pos;
}

void TH_inserer(TH *x, int cle)
{
    Element2p* pelem;
	pelem=(Element2p*)malloc(sizeof(Element2p));
	pelem->prec=NULL;
	pelem->cle=cle;
	pelem->succ = *x;

	if ( ! LR_vide(*x) )
		(*x)->prec = pelem;

	*x = pelem;
}

void TH_supprimer(TH *x,Element2p* p)
{
    if (p == NULL)
		return;


    Element2p* e = p ;

// partie gauche-droite
	if (p->succ == NULL) { // 1er
		e = p->succ;	// mon succeseur
		// e == NULL ?
		// pb si e==NULL, pour e->prec
		*x = e;
	}
	else{ // il y a qqn a G
		// a D de mon predecesseur il y a mon successeur
		e->succ = p->succ;
	}  

// partie droite-gauche
	if(p->succ != NULL) //il y a qqn a D
	{
		e = p->succ;	// son pred est le mien
	}

    // liberation memoire
	free(p);
}
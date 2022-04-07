/* Ch Jaillet
 * projet : arbres binaires de recherche
 * fichier : ABR.c
 * date : 2022/03/18
 *******************
 */

#include "ABR.h"
#include <stdlib.h>

void ABR_creer(ABR* px) 
{	// objectif NULL ;-)
	px = NULL;
}

int  ABR_vide(ABR x)
{	
	return (x==NULL);
}

Noeud* ABR_rechercher(ABR x, int k)
{	
	if(x!=NULL || k == x->cle)
		return x;

	if( k < x->cle)
		return ABR_rechercher(x->gauche,k);
	else
		return ABR_rechercher(x->droite,k);
}

Noeud* ABR_minimum(ABR x)
{	
	if(x == NULL) return NULL;

	while(x->gauche!=NULL)
		x = x->gauche;

	return x;
}

Noeud* ABR_maximum(ABR x)
{	
	if(x == NULL) return NULL;

	while(x->droite!=NULL)
		x = x->droite;

	return x;
}

Noeud* ABR_successeur( Noeud* x)	// il est enracine
{	if( x == NULL )
		return x;
	// else
	
	if(x->droite != NULL)
		return ABR_minimum(x->droite);
	
	Noeud* y = x->pere;
	while (y != NULL && x == y->droite)
	{
		x = y;
		y = x->pere;
	}
	return y;
	
}

Noeud* ABR_predecesseur( Noeud* x)
{	
	if( x == NULL )
		return x;
	// else
	
	if(x->gauche != NULL)
		return ABR_maximum(x->gauche);
	
	Noeud* y = x->pere;
	while (y != NULL && x == y->gauche)
	{
		x = y;
		y = x->pere;
	}
	return y;
}

// routine (interne)
Noeud* nouveau_noeud(int k)		
{	Noeud* p = (Noeud*) malloc( sizeof(Noeud) );
	p->cle = k;
	// noeud isole : tous pointeurs a NULL
	p->droite = NULL;
	p->gauche = NULL;
	p->pere = NULL;
	return p;
}

void ABR_inserer(ABR* px, int k)
{	
	Noeud* y = (Noeud*) malloc( sizeof(Noeud) );
	Noeud* x = (Noeud*) malloc( sizeof(Noeud) );
	Noeud *z = (Noeud*) malloc( sizeof(Noeud) );
	y = NULL;
	x = *px;
	z->cle = k;

	while(x!=NULL)
	{	
		y = x;
		if(k < x->cle)
			x = x->gauche;
		else
			x = x->droite;
	}

	z->pere = y;
	if(y == NULL)
		*px = z;
	else if( z->cle < y->cle )
		y->gauche = z;
	else
		y->droite = z;
}

void ABR_supprimer(ABR* px, Noeud* p)
{	if( p == NULL )
		return;
	Noeud* y = (Noeud*)malloc(sizeof(Noeud));
	if(p->gauche == NULL || p->droite == NULL)
		y = p;
	else
		y = ABR_successeur(p);

	Noeud* x = (Noeud*)malloc(sizeof(Noeud));
	if(p->gauche != NULL)
		x = y->gauche;
	else
		x = y->droite;

	if(x!=NULL)
		x->pere = y->pere;

	if(y->pere == NULL)
		*px = x;
	else if(y == y->pere->gauche)
		y->pere->gauche = x;
		else
			y->pere->droite = x;

	if(y != p)
		p->cle = y->cle;
}

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
	*px = NULL;
}

int  ABR_vide(ABR x)
{	
	return (x == NULL);
}

Noeud* ABR_rechercher(ABR T, int k)
{	
	if( !ABR_vide(T)){// Verficiation que l'arbre est non vide
		Noeud* ab = T->pere; //Positionne à la racine
		if(k == ab->cle ) // Verifique que ce n'est pas la valeur qu'on recherche
			return ab;
		
		if (k < ab->cle) //Regarde si la valeur recherche est plus petite que la valeur clé
			ABR_rechercher(ab->gauche,k); // Recurcive
		else
			ABR_rechercher(ab->droite,k); // Recurcive
	} 
}

Noeud* ABR_minimum(ABR x)
{	
	while (x->gauche != NULL)
	{
		x = x->gauche;
	}
	
	return x;
}

Noeud* ABR_maximum(ABR x)
{	

	while (x->droite != NULL)
	{
		x = x->droite;
	}

	return x;
}

Noeud* ABR_successeur( Noeud* x)	// il est enracine
{	
	Noeud* y ;
	if( x->droite == NULL )
	{
		return ABR_maximum(x);
	}
	else
	{
		y = x->pere;
		while (y != NULL && x == y->droite)
		{
			x = y;
			y = x->pere;
		}
		return y;
	}
}

Noeud* ABR_predecesseur( Noeud* x)
{	
	Noeud* y ;
	if( x->droite == NULL )
	{
		return ABR_minimum(x);
	}
	else
	{
		y = x->pere;
		while (y != NULL && x == y->droite)
		{
			x = y;
			y = x->pere;
		}
		return y;
	}
}

// routine (interne)
Noeud* nouveau_noeud(int k)		
{	Noeud* p = (Noeud*) malloc( sizeof(Noeud) );
	p->cle = k;
	// noeud isole : tous pointeurs a NULL
	p->droite=NULL;
	p->gauche=NULL;
	p->pere=NULL;
	return p;
}

void ABR_inserer(ABR* a, int k)
{	
	if ( *a == NULL )
		return;
	
	Noeud* x = *a;
	Noeud* pereX = NULL;

	while (x != NULL)
	{
		pereX = x;
		if (k < x->cle)
		{
			x = x->gauche;
		}else
		{
			x =x->droite;
		}
	}


	Noeud* z =(Noeud*)malloc(sizeof(Noeud));
	z->pere = pereX;
	if (pereX == NULL)
	{
		*a = z;
	}
	else if ( k < x->cle)
	{
		pereX->gauche = z;
	}
	else
	{
		pereX->droite = z;
	}
}

void ABR_supprimer(ABR* T, Noeud* x)
{	
	Noeud* filsX;
	if( x == NULL )
		return;

	if (x->gauche == NULL && x->droite == NULL)
	{
		if (x->pere == NULL)
		{
			T = NULL;
		}
		else
		{
			if (x == x->pere->gauche)
			{
				x->pere->gauche = NULL;
			}
			else
			{
				x->pere->droite = NULL;
			}
		}
	}else if (x->gauche == NULL || x->droite == NULL)
	{
		if(x->gauche != NULL)
		{
			filsX = x->gauche;
		}
		else
		{
			filsX = x->droite;
		}
		filsX->pere = x->pere;
		if(x->pere == NULL)
		{
			*T = filsX;
		}
		else
		{
			if (x->pere->gauche == x)
			{
				x->pere->gauche = filsX;
			}
			else
			{
				x->pere->droite = filsX;
			}
		}
	}
	else
	{
		Noeud* xmin;
		xmin = ABR_minimum(x->droite);
		ABR_supprimer(T,xmin);
	}
}


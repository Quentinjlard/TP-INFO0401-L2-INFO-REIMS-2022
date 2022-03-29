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

Noeud* ABR_rechercher(ABR x, int k)
{	

}

Noeud* ABR_minimum(ABR x)
{	if( x == NULL )
		return;
	else
		...
	return ...
}

Noeud* ABR_maximum(ABR x)
{	...
}

Noeud* ABR_successeur( Noeud* x)	// il est enracine
{	if( x == NULL )
		return x;
	// else
	...
	return ...
}

Noeud* ABR_predecesseur( Noeud* x)
{	...
}

// routine (interne)
Noeud* nouveau_noeud(int k)		
{	Noeud* p = (Noeud*) malloc( sizeof(Noeud) );
	p->cle = k;
	// noeud isole : tous pointeurs a NULL
	...
	return p;
}

void ABR_inserer(ABR* px, int k)
{	if ( *px == NULL )
		...
	else if ( ... )	// a gauche toute !
		if ( ... )  // il n'y a rien a gauche
			...
		else 	// descendre et relancer
			...
/*	else if( k == xxx.cle ) // ca ne devrait pas arriver
		return;
 */
	else // meme chose a droite
		...
}

void ABR_supprimer(ABR* px, Noeud* p)
{	if( p == NULL )
		return;
	// else
	// 1er cas : feuille : pas de fils
	if ( ... )
	{	...
		free(p);
	}
	// 2eme cas : j'ai un fils
	// => raccorder mon père et mon fils
	else if ( ... ) // j'ai un fils
	{	... 	// => la, je tiens mon fils (peu importe le cote)
		// mon pere sera le sien
		...
		// mais si je n'en ai pas [de pere] (je suis a la racine), 
		//		c'est lui qui s'y colle (a la racine)
		...
		// par contre si j'ai un pere il faut que f soit son fils
		//		(il faut savoir de quel cote)
		...
		
		// et la yapuka liberer la memoire
		free(p);
	}
	// 3eme et dernier cas 
	else 	// j'ai 2 fils
	{	// ramener mon successeur (copier la clé) et supprimer le successeur
		... = ABR_successeur(...);
		...
		ABR_supprimer(...);
	}
}

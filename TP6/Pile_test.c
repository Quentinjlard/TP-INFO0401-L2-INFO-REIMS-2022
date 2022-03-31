/* Ch Jaillet
 * projet : TDA sequentiels
 * fichier : Pile_test.c
 * date : 2022/01
 *******************
 */

// choisissez : 0 pour implem Tab ; 1 pour implem Ch
#define VERSION 1

#include "Element.h"
#if VERSION == 0
	#include "PileTab.h"
	typedef PileTab Pile;
#else
	#include "Cellule.h"
	#include "PileCh.h"
	typedef PileCh Pile;	
#endif

#include <stdio.h>

//////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
//////////////////////////////
// fonctions calculables
// A. leurs declarations (definitions a la fin)
void viderP(Pile *);
void transfererPP(Pile *, Pile *);
void inverserP(Pile *);

// pour ces deux la on ne change pas les valeurs de la pile, et leur ordre global est OK
// mais si l'implem est en chainage les cellules ne sont pas necessairement au meme endroit
int  longueurP(Pile *);
void afficherP(Pile *);

//////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
////////////////////////////// 
// B. le programme de test 
// definitions des fonctions calculables a la fin
int main(void)
{	Pile p; 
	Element e;
	
	creerPile(&p);
	for(int i=0 ; i<10 ; i++)
	{	saisie(&e);
		empiler(&p, e);
	}
	printf("contenu apres remplissage : "); 	
		afficherP(&p);	// le contenu de la structure change : on passe le ptr 

	printf("longueur : %d\n", longueurP(&p));
	printf("contenu avant inversion : "); 	afficherP(&p);
	inverserP(&p);
	printf("contenu apres inversion : "); 	afficherP(&p);
	viderP(&p);
	printf("contenu apres vidage : "); 		afficherP(&p);
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
//////////////////////////////
// fonctions calculables
// C. leurs definitions (declarations a la fin)

void viderP(Pile* p)
{	while ( ! pileVide(*p) )
		depiler(p);
}

// routine : transfert d'une pile dans une autre
void transfererPP(Pile* p, Pile* pp)
{	...
}

int longueurP(Pile* p)
// on enleve les elements puis on les remet : si l'implem est chainee
// 		on a peu de chances que le ptr vers la 1ere cellule ait la meme valeur
//		=> modifie le contenu de la structure => on passe l'adresse de la pile
{	int nb = 0;
	...
	// 1. sortir et stocker
	// 2. reconstituer
	// NB : mon choix : compter a l'aller
	...
	return nb;
}

void afficherP(Pile* p)
// idem mais en affichant au lieu de compter
{	...
}

void inverserP(Pile* p)
{	...
}

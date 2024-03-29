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
	printf("Contenu apres remplissage : \n"); 	
		afficherP(&p);	// le contenu de la structure change : on passe le ptr 

	printf("\t longueur : %d\n", longueurP(&p));
	printf("Contenu avant inversion : \n"); 	afficherP(&p);
	inverserP(&p);
	printf("Contenu apres inversion : \n"); 	afficherP(&p);
	viderP(&p);
	printf("Contenu apres vidage : \n"); 		afficherP(&p);
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
{	
	while( ! pileVide(*p) )
	{
		empiler(pp,sommet(*p));
		depiler(p);
	}
}

int longueurP(Pile* p)
// on enleve les elements puis on les remet : si l'implem est chainee
// 		on a peu de chances que le ptr vers la 1ere cellule ait la meme valeur
//		=> modifie le contenu de la structure => on passe l'adresse de la pile

	// 1. sortir et stocker
	// 2. reconstituer
	// NB : mon choix : compter a l'aller

{	
	int nb = 0;
	Pile tmp;
	creerPile(&tmp);

	while( ! pileVide(*p) )
	{
		empiler(&tmp,sommet(*p));
		depiler(p);
		++nb;
	}

	transfererPP(&tmp,p);
	return nb;
}


void afficherP(Pile* p)
// idem mais en affichant au lieu de compter
{	
	Pile tmp;
	creerPile(&tmp);
	Element e;

	while( ! pileVide(*p) )
	{
		e = sommet(*p);
		empiler(&tmp,e);
		afficher(e);
		depiler(p);
	}

	transfererPP(&tmp,p);
}

void inverserP(Pile* p)
{	
	if(p==NULL) 
		return;
	else
	{
		Pile p2, p3;	
		creerPile(&p2);
		creerPile(&p3);
		transfererPP(p, &p2);
		transfererPP(&p2, &p3);
		transfererPP(&p3, p);
	}
}

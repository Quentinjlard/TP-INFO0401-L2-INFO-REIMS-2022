/* Ch Jaillet
 * projet : TDA sequentiels
 * fichier : Liste_test.c (Liste = Liste avec curseur)
 * date : 2022/01
 *******************
 */

/* Rappel : les 2 remedes pour l'implem. des listes [listes avec curseur]
 * - remede 1
 *		chainage simple
 * 		la tete de lecture est sur la cellule precedant la cellule visee
 * - remede 2
 * 		physiquement la tete de lecture est sur la Cellule2 visee
 *		chainage double
 */

// choisissez : 0 pour implem par tableau
//	sinon chainage 
//			 => 1 pour "remede 1" ; 2 pour "remede 2"	
#define VERSION 2

#include "Element.h"
#if VERSION == 1
	#include "Cellule.h"
	#include "ListeCh1.h"
	typedef ListeCh Liste;
#elif VERSION == 2
	#include "Cellule2.h"
	#include "ListeCh2.h"
	typedef ListeCh Liste;
#else	// VERSION == 0
	#include "ListeTab.h"
	typedef ListeTab Liste;
#endif

#include <stdio.h>
#include <stdlib.h>

/////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
//////////////////////////////
// fonctions calculables
// A. leurs declarations (definitions a la fin)
void viderL(Liste *);

// pour les deux suivantes on passe le ptr 
//		pour etre homogene avec les versions pour les piles / files
int  longueurL(Liste *);
void afficherL(Liste *);

/////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
//////////////////////////////
// B. le programme de test 
// definitions des fonctions calculables a la fin
int main(void)
{	Liste l; 
	Element e;
	
	creerListe(&l);
	for(int i=0 ; i<10 ; i++)
	{	saisie(&e);
		inserer(&l, e);
	}
	printf("contenu apres remplissage : "); 	
		afficherL(&l);	// cette fois le contenu de la struct. ne change pas
		// mais on passe quand meme l'adresse
		// 		pour respecter la notation imposee pour les piles /files

	printf("\t => longueur : %d\n", longueurL(&l));
	printf("contenu apres longueur : "); 	afficherL(&l);

	allerDebut(&l); avancer(&l); avancer(&l);
	printf("on va au debut et on avance 2 fois : "); afficherL(&l);
	printf("\t => longueur : %d\n", longueurL(&l));
	
	supprimer(&l); supprimer(&l); 	saisie(&e); inserer(&l,e);
	printf("on en supprime 2 et on en ajoute 1 : "); afficherL(&l);
	printf("\t => longueur : %d\n", longueurL(&l));

	viderL(&l);
	printf("contenu apres vidage : "); 		afficherL(&l);
	printf("\t => longueur : %d\n", longueurL(&l));
	
	return 0;
}

/////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
//////////////////////////////
// fonctions calculables
// C. leurs definitions (declarations a la fin)

void viderL(Liste *pl)
{	// aller au debut et tout supprimer (un par un)
	while( !listeVide(*pl))
	{
		printf("%d \t",!listeVide(*pl));
		afficherL(pl);
		supprimer(pl);
	}
}
int  longueurL(Liste *pl)
{	// aller au debut et parcourir l'ensemble
	// apres il faut pour se remettre au bon endroit 
	// 	=> il faut d'abord avoir compte la fin
	//	   pour ensuite repartir du debut et avancer du bon nb de cases
	//int nbFin = 0;
	int nbTotal = 0;
	// 1. ? nbFin
	//nbFin = pl->fin;
	// 2. ? nbotal
	Cellule* celCourant = pl->debut->ptr;
	while ( celCourant != NULL )
	{
		nbTotal++;
		celCourant = celCourant->ptr;
	}
	// 3. se remettre au bon endroit
	allerDebut(pl);

	return nbTotal;
}

void afficherL(Liste *pl)
{	// la aussi il faudra se remettre au bon endroit
	// 	=> nbFin et nbTotal necessaires aussi ici
	Cellule *actuCell = pl->debut;

    while (actuCell != NULL)
    {
        printf("%d -> ", actuCell->val);
		actuCell = actuCell->ptr;
    }
    printf("NULL\n");
}

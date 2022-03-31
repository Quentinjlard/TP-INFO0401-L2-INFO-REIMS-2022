/* Ch Jaillet
 * projet : TDA sequentiels
 * fichier : File_test.c
 * date : 2022/01
 *******************
 */

#include "Element.h"

/* choisissez l'implementation des piles : 
 *		0 pour implem Tab
 *		1 pour implem Ch
 */
#define VERSIONP 1

#if VERSIONP == 0
	#include "PileTab.h"
	typedef PileTab Pile;
#else
	#include "Cellule.h"
	#include "PileCh.h"
	typedef PileCh Pile;	
#endif

///////////////////////////////////////////////////////

/* choisissez l'implementation des files : 
 *		0 pour implem TabC
 *		1 pour implem Ch
 */
#define VERSIONF 1

#if VERSIONF == 0
	#include "FileTabC.h"
	typedef FileTabC FileX;
#else
	#include "Cellule.h"
	#include "FileCh.h"
	typedef FileCh FileX;	
#endif

#include <stdio.h>

//////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
//////////////////////////////
// fonctions calculables
// A. leurs declarations (definitions a la fin)
void viderF(FileX *);
void viderP(Pile *);

void transfererFF(FileX *, FileX *);
void transfererFP(FileX *, Pile *);
void transfererPF(Pile *, FileX *);
void transfererPP(Pile *, Pile *);

// on ne modifie pas officiellement mais on bouge les Element 
//	=> les pointeurs on change de valeur => FileX * en parametre
int  longueurF(FileX *);
int  hauteurP(Pile *);

void afficherF(FileX *);
void afficherP(Pile *);

void inverserF(FileX *);
void inverserP(Pile *);

//////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
//////////////////////////////
// B. le programme de test 
// definitions des fonctions calculables a la fin
int main(void)
{	FileX f; 
	Element e;
	
	creerFile(&f);
	for(int i=0 ; i<10 ; i++)
	{	saisie(&e);
		enfiler(&f, e);
	}

	printf("contenu apres remplissage : "); 	afficherF(&f);

	printf("longueur : %d\n", longueurF(&f));
	printf("contenu avant inversion : "); 	afficherF(&f);
	inverserF(&f);
	printf("contenu apres inversion : "); 	afficherF(&f);
	printf("\t => cette fois ca marche (?)\n");
	
	viderF(&f);
	printf("contenu apres vidage : "); 		afficherF(&f);

	return 0;
}

//////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
//////////////////////////////
// fonctions calculables
// C. leurs definitions (declarations a la fin)

...
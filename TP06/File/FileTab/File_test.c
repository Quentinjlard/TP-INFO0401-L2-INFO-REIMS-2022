/* Ch Jaillet
 * projet : TDA sequentiels
 * fichier : File_test.c
 * date : 2022/01
 *******************
 */

/* choisissez l'implem des files : 
 *		0 pour implem TabC
 *		1 pour implem Ch
 */
#define VERSION 0

#include "Element.h"
#if VERSION == 0
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
void transfererFF(FileX *, FileX *);

// on ne modifie pas officiellement mais on bouge les Element 
//	=> les pointeurs on change de valeur => FileX * en parametre
int  longueurF(FileX *);	
void afficherF(FileX *);

void inverserF(FileX *);

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
	printf("Contenu apres remplissage : \n");
		afficherF(&f);	// le contenu de la structure change : on passe le ptr 

	printf("\n \t Longueur : %d\n", longueurF(&f));
	printf("Contenu avant inversion : \n"); 	afficherF(&f);
	inverserF(&f);
	printf("\nContenu apres inversion : \n"); 	afficherF(&f);
	printf("\t => pas sur que ca marche...\n");
	
	viderF(&f);
	printf("Contenu apres vidage : \n"); 		afficherF(&f);

	return 0;
}

//////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
//////////////////////////////
// fonctions calculables
// C. leurs definitions (declarations a la fin)

void viderF(FileX* f)
{	
	while( ! fileVide(*f) )
	{
		afficherF(f);
		defiler(f);
	}
}

void transfererFF(FileX* f, FileX* ff)
{	
	while( ! fileVide(*f) )
	{
		enfiler(ff,tete(*f));
		defiler(f);
	}
}

int longueurF(FileX* f)
{	
	int nb = 0;
	FileX tmp;
	creerFile(&tmp);

	while( ! fileVide(*f) )
	{
		enfiler(&tmp,tete(*f));
		defiler(f);
		++nb;
	}

	transfererFF(&tmp,f);
	return nb;
}

void afficherF(FileX* f)
{	
	FileX tmp;
	creerFile(&tmp);

	while( ! fileVide(*f) )
	{
		enfiler(&tmp,tete(*f));
		afficher(tete(*f));
		printf(" ");
		defiler(f);
	}
	printf("\n");

	transfererFF(&tmp,f);
}

void inverserF(FileX* f)
{	
	if(f==NULL) 
		return;
	else
	{
		FileX f2;	
		creerFile(&f2);
		transfererFF(f, &f2);
		transfererFF(&f2, f);
	}
}

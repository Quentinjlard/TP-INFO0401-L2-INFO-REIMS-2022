/* Ch Jaillet
 * projet : Listes de recherche
 * fichier : LRprincipal.c
 * date : 2022/03/14
 *******************
 */

#include "LR.h"
#include <stdlib.h>
#include <stdio.h>

//////////////////////
// deux fonctions calculables : affichage et vidage

void afficher(LR x)
{	Element2p * p = x;
	printf("contenu : \t");
	while ( p != NULL )
	{	printf("%d\t", p->cle);
		p = p->succ;
	}
	printf("\n");
}

void vider(LR* px)
{	while( ! LR_vide(*px) )
	{
		afficher(*px);
		LR_supprimer(px, *px);
	}
		
}

//////////////////////
// pour le débuggage
#define dprint
void debug(char* msg)
{	static int XXX = 0;
	XXX++;
#ifdef dprint
	printf("================ [%d] %s \n", XXX, msg);	
#endif
}	

//////////////////////
// Et maintenant ? (tatatata !)

int main(void)
{	LR x;
	Element2p * p;
	LR_creer(&x);
debug("creation");	
	afficher(x);
debug("affichage a vide");	
	LR_inserer(&x, 1);
	afficher(x);
debug("aff apres insertion 1");	
	LR_inserer(&x, 2);
	afficher(x);
debug("aff apres insertion 2");	
	for(int i=3; i<=4 ; i++)
{
		LR_inserer(&x, i);
		afficher(x);
debug("aff apres chacune des 2 nouvelles insertions");	
}
	afficher(x);
debug("aff apres les 4 insertions");	

debug("recherches :");	
	p = LR_rechercher(x, 5); printf("%p\n", p);
	p = LR_rechercher(x, 3); printf("%p\n", p);
	LR_supprimer(&x, p);
	afficher(x);
	
debug("vidage :");	
	vider(&x);
	afficher(x);

debug("fini !");
	return 0;
}
/* Ch Jaillet
 * projet : tables de hachage, par chainage
 * fichier : TH_principal.c
 * date : 2022/03/17
 *******************
 */

#include "TH.h"
#include "LR.h"
#include <stdlib.h>
#include <stdio.h>

//////////////////////
// pour le débuggage
#define dprint
void debug(char* msg)
{	static int XXX = 0;
	XXX++;
#ifdef dprint
	printf("================ [%d] %s\n", XXX, msg);	
#endif
}	

//////////////////////
// deux fonctions calculables : affichage et vidage

void afficher(TH t)
{
	for (int i = 0; i <MAX;i++)
	{
		Element2p* p = t[i];
		printf("contenu : \t");
		while ( p != NULL )
		{	
			printf("%d\t", p->cle);
			p = p->succ;
		}
			printf("\n");
	}	
}

void vider(TH* px)
{	
	for(int i = 0; i <MAX; i++){

		while( ! LR_vide((*px)[i]) )
		{
			LR_supprimer(&((*px)[i]), (*px)[i]);
		}
	}
	
}

//////////////////////
// Et maintenant ? (tatatata !) => GREGORY LEMARCHAL

int main(void)
{	TH x;
	Element2p* p;
	int i;
	TH_creer(&x);
debug("creation OK");	
	afficher(x);
debug("affichage a vide OK");	
	TH_inserer(&x, 5141);
	afficher(x);
debug("aff apres insertion 5141 (OK ?)");	
	TH_inserer(&x, 8520);
	afficher(x);
debug("aff apres insertion 8520 (OK ?)");	
	for(i=3; i<=4 ; i++)
	{
		TH_inserer(&x, 340*i);
		afficher(x);
debug("OK (?) apres chacune des 2 nouvelles insertions");	
	}

debug("\n\n+=====================+\n");
debug("  \n|======RECHERCHE======|\n");
debug("  \n+=====================+\n");
debug("recherche de 0");	
	p = TH_rechercher(x, 0); printf("%p\n", p);
debug("recherche de 1020");	
	p = TH_rechercher(x, 1020); printf("%p\n", p);
debug("suppression de 1020");	
	TH_supprimer(&x, p);
debug("affichage apres suppression de 1020");	
	afficher(x);

debug("ajout de 11 et 41 : ");	
	TH_inserer(&x, 11);
	TH_inserer(&x, 41);
	afficher(x);
	
debug("on vide :");	
	vider(&x);
	afficher(x);

	return 0;
}

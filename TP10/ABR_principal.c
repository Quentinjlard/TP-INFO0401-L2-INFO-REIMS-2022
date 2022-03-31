/* Ch Jaillet
 * projet : arbres binaires de recherche
 * fichier : ABR_principal.c
 * date : 2022/03/18
 *******************
 */
 
#include "ABR.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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

// celle-la n'est utile que pour la suivante
void aff_infixe(ABR x) // infixe = croissant
{	

}

void afficher(ABR x)
{	
	printf("contenu : ");
	aff_infixe(x);
	printf("\n");
}

void vider(ABR* px)
{	
	while( ! ABR_vide(*px) )
	{
		afficher(*px);
		ABR_supprimer(px, *px);
	}
}

//////////////////////
// Et maintenant ? (tatatata !)

int main(void)
{	ABR x;
	Noeud* p;
	int k;
debug("creation");	
	ABR_creer(&x);
debug("affichage a vide");	
	afficher(x);
debug("insertion 3");	
	ABR_inserer(&x, 3);
	afficher(x);
debug("insertion 1");	
	ABR_inserer(&x, 1);
	afficher(x);
debug("2 nouvelles insertions");	
	ABR_inserer(&x, 4);
	ABR_inserer(&x, 2);
	afficher(x);

debug("=== R E C H E R C H E S (1ere partie) : ==================");	
debug("- recherche de 0 (il n'y est pas)");	
	p = ABR_rechercher(x, 0); printf("%p\n", p);
debug("- recherche de 1 (il y est)");	
	p = ABR_rechercher(x, 1); printf("%p => %d\n", p, p->cle);

debug("=== d'autres ajouts pour completer ==================");	
debug("10 nombres entre -20 et 20, qu'on ajoute [ou pas !]");
	srand( time(NULL) );
	printf("ajouts : ");
	for(int i=0 ; i<10; i++)
	{	k = rand()%41 - 20;	
		if ( ABR_rechercher(x,k) != NULL ) 
			// il y est deja : ne pas inserer
			printf("[%d] ",k);
		else	// inserer
		{	printf("%d ",k);
			ABR_inserer(&x, k);
		}
	}
	printf("\n");
	afficher(x);

debug("suppression de 1 (qui y est et qui a au moins un fils)");	
	p = ABR_rechercher(x, 1);
	ABR_supprimer(&x, p);
	afficher(x);

debug("=== R E C H E R C H E S (2eme partie) : ==================");	
debug("- minimum et maximum => leurs cles");
	p = ABR_minimum(x); printf("min %d", p->cle);
	printf(" ; max %d\n", ABR_maximum(x)->cle);
	
debug("- 1er, 3eme, 2eme (minimum, successeur x 2, predecesseur => leurs cles");	
	p = ABR_minimum(x); printf("%d", p->cle);
	p = ABR_successeur(p); p = ABR_successeur(p); 	printf(" ; %d", p->cle);
	p = ABR_predecesseur(p);						printf(" ; %d\n", p->cle);

debug("=== S U P P R E S S I O N S  (a priori tous les cas) ==================");	
debug("- j'en supprime 5 (entre -20 et 24)");	
	for(int i=0 ; i<5 ; i++)
	{	k = rand()%45 -20;	p = ABR_rechercher(x,k);
		while ( p == NULL )
		{	printf("\t %d : non\n", k);
			k = rand()%45 -20;	p = ABR_rechercher(x,k);
		}
		printf("\t %d : oui => ", k);
		ABR_supprimer(&x, p);	
		afficher(x);
	}
	
debug("on vide :");	
	vider(&x);
	afficher(x);

debug(" F I N I !!!");	
	return 0;
}

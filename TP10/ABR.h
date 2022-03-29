/* Ch Jaillet
 * projet : arbres binaires de recherche
 * fichier : ABR.h
 * date : 2022/03/18
 *******************
 */
 
#ifndef __ABR_H__
#define __ABR_H__

typedef struct noeud_ds
{	
    Noeud *pere, *droite, *gauche;
    int cle;
} Noeud;

typedef Noeud* ABR;	

/*********************************/
// ... parametres : cf LR.h
// et pensez aux étoiles !!

void ABR_creer(ABR*);
int  ABR_vide (ABR);

Noeud* ABR_rechercher(ABR,int);	// renvoient une position
Noeud* ABR_minimum   (ABR);
Noeud* ABR_maximum   (ABR);
Noeud* ABR_predecesseur( Noeud* );	// il est enracine
Noeud* ABR_successeur  ( Noeud* );

void ABR_inserer  (ABR*, int);
void ABR_supprimer(ABR*, Noeud*);

#endif

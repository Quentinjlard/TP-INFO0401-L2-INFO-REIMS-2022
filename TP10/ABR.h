/* Ch Jaillet
 * projet : arbres binaires de recherche
 * fichier : ABR.h
 * date : 2022/03/18
 *******************
 */
 
#ifndef __ABR_H__
#define __ABR_H__

typedef struct 
{	...
} Noeud;

typedef Noeud* ABR;	

/*********************************/
// ... parametres : cf LR.h
// et pensez aux étoiles !!

void ABR_creer(...);
int  ABR_vide (...);

Noeud* ABR_rechercher(...);	// renvoient une position
Noeud* ABR_minimum   (...);
Noeud* ABR_maximum   (...);
Noeud* ABR_predecesseur( ... );	// il est enracine
Noeud* ABR_successeur  ( ... );

void ABR_inserer  (...);
void ABR_supprimer(...);

#endif

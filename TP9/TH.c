/**
 * @file TH.c
 * @author JUILLIARD Quentin
 * @brief 
 * @version 0.1
 * @date 2022-03-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "TH.h"
#include "LR.h"

#include <stdio.h>
#include <stdlib.h>

int hachage(int cle)
{
	return cle%MAX;
}

void TH_creer(TH* pth)
{
	// LR_creer pour chacune des LR : t[0], ...
    // mais  th est en fait *pth ...
    // donc c'est (*pth)[i] auquel il faut affecter NULL
    // ou LR_creer ( &( (*pth)[i] ) );
    // bien sûr, on fait ça dans une boucle for
	for(int i=0; i<MAX; i++)
	{
		(*pth)[i] = NULL;
	}
}

int TH_vide(TH t)
{
	int i=0;

	while ( i<MAX && t[i] == NULL )
		i++;
	
	return (i == MAX); // elle est vide si on ne s'est pas arrêtés avant
}

Element2p* TH_rechercher(TH t, int k)
{
	int indice = hachage(k);
    return LR_rechercher( t[indice] , k);

}

void TH_inserer(TH *t, int k)
{

	int indice = hachage(k);
	LR_inserer( &((*t)[indice]) , k);
}

void TH_supprimer(TH *t,Element2p* p)
{

	if(p == NULL)
	{
		return;
	}
	else
	{
		int indice = hachage(p->cle);
		LR_supprimer(&((*t)[indice]),p);
	}
	

}
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
	int max = MAX-1;
	return cle%max;
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

Element2p* TH_rechercher(TH t, int cle)
{
	int indice = hachage(cle);
    return LR_rechercher( t[indice] , cle);

	// int i = 0;
	// int j;
	// do
	// {
	// 	j = hachage(cle);
	// 	if(x[j] != NULL)
	// 	{
	// 		Element2p* pos = *x;
	// 		while ( pos != NULL && pos->cle != cle )
	// 			pos = pos->succ;
	// 		return pos;
	// 	}
	// 	else
	// 	{
	// 		i++;
	// 	}
	// } while (x[j] == NULL || i == MAX);
	// return NULL;
}

void TH_inserer(TH *t, int cle)
{
	int indice = LR_rechercher( t , cle);
	LR_inserer(t, cle);
	// int i = 0;
	// int j;
	// do
	// {
	// 	j = hachage(cle);
	// 	if(x[j] != NULL)
	// 	{
	// 		Element2p* pelem;
	// 		pelem=(Element2p*)malloc(sizeof(Element2p));
	// 		*x[j] = pelem->prec;
	// 		pelem->cle=cle;
	// 		pelem->succ = NULL;
			
	// 	}
	// 	else 
	// 	{
	// 		if(x[j] == NULL)
	// 		{
	// 			Element2p* pelem;
	// 			pelem=(Element2p*)malloc(sizeof(Element2p));
	// 			pelem->prec=NULL;
	// 			pelem->cle=cle;
	// 			pelem->succ = NULL;
	// 		}
	// 		else
	// 		{
	// 			i++;
	// 		}
	// 	}
	// } while (i == MAX);
}

void TH_supprimer(TH *t,Element2p* p)
{
	int cle;
	if(p->cle == NULL)
	{
		return;
	}
	else
	{
		cle = p->cle;
	}
	LR_supprimer(*t,cle);

}
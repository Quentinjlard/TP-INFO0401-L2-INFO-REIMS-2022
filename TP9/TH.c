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
	return 1+ cle%MAX;
}

void TH_creer(TH* th)
{
	LR *px = NULL;
	for(int i=0; i<MAX; i++)
	{
		*th[i] = *px;
	}
}

int TH_vide(TH x)
{
	int caseVide = 0;
	for(int i=0; i<MAX; i++)
	{
		x[i] == NULL ? caseVide  : caseVide++; 
	}

	return (caseVide==10);
}

Element2p* TH_rechercher(TH x, int cle)
{
	int i = 0;
	int j;
	do
	{
		j = hachage(cle);
		if(x[j] != NULL)
		{
			Element2p* pos = *x;
			while ( pos != NULL && pos->cle != cle )
				pos = pos->succ;
			return pos;
		}
		else
		{
			i++;
		}
	} while (x[j] == NULL || i == MAX);
	return NULL;
}

void TH_inserer(TH *x, int cle)
{
	int i = 0;
	int j;
	do
	{
		j = hachage(cle);
		if(x[j] != NULL)
		{
			Element2p* pelem;
			pelem=(Element2p*)malloc(sizeof(Element2p));
			*x[j] = pelem->prec;
			pelem->cle=cle;
			pelem->succ = NULL;
			
		}
		else 
		{
			if(x[j] == NULL)
			{
				Element2p* pelem;
				pelem=(Element2p*)malloc(sizeof(Element2p));
				pelem->prec=NULL;
				pelem->cle=cle;
				pelem->succ = NULL;
			}
			else
			{
				i++;
			}
		}
	} while (i == MAX);
}

void TH_supprimer(TH *x,Element2p* p)
{
}
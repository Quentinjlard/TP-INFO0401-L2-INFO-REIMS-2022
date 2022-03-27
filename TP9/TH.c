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

#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

void TH_creer(TH* px)
{
    TH* tableHachage[MAX];

    for (int i = 0; i < MAX; i)
    {
        TH elem2p = NULL;
        tableHachage[i] = elem2p;
    }
}


int TH_vide(TH x)
{
    return (x == NULL);
}

Element2p* TH_rechercher(TH x, int cle)
{
    Element2p* pos = x;
	while ( pos != NULL && pos->cle != cle )
		pos = pos->succ;
	return pos;
}

void TH_inserer(TH *x, int cle)
{
    int k = cle;
    int i = 0;
    do
    {
        if (x[i] == NULL)
        {
            x[i] = cle;
            return x;
        }
        else
        {
            i ++;
        }
    } while (i = MAX);
    printf("Plus de place"); 
}

void TH_supprimer(TH *x,Element2p* p)
{
    if (p == NULL)
		return;

    Element2p* e = p ;

    if(p->succ != NULL) //il y a qqn a D
	{
		e = p->succ;	// son pred est le mien
	}  

    // liberation memoire
	free(p);
}
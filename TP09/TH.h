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

#ifndef __TH_H__
#define __TH_H__

#define MAX 10
#include "LR.h"

typedef LR TH[MAX];

void TH_creer(TH*);

void TH_inserer(TH*, int);

void TH_supprimer(TH*,Element2p*);

Element2p* TH_rechercher(TH,int);

int TH_vide(TH);

#endif
/**
 * @file Element.c
 * @author JUILLIARD Quentin (quentin.juilliard@etudiant.univ-reims.fr)
 * @brief 
 * @version1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Element.h"

#include <stdio.h>
#include <stdlib.h>

void saisie(Element* element)
{
    printf("Saisir un element : ");
    scanf("%d", element);
}

void affichage(Element element)
{
    printf("%d ",element);
}
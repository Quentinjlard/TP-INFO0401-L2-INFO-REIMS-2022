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
    printf("%d",element);
}
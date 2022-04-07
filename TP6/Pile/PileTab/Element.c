#include "Element.h"
#include <stdio.h>

Element saisie(Element *element)
{
    printf("Saisir un element : ");
    scanf("%d", element);

    return *element;
}

void afficher(Element element)
{
    printf("|  %d  |\n",element);
}
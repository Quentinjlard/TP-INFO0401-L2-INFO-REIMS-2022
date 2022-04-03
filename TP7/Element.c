#include "Element.h"
#include <stdio.h>
#include <stdlib.h>

Element saisie(Element* element)
{
    printf("Saisir un element : ");
    scanf("%d", element);

    return *element;
}

void Affichage(Element element)
{
    printf("%d",element);
}
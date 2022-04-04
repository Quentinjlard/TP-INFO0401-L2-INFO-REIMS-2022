#include "Element.h"
#include <stdlib.h>
#include <stdio.h>

Element SaisirElement(Element element)
{
    printf("Saisir un element");
    scanf("%d", &element);

    return element;
}

void Affichage(Element element)
{
    printf("%d",element);
}
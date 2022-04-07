#include "Element.h"
#include <stdlib.h>
#include <stdio.h>

void saisie(Element* element)
{
    printf("Saisir un element");
    scanf("%d", element);
}

void afficher(Element element)
{
    printf("%d",element);
}
#include "polyn.h"
#include <stdlib.h>

int main(void)
{
    Polynome Poly1;
    Polynome Poly2;
    Polynome Poly3;

    int degres;

    Poly1.degres = SaisirDegres();
    Poly1.coeff = (int*)malloc((Poly1.degres+1)*sizeof(int));
    if(Poly1.coeff == NULL){
        printf("Probléme d'allocution \n");
        exit(0);
    }

    SaisirCoeff(Poly1);

    Affiche(Poly1);

    printf("\n Evaluation : \n %d", Evaluation(Poly1, -12.7));

    Poly2.degres = SaisirDegres();
    Poly2.coeff = (int*)malloc((Poly2.degres+1)*sizeof(int));
    if(Poly2.coeff == NULL){
        printf("Probléme d'allocution \n");
        exit(0);
    }

    if(Poly1.degres < Poly2.degres){
        degres = Poly2.degres;
    }else{
        degres = Poly1.degres;
    }

    Poly3.coeff = (int*)malloc((degres+1)*sizeof(int));
    if(Poly3.coeff == NULL){
        printf("Probléme d'allocution \n");
        exit(0);
    }

    if(Poly1.degres < Poly2.degres){
        Poly3 = Sommes1(Poly1, Poly2);
        Affiche(Poly3);
    }else{
        Poly3 = Sommes1(Poly2, Poly1);
        Affiche(Poly3);
    }

    Affiche(Poly3);

    if(Poly1.degres < Poly2.degres){
        Affiche(Produit2(Poly1, Poly2, Poly3));
    }else{
        Affiche(Produit2(Poly2, Poly1, Poly3));
    }
 
    return 0;
}
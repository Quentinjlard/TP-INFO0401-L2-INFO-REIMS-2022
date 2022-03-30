#include "polyn.h"
#include <stdlib.h>

int SaisirDegres()
{
    int degres;
    printf("Merci de saisir de le degres : ");
    scanf("%d",&degres);

    return degres;
}

void SaisirCoeff(Polynome P)
{
    for(int i = 0; i <= P.degres; i++){
        printf("Saisir Valeur : ");
        scanf("%d",&P.coeff[i]);
    }
}

int Affichage(Polynome P){

    int* CoeffMax = P.degres;
    for(int i = 0; i < P.degres; i++){
        if(P.degres != 0){
            printf("%dx%d ",P.coeff[i],P.degres[CoeffMax]);
        }
        else
        {
            printf("%d ",P.coeff[i]);
        }
        printf(" + ");
        CoeffMax = CoeffMax -1;
    }
}

int Evaluation(Polynome P, double coeff){

    int resultat;
    for(int i = 0; i < P.degres+1; i++){
        resultat += P.coeff[i]*pow(coeff,i);
    }

    return resultat;
}

Polynome Sommes1(Polynome Poly1, Polynome Poly2){

    Polynome Poly3;
    int degres=0;
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

    for(int i = 0; i < Poly1.degres+1; i++){
        Poly3.coeff[i] += Poly1.coeff[i] + Poly2.coeff[i]; 
    }

    return Poly3;
}

void Sommes2(Polynome Poly1, Polynome Poly2,Polynome Poly3){

    for(int i = 0; i < Poly1.degres+1; i++){
        Poly3.coeff[i] += Poly1.coeff[i] + Poly2.coeff[i]; 
    }

    Affichage(Poly3);
}

Polynome Produit2(Polynome Poly1, Polynome Poly2, Polynome Poly3){

    for(int i = 0; i < Poly1.degres+1; i++){
        Poly3.coeff[i] += Poly1.coeff[i] * Poly2.coeff[i]; 
    }

    return Poly3;
}
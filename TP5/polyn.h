#ifndef __POLYN__H__
#define __POLYN__H__

typedef int* Poly;

typedef struct Polynome{
    int degres;
    Poly coeff;
}Polynome;

//Saisie
int SaisirDegres();
void SaisirCoeff();

//Affiche 
int Affichage(Polynome P);

//Evaluation
int Evaluation(Polynome P, int ok);

//Sommes
Polynome Sommes1(Polynome Poly1, Polynome Poly2);
void Sommes2(Polynome Poly1, Polynome Poly2, Polynome Poly3);

//Produit 
Polynome Produit2(Polynome Poly1, Polynome Poly2, Polynome Poly3);


#endif

/**
 *  METHODE 
 * 
 *  void saisir(polyn);
 *  void affichage(polyn);
 *  double evaluation(polyn, double);
 *  polyn add1 (polyn, polyn);
 *  void add2 (polyn, polyn, polyn)
 *  polyn prod (polyn, polyn);
 * 
 */
#include "ABR.h"
#include <stdio.h>
#include <stdlib.h>

void ABR_creer(ABR *arbreBinaireRecherche){
	*arbreBinaireRecherche=NULL;
}
int ABR_vide(ABR arbreBinaireRecherche){
	return(arbreBinaireRecherche==NULL);
}
// routine (interne)
Noeud* nouveau_noeud(int cle){
	Noeud* tmp;	
	tmp=(Noeud*)malloc(sizeof(Noeud));
	tmp->cle=cle;
	tmp->gauche=NULL;
	tmp->droite=NULL;
	tmp->pere=NULL;
	return tmp;
}
void ABR_inserer(ABR *arbreBinaireRecherche,int cle){
	Noeud *tmp;
	if(*arbreBinaireRecherche==NULL){
		*arbreBinaireRecherche=nouveau_noeud(cle);
	}else{
		//premier cas : la cle a place est plus petite que la cle de l'element que je regarde --> place a gauche
		if((*arbreBinaireRecherche)->cle>cle){
			//le noeud possede un fils gauche, je me compare a lui
			if((*arbreBinaireRecherche)->gauche!=NULL){
				ABR_inserer(&(*arbreBinaireRecherche)->gauche,cle);
			}else{
			//le noeud ne possede pas de fils gauche, je le créé
				tmp=nouveau_noeud(cle);
				tmp->pere=*arbreBinaireRecherche;
				(*arbreBinaireRecherche)->gauche=tmp;
			}
		}else if((*arbreBinaireRecherche)->cle==cle){
			return;
		//deuxieme cas : la cle a place est plus grande que la cle de l'element que je regarde --> place a droite
		}else{
			//le noeud possede un fils droit, je me compare a lui
			if((*arbreBinaireRecherche)->droite!=NULL){
				ABR_inserer(&(*arbreBinaireRecherche)->droite,cle);
			}else{
			//le noeud ne possede pas de fils droit, je le créé
				tmp=nouveau_noeud(cle);
				tmp->pere=*arbreBinaireRecherche;
				(*arbreBinaireRecherche)->droite=tmp;
			}
		}
	}
}
Noeud* ABR_rechercher(ABR arbreBinaireRecherche,int cle){
	Noeud *tmp=arbreBinaireRecherche;
	while(tmp!=NULL && tmp->cle!=cle){
		if(tmp->cle>cle){
			tmp=tmp->gauche;
		}else{
			tmp=tmp->droite;
		}
	}
	return tmp;
}
//Pour la suppression, on donne la position de l'élément à supprimer, obtenu via une recherche : on ne refait pas une recherche
void ABR_supprimer(ABR *arbreBinaireRecherche,Noeud *elementASupprimer){
	Noeud *tmp;
	int cleSucc;
	if(!ABR_vide(*arbreBinaireRecherche)){
		if(elementASupprimer==NULL){
			return;
		}else{
			if(elementASupprimer->droite==NULL && elementASupprimer->gauche==NULL){
				//c'est une feuille, on peut supprimer sans problème à condition que ce ne soit pas la racine
				tmp=elementASupprimer->pere;
				//on regarde si je suis le fils droit ou le fils gauche de mon pere
				if(tmp!=NULL){
					if(tmp->droite==elementASupprimer)
						tmp->droite=NULL;
					else
						tmp->gauche=NULL;
				}else{
					//je suis la racine sans fils
					*arbreBinaireRecherche=NULL;//très important !
				}
				free(elementASupprimer);
				elementASupprimer=NULL;
			}else if(elementASupprimer->droite==NULL && elementASupprimer->gauche!=NULL){
				//j'ai un fils gauche pas de fils droit
				tmp=elementASupprimer->gauche;
				if(elementASupprimer->pere!=NULL){
					tmp->pere=elementASupprimer->pere;//raccordement fils->pere
					//le raccordement grand pere -> fils dépend du lien grand père -> père
					if(elementASupprimer->pere->gauche==elementASupprimer)//mon pere était le fils gauche de mon grand pere, donc je serais son fils gauche aussi
						tmp->pere->gauche=tmp;//raccordement grand pere->fils
					else//mon pere était le fils gauche de mon grand pere, donc je serais son fils droit aussi
						tmp->pere->droite=tmp;
				}else{
					//je n'ai pas de pere, donc je suis la racine
					*arbreBinaireRecherche=tmp;
					tmp->pere=NULL;
				}
				free(elementASupprimer);
				elementASupprimer=NULL;
			}else if(elementASupprimer->droite!=NULL && elementASupprimer->gauche==NULL){
				//j'ai un fils droit pas de fils gauche
				tmp=elementASupprimer->droite;
				if(elementASupprimer->pere!=NULL){
					tmp->pere=elementASupprimer->pere;//raccordement fils->pere
					if(elementASupprimer->pere->gauche==elementASupprimer)//mon pere était le fils gauche de mon grand pere, donc je serais son fils gauche aussi
						tmp->pere->gauche=tmp;//raccordement grand pere->fils
					else//mon pere était le fils gauche de mon grand pere, donc je serais son fils droit aussi
						tmp->pere->droite=tmp;
				}else{
					//je n'ai pas de pere, donc je suis la racine
					*arbreBinaireRecherche=tmp;
					tmp->pere=NULL;
				}
				free(elementASupprimer);
				elementASupprimer=NULL;
			}else{
				//j'ai deux fils, je vais être remplacé par le successeur
				tmp=ABR_successeur(elementASupprimer);
				cleSucc=tmp->cle;
				elementASupprimer->cle=cleSucc;
				ABR_supprimer(&(*arbreBinaireRecherche),tmp);
			}
		}
	}
}
Noeud* ABR_minimum(ABR arbreBinaireRecherche){
	Noeud *tmp=arbreBinaireRecherche;
	if(tmp!=NULL){
		while(tmp->gauche!=NULL){
			tmp=tmp->gauche;
		}
	}
	return tmp;
}
Noeud* ABR_maximum(ABR arbreBinaireRecherche){
	Noeud *tmp=arbreBinaireRecherche;
	if(tmp!=NULL){
		while(tmp->droite!=NULL){
			tmp=tmp->droite;
		}
	}
	return tmp;
}
Noeud* ABR_successeur(Noeud* elementASucceder){
	Noeud *tmp=elementASucceder;
	if(tmp==NULL){
		return tmp;
	}else if(tmp->droite!=NULL){
			return ABR_minimum(tmp->droite);
	}else{
		while(tmp->pere!=NULL && tmp->pere->droite==tmp){
			tmp=tmp->pere;
		}
		return tmp->pere;
	}
}
Noeud* ABR_predecesseur(Noeud* elementAPreceder){
	Noeud *tmp=elementAPreceder;
	if(tmp==NULL){
		return tmp;
	}else if(tmp->gauche!=NULL){
		return ABR_maximum(tmp->gauche);
	}else{
		while(tmp->pere!=NULL && tmp->pere->gauche==tmp){
			tmp=tmp->pere;
		}
		return tmp->pere;
	}
}

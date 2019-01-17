/*
 * proposition.h
 *
 *  Created on: 22 déc. 2018
 *      Author: Uriel Vido
 */

//#ifndef PROPOSITION_H_
#define PROPOSITION_H_

/**
 * \brief Structure de Proposition et initialisation
 */
typedef struct{
	char nom;
	int boolean; //valeur= 0 ou 1
} proposition;

proposition creeProposition(char nom){
	proposition p;
	p.nom=nom;
	p.boolean=0; //valeur par défault
	return p;
}

void valider(proposition *p)
{
	p->boolean = 1;	
}

//#endif /* PROPOSITION_H_ */

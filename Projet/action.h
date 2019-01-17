/*
 * action.h
 *
 *  Created on: 22 déc. 2018
 *      Author: Uriel Vido
 */

//#ifndef ACTION_H_
//#define ACTION_H_

/**
 * \brief Structure de tâches et initialisation
 */
typedef struct{
	char *nom;
	proposition preCond[TAILLE_MAX];
	int nbPreCond;
	proposition postCond[TAILLE_MAX];
	int nbPostCond;
}action;

action creeAction(char *nom){
	action a;
	a.nom=nom;
	a.nbPreCond = 0;
	a.nbPostCond = 0;
	
	return a;
}

void ajoutPreCond(action *a, proposition p)
{
	(*a).preCond[(*a).nbPreCond] = p;
	(*a).nbPreCond++;
}

void ajoutPostCond(action *a, proposition p)
{
	(*a).postCond[(*a).nbPostCond] = p;
	(*a).nbPostCond++;
}

/**
* Vérifie que toutes les precond sont validées
* return 1 si elles sont toutes validées et 0 sinon
*//*
int verifConditions(action a)
{
	int i;
	for(i=0; i<a.nbPreCond; i++)
	{
		if(precCond[i].boolean == 0)
			return 0;
	}
	
	return 1;
}*/

/**
* Valide les postCond d'une action
*//*
void validerPostConditions(action a)
{
	int i;
	for(i=0; i<a.nbPostCond; i++)
	{
		postCond[i].boolean = 1;
	}
}*/

/**
	Retourne les preCond et les postCond (Le résultat après l'action)
*//*
Action *ResultatAction(action a)
{
	if(verifConditions(a) == 1)
	{
		validerPostConditions(a);
		//contient l'ensemble des preCond et des postCond
		int nbProp = (a->nbPreCond) + (a->nbPostCond);
		proposition *tab[nbProp];
		//i parcours tab j parcours PreCond et PostCond
		int i=0, j=0;
		//Récupère les preCond
		while(i<nbPreCond)
		{
			tab[i] = a->preCond[j];
			i++;
			j++;
		}
		
		//Récupère les postCond
		j=0;
		while(i<nbPreCond)
		{
			tab[i] = a->postCond[j];
			i++;
			j++;
		}
		
		return tab;
	}	
}
*/
//#endif /* ACTION_H_ */

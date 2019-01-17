#define TAILLE_MAX 100
#include <stdio.h>
#include <stdlib.h>
#include "proposition.h"
#include "action.h"
#include "mallocFree.h"
#include <string.h>
#include "lectureFichier.h"


int main()
{
	char *tabDebut, *tabFin, *tabTout, *tabAct, *tabPre, *tabPost;

	int i, j;
	tabDebut = malloc(10*sizeof(int)); //recuperer les proposition pour tracer le graphe..
	tabFin = malloc(10*sizeof(int)); 
	tabTout = malloc(10*sizeof(int)); 
	tabPre = malloc(10*sizeof(int));
	tabPost = malloc(10*sizeof(int));
	tabAct = malloc(10*sizeof(int));

	lireFichier("fichierTexte.txt", tabDebut, tabFin, tabTout, tabPre, tabPost);

	for(i = 0; i < strlen(tabPre); i++){
	 		printf("prop dans tabPre : %c \n", tabPre[i]);
	 	}

	for(i = 0; i < strlen(tabPost); i++){
		 		printf("prop dans tabPost : %c \n", tabPost[i]);
		 	}

	node *e1 = malloc_wrapper(sizeof(node));

	(*e1).value = tabDebut;

	int indmin, indmax, l, cptTabPost = 0;
	i = 0;

	//tabDebut[strlen(tabDebut)] = 'a';
	//tabDebut[strlen(tabDebut)] = 'y';
	int cpt, c,size = strlen(tabDebut), m;

	do{

	while(i < strlen(tabPre)-1){
		if(tabPre[i] == '!')
			indmin = i+1;

		for(j = indmin; j < strlen(tabPre); j++){
			if(tabPre[j] == '!'){
				indmax = j-1;
				i = indmax;
				break;
			}
		}
		i++;


		int result = 0;
		for(l = indmin; l <= indmax; l++){
			for(cpt = 0; cpt < size; cpt++){
					if(tabDebut[cpt] == tabPre[l]){
						result = result + 1;
					}
				}
		}

		//printf("diff ind : %d \n", indmin - indmax);
		if(result > indmax - indmin){
			tabDebut[strlen(tabDebut)] = tabPost[cptTabPost];
			printf("Numero Action : %d \n", cptTabPost);
			//sprintf(tabResult, "%d", cptTabPost),
					//tabResult[strlen(tabResult)] = cptTabPost;
			cptTabPost = cptTabPost + 2;
			//printf("tabPost : %c \n", tabPost[cptTabPost]);
		}

	}

	for(i = 0; i < strlen(tabDebut); i++){
		//printf("prop dans tabDebut : %c \n", tabDebut[i]);
		//printf("prop dans tabFin : %c \n", tabFin[i]);
		//printf("prop dans tabTOUT : %c \n", tabTout[i]);
	}

	}
	while(strlen(tabDebut) != strlen(tabTout));

	free_wrapper(e1);

	return 0;
}



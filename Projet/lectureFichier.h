//Prend en paramètre la liste de propositions, le nombre de propositions contenues dans la liste et le nom de la propositon recherchée
//Retourne la proposition que l'on cherche si elle se trouve dans la liste

char afficheProposition(proposition p)
{
	printf("Prop : %c boolean %d\n", p.nom, p.boolean);
	return p.nom;
}

void afficheAction(action a, char *tabPre, char *tabPost)
{
	printf("\nAction %s \n", a.nom);

	printf("PreCond : \n");
	int i, j;
	
	for(i=0; i<a.nbPreCond; i++){
		afficheProposition(a.preCond[i]);
		tabPre[strlen(tabPre)] = a.preCond[i].nom;
	}
	tabPre[strlen(tabPre)] = '!';

	printf("\nPostCond : \n");
	for(i=0; i<a.nbPostCond; i++){
		afficheProposition(a.postCond[i]);
		tabPost[strlen(tabPost)] = a.postCond[i].nom;
	}
	tabPost[strlen(tabPost)] = '!';

	printf("\n");
	
}

void lireFichier(char *nomFichier, char *tabDebut, char *tabFin, char *tabTout, char *tabPre, char *tabPost)
{
	FILE * fichier = NULL;
	char ligne[TAILLE_MAX];	//contiendra les lignes du fichier
	fichier = fopen(nomFichier, "r");
	int i, j, k;
	//action act;
	proposition p;
	char *nomAction;	//contiendra le nom des actions
	proposition listeProposition[TAILLE_MAX];	//Contiendra toutes les propositions
	int nbProp = 0; //Nombre de propositions dans le tableau listeProposition
	proposition propDebut[TAILLE_MAX]; //Contiendra la liste des propositions au début
	int nbPropDebut;
	proposition propFin[TAILLE_MAX]; //Contiendra la liste des propositions à la fin
	int nbPropFin;
	action tabAction[TAILLE_MAX];
	int nbActions = 0;
	
	
	if(fichier != NULL)	//Si le fichier a bien été chargé
	{
		while(fgets(ligne, TAILLE_MAX, fichier) != NULL)	//Lis chaque ligne du fichier
		{
			if(strncmp(ligne, "actions", 7) == 0)	//On va lire des actions (si la ligne contient le mot actions)
			{
				fgets(ligne, TAILLE_MAX, fichier);	//On lit la ligne suivante
				if(ligne != NULL)
				{
					nomAction = malloc(sizeof(strlen(ligne))-2);	//Tableau qui va contenir le nom de l'action //-2 pour ne pas prendre # et retour à la ligne
					while(ligne[0] == '#')//Tant qu'on déclare nom d'une action
					{
						j=0; //parcourt nomAction pour récupérer chaque caractère
						for(i=1; i<strlen(ligne)-1; i++)	//le nom de l'action -1 pour ne pas prendre le retour à la ligne
						{	
							nomAction[j] = ligne[i];	//met chaque caractère du fichier dans la chaine de caractère nomAction
							j++;
						}
					
						tabAction[nbActions] = creeAction(nomAction);	//Crée l'action avec son nom
						
						fgets(ligne, TAILLE_MAX, fichier);	//On passe la ligne des preCon
						
						for(i=0; i< strlen(ligne); i++)	//On lit chaque preCondition
						{
							if(ligne[i] != ' ')
							{
								for(k=0; k<nbProp; k++)
								{
									if(listeProposition[k].nom == ligne[i])
										ajoutPreCond(&tabAction[nbActions], listeProposition[k]);	//On l'ajoute aux preConditions de l'action
								}
							}
						}
					
						fgets(ligne, TAILLE_MAX, fichier);	//On lit la ligne suivante
				
						for(i=0; i< strlen(ligne); i++)	//On lit chaque postCondition
						{
							if(ligne[i] != ' ')
							{
								for(k=0; k<nbProp; k++)
								{
									if(listeProposition[k].nom == ligne[i])
										ajoutPostCond(&tabAction[nbActions], listeProposition[k]);	//On l'ajoute aux postConditions de l'action
								}
							}
						}
						
						nbActions++;
						fgets(ligne, TAILLE_MAX, fichier);	//On lit la ligne suivante
					}

				}
				
			}
			
			if(strncmp(ligne, "props", 5) == 0)	//On va lire des props
			{
				fgets(ligne, TAILLE_MAX, fichier);	//On lit la ligne suivante
				
				if(ligne != NULL)
				{
					
					for(i=0; i< strlen(ligne); i++)	//On lit chaque props
					{
						if(ligne[i] != ' ' && ligne[i] != '\n'){
							p = creeProposition(ligne[i]);	// On crée la prop
							listeProposition[nbProp] = p;	//On la met dans le tableau des propositions
							nbProp++;
						 } 
					}
				}
			}
			
			if(strncmp(ligne, "debut", 5) == 0)	//On va lire les props du début
			{
				fgets(ligne, TAILLE_MAX, fichier);	//On lit la ligne suivante
				
				if(ligne != NULL)
				{
					j=0;
					for(i=0; i< strlen(ligne); i++)	//On lit chaque prop debut
					{
						if(ligne[i] != ' ' && ligne[i] != '\n')
						{
							for(k=0; k<nbProp; k++)
							{
								if(listeProposition[k].nom == ligne[i])
								{
									valider(&(listeProposition[k]));
									propDebut[j] = listeProposition[k];
									j++;
								}
							}
						}
						
					}
					
					nbPropDebut = j;	
				}	
			}
			
			if(strncmp(ligne, "fin", 3) == 0)	//On va lire les props de la fin
			{
				fgets(ligne, TAILLE_MAX, fichier);	//On lit la ligne suivante
				
				if(ligne != NULL)
				{
					j=0;
					for(i=0; i < strlen(ligne); i++)	//On lit chaque prop fin
					{
						if(ligne[i] != ' ' && ligne[i] != '\n')
						{
							for(k=0; k<nbProp; k++)
							{
								if(listeProposition[k].nom == ligne[i])
								{
									propFin[j] = listeProposition[k];
									j++;
								}
							}
						}
					}
					
					nbPropFin = j;
				}	
			}
		}	
	}
	
	printf("\n\nPropFin : \n");
	for(i=0; i<nbPropFin; i++)
		tabFin[i] = afficheProposition(propFin[i]);
		
	printf("\n\nPropDebut : \n");
	for(i=0; i<nbPropDebut; i++)
		tabDebut[i] = afficheProposition(propDebut[i]);
		

	printf("\n\nToutes les propositions : \n");
	for(i=0; i<nbProp; i++)
	{
		tabTout[i] = afficheProposition(listeProposition[i]);
	}


	for(i=0; i<nbActions; i++){
		afficheAction(tabAction[i], tabPre, tabPost);
	}
	
	free(nomAction);
	fclose(fichier);
}
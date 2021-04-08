////////////////////////// TP10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prod.h"
#include "lireCommande.h"
#include "lireProduits.h"
#include "genererFacture.h"

int lireProchaineCommande() //pour lire l'int contenu dans nextFact
{
FILE *f;
int N;
f=fopen("nextFact","r");
fread(&N,sizeof(int),1,f);
fclose(f);
//printf("\n--->lu N=%d",N);
return N;
}

void convertirNenChaine4(int N,char *N4) //convertit l'int N en une chaine de 4 caracteres
{ // si N=1234 alors N4 sera égal à "1234"
int m,c,d,u;
char cm,cc,cd,cu;
m=N/1000;cm=48+m;
N%=1000;
c=N/100;cc=48+c;
N%=100;
d=N/10;cd=48+d;
u=N%10;
cu=48+u;
N4[0]=cm;N4[1]=cc;N4[2]=cd;N4[3]=cu;N4[4]='\0';
}


void lireLesCommandes() //cette fonction ouvre tous les fichiers commandeXXX.txt avec XXXX démarrant à N
{
FILE *ficCommande=NULL;
T_TableauDeProduits listeProduits; // Liste des produits
T_TableauDeProduits listeCommande; // Liste commande par les utilisateurs
int FINI=0;
int tailleListe;
int N = lireProchaineCommande(); //numero de la premiere commande qui sera lue et traitee
char NNNN[5];
char nomCommande[29];
char nomClient[TAILLE];
int quantite[TAILLE];
tailleListe = lireProduits(listeProduits);
int nbElt;
	do //ce do while prend fin dès que fichier commandeXXXX.txt est absent 
		{
		strcpy(nomCommande,"./commandes/commande");
		convertirNenChaine4(N,NNNN); 
		//printf("\n==>%s<==",NNNN);
		ficCommande=NULL;
		strcat(nomCommande,NNNN);
		strcat(nomCommande,".txt");
		
		printf("\n traitement de  %s\n",nomCommande);
		
		ficCommande=fopen(nomCommande,"rt");
		if (ficCommande!=NULL)
			{ // le fichier commandeNNNN.txt existe
				printf("\n fichier %s present\n",nomCommande);
				nbElt = lireCommande(nomCommande, listeProduits, &tailleListe, nomClient, listeCommande, quantite); // à vous de coder cette fonction lors de ce TP9
				fclose(ficCommande);
				genererFacture(nomClient, NNNN, listeCommande, nbElt, quantite);
			}
		else
			{
				printf("\n toutes les commandes presentes ont ete traitees.\n");
				FILE *f=fopen("nextFact","w"); // on va ecrire la valeur de N dans enxtFact
				fwrite(&N,1,sizeof(int),f);
				fclose(f);
				FINI=1;			
			}

		N++;
		}while(FINI==0);		
}



int main()
{
	//creation d un fichier d'un seul int nommé nextFact et contenant l'int 1
	// code à utiliser pour réinitialiser nextFact à 1 si besoin au cours du TP 	
	
	int choix = 0;
	FILE *f;
	int N=1;

	

	do{
		printf("\t --- MENU --- \n");
		printf("1- Regenerer les factures\n");
		printf("2- Generer les nouvelles factures\n");
		printf("0- Quitter\n");
		printf("Votre choix : ");
		scanf("%d", &choix);

		switch(choix){
			case 1 :
				f=fopen("nextFact","w");
				fwrite(&N,1,sizeof(int),f);
				fclose(f);
				lireLesCommandes(); //lecture de tous les fichiers commandeXXX.txt (fichiers non traités jusqu'ici)	
			break;

			case 2 :
				lireLesCommandes(); //lecture de tous les fichiers commandeXXX.txt (fichiers non traités jusqu'ici)	
			break;

			case 0 :
				printf("Bye !\n");
			break;

			default :
				printf("Mauvaise entree\n");
			break;
		}

	} while (choix != 0);


	//PARTIE 1 du TP : sans Gestion de stock
	

	//PARTIE 2 du TP : avec Gestion de stock
	//copiez coller votre travail précédent puis modifiez le  
	//lireLesCommandes2(); 	
	return 0;
}

#include <stdio.h>
#include <string.h>
#include "prod.h"

void chercheProduit(unsigned int * ref, T_TableauDeProduits listeProduits, int * tailleListe, char * lib, float * prix);

int lireCommande(const char * nomCommande, T_TableauDeProduits listeProduits, int * tailleListe, char * nomClient, T_TableauDeProduits listeCommande, int quantites[]){
    
    FILE * commande = NULL;
    commande = fopen(nomCommande, "rt"); // On ouvre la commande
    char nom[TAILLE];
    char lib[TAILLE];
    float prix;
    unsigned int ref;
    int qte;
    int i=0;

    // On a réussi à ouvrir la commande
    if (commande != NULL){
        // On lit le nom
        if (fscanf(commande, "%s", nom) != EOF) strcpy(nomClient, nom); 
        // printf("\nNom lu : %s\n", nom);

        // On liste les commandes
        while (fscanf(commande, "%d %d", &ref, &qte) != EOF){
            chercheProduit(&ref, listeProduits, tailleListe, lib, &prix);
            printf("Lib : %s\tRef : %d\tQTE : %d\tPU : %.2f\tPT : %.2f\n", lib, ref, qte, prix, prix*qte);
            listeCommande[i].prixU = prix;
            strcpy(listeCommande[i].libelle, lib);
            listeCommande[i].reference = ref;
            quantites[i] = qte;
            i++;
        }
        fclose(commande);
        return 1;
    }

    // On n'a pas réussi --> problème
    else return 0;
}

void chercheProduit(unsigned int * ref, T_TableauDeProduits listeProduits, int * tailleListe, char * lib, float * prix){
    int i;    
    for(i=0 ; i<*tailleListe ; i++){
        if(*ref == listeProduits[i].reference) {
            strcpy(lib, listeProduits[i].libelle);
            *prix = listeProduits[i].prixU;
        }
    }
}

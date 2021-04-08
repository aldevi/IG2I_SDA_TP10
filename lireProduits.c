#include <stdio.h>
#include <string.h>
#include "prod.h"

int lireProduits(T_TableauDeProduits listeProduits){
    FILE * prod = NULL;
    int i=0;
    int ref;
    float prix;
    char nom[TAILLE];
    prod = fopen("produits.txt", "rt");
    
    // On a réussi à ouvrir le fichier
    if(prod != NULL){
        // On récupère les références, les prix et les libellés
        while(fscanf(prod, "%d %s %f", &ref, nom, &prix) != EOF){
            // On les insère dans notre liste de produits
            // printf("Libelle : %s\nRef : %d\nPrix : %.2f\n", nom, ref, prix);
            listeProduits[i].reference = ref;
            strcpy(listeProduits[i].libelle, nom);
            listeProduits[i].prixU = prix;
            i++;
        }
        // On ferme le fichier
        fclose(prod);
        return i;
    }
    // On n'a pas réussi à l'ouvrir
    else return 0;
}
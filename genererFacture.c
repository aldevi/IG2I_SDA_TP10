#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prod.h"

int genererFacture(char client[], char num_facture[], T_TableauDeProduits produits[], int nb_references, int quantites[])
{
    FILE *ficFacture = NULL;
    char nomFacture[50] = "./factures/facture";
    strcat(nomFacture, num_facture);
    strcat(nomFacture, ".txt");

    float sous_total = 0;
    float total = 0;

    ficFacture = fopen(nomFacture, "w");
    if (ficFacture != NULL)
    {
        fprintf(ficFacture, "Facture numéro : %s\n\n", num_facture);
        fprintf(ficFacture, "Nom du client : %s\n\n", client);

        for (int i = 0; i < nb_references; i++)
        {
            sous_total = quantites[i] * produits[i]->prixU;
            total += sous_total;
            fprintf(ficFacture, "%d %s (PU=%.2f€) :: %.2f€\n", quantites[i], produits[i]->libelle, produits[i]->prixU, sous_total);
        }

        fprintf(ficFacture, "\n\t\t\tTOTAL : %.2f€", total);

        fclose(ficFacture);
        return 1;
    }

    return 0;
}
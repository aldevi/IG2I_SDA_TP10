#ifndef _LIRECOMMANDE_H_
#define _LIRECOMMANDE_H_
#include "prod.h"

int lireCommande(const char * nomCommande, T_TableauDeProduits listeProduits, int * tailleListe, char * nomClient, T_TableauDeProduits listeCommande, int quantites[]);

#endif
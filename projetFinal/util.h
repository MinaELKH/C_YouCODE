#ifndef UTIL_H
#define UTIL_H
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_RES 100
#define MAX_CHAR 50

typedef enum {
    VALIDE,
    REPORTE,
    ANNULE,
    TRAITE
} Statut;

typedef struct {
    int jour;
    int mois;
    int annee;
} DATE;

typedef struct {
    char nom[MAX_CHAR];
    char prenom[MAX_CHAR];
    char telephone[MAX_CHAR];
    int age;
    Statut statut; 
    char reference[MAX_CHAR]; 
    DATE date; 
} Str_RES;

// Déclaration des variables globales
extern Str_RES arrayRes[MAX_RES]; // Tableau global de réservations
extern int compteur;               // Compteur global
extern int compteurRef;               // Compteur pour les reference , l idee et d voir un compteur qui ne desincrement pas meme si on supprimer les patients

///////////////////////////////////////// Prototypes de fonctions
const char* statutToString(Statut statut);
void genererRef(char *ref);
void menu(); 
void clearScreen(); 
void TriResRef_Bulle();
int RechercherRef_Dichotomique();
void formulaire();
void AfficherRef(int i);

#endif // UTIL_H

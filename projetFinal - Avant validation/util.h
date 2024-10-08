#ifndef UTIL_H
#define UTIL_H
#include "util.h"
#include "style.h"
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

void clearScreen(); 

void formulaire();
void AfficherIndex(int i);

/*  tri     */
void TriRes_Bulle();   int comparerREF();   int comparerNom();  int comparerDate(); int comparerStatut();  void TriResRef_Bulle();//  TriResRef_Bulle   je l utlise pour tester
void triAge_selection() ;
/*  recherche */

int RechercherRef_Dichotomique();
void RechercherNom_Dichotomique();  // on peut avoir plusieur reservation avec meme nom donc on fait la affiche a l interieur du fonction pour evite un tableau des index dans le retour 
void RechercherDate_Dichotomique();
void RechercherStatut_Linaire(int statut) ; 

/*   menu et sous menu */
void menu();     void menuTrier();   void menuRechercher();   void menuStatistique();

/*   entete de tableau d affichage */
void enteteTableau() ; 

#endif // UTIL_H

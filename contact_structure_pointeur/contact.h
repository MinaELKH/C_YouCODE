#ifndef CONTACT_H
#define CONTACT_H



///////////////////////////////////////// Biblio  /////////////////////////////
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>



///////////////////////////////////////// declaration structure et variable global/////////////////////////////
#define MAX_CHAR 50
#define MAX_contacts 100

typedef struct contact {
    char nom[MAX_CHAR];
    char tel[MAX_CHAR];
    char email[MAX_CHAR];
} CONTACT;

// Déclaration du tableau et de compteur  (à définir dans un fichier .c)
extern CONTACT contact[MAX_contacts]; 
extern int compteur;

///////////////////////////////////////// declaration des fonctions projet  /////////////////////////////
void menu();
void Ajouter();
int Rechercher();
void Supprimer();
void Modifier();
void ListContact();
void triSelectionParNom();
void triBulleParNom();

CONTACT create();

///////////////////////////////////////// declaration des fonctions supplimentaire /////////////////////////////
void AjouterContactsExemple();
int is_alpha_string(const char *valeur);









///////////////////////////////////  style  -    couleur ///////////////////////////////////////////

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif
 
// Définition des macros pour les couleurs
#define RESET       "\033[0m"        // Réinitialise les couleurs
#define RED         "\033[31m"       // Rouge
#define GREEN       "\033[32m"       // Vert
#define YELLOW      "\033[33m"       // Jaune
#define BLUE        "\033[34m"       // Bleu
#define MAGENTA     "\033[35m"       // Magenta
#define CYAN        "\033[36m"       // Cyan
#define WHITE       "\033[37m"       // Blanc

// Couleur de fond
#define BG_RED      "\033[41m"       // Fond rouge
#define BG_GREEN    "\033[42m"       // Fond vert
#define BG_YELLOW   "\033[43m"       // Fond jaune
#define BG_BLUE     "\033[44m"       // Fond bleu
#define BG_MAGENTA  "\033[45m"       // Fond magenta
#define BG_CYAN     "\033[46m"       // Fond cyan

#endif 
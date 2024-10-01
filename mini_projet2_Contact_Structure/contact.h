#ifndef CONTACT_H
#define CONTACT_H
#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

#define MAX_CHAR 50
#define MAX_contacts 100

#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

void AjouterContactsExemple();
void toLowerCase(char *str);
typedef struct contact {
    char nom[MAX_CHAR];
    char tel[MAX_CHAR];
    char email[MAX_CHAR];
} CONTACT;

// Déclaration du tableau et de compteur  (à définir dans un fichier .c)
extern CONTACT contact[MAX_contacts]; 
extern int compteur;


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
#ifndef STYLE_H
#define STYLE_H

#include "../header.h"  
#include "style.h"


void clearScreen(); 
const char* getStatutColor(int statut);
void enteteTableau();




/********  validation des champs  */

void capitalizeFirstLetter(char *str);
 int is_alpha_string();

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
#define BG_WHITE    "\033[47m"       // Fond blanc
#define BG_GRAY     "\033[100m"      // Fond gris clair


#endif
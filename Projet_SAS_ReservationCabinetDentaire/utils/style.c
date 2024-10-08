
#include "../header.h"  
#include "style.h"


void clearScreen() {
    #ifdef _WIN32
        system("cls");  
    #else
        system("clear");  
    #endif
}
 

const char* statutToString(Statut statut) {
    switch (statut) {
        case VALIDE: return "valide";
        case REPORTE: return "reporte";
        case ANNULE: return "annule";
        case TRAITE: return "traite";
        default: return "inconnu";
    }
}


void enteteTableau(){
    printf("|------          Afficher la liste des Patients qui ont reserve       ------------|\n");
    printf("+----------+----------+----------+-------------+-------+----------+---------------+\n");
    printf(BG_GRAY"|   REF    |   Nom    |  Prenom  |  Telephone  |  Age  |  Statut  |     Date      |\n"RESET);
    printf("+----------+----------+----------+-------------+-------+----------+---------------+\n");
}


// Exemple de fonction pour obtenir la couleur du statut
const char* getStatutColor(int statut) {
    switch(statut) {
        case 0: return GREEN;   // Valide -> Vert
        case 1: return  YELLOW;  // Reporté -> Jaune
        case 2: return  RED;     // Annulé -> Rouge
        case 3: return MAGENTA ;  // Traité -> Jaune
        default: return RESET;  // Inconnu -> Pas de couleur
    }
}
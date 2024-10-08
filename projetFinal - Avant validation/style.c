#include "style.h"

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
#include "util.h"
#include "style.h"
#include "reservation.h"

// Initialisation des variables globales
Str_RES arrayRes[MAX_RES]; 
int compteur = 1;          
int compteurRef=1;


int main(void) {
    
    AjouterReservationPardefaut();  // Ajouter des réservations par défaut 
    menu();

    return 0;
}

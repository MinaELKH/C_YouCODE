#ifndef STATISTIQUE_H
#define STATISTIQUE_H

#include "util.h" // Inclure util.h pour accéder aux définitions et déclarations
#include "reservation.h" 

/*Calculer la moyenne d'âge des patients ayant réservé.
Afficher le nombre de patients par tranche d'âge (ex. : 0-18 ans, 19-35 ans, 36+ ans).
Générer des statistiques pour connaître le nombre total de réservations par statut (validé, annulé, etc.).*/
void CalculerMoyAge();
void TrancheAge();
void NbReservationStatut();


#endif // STATISTIQUE_H
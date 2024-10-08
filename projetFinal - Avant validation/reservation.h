#ifndef RESERVATION_H
#define RESERVATION_H

#include "util.h" // Inclure util.h pour accéder aux définitions et déclarations




// Prototypes de fonctions sans paramètres
void Ajouter();
void Modifier();
void Supprimer();
void AfficherDetails();

void AfficherStatistiques();
void AfficherList();
void AjouterReservationPardefaut();


int RechercherParReference();
void RechercherParNom();
void RechercherParDate();
void RechercherParStatut();


void TrierParRef();
void TrierParNom() ;
void TrierParDate();
void TrierParStatut();

#endif // RESERVATION_H



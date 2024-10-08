#include "header.h"
#include "utils/style.h"

// Initialisation des variables globales
Str_RES arrayRes[MAX_RES]; 
int compteur = 1;          
int compteurRef = 1;

int main() {


   AjouterReservationPardefaut();  // Ajouter des réservations par défaut 
 // AfficherTest(); 
   menu();
   return 0;
}





/****** Menu principal ******/
void menu() {
    int choix;
    bool continuer = true;

    while (continuer) {
        clearScreen();
        printf(GREEN"\n----- Menu de Gestion des Reservations -----\n"RESET);
        printf("1. Ajouter\n");
        printf("2. Modifier\n");
        printf("3. Supprimer\n");
        printf("4. Afficher\n");
        printf("5. Trier\n");
        printf("6. Rechercher\n");
        printf("7. Statistiques\n");
        printf("8. Liste des reservations\n");
        printf("0. Quitter le programme\n");
        printf("Veuillez choisir une option : ");

        scanf("%d", &choix);
        getchar();  // Pour nettoyer le tampon d'entrée après scanf

        switch (choix) {
            case 1:
               
                Ajouter();  // Appel de la fonction pour ajouter
                break;
            case 2:
               
                Modifier();  // Appel de la fonction pour modifier
                break;
            case 3:
                
                Supprimer();  // Appel de la fonction pour supprimer
                break;
            case 4:
               
                AfficherDetails();  // Appel de la fonction pour afficher
                break;
            case 5:
                
                printf("/********* Trier par :  ***********/ \n1: Reference\t\t 2: Nom\t\t 3: Date\t\t 4: Statut \n");
                menuTrier();
                break;
            case 6:
              
                printf("/********* Rechercher par :  ***********/ \n1: Reference\t 2: Nom\t 3: Date\t 4: Statut \n");
                menuRechercher();
                break;
            case 7:
                
                printf(GREEN" ********* Statistiques: ***********\n"RESET);
                CalculerMoyAge();
                TrancheAge();
                NbReservationStatut();
                break;
            case 8:
                AfficherList();  // Afficher la liste des réservations
                break;
            case 0:
                continuer = false;
                printf("Merci d'avoir utilise le programme. À bientot !\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
                break;
        }
        

        // Demander à l'utilisateur s'il veut continuer ou quitter
        if (continuer) {
            char confirmation;
            printf("Voulez-vous retourner au menu principal ? (o/n) : ");
            scanf(" %c", &confirmation); 
            if (confirmation != 'o' && confirmation != 'O') {
                continuer = false;
                printf("Merci d'avoir utilise le programme. À bientot !\n");
            }
        }
    
    }
}

/****************** Menu de tri ******************/
void menuTrier() {
    int choix;
    printf("Choix : ");
    scanf("%d", &choix);
    getchar();  // Nettoyage du tampon d'entrée

    switch (choix) {
        case 1: TrierParRef(); break;
        case 2: TrierParNom(); break;
        case 3: TrierParDate(); break;
        case 4: TrierParStatut(); break;
        default: printf(RED"Choix invalide\n"RESET); break;
    }
    AfficherList();
}

/****************** Menu de recherche ******************/
void menuRechercher() {
    int choix;
    printf("Choix : ");
    scanf("%d", &choix);
    getchar();  // Nettoyage du tampon d'entrée

    switch (choix) {
        case 1: RechercherParReference(); break;
        case 2: RechercherParNom(); break;
        case 3: RechercherParDate(); break;
        case 4: RechercherParStatut(); break;
        default: (RED"Choix invalide\n"RESET); break;
    }
}

/****************** Menu de statistiques ******************/
void menuStatistique() {
    int choix;
    printf("Choix : ");
    scanf("%d", &choix);
    getchar();  // Nettoyage du tampon d'entrée

    switch (choix) {
        case 1: CalculerMoyAge(); break;
        case 2: TrancheAge(); break;
        case 3: NbReservationStatut(); break;
        default: (RED"Choix invalide\n"RESET); break;
    }
}


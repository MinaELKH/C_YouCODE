#include "header.h"
#include "utils/style.h"

// Initialisation des variables globales
Str_RES arrayRes[MAX_RES]; 
int compteur = 1;          
int compteurRef = 1;

int main() {
    AjouterReservationPardefaut();  // Ajouter des réservations par défaut 
    menu();
    return 0;
}


// Fonction pour ajouter des reservations par defaut
void AjouterReservationPardefaut() {
    char noms[10][50] = {"Amine", "Hamed", "Nadir", "Saadi", "Zahid", "Nadir", "Salem", "Rafik", "Nadir", "Azhar"};
    char prenoms[10][50] = {"Hassna", "Fatima", "Omar", "Khadija", "Hassan", "Leila", "Youssef", "Amina", "Rachid", "Sara"};
    char tels[10][15] = {"0612345678", "0698765432", "0712345678", "0798765432", "0812345678", "0898765432", "0912345678", "0998765432", "0512345678", "0598765432"};
    int ages[10] = {25, 60, 28, 28, 35, 16, 40, 75, 18, 27};

    int jour[10] = {2,    10,    22,   4,    5,    22,   30,   22,   28,   27}; //on peut pas mettre 08 ou 07 car il concedere comme a base de octe et nous somme sur base de decimal 
    int mois[10] = {2,    4,     5,    6,    10,   5,   11,    5,    8,   12};  
    int annee[10] ={2024, 2023, 2022, 2028, 2025, 2022, 2024, 2022, 2018, 2027};
    Statut statuts[10] = {VALIDE, REPORTE, ANNULE, TRAITE, VALIDE, REPORTE, VALIDE, ANNULE, TRAITE, VALIDE};

    for (int j = 0; j < 10; j++) {
        strcpy(arrayRes[compteur].nom, noms[j]);
        strcpy(arrayRes[compteur].prenom, prenoms[j]);
        strcpy(arrayRes[compteur].telephone, tels[j]);  
        arrayRes[compteur].age = ages[j];
        arrayRes[compteur].statut = statuts[j];
        // date
        arrayRes[compteur].date.jour = jour[j];
        arrayRes[compteur].date.mois = mois[j];
        arrayRes[compteur].date.annee = annee[j];
        genererRef(arrayRes[compteur].reference); // appel un fonction Generer la reference pour chaque reservation

        compteur++;

    }
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


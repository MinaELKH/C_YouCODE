#include "reservation.h"
#include "util.h"

const char* statutToString(Statut statut) {
    switch (statut) {
        case VALIDE: return "valide";
        case REPORTE: return "reporte";
        case ANNULE: return "annule";
        case TRAITE: return "traite";
        default: return "inconnu";
    }
}

void genererRef(char *ref) {
   
    snprintf(ref, 50, "REF%d", compteurRef++);
}

void menu() {
    int choix;
    bool continuer = true;
    char reference[MAX_CHAR];

    while (continuer) {
        printf("\n----- Menu de Gestion des Reservations -----\n");
        printf("1. Ajouter une reservation\n");
        printf("2. Modifier une reservation\n");
        printf("3. Supprimer une reservation\n");
        printf("4. Afficher les details d'une reservation\n");
        printf("5. Trier les Reservations par nom\n");
        printf("6. Rechercher par reference\n");
        printf("7. Afficher les statistiques\n");
        printf("8. Afficher la liste des reservations\n");
        printf("0. Quitter le programme\n");
        printf("Veuillez choisir une option : ");
        
        scanf("%d", &choix);
        getchar();

        switch (choix) {
            case 1:
            clearScreen();
                Ajouter(); // Pas besoin de passer des paramètres
                break;
            case 2:
             clearScreen();
                Modifier(); // Pas besoin de passer des paramètres
                break;
            case 3:
             clearScreen();
                Supprimer(); // Pas besoin de passer des paramètres
                break;
            case 4:
             clearScreen();
                AfficherDetails(); 
                break;
            case 5:
             clearScreen();
                TrierParNom(); 
                break;
            case 6: {
                
                printf("Entrez la reference à rechercher : ");
                fgets(reference, sizeof(reference), stdin);
                reference[strcspn(reference, "\n")] = 0;
                RechercherParReference(reference); 
                break;
            }
            case 7:
                AfficherStatistiques(); 
                break;
            case 8 : 
                 AfficherList();
                 break; 
            case 0:
                continuer = false;
                printf("Merci d'avoir utilise le programme. À bientôt !\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
                break;
        }
    }
}


void clearScreen() {
    #ifdef _WIN32
        system("cls");  
    #else
        system("clear");  
    #endif
}


void TriResRef_ParBulle(){
    int i, j;
    Str_RES temp;
    int sorted;

    for (i = 0; i < compteur - 1; i++) {
        sorted = 1; // le tableau est déjà trié
        for (j = 0; j < compteur - 1 - i; j++) {
            if (strcmp(arrayRes[j].reference, arrayRes[j + 1].reference) > 0) {
                temp = arrayRes[j];
                arrayRes[j] = arrayRes[j + 1];
                arrayRes[j + 1] = temp;
                sorted = 0; // le tableau n'est pas encore trié 
            }
        }
        // Si aucune permutation n'a eu lieu, le tableau est trié
        if (sorted) {
            break;
        }
    }

}

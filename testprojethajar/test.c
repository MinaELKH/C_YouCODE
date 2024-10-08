#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définition de la structure de réservation
typedef struct reservation {
    char nom[50];
    char prenom[50];
    char tele[13];
    int age;
    char statut[20];
    int reference;
    char date[11];
} RESERVATION;

RESERVATION reservations[9000]; // Tableau pour stocker les réservations
int compteur = 0;                // Compteur pour le nombre de réservations
int reference = 1;               // Référence unique pour chaque réservation

// Déclaration des fonctions
void menu();
int genererReference();
void ajouter();
void afficher();
void modifier();
void supprimer();
void rechercher();
void trier();
void statistiques();
void dixreservations();

int main() {
    dixreservations();
    menu(); // Appel de la fonction menu
    return 0;
}

void dixreservations() {
    strcpy(reservations[compteur].nom, "hajar");
    strcpy(reservations[compteur].prenom, "walfi");
    strcpy(reservations[compteur].tele, "0660007874");
    reservations[compteur].age = 22;
    strcpy(reservations[compteur].statut, "valide");
    reservations[compteur].reference = genererReference();
    strcpy(reservations[compteur].date, "01/01/2024");
    compteur++;

    strcpy(reservations[compteur].nom, "abderrahim");
    strcpy(reservations[compteur].prenom, "walfi");
    strcpy(reservations[compteur].tele, "0674962100");
    reservations[compteur].age = 65;
    strcpy(reservations[compteur].statut, "annule");
    reservations[compteur].reference = genererReference();
    strcpy(reservations[compteur].date, "02/01/2024");
    compteur++;
    
    strcpy(reservations[compteur].nom, "rachida");
    strcpy(reservations[compteur].prenom, "hammadi");
    strcpy(reservations[compteur].tele, "0613018176");
    reservations[compteur].age = 63;
    strcpy(reservations[compteur].statut, "reporte");
    reservations[compteur].reference = genererReference();
    strcpy(reservations[compteur].date, "02/01/2024");
    compteur++;
    
    strcpy(reservations[compteur].nom, "meriem");
    strcpy(reservations[compteur].prenom, "walfi");
    strcpy(reservations[compteur].tele, "0612201003");
    reservations[compteur].age = 30;
    strcpy(reservations[compteur].statut, "traite");
    reservations[compteur].reference = genererReference();
    strcpy(reservations[compteur].date, "02/01/2024");
    compteur++;
    
    strcpy(reservations[compteur].nom, "issam");
    strcpy(reservations[compteur].prenom, "couchi");
    strcpy(reservations[compteur].tele, "0655751143");
    reservations[compteur].age = 23;
    strcpy(reservations[compteur].statut, "annule");
    reservations[compteur].reference = genererReference();
    strcpy(reservations[compteur].date, "02/06/2024");
    compteur++;
    
    strcpy(reservations[compteur].nom, "hicham");
    strcpy(reservations[compteur].prenom, "benalia");
    strcpy(reservations[compteur].tele, "0688943629");
    reservations[compteur].age = 31;
    strcpy(reservations[compteur].statut, "reporte");
    reservations[compteur].reference = genererReference();
    strcpy(reservations[compteur].date, "02/10/2024");
    compteur++;
    
    strcpy(reservations[compteur].nom, "mina");
    strcpy(reservations[compteur].prenom, "walfi");
    strcpy(reservations[compteur].tele, "0675962100");
    reservations[compteur].age = 45;
    strcpy(reservations[compteur].statut, "annule");
    reservations[compteur].reference = genererReference();
    strcpy(reservations[compteur].date, "02/03/2024");
    compteur++;
    
    strcpy(reservations[compteur].nom, "hiba");
    strcpy(reservations[compteur].prenom, "walfi");
    strcpy(reservations[compteur].tele, "0674962100");
    reservations[compteur].age = 55;
    strcpy(reservations[compteur].statut, "annule");
    reservations[compteur].reference = genererReference();
    strcpy(reservations[compteur].date, "02/08/2024");
    compteur++;
    
    strcpy(reservations[compteur].nom, "ilham");
    strcpy(reservations[compteur].prenom, "walfi");
    strcpy(reservations[compteur].tele, "0674932100");
    reservations[compteur].age = 57;
    strcpy(reservations[compteur].statut, "reporte");
    reservations[compteur].reference = genererReference();
    strcpy(reservations[compteur].date, "02/6/2024");
    compteur++;
    
    strcpy(reservations[compteur].nom, "nada");
    strcpy(reservations[compteur].prenom, "walfi");
    strcpy(reservations[compteur].tele, "0774962100");
    reservations[compteur].age = 25;
    strcpy(reservations[compteur].statut, "valide");
    reservations[compteur].reference = genererReference();
    strcpy(reservations[compteur].date, "02/01/2024");
    compteur++;
}

// Définition de la fonction menu
void menu() {
    int choix;
    do {
        printf("                            ===========================             \n");
        printf("                                       Menu                         \n");
        printf("                            ===========================           \n\n");
        printf("                             1. Ajouter une reservation             \n");
        printf("                             2. Afficher les reservations           \n");
        printf("                             3. Modifier une reservation            \n");
        printf("                             4. Supprimer une reservation           \n");
        printf("                             5. Rechercher une reservation          \n");
        printf("                             6. Trier les reservations par nom      \n");
        printf("                             7. Statistiques                        \n");
        printf("                             0. Quitter le programme              \n\n");
        printf("                           =============================          \n\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);
        getchar(); // Pour capturer le caractère de nouvelle ligne

        switch (choix) {
            case 1:
                ajouter();
                break;
            case 2:
                afficher();
                break;
            case 3:
                modifier();
                break;
            case 4:
                supprimer();
                break;
            case 5:
                rechercher();
                break;
            case 6:
                trier();
                break;
            case 7:
                statistiques();
                break;
            case 0:
                exit(0);
            default:
                printf("Veuillez entrer une option valide.\n");
        }
    } while (choix != 0);
}

// Définition de la fonction générerReference
int genererReference() {
    return reference++;
}

// Définition de la fonction ajouter
void ajouter() {
    int choix;
    printf("Veuillez ajouter les informations suivantes:\n");

    printf("Entrez votre nom: ");
    fgets(reservations[compteur].nom, sizeof(reservations[compteur].nom), stdin);
    reservations[compteur].nom[strcspn(reservations[compteur].nom, "\n")] = 0;

    printf("Entrez votre prenom: ");
    fgets(reservations[compteur].prenom, sizeof(reservations[compteur].prenom), stdin);
    reservations[compteur].prenom[strcspn(reservations[compteur].prenom, "\n")] = 0;

    printf("Entrez votre numero de telephone: ");
    fgets(reservations[compteur].tele, sizeof(reservations[compteur].tele), stdin);
    reservations[compteur].tele[strcspn(reservations[compteur].tele, "\n")] = 0;

    printf("Entrez votre age: ");
    scanf("%d", &reservations[compteur].age);

    printf("Entrez le status:\n");
    printf("1. Valide\n");
    printf("2. Reporte\n");
    printf("3. Annule\n");
    printf("4. Traite\n");
    printf("Veuillez choisir une option d'apres le menu suivant:\n");
    scanf("%d", &choix);
    getchar();

    if (choix >= 1 && choix <= 4) {
        switch (choix) {
            case 1:
                strcpy(reservations[compteur].statut, "valide");
                break;
            case 2:
                strcpy(reservations[compteur].statut, "Reporte");
                break;
            case 3:
                strcpy(reservations[compteur].statut, "Annule");
                break;
            case 4:
                strcpy(reservations[compteur].statut, "Traite");
                break;
        }
    } else {
        printf("La reservation n'a pas ete ajoutee. Veuillez entrer une option valide.\n");
        return; // Ne pas incrémenter le compteur si la réservation n'est pas ajoutée
    }

    printf("Entrez une date suivant cette forme: (j/m/a)\n");
    fgets(reservations[compteur].date, sizeof(reservations[compteur].date), stdin);
    reservations[compteur].date[strcspn(reservations[compteur].date, "\n")] = 0;

    reservations[compteur].reference = genererReference();
    compteur++;
    printf("Votre reservation a ete bien ajoutee.\n");
}

void afficher() {
    printf("Il y a %d reservations.\n", compteur);
    
    // Header for the table
    printf("+----------+----------+----------+-------------+-------+------------+-----------+\n");
    printf("| Reference| Nom      | Prenom   | Telephone   | Age   | Statut     | Date      |\n");
    printf("+----------+----------+----------+-------------+-------+------------+-----------+\n");

    // Loop through all reservations and print them
    for (int i = 0; i < compteur; i++) {
        printf("| %-8d | %-8s | %-8s | %-11s | %-5d | %-10s | %-8s |\n",
               reservations[i].reference,                
               reservations[i].nom,                     
               reservations[i].prenom,                  
               reservations[i].tele,                    
               reservations[i].age,                     
               reservations[i].statut,                  
               reservations[i].date                     
        );   
    }

    // Footer for the table
    printf("+----------+----------+----------+-------------+-------+------------+-----------+\n");
}

// Définition de la fonction rechercher
void rechercher() {
    int choix;
    printf("Voulez vous rechercher par nom ou par reference?\n");
    printf("Choisissez:\n");
    printf("1. pour chercher par reference;\n");
    printf("2. pour chercher par nom;\n");
    scanf("%d", &choix);
    switch (choix) {
        case 1: {
            int referenceRechercher;
            printf("Veuillez entrer la reference que vous souhaitez rechercher:\n");
            scanf("%d", &referenceRechercher);
            int trouve = 0;
            for (int i = 0; i < compteur; i++) {
                if (referenceRechercher == reservations[i].reference) {
                    printf("La reference a ete trouvee.\n");
                    printf("Nom: %s ;\n", reservations[i].nom);
                    printf("Prenom: %s ;\n", reservations[i].prenom);
                    printf("Age: %d ;\n", reservations[i].age);
                    printf("Tele: %s ;\n", reservations[i].tele);
                    printf("Statut: %s ;\n", reservations[i].statut);
                    printf("Reference: %d ;\n", reservations[i].reference);
                    printf("Date: %s ;\n", reservations[i].date);
                    trouve++;
                }
            }
            if (trouve == 0) {
                printf("Reservation introuvable.Veuillez reessayer!\n");
            }
            break;
        }
        case 2: {
            char nomRechercher[50];
            printf("Veuillez entrer le nom que vous souhaitez rechercher:\n");
            fgets(nomRechercher, sizeof(nomRechercher), stdin);
            nomRechercher[strcspn(nomRechercher, "\n")] = 0;
            int trouve = 0;
            for (int i = 0; i < compteur; i++) {
                if (strcmp(nomRechercher, reservations[i].nom) == 0) {
                    printf("La reservation a ete trouvee.\n");
                    printf("Nom: %s ;\n", reservations[i].nom);
                    printf("Prenom: %s ;\n", reservations[i].prenom);
                    printf("Age: %d ;\n", reservations[i].age);
                    printf("Tele: %s ;\n", reservations[i].tele);
                    printf("Statut: %s ;\n", reservations[i].statut);
                    printf("Reference: %d ;\n", reservations[i].reference);
                    printf("Date: %s ;\n", reservations[i].date);
                    trouve++;
                }
            }
            if (trouve == 0) {
                printf("Reservation introuvable. Veuillez reessayer!\n");
            }
            break;
        }
        default:
            printf("Veuillez choisir une option valide.\n");
            break;
    }
}

// Définition de la fonction supprimer
void supprimer() {
    int referenceASupprimer;
    printf("Veuillez entrer la reference de la reservation a supprimer:\n");
    scanf("%d", &referenceASupprimer);
    int trouve = 0;
    for (int i = 0; i < compteur; i++) {
        if (reservations[i].reference == referenceASupprimer) {
            trouve++;
            for (int j = i; j < compteur - 1; j++) {
                reservations[j] = reservations[j + 1];
            }
            compteur--; // Décrementer le compteur
            printf("La reservation a bien ete supprimee.\n");
            break;
        }
    }
    if (trouve == 0) {
        printf("Reservation introuvable.Veuillez reessayer!\n");
    }
}

// Définition de la fonction modifier
void modifier() {
    int referenceAModifier;
    int choix;
    printf("Veuillez entrer la reference de la reservation a modifier:\n");
    scanf("%d", &referenceAModifier);
    getchar();
    int trouve = 0;
    for (int i = 0; i < compteur; i++) {
        if (reservations[i].reference == referenceAModifier) {
            trouve++;
            printf("Entrez le nouveau nom: ");
            fgets(reservations[i].nom, sizeof(reservations[i].nom), stdin);
            reservations[i].nom[strcspn(reservations[i].nom, "\n")] = 0;

            printf("Entrez le nouveau prenom: ");
            fgets(reservations[i].prenom, sizeof(reservations[i].prenom), stdin);
            reservations[i].prenom[strcspn(reservations[i].prenom, "\n")] = 0;

            printf("Entrez le nouveau numero de telephone: ");
            fgets(reservations[i].tele, sizeof(reservations[i].tele), stdin);
            reservations[i].tele[strcspn(reservations[i].tele, "\n")] = 0;

            printf("Entrez le nouvel age: ");
            scanf("%d", &reservations[i].age);

            printf("Entrez le nouveau status:\n");
            printf("1. Valide\n");
            printf("2. Reporte\n");
            printf("3. Annule\n");
            printf("4. Traite\n");
            printf("Veuillez choisir une option d'apres le menu suivant:\n");
            scanf("%d", &choix);
            getchar();

            if (choix >= 1 && choix <= 4) {
                switch (choix) {
                    case 1:
                        strcpy(reservations[i].statut, "valide");
                        break;
                    case 2:
                        strcpy(reservations[i].statut, "Reporte");
                        break;
                    case 3:
                        strcpy(reservations[i].statut, "Annule");
                        break;
                    case 4:
                        strcpy(reservations[i].statut, "Traite");
                        break;
                }
            }

            printf("Entrez une nouvelle date suivant cette forme: (j/m/a)\n");
            fgets(reservations[i].date, sizeof(reservations[i].date), stdin);
            reservations[i].date[strcspn(reservations[i].date, "\n")] = 0;

            printf("La reservation a bien ete modifiee.\n");
            break;
        }
    }
    if (trouve == 0) {
        printf("Reservation introuvable.Veuillez reessayer!\n");
    }
}

// Définition de la fonction trier
void trier() {
    // Utilisation de l'algorithme de tri à bulle
    for (int i = 0; i < compteur - 1; i++) {
        for (int j = 0; j < compteur - i - 1; j++) {
            if (strcmp(reservations[j].nom, reservations[j + 1].nom) > 0) {
                RESERVATION temp = reservations[j];
                reservations[j] = reservations[j + 1];
                reservations[j + 1] = temp;
            }
        }
    }
    printf("Les reservations ont ete triees par nom.\n");
}

//definition de la fonction statistique
void statistiques() {
    int valide = 0;
    int reporte = 0;
    int annule = 0;
    int traite = 0;
    int age18 = 0; 
    int age1935 = 0;
    int age36p = 0;
    int totalAge = 0;

    // Statistique par âge
    for (int i = 0; i < compteur; i++) {
        totalAge += reservations[i].age;

        if (reservations[i].age >= 0 && reservations[i].age <= 18) {
            age18++;
        } else if (reservations[i].age >= 19 && reservations[i].age <= 35) {
            age1935++;
        } else {
            age36p++;
        }

        // Statistique par statut
        if (strcmp(reservations[i].statut, "valide") == 0) {
            valide++;
        } else if (strcmp(reservations[i].statut, "Reporte") == 0) {
            reporte++;
        } else if (strcmp(reservations[i].statut, "Annule") == 0) {
            annule++;
        } else if (strcmp(reservations[i].statut, "Traite") == 0) {
            traite++;
        }
    }

    // Statistique par moyenne
    float moyenne;
    if (compteur > 0) {
        moyenne = (float)totalAge / compteur;
    } else {
        moyenne = 0;
    }

    // Affichage des statistiques
    printf("Nombre total de réservations : %d\n", compteur);
    printf("Âge moyen des patients : %.2f ans\n", moyenne);
    printf("Nombre de patients dans la tranche d'âge 0-18 ans : %d\n", age18);
    printf("Nombre de patients dans la tranche d'âge 19-35 ans : %d\n", age1935);
    printf("Nombre de patients dans la tranche d'âge 36 ans et plus : %d\n", age36p);
    printf("Nombre de réservations valides : %d\n", valide);
    printf("Nombre de réservations reportées : %d\n", reporte);
    printf("Nombre de réservations annulées : %d\n", annule);
    printf("Nombre de réservations traitées : %d\n", traite);
}

#include <stdio.h>

// Function prototypes
void initialisationAffichage();
void saisieAffichageElements();
void sommeElements();
void trouverMaximum();
void trouverMinimum();
void multiplicationElements();
void tableauOrdreCroissant();
void copieTableau();
void inversionTableau();
void rechercherElement();

int main() {
    int choix;

    do {
        // Menu for array challenges
        printf("\n===== MENU DES TABLEAUX =====\n");
        printf("1. Initialisation et Affichage\n");
        printf("2. Saisie et Affichage des Éléments\n");
        printf("3. Somme des Éléments\n");
        printf("4. Trouver le Maximum\n");
        printf("5. Trouver le Minimum\n");
        printf("6. Multiplication des Éléments\n");
        printf("7. Tableau en Ordre Croissant\n");
        printf("8. Copie d'un Tableau\n");
        printf("9. Inversion d'un Tableau\n");
        printf("10. Rechercher un Élément\n");
        printf("0. Quitter\n");
        printf("=============================\n");
        printf("Choisissez une option: ");
        scanf("%d", &choix);

        // Function calls based on the user’s choice
        switch (choix) {
            case 1: initialisationAffichage(); break;
            case 2: saisieAffichageElements(); break;
            case 3: sommeElements(); break;
            case 4: trouverMaximum(); break;
            case 5: trouverMinimum(); break;
            case 6: multiplicationElements(); break;
            case 7: tableauOrdreCroissant(); break;
            case 8: copieTableau(); break;
            case 9: inversionTableau(); break;
            case 10: rechercherElement(); break;
            case 0: printf("Au revoir!\n"); break;
            default: printf("Option invalide! Veuillez réessayer.\n");
        }
        sleep();

    } while (choix != 0);

    return 0;
}

// Exercice 1: Initialisation et Affichage d'un tableau
void initialisationAffichage() {
    printf("Challenge 1: Initialisation et Affichage\n");
    int tab[] = {1, 2, 3, 4, 5};
    int size = sizeof(tab) / sizeof(tab[0]);

    for (int i = 0; i < size; i++) {
        printf("%d\n", tab[i]);
    }
}

// Exercice 2: Saisie et Affichage des Éléments d'un tableau
void saisieAffichageElements() {
    int size = 0;
    int tab[100];

    printf("Challenge 2: Saisie et Affichage des éléments\n");
    printf("Veuillez saisir la taille du tableau : ");
    scanf("%d", &size);

    printf("Veuillez saisir les valeurs :\n");
    for (int i = 0; i < size; i++) {
        printf("tab[%d] = ", i);
        scanf("%d", &tab[i]);
    }

    printf("Affichage des valeurs du tableau :\n");
    for (int i = 0; i < size; i++) {
        printf("tab[%d] = %d\n", i, tab[i]);
    }
}

// Exercice 3: Calculer la somme des éléments d'un tableau
void sommeElements() {
    printf("Challenge 3: Somme des Éléments\n");
    int size = 0, sum = 0;
    int tab[100];

    printf("Veuillez saisir la taille du tableau : ");
    scanf("%d", &size);

    printf("Veuillez saisir les valeurs :\n");
    for (int i = 0; i < size; i++) {
        printf("tab[%d] = ", i);
        scanf("%d", &tab[i]);
        sum += tab[i];
    }

    printf("La somme = %d\n", sum);
}

// Exercice 4: Trouver le Maximum dans un tableau
void trouverMaximum() {
    printf("Challenge 4: Trouver le Maximum\n");
    int size = 0, max;
    int tab[100];

    printf("Veuillez saisir la taille du tableau : ");
    scanf("%d", &size);

    printf("Veuillez saisir les valeurs :\n");
    for (int i = 0; i < size; i++) {
        printf("tab[%d] = ", i);
        scanf("%d", &tab[i]);
        if (i == 0) {
            max = tab[i];
        } else if (tab[i] > max) {
            max = tab[i];
        }
    }

    printf("Max = %d\n", max);
}

// Exercice 5: Trouver le Minimum dans un tableau
void trouverMinimum() {
    printf("Challenge 5: Trouver le Minimum\n");
    int size = 0, min;
    int tab[100];

    printf("Veuillez saisir la taille du tableau : ");
    scanf("%d", &size);

    printf("Veuillez saisir les valeurs :\n");
    for (int i = 0; i < size; i++) {
        printf("tab[%d] = ", i);
        scanf("%d", &tab[i]);
        if (i == 0) {
            min = tab[i];
        } else if (tab[i] < min) {
            min = tab[i];
        }
    }

    printf("Min = %d\n", min);
}

// Exercice 6: Multiplier tous les éléments d'un tableau par un facteur
void multiplicationElements() {
    printf("Challenge 6: Multiplication des Éléments\n");
    int size = 0, facteur;
    int tab[100];

    printf("Veuillez saisir le facteur : ");
    scanf("%d", &facteur);
    printf("Veuillez saisir la taille du tableau : ");
    scanf("%d", &size);

    printf("Veuillez saisir les valeurs :\n");
    for (int i = 0; i < size; i++) {
        printf("tab[%d] = ", i);
        scanf("%d", &tab[i]);
        tab[i] *= facteur;
    }

    printf("Affichage des valeurs du tableau :\n");
    for (int i = 0; i < size; i++) {
        printf("tab[%d] = %d\n", i, tab[i]);
    }
}

// Exercice 7: Trier un tableau en ordre croissant
void tableauOrdreCroissant() {
    printf("Challenge 7: Tableau en Ordre Croissant\n");
    int size = 0, temp;
    int tab[100];

    printf("Veuillez saisir la taille du tableau : ");
    scanf("%d", &size);

    printf("Veuillez saisir les valeurs :\n");
    for (int i = 0; i < size; i++) {
        printf("tab[%d] = ", i);
        scanf("%d", &tab[i]);
    }

    // Tri du tableau en ordre croissant
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (tab[i] > tab[j]) {
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }

    printf("Tableau trié :\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

// Exercice 8: Copier un tableau dans un autre tableau
void copieTableau() {
    printf("Challenge 8: Copie d'un Tableau\n");
    int size = 0;
    int tab[100], tabCopie[100];

    printf("Veuillez saisir la taille du tableau : ");
    scanf("%d", &size);

    printf("Veuillez saisir les valeurs :\n");
    for (int i = 0; i < size; i++) {
        printf("tab[%d] = ", i);
        scanf("%d", &tab[i]);
    }

    for (int i = 0; i < size; i++) {
        tabCopie[i] = tab[i];
    }

    printf("Tableau original :\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", tab[i]);
    }
    printf("\nTableau copié :\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", tabCopie[i]);
    }
    printf("\n");
}

// Exercice 9: Inverser un tableau
void inversionTableau() {
    printf("Challenge 9: Inversion d'un Tableau\n");
    int size = 0, temp;
    int tab[100];

    printf("Veuillez saisir la taille du tableau : ");
    scanf("%d", &size);

    printf("Veuillez saisir les valeurs :\n");
    for (int i = 0; i < size; i++) {
        printf("tab[%d] = ", i);
        scanf("%d", &tab[i]);
    }

    // Inversion du tableau
    for (int i = 0; i < size / 2; i++) {
        temp = tab[i];
        tab[i] = tab[size - i - 1];
        tab[size - i - 1] = temp;
    }

    printf("Tableau inversé :\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

// Exercice 10: Rechercher un élément dans un tableau
void rechercherElement() {
    printf("Challenge 10: Rechercher un Élément\n");
    int size = 0, nb, present = 0;
    int tab[100];

    printf("Veuillez saisir la taille du tableau : ");
    scanf("%d", &size);

    printf("Veuillez saisir les valeurs :\n");
    for (int i = 0; i < size; i++) {
        printf("tab[%d] = ", i);
        scanf("%d", &tab[i]);
    }

    printf("Entrez l'élément à rechercher : ");
    scanf("%d", &nb);

    for (int i = 0; i < size; i++) {
        if (tab[i] == nb) {
            present = 1;
            printf("L'élément %d est trouvé à l'indice %d\n", nb, i);
        }
    }

    if (!present) {
        printf("L'élément %d n'est pas trouvé\n", nb);
    }
}

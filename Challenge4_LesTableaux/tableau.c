#include <stdio.h>
#include <unistd.h>
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
void remplacerElement();          
void afficherElementsPairs();     
void afficherElementsImpairs();  
void calculerMoyenne();           
void fusionnerTableaux();      
int main() {
    int choix;

    do {
        printf("\n===== MENU DES TABLEAUX =====\n");
        printf("1. Initialisation et Affichage\n");
        printf("2. Saisie et Affichage des elements\n");
        printf("3. Somme des elements\n");
        printf("4. Trouver le Maximum\n");
        printf("5. Trouver le Minimum\n");
        printf("6. Multiplication des elements\n");
        printf("7. Tableau en Ordre Croissant\n");
        printf("8. Copie d'un Tableau\n");
        printf("9. Inversion d'un Tableau\n");
        printf("10. Rechercher un element\n");
        printf("11. remplacer un element()\n");
        printf("12. afficher les Elements Pairs\n");
        printf("13. afficher les elements Impairs\n");
        printf("14. calculer la moyenne\n");
        printf("15. fusionner deux Tableaux()\n");
        printf("0. Quitter\n");
        printf("=============================\n");
        printf("Choisissez une option: ");
        scanf("%d", &choix);

        
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
            case 11 :remplacerElement() ; break;
            case 12: afficherElementsPairs(); break;
            case 13: afficherElementsImpairs(); break;
            case 14: calculerMoyenne(); break;
            case 15: fusionnerTableaux(); break;
            case 0: printf("Au revoir!\n"); break;
            default: printf("Option invalide! Veuillez reessayer.\n");
        }
        sleep(2);

    } while (choix != 0);

    return 0;
}

/*Challenge 1 : Initialisation et Affichage
ecrivez un programme C qui initialise un tableau d'entiers avec des valeurs donnees et affiche ces valeurs. Par exemple, vous pouvez initialiser un tableau avec les valeurs [1, 2, 3, 4, 5] et afficher chaque valeur sur une nouvelle ligne.*/
void initialisationAffichage() {
    printf("Challenge 1: Initialisation et Affichage\n");
    int tab[] = {1, 2, 3, 4, 5};
    int size = sizeof(tab) / sizeof(tab[0]);

    for (int i = 0; i < size; i++) {
        printf("%d\n", tab[i]);
    }
}

/*Challenge 2 : Saisie et Affichage des elements
ecrivez un programme C qui demande a l'utilisateur le nombre d'elements d'un tableau, puis demande a l'utilisateur de saisir ces elements. Affichez ensuite les elements du tableau.
*/
void saisieAffichageElements() {
    int size = 0;
    int tab[100];

    printf("Challenge 2: Saisie et Affichage des elements\n");
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

/*Challenge 3 : Somme des elements
ecrivez un programme C qui calcule et affiche la somme des elements d'un tableau d'entiers. Le programme doit demander le nombre d'elements, puis les elements du tableau, et afficher la somme totale.
*/
void sommeElements() {
    printf("Challenge 3: Somme des elements\n");
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

/*Challenge 4 : Trouver le Maximum
ecrivez un programme C qui trouve et affiche le plus grand element dans un tableau d'entiers. Le programme doit demander le nombre d'elements et les elements du tableau.*/
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

/*Challenge 5 : Trouver le Minimum
ecrivez un programme C qui trouve et affiche le plus petit element dans un tableau d'entiers. Le programme doit demander le nombre d'elements et les elements du tableau.*/
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

/*Challenge 6 : Multiplication des elements
ecrivez un programme C qui multiplie chaque element d'un tableau d'entiers par un facteur donne et affiche le tableau resultant. Le programme doit demander le nombre d'elements, les elements du tableau, et le facteur de multiplication.*/
void multiplicationElements() {
    printf("Challenge 6: Multiplication des elements\n");
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

/*Challenge 7 : Tableau en Ordre Croissant
ecrivez un programme C qui demande a l'utilisateur de saisir un tableau d'entiers, puis affiche le tableau trie en ordre croissant sans utiliser de fonction de tri predefinie.*/
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


    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (tab[i] > tab[j]) {
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }

    printf("Tableau trie :\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

// ecrivez un programme C qui copie les elements d'un tableau d'entiers dans un autre tableau. Affichez les elements du tableau original et du tableau copie pour verifier que la copie est correcte.
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
    printf("\nTableau copie :\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", tabCopie[i]);
    }
    printf("\n");
}

/*Challenge 9 : Inversion d'un Tableau
ecrivez un programme C qui inverse les elements d'un tableau d'entiers. Par exemple, si le tableau est [1, 2, 3, 4, 5], il doit devenir [5, 4, 3, 2, 1]. Affichez le tableau inverse.*/
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

    printf("Tableau inverse :\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

/*Challenge 10 : Rechercher un element
ecrivez un programme C qui recherche un element specifique dans un tableau d'entiers en utilisant une recherche lineaire. Le programme doit demander a l'utilisateur le nombre d'elements, les elements du tableau, et l'element a rechercher, puis afficher si l'element est present ou non.*/
void rechercherElement() {
    printf("Challenge 10: Rechercher un element\n");
    int size = 0, nb, present = 0;
    int tab[100];

    printf("Veuillez saisir la taille du tableau : ");
    scanf("%d", &size);

    printf("Veuillez saisir les valeurs :\n");
    for (int i = 0; i < size; i++) {
        printf("tab[%d] = ", i);
        scanf("%d", &tab[i]);
    }

    printf("Entrez l'element a rechercher : ");
    scanf("%d", &nb);

    for (int i = 0; i < size; i++) {
        if (tab[i] == nb) {
            present = 1;
            printf("L'element %d est trouve a l'indice %d\n", nb, i);
        }
    }

    if (!present) {
        printf("L'element %d n'est pas trouve\n", nb);
    }
}
/*Challenge 11 : Remplacer un element
ecrivez un programme C qui remplace toutes les occurrences d'une valeur specifique 
dans un tableau d'entiers par une nouvelle valeur.
 Le programme doit demander a l'utilisateur le nombre d'elements,
  les elements du tableau, la valeur a remplacer, et la nouvelle valeur.
*/

void remplacerElement() {
    printf("Challenge11 : Remplacer un element\n");
    int size, old, new;
    int tab[100];
    printf("Veuillez saisir la taille du tableau : ");
     scanf("%d", &size);
    printf("Veuillez saisir les valeurs :\n");
    for (int i = 0; i < size; i++) {
        printf("tab[%d] = ", i);
        scanf("%d", &tab[i]);
    }
    printf("Veuillez saisir la valeur a remplacer : ");
    scanf("%d", &old);
    printf("Veuillez saisir la nouvelle valeur : ");
    scanf("%d", &new);

    for (int i = 0; i < size; i++) {
        if (tab[i] == old) {
            tab[i] = new;
        }
    }

    printf("Affichage du tableau  :\n");
    for (int i = 0; i < size; i++) {
        printf("tab[%d] = %d\n", i, tab[i]);
    }
}
/*
Challenge 12 : Afficher les elements Paire
ecrivez un programme C qui affiche uniquement les elements pairs 
d'un tableau d'entiers. Le programme doit demander le nombre d'elements et les elements du tableau.

*/
void afficherElementsPairs() {
    printf("Challenge 12: Afficher les elements Pairs\n");
    int size;
    int tab[100];

    printf("Veuillez saisir la taille du tableau : ");
    scanf("%d", &size);
    printf("Veuillez saisir les valeurs :\n");
    for (int i = 0; i < size; i++) {
        printf("tab[%d] = ", i);
        scanf("%d", &tab[i]);
    }

    printf("Affichage des elements pairs :\n");
    for (int i = 0; i < size; i++) {
        if (tab[i] % 2 == 0) {
            printf("tab[%d] = %d\n", i, tab[i]);
        }
    }
}
/*Challenge 13 : Afficher les elements Impairs
ecrivez un programme C qui affiche uniquement les elements impairs d'un tableau d'entiers.
 Le programme doit demander le nombre d'elements et les elements du tableau.

*/
void afficherElementsImpairs() {
    printf("Challenge : Afficher les elements Impairs\n");
    int size;
    int tab[100];
    printf("Veuillez saisir la taille du tableau : ");
    scanf("%d", &size);
    printf("Veuillez saisir les valeurs :\n");
    for (int i = 0; i < size; i++) {
        printf("tab[%d] = ", i);
        scanf("%d", &tab[i]);
    }

    printf("Affichage des elements impairs :\n");
    for (int i = 0; i < size; i++) {
        if (tab[i] % 2 != 0) {
            printf("tab[%d] = %d\n", i, tab[i]);
        }
    }
}
/*Challenge 14 : Calculer la Moyenne
ecrivez un programme C qui calcule la moyenne des elements d'un tableau d'entiers.
 Le programme doit demander le nombre d'elements, les elements du tableau, puis afficher la moyenne.
*/
void calculerMoyenne() {
    printf("Challenge : Calculer la Moyenne\n");
    int size, sum = 0;
    int tab[100];

    printf("Veuillez saisir la taille du tableau : ");
    scanf("%d", &size);

    printf("Veuillez saisir les valeurs :\n");
    for (int i = 0; i < size; i++) {
        printf("tab[%d] = ", i);
        scanf("%d", &tab[i]);
        sum = sum + tab[i];
    }

    double moyenne = (double)sum / size;
    printf("La moyenne est : %.2f\n", moyenne);

}
/*
Challenge 15 : Fusion de Deux Tableaux
ecrivez un programme C qui fusionne deux tableaux d'entiers en un seul tableau.
 Le programme doit demander a l'utilisateur le nombre d'elements pour chaque tableau, 
 puis les elements des deux tableaux, et afficher le tableau fusionne.
*/
void fusionnerTableaux() {
    printf("Challenge : Fusionner Deux Tableaux\n");
    int size1, size2;
    int tab1[100], tab2[100], tabFusion[200];

    printf("Veuillez saisir la taille du premier tableau : ");
    scanf("%d", &size1);
    printf("Veuillez saisir les valeurs du premier tableau :\n");
    for (int i = 0; i < size1; i++) {
        printf("tab1[%d] = ", i);
        scanf("%d", &tab1[i]);
    }

    printf("Veuillez saisir la taille du deuxieme tableau : ");
    scanf("%d", &size2);
    printf("Veuillez saisir les valeurs du deuxieme tableau :\n");
    for (int i = 0; i < size2; i++) {
        printf("tab2[%d] = ", i);
        scanf("%d", &tab2[i]);
    }

    for (int i = 0; i < size1; i++) {
        tabFusion[i] = tab1[i];
    }
    for (int i = 0; i < size2; i++) {
        tabFusion[size1 + i] = tab2[i];
    }

    printf("Affichage du tableau fusionne :\n");
    for (int i = 0; i < size1 + size2; i++) {
        printf("tabFusion[%d] = %d\n", i, tabFusion[i]);
    }
}
#include "contact.h"



int Rechercher() {
    system(CLEAR); 
    int i ,  id=0;
    char name[50];
    printf(BLUE "NOM : "RESET);
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = 0;
  
    for (i = 0; i < compteur; i++) { 
        if (strcmp(contact[i].nom, name) == 0) {
            printf("Id : %d\n", i);
            printf("Nom : %s\n", contact[i].nom);
            printf("Telephone : %s\n", contact[i].tel);
            printf("Email : %s\n", contact[i].email);
            id = i;
        }
    }

    if ( id==0) {
        printf(RED"  1.\n"RESET, name);
        return 0; //introuvable en renvoi -1 
    } else {
        return id; 
    }
    
}
void triBulleParNom() {
    int i, j;
    CONTACT temp;
    int sorted;

    for (i = 0; i < compteur - 1; i++) {
        sorted = 1; // le tableau est déjà trié
        for (j = 0; j < compteur - 1 - i; j++) {
            if (strcmp(contact[j].nom, contact[j + 1].nom) > 0) {
                temp = contact[j];
                contact[j] = contact[j + 1];
                contact[j + 1] = temp;
                sorted = 0; // le tableau n'est pas encore trié 
            }
        }
        // Si aucune permutation n'a eu lieu, le tableau est trié
        if (sorted) {
            break;
        }
    }
}

void triSelectionParNom() {
    int i, j, minIndex;
    CONTACT temp;

    for (i = 0; i < compteur - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < compteur; j++) {
            if (strcmp(contact[j].nom, contact[minIndex].nom) < 0) {
                minIndex = j;
            }
        }
        
        if (minIndex != i) {
            temp = contact[i];
            contact[i] = contact[minIndex];
            contact[minIndex] = temp;
        }
    }
}

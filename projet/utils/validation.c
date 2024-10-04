#include "../header.h"  
#include "style.h"
#include <stdlib.h>
#include <ctype.h>

/************************************* */
// mina / Mi-> Mina
void capitalizeFirstLetter(char *str) {
    if (str[0] != '\0') {
        str[0] = toupper(str[0]);  // majuscule 
    }

    for (int i = 1; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);  // minuscules
    }
}

int is_alpha_string(Str_RES res) {
    char nom[50], prenom[50] , tel[50] ;
    int validNom = 1, validPrenom = 1, validTel = 1, validAge = 1, validDate = 1;
    strcpy(nom, res.nom);
    strcpy(prenom, res.prenom);
    strcpy(tel, res.telephone);
    int age = res.age;
    DATE date = res.date;

    // nom 
    int sizeNom = strlen(nom);
    for (int i = 0; i < sizeNom; i++) {
        if (isalpha(nom[i]) == 0) {
            validNom = 0;
        }
    }
    if (validNom == 0) {
        printf(YELLOW"Nom invalide. Veuillez reessayer.\n"RESET);
    }

    // prenom 
    int sizePrenom = strlen(prenom);
    for (int i = 0; i < sizePrenom; i++) {
        if (isalpha(prenom[i]) == 0) {
            validPrenom = 0;
        }
    }
    if (validPrenom == 0) {
        printf(YELLOW"Prenom invalide. Veuillez reessayer.\n"RESET);
    }

    // tel 
    int sizeTel = strlen(tel);
    if (tel[0] == '0' && sizeTel == 9) {
        for (int i = 1; i < 10; i++) {
            if (!isdigit(tel[i])) {
                validTel = 0;
            }
        }
        if (validTel == 0) {
            printf(YELLOW"Telephone invalide. Veuillez reessayer.\n"RESET);
        }
    }

    // age 
    if (age < 0 || age > 140) {
        validAge = 0;
        printf(YELLOW"Age invalide. Veuillez reessayer.\n"RESET);
    }

    // date 
    if (!(date.jour > 0 && date.jour < 32 && date.mois > 0 && date.mois < 13 && date.annee > 2020 && date.annee < 2060)) {
        validDate = 0;
        printf(YELLOW"Date invalide. Veuillez reessayer.\n"RESET);
    }

    if (validAge && validNom && validPrenom && validTel && validDate) {
        return 1;
    } else {
        return 0;
    }
}

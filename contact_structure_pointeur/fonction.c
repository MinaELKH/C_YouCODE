#include "contact.h"

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

int is_alpha_string(const char *nom , const char *tel , const char *email) { //  on a ajoute const pour montrer que le nom doit pas etre modifie
    
    // nom 
    int sizeNom  = strlen(nom);
    for (int i = 0; i < sizeNom; i++) {
        if (isalpha(nom[i]) == 0) {
            return 0;  // s il a trouve une valeur non alpha va sortir  
        }
    }

    // tel 
    int sizeTel  = strlen(tel);
    for (int i = 0; i < sizeTel; i++) {
        if (!isNumerique(tel[i])) {
            return 0;  // s il a trouve une valeur non num va sortir  
        }
    }

     // email
    int sizeTel  = strlen(tel);
    for (int i = 0; i < sizeTel; i++) {
        if (isalpha(nom[i]) == 0) {
            return 0;  // s il a trouve une valeur non alpha va sortir  
        }
    }


    return 1;  //sinon il va envoyer un 1 pour dire que la valeur ne contient que des alpha
}


/************************************** */
void AjouterContactsExemple()
{
    // Tableaux de chaînes pour les données prédéfinies des contacts
    char noms[10][50] = {"Ahmed", "Fatima", "Omar", "Khadija", "Hassan", "Leila", "Youssef", "Amina", "Rachid", "Sara"};

    char tels[10][15] = {"0612345678", "0698765432", "0712345678", "0798765432", "0812345678", "0898765432", "0912345678", "0998765432", "0512345678", "0598765432"};

    char emails[10][50] = {
        "ahmed@gmail.com", "fatima@gmail.com", "omar@gmail.com", "khadija@gmail.com", "hassan@gmail.com",
        "leila@gmail.com", "youssef@gmail.com", "amina@gmail.com", "rachid@gmail.com", "sara@gmail.com"};
    int i = compteur; 
    for (int j = 0; j < 10; j++ , i++)
    {
        strcpy(contact[i].nom, noms[j]);
        strcpy(contact[i].tel, tels[j]);
        strcpy(contact[i].email, emails[j]);
      
    }
    compteur = i; // le nouveau nb d contact apres l ajout des exemples

}


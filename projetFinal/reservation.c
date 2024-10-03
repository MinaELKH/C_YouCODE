#include "reservation.h"




void Ajouter() {
    if (compteur >= MAX_RES) {
        printf("Erreur : nombre maximum de reservations atteint.\n");
        return;
    }
     printf("------           Ajouter une reservation           --------\n");
    Str_RES res;
    printf("Entrez le nom : ");
    fgets(res.nom, MAX_CHAR, stdin);
    res.nom[strcspn(res.nom, "\n")] = 0; 

    printf("Entrez le prenom : ");
    fgets(res.prenom, MAX_CHAR, stdin);
    res.prenom[strcspn(res.prenom, "\n")] = 0;

    printf("Entrez le telephone : ");
    fgets(res.telephone, MAX_CHAR, stdin);
    res.telephone[strcspn(res.telephone, "\n")] = 0;

    printf("Entrez l'age : ");
    scanf("%d", &res.age);
    getchar(); // Pour nettoyer le buffer d'entree

    printf("Entrez le statut (0: VALIDE, 1: REPORTE, 2: ANNULE, 3: TRAITE) : ");
    int statut_input;
    scanf("%d", &statut_input);
    
    // Validation du statut
    while (statut_input < 0 || statut_input > 3) {
        printf("Statut invalide. Veuillez choisir entre 0 et 3 : ");
        scanf("%d", &statut_input);
    }

    res.statut = (Statut)statut_input;

    printf("Entrez la date de reservation (jj mm aaaa) : ");
    scanf("%d %d %d", &res.date.jour, &res.date.mois, &res.date.annee);

    // Generer une reference
    genererRef(res.reference);
    
    // Ajouter la reservation au tableau
    arrayRes[compteur] = res;
    printf("res  compteur : %d.\n" , compteur);
    compteur++;
    printf("Reservation ajoutee avec succes.\n");
 
}
void AfficherList() {
 printf("------          Afficher la liste des Patients qui ont réservé       --------\n");
    printf("Nombre des Reservatio : %d\n", compteur);
    printf("+----------+----------+----------+-------------+-------+----------+---------------+\n");
    printf("|   REF    |   Nom    |  Prenom  |  Telephone  |  Age  |  Statut  |     Date      |\n");
    printf("+----------+----------+----------+-------------+-------+----------+---------------+\n");
    
    for (int i = 0; i < compteur; i++) { 
        printf("| %-8s | %-8s | %-8s | %-11s | %-5d | %-8s | %02d/%02d/%-8d |\n",
               arrayRes[i].reference,               
               arrayRes[i].nom,              
               arrayRes[i].prenom,             
               arrayRes[i].telephone,         
               arrayRes[i].age,               
               statutToString(arrayRes[i].statut), 
               arrayRes[i].date.jour, 
               arrayRes[i].date.mois, 
               arrayRes[i].date.annee);           
    }
    printf("+----------+----------+----------+-------------+-------+----------+---------------+\n");

}
/***************************************************** */
int RechercherParReference() {
    TriResRef_Bulle(); 
    printf("------           Rechecher une reservation           --------\n");
    int  index=0;
            char ref[50];
            printf("REF: ");
            fgets(ref, 50, stdin);
            ref[strcspn(ref, "\n")] = 0;
    index  = RechercherRef_Dichotomique(ref);
    printf(" l index est %d \n", index);
    AfficherRef(index);
    return index ; 
}
/************************************************** */
void Modifier(void) { 
   printf("------           Modifier une reservation           --------\n");
    int index = RechercherParReference() ; 
    formulaire(index);  
}
/******************************************************* */
void Supprimer(void) { 
    printf("------           Supprimer une reservation           --------\n");
    int index = RechercherParReference() ; 
    for (int i = index; i < compteur-1; i++)
    {
        arrayRes[i] = arrayRes[i + 1];
    }
    compteur--;
    printf("\n  Le contact a ete supprime avec succes !\n");
    
}

void AfficherDetails() { 
       printf("------          Afficher  une reservation           --------\n");
    int i ,  index=0;
    char ref[50];
            printf("REF: ");
            fgets(ref, 50, stdin);
            ref[strcspn(ref, "\n")] = 0;
    index = RechercherParReference(ref);
}

void TrierParNom(void) { 
    printf("--.\n");
}

void AfficherStatistiques(void) { 
    printf("--.\n");
}















// Fonction pour ajouter des reservations par defaut
void AjouterReservationPardefaut() {
    char noms[10][50] = {"Amine", "Hamed", "Nadir", "Saadi", "Zahid", "Jaber", "Salem", "Rafik", "Farid", "Azhar"};
    char prenoms[10][50] = {"Hassna", "Fatima", "Omar", "Khadija", "Hassan", "Leila", "Youssef", "Amina", "Rachid", "Sara"};
    char tels[10][15] = {"0612345678", "0698765432", "0712345678", "0798765432", "0812345678", "0898765432", "0912345678", "0998765432", "0512345678", "0598765432"};
    int ages[10] = {25, 60, 22, 28, 35, 16, 40, 75, 18, 27};
    int jour[10] = {2, 10, 7, 4, 5, 16, 30, 8, 18, 27}; //on peut pas mettre 08 ou 07 car il concedere comme a base de octe et nous somme sur base de decimal 
    int mois[10] = {2, 4, 2, 5, 10, 16, 14, 15, 10, 27};  
    int annee[10] = {2024, 2023, 2022, 2028, 2025, 2021, 2024, 2022, 2018, 2027};
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
        
            printf("res  compteur : %d.\n" , compteur);
        compteur++;

    }
}

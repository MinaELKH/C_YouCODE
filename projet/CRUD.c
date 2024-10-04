#include "header.h"
#include "utils/style.h"


void genererRef(char *ref) {
   
    snprintf(ref, 50, "REF%d", compteurRef++);
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
    capitalizeFirstLetter(res.nom);

    printf("Entrez le prenom : ");
    fgets(res.prenom, MAX_CHAR, stdin);
    res.prenom[strcspn(res.prenom, "\n")] = 0;
    capitalizeFirstLetter(res.prenom); 

    printf("Entrez le telephone : ");
    fgets(res.telephone, MAX_CHAR, stdin);
    res.telephone[strcspn(res.telephone, "\n")] = 0;

    printf("Entrez l'age : ");
    scanf("%d", &res.age);
 
    printf("Entrez le statut (0: VALIDE, 1: REPORTE, 2: ANNULE, 3: TRAITE) : ");
    int statut_input;
    scanf("%d", &statut_input);
    
    // Validation du statut
    while (statut_input < 0 || statut_input > 3) {
        printf("Statut invalide. Veuillez choisir entre 0 et 3 : ");
        scanf("%d", &statut_input);
    }

    res.statut = (Statut)statut_input;

    printf("Entrez la date de reservation (jj-mm-aaaa) : ");
    scanf("%d-%d-%d", &res.date.jour, &res.date.mois, &res.date.annee);

    // Generer une reference
    genererRef(res.reference);
    

     int valide =  is_alpha_string( res);
     if(valide==1){
    // Ajouter la reservation au tableau
            arrayRes[compteur] = res;
            printf(GREEN"le Nombre total de reservation est  : %d.\n"RESET , compteur);
            compteur++;
            printf(GREEN"Reservation ajoutee avec succes.\n"RESET);
     }
     else {
                printf(RED"Erreur lors de l ajout.\n"RESET);
     }
}

void AfficherList() {

    enteteTableau() ;// juste affichage de l entete de tableau 
    for (int i = 1; i < compteur; i++) { 
       //char statut[] =  statutToString(arrayRes[i].statut) ;
       const char* statutStr = statutToString(arrayRes[i].statut);
       const char* statutColor = getStatutColor(arrayRes[i].statut);

        printf("| %-8s | %-8s | %-8s | %-11s | %-5d |%s%-10s%s| %02d/%02d/%-7d |\n",
               arrayRes[i].reference,               
               arrayRes[i].nom,              
               arrayRes[i].prenom,             
               arrayRes[i].telephone,         
               arrayRes[i].age,               
               //statutToString(arrayRes[i].statut), 
               statutColor, statutStr, RESET,
               arrayRes[i].date.jour, 
               arrayRes[i].date.mois, 
               arrayRes[i].date.annee);           
    }
    printf("+----------+----------+----------+-------------+-------+----------+---------------+\n");

}
/************************************************** */
void Modifier(void) { 
   printf("------           Modifier une reservation           --------\n");
    int index = RechercherParReference() ; 
    if (index>0){formulaire(index); printf(GREEN"Reservation Modifee avec succes.\n"RESET); }
    
}
/******************************************************* */
void Supprimer(void) { 
    printf("------           Supprimer une reservation           --------\n");
    int index = RechercherParReference() ; 
    if (index > 0 ){
    for (int i = index; i < compteur-1; i++)
    {
        arrayRes[i] = arrayRes[i + 1];
    }
    compteur--;
    printf(GREEN"\n  Le contact a ete supprime avec succes !\n"RESET);}
    
}
// detaille d une seule reservation 
void AfficherDetails() { 
     printf("------          Afficher  une reservation           --------\n");
     RechercherParReference();
}



/********************    formulaire modif ************************** */

void formulaire( int index){
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
        printf(RED"Statut invalide. Veuillez choisir entre 0 et 3 : \n"RESET);
        scanf("%d", &statut_input);
    }

    res.statut = (Statut)statut_input;
  
    printf("Entrez la date de reservation (jj mm aaaa) : ");
    scanf("%d %d %d", &res.date.jour, &res.date.mois, &res.date.annee);

    strcpy(res.reference, arrayRes[index].reference);

    arrayRes[index] = res;
 
}


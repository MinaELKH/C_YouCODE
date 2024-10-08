#include "reservation.h"

#include "style.h"



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

    void enteteTableau() ;// juste affichage de l entete de tableau 
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
// cette fonction est base sur la fonction 
void AfficherDetails() { 
     printf("------          Afficher  une reservation           --------\n");
     RechercherParReference();
}

void AfficherStatistiques(void) { 
    printf("--.\n");
}




/********************  trier par   */
// reference 
void TrierParRef(){
    TriRes_Bulle(comparerREF) ; 
}
// Nom
void TrierParNom() { 
    TriRes_Bulle(comparerNom) ;
}
// Date
void TrierParDate(){
    TriRes_Bulle(comparerDate) ; 
}
// Statut
void TrierParStatut(){
    TriRes_Bulle(comparerStatut) ; 
}


/***************************************************** */

/**************************** Recherche ************************* */
int RechercherParReference() {
    TrierParRef(); 
    int  index=0;
            char ref[50];
            printf("REF: ");
            fgets(ref, 50, stdin);
            ref[strcspn(ref, "\n")] = 0;
    index  = RechercherRef_Dichotomique(ref);
    AfficherIndex(index);
    return index ; 
}

void RechercherParNom(){
    TrierParNom(); //  il va verfiver est ce que c est tri avec variable sorted sinnon il va le tri
    int  index=0;
   
            char nom[50];
            printf("Nom: ");

            fgets(nom, 50, stdin);
            nom[strcspn(nom, "\n")] = 0;
     RechercherNom_Dichotomique(nom);
  
}

void RechercherParDate(){
   TrierParDate(); 
    int  annee , jour , mois , index=0;
            char nom[50];
            printf("Date (ex 11-02-2024) ");
            scanf("%d-%d-%d" , &annee , &mois , &jour );
            DATE dat = {annee , mois , jour}; 
   RechercherDate_Dichotomique(dat);
}

void RechercherParStatut(){
       printf("Entrez le statut (0: VALIDE, 1: REPORTE, 2: ANNULE, 3: TRAITE) : ");
    int statut_input;
    scanf("%d", &statut_input);
    
    // Validation du statut
    while (statut_input < 0 || statut_input > 3) {
        printf("Statut invalide. Veuillez choisir entre 0 et 3 : ");
        scanf("%d", &statut_input);
    }
  RechercherStatut_Linaire(statut_input) ; 
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

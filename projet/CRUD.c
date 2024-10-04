#include "header.h"
#include "utils/style.h"


void genererRef(char *ref) {
   
    snprintf(ref, 50, "REF%d", compteurRef++);
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

    printf("Entrez le prenom : ");
    fgets(res.prenom, MAX_CHAR, stdin);
    res.prenom[strcspn(res.prenom, "\n")] = 0;

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


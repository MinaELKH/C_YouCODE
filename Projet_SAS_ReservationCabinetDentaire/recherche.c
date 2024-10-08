#include "header.h"
#include "utils/style.h"


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


/************************************   recherche *********************** */

// cette fonction est fonctionnelle mais j utlise la 2ieme plus general pour eviter la reptition 
int RechercherRef_Dichotomique(char* reference ) {
    int low = 0, high = compteur - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int cmp = strcmp(arrayRes[mid].reference, reference);

        if (cmp == 0) {
            return mid;  
        }

        if (cmp < 0) {
            low = mid + 1;  // Chercher dans la moitié supérieure
        } else {
            high = mid - 1;  // Chercher dans la moitié inférieure
        }
    }
    return -1;  // Référence non trouvée
}


/*int RechercherNom_Dichotomique( char* nomRech) {
    int low = 0, high = compteur - 1;
    Str_RES resRech ;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        int cmp = strcmp(arrayRes[mid].nom, nomRech);
        if (cmp == 0) {
            return mid;  
        }

        if (cmp < 0) {
            low = mid + 1;  // Chercher dans la moitié supérieure
        } else {
            high = mid - 1;  // Chercher dans la moitié inférieure
        }
    }
    return -1;  // Référence non trouvée
}*/
void RechercherNom_Dichotomique(char* nomRech) { // semi dich
    int low = 0, high = compteur - 1;
    int index = -1;
    
    // Étape 1 : Recherche dichotomique pour trouver une occurrence
    while (low <= high) {
        int mid = (low + high) / 2;
        int cmp = strcmp(arrayRes[mid].nom, nomRech);
        
        if (cmp == 0) {
            index = mid;  // Trouver une occurrence
            break;
        }

        if (cmp < 0) {
            low = mid + 1;  // Chercher dans la moitié supérieure
        } else {
            high = mid - 1;  // Chercher dans la moitié inférieure
        }
    }

    // Étape 2 : Si aucune occurrence n'est trouvée, afficher un message et quitter
    if (index == -1) {
        printf("Aucune reservation trouvee pour le nom: %s\n", nomRech);
        return;
    }

    // Étape 3 : Afficher toutes les occurrences du nom (avant et après `index`)
    // Afficher les occurrences avant `index`
    enteteTableau() ; // juste affichage de l entete de tableau 
    int i = index;
    while (i >= 0 && strcmp(arrayRes[i].nom, nomRech) == 0) {
        AfficherIndex(i);  // Fonction qui affiche la réservation à l'index donné
        i--;
    }

    // Afficher les occurrences après `index`
    i = index + 1;
    while (i < compteur && strcmp(arrayRes[i].nom, nomRech) == 0) {
        AfficherIndex(i);  // Fonction qui affiche la réservation à l'index donné
        i++;
    }
}


void RechercherDate_Dichotomique(DATE dateRech) {  // semi dich , qd il trouve la valeur recherche il monte en haut et descant pour chercher les occurences du valeur  
    int low = 0, high = compteur - 1;
    int index = -1;
        Str_RES resRech ;
    resRech.date.annee = dateRech.annee ; 
    resRech.date.mois = dateRech.mois ; 
    resRech.date.jour = dateRech.jour ; 
    // Étape 1 : Recherche dichotomique pour trouver une occurrence de la date
    while (low <= high) {
        int mid = (low + high) / 2;

        // Comparaison des dates avec la fonction comparerDate
        int cmp = comparerDate(arrayRes[mid], resRech);

        if (cmp == 0) {
            index = mid;  // Trouver une occurrence
            break;
        }

        if (cmp < 0) {
            low = mid + 1;  // Chercher dans la moitié supérieure
        } else {
            high = mid - 1;  // Chercher dans la moitié inférieure
        }
    }

    // Étape 2 : Si aucune occurrence n'est trouvée, afficher un message et quitter
    if (index == -1) {
        printf("Aucune réservation trouvée pour la date : %02d/%02d/%d\n", 
               dateRech.jour, dateRech.mois, dateRech.annee);
        return;
    }

    // Étape 3 : Afficher toutes les occurrences de la date (avant et après `index`)
    // Afficher les occurrences avant `index`
    int i = index;
    while (i >= 0 && comparerDate(arrayRes[i], resRech) == 0) {
       AfficherIndex(i);  // Fonction qui affiche la réservation à l'index donné
        i--;
    }

    // Afficher les occurrences après `index`
    i = index + 1;
    while (i < compteur && comparerDate(arrayRes[i], resRech) == 0) {
        AfficherIndex(i);  // Fonction qui affiche la réservation à l'index donné
        i++;
    }
   
}

void RechercherStatut_Linaire(int statut) {  // semi dich , qd il trouve la valeur recherche il monte en haut et descant pour chercher les occurences du valeur  
    enteteTableau();
    for (int i = 1; i < compteur; i++) { 
        if (arrayRes[i].statut==statut) {
          AfficherIndex(i);
        }
    }
}

/************************************   Afficher une Reseration *********************** */
void AfficherIndex(int i) { 
    if (i>0){
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
    printf("+----------+----------+----------+-------------+-------+----------+---------------+\n");
   }else {
           printf("Aucune reservation trouvee.\n");
   }

}

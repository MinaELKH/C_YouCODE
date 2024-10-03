#include "reservation.h"
#include "util.h"


const char* statutToString(Statut statut) {
    switch (statut) {
        case VALIDE: return "valide";
        case REPORTE: return "reporte";
        case ANNULE: return "annule";
        case TRAITE: return "traite";
        default: return "inconnu";
    }
}

void genererRef(char *ref) {
   
    snprintf(ref, 50, "REF%d", compteurRef++);
}

void menu() {
    int choix;
    bool continuer = true;
    char reference[MAX_CHAR];

    while (continuer) {
        printf(GREEN"\n----- Menu de Gestion des Reservations -----\n"RESET);
        printf("1. Ajouter\n");
        printf("2. Modifier\n");
        printf("3. Supprimer\n");
        printf("4. Afficher  \n");
        printf("5. Trier \n");
        printf("6. Rechercher\n");
        printf("7. Statistiques\n");
        printf("8. Liste des reservations\n");
        
        printf("0. Quitter le programme\n");
        printf("Veuillez choisir une option : ");
        
        scanf("%d", &choix);
        getchar();

        switch (choix) {
            case 1:
            clearScreen();
                Ajouter(); // Pas besoin de passer des paramètres
                break;
            case 2:
                clearScreen();
                Modifier(); // Pas besoin de passer des paramètres
                break;
            case 3:
             clearScreen();
                Supprimer(); // Pas besoin de passer des paramètres
                break;
            case 4:
             clearScreen();
                AfficherDetails(); 
                break;
            case 5: {// trier
                 clearScreen();
                 printf("/********* Trier par :  ***********/ \n 1: Reference\t  2: Nom\t  3: Date\t  4:Statue \n");
                 menuTrier(); 
                break;}
              
            case 6: {
                RechercherParReference(); 
                break;
            }
            case 7:
                AfficherStatistiques(); 
                break;
            case 8 : 
                 AfficherList();
                 break; 
            case 9 : 
                 TriResRef_Bulle();
                 break; 
            case 0:
                continuer = false;
                printf("Merci d'avoir utilise le programme. À bientôt !\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
                break;
        }
    }
}


void clearScreen() {
    #ifdef _WIN32
        system("cls");  
    #else
        system("clear");  
    #endif
}

/*********************     tri     ************************************* */
void TriResRef_Bulle(){
    int i, j;
    Str_RES temp;
    int sorted;

    for (i = 0; i < compteur - 1; i++) {
        sorted = 1; // le tableau est déjà trié
        for (j = 0; j < compteur - 1 - i; j++) {
           if (strcmp(arrayRes[j].reference, arrayRes[j + 1].reference) > 0){
                temp = arrayRes[j];
                arrayRes[j] = arrayRes[j + 1];
                arrayRes[j + 1] = temp;
                sorted = 0; // le tableau n'est pas encore trié 
            }
        }
        // Si aucune permutation n'a eu lieu, le tableau est trié
        if (sorted) {
            break;
        }
    }

}


void TriRes_Bulle(int (*comparer)(Str_RES  ,Str_RES)){
    int i, j;
    Str_RES temp;
    int sorted;

    for (i = 0; i < compteur - 1; i++) {
        sorted = 1; // le tableau est déjà trié
        for (j = 0; j < compteur - 1 - i; j++) {
           if (comparer(arrayRes[j], arrayRes[j + 1]) > 0){
                temp = arrayRes[j];
                arrayRes[j] = arrayRes[j + 1];
                arrayRes[j + 1] = temp;
                sorted = 0; // le tableau n'est pas encore trié 
            }
        }
        // Si aucune permutation n'a eu lieu, le tableau est trié
        if (sorted) {
            break;
        }
    }

}


int comparerREF(Str_RES a , Str_RES b){
     return    strcmp(a.reference, b.reference) ; 
}
int comparerNom(Str_RES a , Str_RES b){
     return    strcmp(a.nom, b.nom) ; 
}
int comparerDate(Str_RES a , Str_RES b){
        if(a.date.annee > b.date.annee )
             { return 1 ; }
        else if (a.date.annee == b.date.annee &&  a.date.mois > b.date.mois )
             { return 1 ; }
        else if (a.date.annee == b.date.annee &&  a.date.mois == b.date.mois && a.date.jour > b.date.jour )
             {  return 1 ;}
        else {return 0 ; }
}

int comparerStatut(Str_RES a , Str_RES b){
        if(a.statut > b.statut ){
            return 1 ; 
        } else {return 0 ; }
}
/************************************   recherche *********************** */
int RechercherRef_Dichotomique(char* reference) {
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


/************************************   Afficher une Reseration *********************** */
void AfficherRef(int i) { 
    if (i>0){
        printf("+----------+----------+----------+-------------+-------+----------+---------------+\n");
       printf("|   REF    |   Nom    |  Prenom  |  Telephone  |  Age  |  Statut  |     Date      |\n");
       printf("+----------+----------+----------+-------------+-------+----------+---------------+\n");
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
    printf("+----------+----------+----------+-------------+-------+----------+---------------+\n");
   }else {
           printf("Aucune reservation trouvee.\n");
   }

}




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
        printf("Statut invalide. Veuillez choisir entre 0 et 3 : ");
        scanf("%d", &statut_input);
    }

    res.statut = (Statut)statut_input;
  
    printf("Entrez la date de reservation (jj mm aaaa) : ");
    scanf("%d %d %d", &res.date.jour, &res.date.mois, &res.date.annee);

    strcpy(res.reference, arrayRes[index].reference);

    arrayRes[index] = res;
    printf("Modifffffffff: ");
}


/********************  sous   menu                */

void menuTrier(){
    int choix;
     printf("Choix : ");
     scanf("%d", &choix);
    switch(choix) {
        case 1 : TrierParRef();  break; 
        case 2 : TrierParNom();  break; 
        case 3 : TrierParDate();  break;
        case 4 : TrierParStatut();  break;
       default : printf("choix invalide");  break;
    }
    AfficherList() ;
}
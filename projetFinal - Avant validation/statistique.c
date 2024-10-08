#include "reservation.h"
#include "util.h"


void CalculerMoyAge(){
    int sum = 0;
     for(int i=1 ; i<compteur ; i++) {
        sum =sum + arrayRes[i].age;
     }
     float moy = sum/compteur ; 
     printf(MAGENTA"la moyenne d'age des patients ayant reserve" RESET" : %.f\n\n" , moy) ; 

}
void TrancheAge() {
    triAge_selection();  // Tri du tableau par âge
    
    int i = 1 , t1=0 ,t2=0  , t3=0 ;
    //enteteTableau();
   // printf(BG_WHITE RED"*********           Tranche d'Age -18:                 *************************"RESET);
   // printf("\n");
 // printf("+----------+----------+----------+-------------+-------+----------+---------------+\n");
    while (i < compteur && arrayRes[i].age <= 18) {   // Parcours des âges inférieurs à 18
       // AfficherIndex(i);
        i++;
        t1++ ; 
    }

   // printf( BG_WHITE RED"*********           Tranche d'Age 19-35:                 **************************"RESET);
    // printf("\n");
  //  printf("+----------+----------+----------+-------------+-------+----------+---------------+\n");
    while (i < compteur && arrayRes[i].age >= 19 && arrayRes[i].age <= 35) {  // Parcours des âges entre 18 et 35
       // AfficherIndex(i);
        i++;
        t2++ ; 
    }

   // printf( BG_WHITE RED"*********           Tranche d'Age 36+:                 *************************"RESET);
    //printf("\n");
  //  printf("+----------+----------+----------+-------------+-------+----------+---------------+\n");
    while (i < compteur && arrayRes[i].age > 35) {  // Parcours des âges supérieurs à 35
      //  AfficherIndex(i);
        i++;
        t3++ ; 
    }

    printf(MAGENTA"Nombre des reservations par tranche d age :\n"RESET);
    printf("\tTranche d'Age -18   : %d \n" ,t1);
    printf("\tTranche d'Age 19-35 : %d \n",t2);
    printf("\tTranche d'Age +36   : %d \n\n",t3);

}

void NbReservationStatut(){
    TrierParStatut(); 
     int i = 1 , t1=0 ,t2=0  , t3=0  , t4=0;
   
    while (i <=  compteur && arrayRes[i].statut == 0) {   // 0 VALIDE
        i++;
        t1++ ; 
    }
    while (i <=  compteur && arrayRes[i].statut == 1) {  //1 REPORTE
        i++;
        t2++ ; 
    }
    while (i <= compteur && arrayRes[i].statut == 2) {  // 2 ANNULE
        i++;
        t3++ ; 
    }
   while (i <= compteur && arrayRes[i].statut == 3) {  // 3 traite
        i++;
        t4++ ; 
    }
    printf(MAGENTA"Nombre des reservations par statut :\n"RESET);
    printf("\t Valide  : %d \n" ,t1);
    printf("\t Reporte : %d \n",t2);
    printf("\t Annule  : %d \n",t3);
    printf("\t Traite  : %d \n",t4);
}
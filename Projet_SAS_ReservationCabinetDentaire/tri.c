#include "header.h"
#include "utils/style.h"


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

/*********************     tri     ************************************* */

// cette fonction not use , elle est remplace par triRes_Bulle
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
         else if (a.date.annee == b.date.annee &&  a.date.mois == b.date.mois && a.date.jour == b.date.jour )
             {  return 0 ;}
        else {return -1 ; }
}
int comparerStatut(Str_RES a , Str_RES b){
        if(a.statut > b.statut ){
            return 1 ; }
        else if(a.statut == b.statut){return 0 ; }
        else {return -1 ; }
}

void triAge_selection() {
    int ind_min;
    Str_RES temp; 

    for (int i = 0; i < compteur - 1; i++) {
        ind_min = i;  
        for (int j = i + 1; j < compteur; j++) {
            if (arrayRes[j].age < arrayRes[ind_min].age) {
                ind_min = j;  
            }
        }
        if (ind_min != i) {
            temp = arrayRes[i];
            arrayRes[i] = arrayRes[ind_min];
            arrayRes[ind_min] = temp;
        }
    }
}
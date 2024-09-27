#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define sizeBook 100
#define sizeAutor 50
#define sizeTitle 50


char title[sizeBook][sizeTitle];
char autor[sizeBook][sizeAutor];
float price[sizeBook];
int qte[sizeBook];
int compteur = 1;  


void Create();   
void Get();         
int Find();       
void SetQte();      
void Delete();    
void GetQte();      

int main() {
    int choix;

    while (1) {  
        printf("\n******** Menu de Gestion de Stock ********\n");
        printf("1. Ajouter un livre au stock.\n");
        printf("2. Afficher tous les livres disponibles.\n");
        printf("3. Rechercher un livre par son titre.\n");
        printf("4. Mettre à jour la quantité d'un livre.\n");
        printf("5. Supprimer un livre du stock.\n");
        printf("6. Afficher le nombre total de livres en stock.\n");
        printf("7. Quitter.\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        getchar();

        switch (choix) {
            case 1:
                Create();
                break;
            case 2:
                Get();
                break;
            case 3:
                Find();
                break;
            case 4:
                SetQte();
                break;
            case 5:
                Delete();
                break;
            case 6:
                GetQte();
                break;
            case 7:
                printf("Au revoir !\n");
                exit(0);  
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    }

    return 0;
}
void  Create() {
    int i = compteur++;  
    printf("******** Ajouter un livre **********\n"); 
    
    printf("Titre du livre : ");fgets(title[i], 50, stdin);
    title[i][strcspn(title[i], "\n")] = '\0';
    
    printf("Auteur du livre : "); fgets(autor[i], 50, stdin);
    autor[i][strcspn(autor[i], "\n")] = '\0';
    
    printf("Prix du livre : ") ; scanf("%f", &price[i]);
    printf("Quantite disponible : "); scanf("%d", &qte[i]);

    printf("\nLivre ajoute avec succes !\n");
}
void Get(){
     printf("******** Liste de livres **********\n"); 
      printf("\nTitre\t Auteur\t Prix\t Quantite\f \n") ;
    for(int i = 1 ; i < compteur ;i++)
    {
         printf(" %s\t %s\t %.2f\t %d\t \n  " ,title[i] , autor[i] , price[i] , qte[i] );
    }
}         
int Find(){
     printf("******** Chercher un livre **********\n"); 
     char name[sizeTitle] ; 
     bool find = false ;
     int i; 
     printf("Titre du livre recherche: ");
     fgets(name, 50, stdin);
     name[strcspn(name, "\n")] = 0;

      for(i = 1 ; i < compteur ;i++)
      {
         if (strcmp((name) ,title[i] )==0) {
         find = true ; 
         printf("Titre\t Auteur\t Prix\t Quantite\f \n %s\t %s\t %.2f\t %d\t  " ,title[i] , autor[i] , price[i] , qte[i] );
         break ; 
    }  }
    if (find = true) {
         return i ; 
    } else {
         printf("\nle livre n est pas trouve");
        return 0 ;
    }
}         
void SetQte(){
    int i = Find(); 
    if (i != 0 ){
         printf("\nle livre est trouve , vous pourrez entrer la nouvelle quantite");
         scanf("%d",&qte[i]); 
    } else {printf("Veuillez entrer le livre d abord ");}
}        
void Delete(){
     int i = Find();
     if (i != 0 ){
           for (i; i < compteur; i++)
     {
         title[i] = title[i + 1];
         autor[i] = autor[i+1];
         price[i] = price[i + 1];
         qte[i] = qte[]; 
     }
    } else {printf("Veuillez entrer le livre d abord ");}
   
}      
void GetQte(){}    
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
int compteur = 0;  


void Create();   
void Get();         
int Find();       
void SetQte();      
void Delete();    
void GetQte();
void menu();

int main() {
    menu(); 
    return 0;
}

void  Create() {
    int i = ++compteur;

    printf("Titre du livre : ");fgets(title[i], 50, stdin);
    title[i][strcspn(title[i], "\n")] = '\0';
    
    printf("Auteur du livre : "); fgets(autor[i], 50, stdin);
    autor[i][strcspn(autor[i], "\n")] = '\0';
    
    printf("Prix du livre : ") ; scanf("%f", &price[i]);
    printf("Quantite disponible : "); scanf("%d", &qte[i]);

    printf("\nLivre ajoute avec succes --- nombre de livres est %d : !\n" , compteur );
}
void Get(){
     if (compteur == 0 ){  
        printf("Le stock est vide, aucun livre n'est disponible.\n");
        exit;
     }else {
    printf("*************************************** Liste de livres *****************************\n"); 
    printf("+--------+---------------------+---------------------+--------+---------+\n");
    printf("+  id    | Titre               | Auteur              | Prix   | Quantite|\n");
    printf("+--------+---------------------+---------------------+--------+---------+\n");

    for(int i = 1 ; i <=compteur ;i++)
    {
        printf("| %-6.2d | %-19s | %-19s | %-6.2f | %-7d|\n",i , title[i] , autor[i] , price[i] , qte[i]);
    }
    printf("+--------+---------------------+---------------------+--------+---------+\n");
     }
}         
int Find(){
    
     char name[sizeTitle] ; 
     bool find = false ;
     int i , id; 
     printf("Titre du livre recherche: ");
     fgets(name, 50, stdin);
     name[strcspn(name, "\n")] = 0;
    if (compteur == 0 ){  
        printf("Le stock est vide, aucun livre n'est disponible.\n");
        exit;
     }
    else{
        printf("*************************** Liste de livres *****************************\n"); 
        printf("+--------+---------------------+---------------------+--------+---------+\n");
        printf("+  id    | Titre               | Auteur              | Prix   | Quantite|\n");
        printf("+--------+---------------------+---------------------+--------+---------+\n");

        for(i = 1 ; i <= compteur ;i++)
        {
            if (strcmp((name) ,title[i] )==0) {
                    find = true ;
                    id = i; 
                     printf("| %-6.2d | %-19s | %-19s | %-6.2f | %-7d|\n",i , title[i] , autor[i] , price[i] , qte[i]);
                    break ; 
               } 
        }
        printf("+--------+---------------------+---------------------+--------+---------+\n");
        if (find == true) {
            return id ; 
        } else {
            printf("Nom de livre invalide. Veuillez reessayer.\n");
            return -1 ;
        }     
    }
}         
void SetQte(){
    int i = Find(); 
    if (i > 0 ){
         printf("\n Pourrez-vous entrer la nouvelle quantite  : ");
         scanf("%d",&qte[i]); 
    }  //else {printf("Nom de livre invalide. Veuillez reessayer.\n ");}
}        
void Delete(){
     int id = Find();
     bool deleted = false;
     if (id > 0 ){
         for ( int i = id; i <= compteur-1; i++)
                {
                    strcpy(title[i], title[i + 1]);
                    strcpy(autor[i], autor[i + 1]);
                    price[i] = price[i + 1];
                    qte[i] = qte[i+1];
                    
                }
        deleted = true;
        printf("\nLivre a ete supprime avec succes !\n");
        compteur--;
     }
  else {printf("Erreur : Aucun livre trouvé pour suppression.\n");}
   
}   

void GetQte(){
    int sum=0; 
    for (int i = 1 ; i <= compteur; i++)
    {
        sum = sum +qte[i]; 
     
     }

        printf("\n la somme de livre est %d : " , sum);
}    


void menu(){
    int choice ,  reponse;
    do
    {  
        printf("\n******** Menu de Gestion de Stock ********\n");
        printf("1. Ajouter un livre au stock.\n");
        printf("2. Afficher tous les livres disponibles.\n");
        printf("3. Rechercher un livre par son titre.\n");
        printf("4. Mettre a jour la quantite d'un livre.\n");
        printf("5. Supprimer un livre du stock.\n");
        printf("6. Afficher le nombre total de livres en stock.\n");
        printf("0. Quitter.\n");
        printf("Votre choix : ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
              printf("******** Ajouter un livre **********\n"); 
                Create();
                break;
            case 2:
                printf("******** Afficher un livre **********\n"); 
                Get();
                break;
            case 3:
                 printf("******** Chercher un livre **********\n"); 
                Find();
                break;
            case 4:
                printf("******** Modifier un livre **********\n"); 
                SetQte();
                break;
            case 5:
                printf("******** Supprimer un livre **********\n"); 
                Delete();
                break;
            case 6:
                printf("******** Afficher la quantite **********\n"); 
                GetQte();
                break;
            case 0:
                printf("Au revoir !\n");
                exit(0);  
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
        printf("\nTapez '1' pour Revenir au menu ou '0' pour quitter : ");
        scanf("%d", &reponse); 
        if (reponse == 0) {
            printf("Au revoir !\n");
            exit(0);
        }else if (reponse != 0 && reponse != 1){
            printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (reponse != '1'); 
}
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct contact {
    char nom[50];
    char tel[10];
    char email[50];
} CONTACT;

CONTACT contact[100];

int compteur=1;

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}


void Ajouter();
int Rechercher();
void Supprimer();
void Modifier();
void ListContact();

void menu(){
    int choice ;
    do {
    printf("----- Menu Contact -----\n");
    printf("1. Ajouter un contact.\n");
    printf("2. Modifier un contact.\n");
    printf("3. Supprimer un contact.\n");
    printf("4. Listes des contacts.\n");
    printf("5. Chercher un contact par nom.\n");
    printf("0. Quitter le programme .\n");
    printf("----------------\n");
    printf("Entrez votre choix : ");
    scanf("%d", &choice);
    getchar();
    switch (choice) { 
        case 1:
            Ajouter();
            break;
        case 2:
            Modifier();
            break;
        case 3:
            Supprimer();
            break;
        case 4 :
            ListContact();
            break;
        case 5:
            printf("******** Chercher un contact par NOM ******** \n");
            Rechercher();
            break;
        case 0 :
            exit;
        default:
            printf("Choix invalide. Veuillez ressayer.\n");
            break;
    }

    } while(choice != 0); 

}

int main() {
    menu();
    return 0;
}

void Ajouter(){
    
     printf("********  Ajouter  ********\n ");
     printf("Veuiller remplir cette formulaire \n");

     int i = compteur++;

    printf("Nom : ");
    fgets(contact[i].nom, sizeof(contact[i].nom), stdin);
    contact[i].nom[strcspn(contact[i].nom, "\n")] = 0;


    printf("Telephone : ");
    fgets(contact[i].tel, sizeof(contact[i].tel), stdin);
    contact[i].tel[strcspn(contact[i].tel, "\n")] = 0;
    

    printf("email : ");
    fgets(contact[i].email, sizeof(contact[i].email), stdin);
    contact[i].email[strcspn(contact[i].email, "\n")] = 0;
   

     printf("\n Le Contact  ajoute avec succes --- nombre de contacts est %d : !\n" , compteur );
}
void ListContact() {
    int i;
   
        printf("*************************** Liste de Contact *******************\n"); 
        printf("+--------+---------------------+---------------------+---------------------+\n");
        printf("+  id    | Contact             | telephone           | email  | \n");
        printf("+--------+---------------------+---------------------+---------------------+\n");
    for (i = 1; i < compteur; i++) { 
      printf("| %-6.2d | %-19s | %-19s | %-19s |\n",i , contact[i].nom ,  contact[i].tel ,  contact[i].email );
      printf("-------------------------------------------------------------------------------\n");
    }
}
int Rechercher() {
    int i ,  id=0;
    char name[50];
    printf("NOM : ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = 0;

    for (i = 0; i < compteur; i++) { 
        if (strcmp(contact[i].nom, name) == 0) {
            printf("Id : %d\n", i);
            printf("Nom : %s\n", contact[i].nom);
            printf("Telephone : %s\n", contact[i].tel);
            printf("Email : %s\n", contact[i].email);
            id = i;
        }
    }

    if ( id==0) {
        printf("Le contact %s introuvable.\n", name);
        return 0; //introuvable en renvoi -1 
    } else {
        return id; 
    }
    
}
void Supprimer(){
      printf("******** Supprimer un contact par NOM ******** \n");
    int id = Rechercher();
    if(id>0){
    for (int i = id; i < compteur-1; i++)
    {
        contact[i] = contact[i + 1];
    }
    compteur--;
    printf("\nLe contact a ete supprime avec succes !\n");
    } 
     
}
void Modifier(){
      printf("******** Modifier un contact par NOM ******** \n");
    int id = Rechercher();
    if(id>0){
      printf("\nVeuillez saisir les nouvelles donnees : \n");
     printf("Telephone : ");
     fgets(contact[id].tel, sizeof(contact[id].tel), stdin);
     contact[id].tel[strcspn(contact[id].tel, "\n")] = 0; 

     printf("email : ");
     fgets(contact[id].email, sizeof(contact[id].email), stdin);
     contact[id].email[strcspn(contact[id].email, "\n")] = 0;  
    }
    printf("\nLe contact a ete modifie avec succes !\n");
}
     




#include "contact.h"
CONTACT contact[MAX_contacts];
int compteur=1;

void menu();
void Ajouter();
int Rechercher();
void Supprimer();
void Modifier();
void ListContact();
// maj
void toLowerCase(char *str); 

int main() {
    printf("Nombre total de contact %d", compteur); 
    menu();
    return 0;
}

void menu(){
    system(CLEAR); 
    int choice ;
    do {
    printf(GREEN"----- Menu Contact -----\n"RESET);
    printf("1. Ajouter un contact.\n");
    printf("2. Modifier un contact.\n");
    printf("3. Supprimer un contact.\n");
    printf("4. Listes des contacts.\n");
    printf("5. Chercher un contact par nom.\n");
    printf(MAGENTA "6. Ajouter dix contacts par defaut pour tester le programme.\n" RESET);
      printf("\n");
    printf("\t\t" RED "0. Quitter le programme.\n" RESET);
    printf("----------------\n");
    printf(BLUE"Entrez votre choix : "RESET);
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
        case 6:
            AjouterContactsExemple();
            break;
        case 0 :
            exit;
            break;
        default:
            printf("Choix invalide. Veuillez ressayer.\n");
            break;
    }

    } while(choice != 0); 

}


void Ajouter(){
    system(CLEAR); 
     printf("********  Ajouter  ********\n ");
     printf("Veuiller remplir cette formulaire \n");

     int i = compteur++;

    printf(BLUE "Nom : "RESET);
    fgets(contact[i].nom, sizeof(contact[i].nom), stdin);
    contact[i].nom[strcspn(contact[i].nom, "\n")] = 0;
    toLowerCase(contact[i].nom);

    printf(BLUE "Telephone : "RESET);
    fgets(contact[i].tel, sizeof(contact[i].tel), stdin);
    contact[i].tel[strcspn(contact[i].tel, "\n")] = 0;
    

    printf(BLUE "email : "RESET);
    fgets(contact[i].email, sizeof(contact[i].email), stdin);
    contact[i].email[strcspn(contact[i].email, "\n")] = 0;
   

     printf(GREEN"\n   Le Contact  ajoute avec succes --- nombre de contacts est %d : !\n" RESET , compteur );
}
void ListContact() {
    system(CLEAR);
    int i;
   
        printf("*************************** Liste de Contact *******************\n"); 
        printf("+--------+---------------------+---------------------+---------------------+\n");
        printf("+  id    | Contact             | telephone           | email               | \n");
        printf("+--------+---------------------+---------------------+---------------------+\n");


    for (i = 1; i < compteur; i++) { 
      printf("| %-6.2d | %-19s | %-19s | %-19s |\n",i , contact[i].nom ,  contact[i].tel ,  contact[i].email );
      printf("-------------------------------------------------------------------------------\n");
    }
}
int Rechercher() {
    system(CLEAR); 
    int i ,  id=0;
    char name[50];
    printf(BLUE "NOM : "RESET);
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = 0;
    toLowerCase(name); 

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
        printf(RED"  1.\n"RESET, name);
        return 0; //introuvable en renvoi -1 
    } else {
        return id; 
    }
    
}
void Supprimer(){
    system(CLEAR); 
      printf("******** Supprimer un contact par NOM ******** \n");
    int id = Rechercher();
    if(id>0){
    for (int i = id; i < compteur-1; i++)
    {
        contact[i] = contact[i + 1];
    }
    compteur--;
    printf(GREEN"\n  Le contact a ete supprime avec succes !\n"RESET);
    } 
     
}
void Modifier(){
    system(CLEAR); 
      printf("******** Modifier un contact par NOM ******** \n");
    int id = Rechercher();
    if(id>0){
      printf(CYAN"\nVeuillez saisir les nouvelles donnees : \n"RESET);
     printf("Telephone : ");
     fgets(contact[id].tel, sizeof(contact[id].tel), stdin);
     contact[id].tel[strcspn(contact[id].tel, "\n")] = 0; 

     printf("email : ");
     fgets(contact[id].email, sizeof(contact[id].email), stdin);
     contact[id].email[strcspn(contact[id].email, "\n")] = 0;  
    }
    printf(GREEN"\n  Le contact a ete modifie avec succes !\n"RESET);
}
     


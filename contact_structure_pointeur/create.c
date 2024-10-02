#include "contact.h"
is_alpha_string(const char *valeur);

CONTACT create(  int *compteur){
    CONTACT contact1;
    int i = *compteur;
 
    system(CLEAR); 
     printf("********  Ajouter  ********\n ");
     if (i==MAX_contacts){
         printf("Le carnet de contacts est sature\n");
     }else{

                printf("Veuiller remplir cette formulaire \n");

                printf(BLUE "Nom : "RESET);
                fgets(contact1.nom, sizeof(contact1.nom), stdin);
                contact1.nom[strcspn(contact1.nom, "\n")] = 0;

                printf(BLUE "Telephone : "RESET);
                fgets(contact1.tel, sizeof(contact1.tel), stdin);
                contact1.tel[strcspn(contact1.tel, "\n")] = 0;
                

                printf(BLUE "email : "RESET);
                fgets(contact1.email, sizeof(contact1.email), stdin);
                contact1.email[strcspn(contact1.email, "\n")] = 0;

                contact[i] = contact1; 

                printf(GREEN "\n   Le Contact  ajoute avec succes --- nombre de contacts est %d : !\n" RESET, compteur);
                (*compteur)++;
   
    }
   
}
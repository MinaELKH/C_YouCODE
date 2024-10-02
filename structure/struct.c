#include <stdio.h>
#include <unistd.h>
//exo 3
  typedef   struct rectangle
    {
        float largeur;
        float longeur; 

    } rectangle ;
// exo 4
  typedef   struct point
    {
        int x;
        int y;

    } POINT; 
// exo 5 
 typedef struct livre
 {
     char titre[50];
     char auteur[50];
     int annee;
 }LIVRE; 
 

void definitionStruct(); //exo 1
void StructTableau();// exo 2
float AireRectangle(); // exo 3
LIVRE RetourStructLivre(); // exo5
void Structpoint(); // exo4


int main(){
    int choix; 
   printf("1. ****************** Structure ***************************\n");
    printf("1. challenge 1 :Definition et Utilisation de Structure.\n");
    printf("2. Challenge 2 : Structure avec Tableau.\n");
    printf("3. Challenge 3 : Passage de Structure en Argument\n");
    printf("4. Challenge 4 : Structure avec Pointeurs.\n");
     printf("5. Challenge 5 : Structure et Fonction de Retour.\n");


    printf("Choisissez une option: ");
    scanf("%d", &choix);

    POINT p = {0.0};
    POINT *pt = &p;
    LIVRE livre1;


    switch (choix)
    {
    case 1 :  definitionStruct(); break;
    case 2 :  StructTableau(); break;
    case 3 : { 
               struct rectangle rec = {2 , 4}; 
               printf(" l aire du rectangle est %.2f :", AireRectangle(rec)); 
               break;}
    case 4 :
   
        Structpoint(pt);
        break;
    case 5 : {
        livre1 = RetourStructLivre();
        printf(" livre  => titre : %s   , auteur : %s  , annee :%d ", livre1.titre, livre1.auteur, livre1.annee);
        break;
    }
    default:
        break;
}
    return 0; 
}


/*Challenge 1 : Définition et Utilisation de Structure
Écrivez un programme C qui définit une structure pour représenter une personne avec les champs nom
, prenom, et age. Créez une variable de cette structure, assignez des valeurs aux champs, 
et affichez ces valeurs.*/
void definitionStruct(){
     printf("Challenge 1: \n");
typedef   struct std
    {
        char nom[50];
        char prenom[50];
        int age; 
    } std ;
    std std1 = {"sara" , "ouss" , 18};
    printf(" etudiant (nom:%s  , prenom:%s  , age:%d)" , std1.nom , std1.prenom , std1.age);
}



/*Challenge 2 : Structure avec Tableau
Écrivez un programme C qui définit une structure pour représenter un étudiant avec les champs nom, 
prenom, et un tableau d'entiers pour stocker les notes. Assignez des valeurs aux champs et aux notes, 
puis affichez les informations de l'étudiant.
*/
void StructTableau(){
     printf("Challenge 2: \n");
typedef   struct std
    {
        char nom[50];
        char prenom[50];
        float note[3]; 
    } std ;
    std std1 = {"ines" , "alami" , {10 , 16 , 20}};
    printf(" etudiant => nom:%s  , prenom:%s   , note :" , std1.nom , std1.prenom);
    for (int i = 0; i < 3; i++)
    {
      printf("%.2f  "   ,  std1.note[i] ); 
    }
}
/*Challenge 3 : Passage de Structure en Argument
Écrivez un programme C qui définit une structure pour représenter un rectangle
 avec les champs longueur et largeur. Écrivez une fonction qui prend une variable 
 de cette structure en argument et calcule l'aire du rectangle. Affichez l'aire 
 dans le programme principal.*/
float  AireRectangle( rectangle rec){
     printf("Challenge 3: \n");
     float aire = (rec.longeur * rec.largeur) ;
     return  aire;

}

/*Challenge 4 : Structure avec Pointeurs
Écrivez un programme C qui définit une structure pour représenter un point dans 
un plan avec les champs x et y. 
Utilisez des pointeurs pour créer une variable de cette structure et modifiez ses valeurs. 
Affichez les valeurs du point.*/

void Structpoint(POINT *pt){
    printf("Challenge 4: \n");
    printf("A(%d,%d)" , pt->x , pt->y); 
    printf(" veuillez saisir x  y ");
    scanf("%d %d", &pt->x, &pt->y);
     printf("A(%d,%d)" ,pt->x , pt->y);

}

/* Challenge 5 : Structure et Fonction de Retour
Écrivez un programme C qui définit une structure pour représenter 
un livre avec les champs titre, auteur, et année. 
Écrivez une fonction qui retourne une variable de 
cette structure initialisée avec des valeurs données. 
Affichez les informations du livre dans le programme principal.*/

LIVRE RetourStructLivre(){
    LIVRE livre1 = {"Biblio Adam", "Victor", 2012};
    return livre1; 
}
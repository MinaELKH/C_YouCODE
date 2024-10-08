#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>

//Exercices sur les Boucles en C
void tableMultiplication();
void factorielle();
void sommeNNombres();
void nombresImpairs();
void calculPuissance();
void nombresPairs();
void inversionEntier();
void suiteFibonacci();
void compteurChiffres();
void sommeNEntiers();

int main() {
    int choix;

    do {
        // Affichage du menu
        printf("\n===== MENU =====\n");
        printf("1. Table de Multiplication\n");
        printf("2. Factorielle d'un Nombre\n");
        printf("3. Somme des N Nombres\n");
        printf("4. Affichage des N Premiers Nombres Impairs\n");
        printf("5. Calcul de la Puissance\n");
        printf("6. Affichage des N Premiers Nombres Pairs\n");
        printf("7. Inversion d'un Entier\n");
        printf("8. Affichage de la Suite de Fibonacci\n");
        printf("9. Compteur de Chiffres\n");
        printf("10. Calcul de la Somme des N Entiers\n");
        printf("0. Quitter\n");
        printf("=================\n");
        printf("Choisissez une option: ");
        scanf("%d", &choix);

        // Appel des fonctions selon le choix de l'utilisateur
        switch (choix) {
            case 1: tableMultiplication(); break;
            case 2: factorielle(); break;
            case 3: sommeNNombres(); break;
            case 4: nombresImpairs(); break;
            case 5: calculPuissance(); break;
            case 6: nombresPairs(); break;
            case 7: inversionEntier(); break;
            case 8: suiteFibonacci(); break;
            case 9: compteurChiffres(); break;
            case 10: sommeNEntiers(); break;
            case 0: printf("Au revoir!\n"); break;
            default: printf("Option invalide! Veuillez réessayer.\n");
        }

    } while (choix != 0);

    return 0;
}

/*Challenge 1 : Table de Multiplication
Écrivez un programme C qui demande un nombre à l’utilisateur et affiche sa table de multiplication de 1 à 10. Par exemple, pour le nombre 4, affichez :
4 * 1 = 4 4 * 2 = 8 4 * 3 = 12 ... 4 * 10 = 40*/

void tableMultiplication() {
      printf("******** *Challenge 1 : Table de Multiplication*********\n");
    int nb ;
    printf("Veuillez saisir un nombre : ");
    scanf("%d", &nb);
    for (int i = 0; i < 11; i++){
        printf("\n %d * %d = %d", nb, i, nb * i); 
    }
}
/*Challenge 2 : Factorielle d'un Nombre
Écrivez un programme C qui calcule la factorielle d'un nombre entier positif n entré par l’utilisateur. La factorielle de n est le produit de tous les entiers positifs inférieurs ou égaux à n. Par exemple, pour n = 5, affichez : 5! = 120.
 */
void factorielle() {
    printf("******** *Challenge 2 : Factorielle d'un Nombre*********\n");
    int nb ;
    long f = 1;
    printf("Veuillez saisir un nombre : ");
     scanf("%d", &nb);
      for (int i = 1 ; i <= nb; i++){
          f = f * i; 
      }
       printf("%d! = %ld", nb, f); 

}

/*Challenge 3 : Somme des N Nombres
Écrivez un programme C qui demande un nombre entier n à l’utilisateur 
et calcule la somme des n premiers nombres naturels. 
Par exemple, pour n = 4, la somme est 1 + 2 + 3 + 4 = 10.
*/
void sommeNNombres() {
   printf("******** *Challenge 3 : Somme des N Nombres*********\n");
    int nb , sum =0 ;
    printf("Veuillez saisir un nombre : ");
     scanf("%d", &nb);
      for (int i = 1 ; i <= nb; i++){
          sum = sum + i; 
      }
       printf("la somme est %d", sum  ); 
}
/*Challenge 4 : Affichage des N Premiers Nombres Impairs
Écrivez un programme C qui demande un nombre entier n et affiche les n premiers nombres impairs.
 Par exemple, pour n = 5, affichez : 1, 3, 5, 7, 9.
*/
void nombresImpairs() {
    printf("******** *Challenge 4 : Affichage des N Premiers Nombres Impairs*********\n");
    int nb ;
    printf("Veuillez saisir un nombre : ");
     scanf("%d", &nb);
    printf("les nombres impairs :  " ); 
      for (int i = 0 ; i <= nb; i=i+2){
           printf("%d\t", i ); 
      }
}
/*Challenge 5 : Calcul de la Puissance
Écrivez un programme C qui calcule la puissance d'un nombre entier base élevé à un exposant exposant.
 Utilisez une boucle pour effectuer le calcul. Par exemple,
  pour base = 3 et exposant = 4, le résultat est 3^4 = 81.
*/
void calculPuissance() {
     printf("******** *Challenge 5 : Calcul de la Puissance*********\n");
    int nb , ex  ;
    long res = 1;
    printf("Veuillez saisir un nombre  et un exposant  : ");
    scanf("%d %d", &nb , &ex);
      for (int i =1  ; i <= ex ; i++){
                res = res * nb; 
      }
       printf("%d^%d =  %ld", nb , ex , res  ); 
}
/*
Challenge 6 : Affichage des N Premiers Nombres Pair
Écrivez un programme C qui demande un nombre entier n et affiche les n premiers nombres pairs. 
Par exemple, pour n = 4, affichez : 2, 4, 6, 8.
*/
void nombresPairs() {
    printf("******** *Challenge  6: Affichage des N Premiers Nombres Pairs*********\n");
    int nb ;
    printf("Veuillez saisir un nombre : ");
     scanf("%d", &nb);
    printf("les nombres impairs :  " ); 
      for (int i = 1 ; i <= nb; i=i+2){
        printf("%d\t", i ); 
      }
}
/* Challenge 7 : Inversion d'un Entier
Écrivez un programme C qui lit un entier à plusieurs chiffres et 
l'affiche en ordre inverse sans utiliser de tableaux.
 Par exemple, si l'entrée est 12345, affichez 54321.
 */
void inversionEntier() {
   printf("******** *Challenge 7 : Inversion d'un Entier*********\n");
   int nb , rest=0 , unite =0;
    printf("Veuillez saisir un nombre : ");
     scanf("%d", &nb);
     do{
            unite=nb%10;
            nb = nb/10 ;
            rest=rest*10 + unite ;
        }while(nb%10!=0) ;
     printf("Nombre inverse est %d: \n" , rest);
     
}


/*
Challenge 8 : Affichage de la Suite de Fibonacci
Écrivez un programme C qui génère les n premiers termes de la suite de Fibonacci, 
où n est entré par l’utilisateur. L
a suite de Fibonacci est définie comme suit : F(0) = 0, F(1) = 1, et F(n) = F(n-1) + F(n-2).
*/

void suiteFibonacci() {
     printf("******** *Challenge 8 : Affichage de la Suite de Fibonacci*********\n");
     int n, i;
     long long F0 = 0, F1 = 1; 
     long long FN, FN1, FN2;

     do {
     printf("Entrez la valeur de N  superieur a 2 : ");
     scanf("%d", &n);
  }while (n<2) ;
 // on commence par n= 1
     FN1=F1;
     FN2 =F0 ; 

  for (i = 2; i <= n; i++)
  {
      FN = FN1 + FN2;
      FN2 = FN1;
      FN1 = FN;
      printf("F(%d) = %llu\n", i, FN);
     } 
}
/*Challenge 9 : Compteur de Chiffres
Écrivez un programme C qui demande à l’utilisateur un entier positif 
et compte le nombre de chiffres dans cet entier. 
Par exemple, pour n = 12345, affichez : Nombre de chiffres = 5.
*/
void compteurChiffres() {
   printf("******** *Challenge 9 : Compteur de Chiffres*********\n");
   int nb , iter=0 ;
   printf("Veuillez saisir un nombre : ");
   scanf("%d", &nb);
     do{
            nb=nb / 10;
            iter++; 
        }while(nb%10!=0) ;
        
     printf("Nombre de chiffre %d: \n" , iter);
 
}
/*Challenge 10 : Calcul de la Somme des N Entiers
Écrivez un programme C qui demande à l’utilisateur un nombre entier n 
et calcule la somme des n premiers entiers naturels en utilisant une boucle. 
Par exemple, pour n = 3, la somme est 1 + 2 + 3 = 6.*/

void sommeNEntiers() {
      printf("******** *Challenge 10 : Somme des N Nombres*********\n");
    int nb , sum =0 ;
    printf("Veuillez saisir un nombre : ");
     scanf("%d", &nb);
      for (int i = 1 ; i <= nb; i++){
          sum = sum + i; 
      }
       printf("la somme est %d", sum  ); 
}
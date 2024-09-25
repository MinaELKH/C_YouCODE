#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void AffichageInformations();
void ConversionTemperature();
void ConversionDistance();
void ConversionVitesse(); 
void AffichageTemperatureEtat();
void Calcul();
void MoyennePonderee();
void calculMoyenGeometrique();
void calculDistanceEntreDeuxPoint();
void VolumeSphere();
void SurfaceRectangle();
void NombreEntierInverse();
void AfficherValeurBinaireHexadecimale();
void ViderTamponEntree()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);  }


int main() {
    int choice;
    do { 
         printf("\n --------------------------------------------------------------\n");
        printf("\n \n        /* * * * * *  *  * Menu * * * * * *  *  */\n");
        printf("\n             >> Veuillez Choisir le numero d exercice       \n");
        printf("\n --------------------------------------------------------------\n");
        printf("1. Afficher les informations \n");
        printf("2. Conversion de temperature (Celsius -> Kelvin)\n");
        printf("3. Conversion de distance ( KM -> Yards) \n");
        printf("4. Conversion de vitesse (km/h -> m/s )\n");
        printf("5. Afficher l'etat de matiere selon sa temperature\n");
        printf("6. Calcul deux Nombres \n");
        printf("7. Calcul de la moyenne ponderee\n");
        printf("8. Calcul du moyenne geometrique\n");
        printf("9. Calcul de la distance entre deux points\n");
        printf("10. Calcul du volume d'une sphere\n");
        printf("11. Calcul de la surface d'un rectangle\n");
        printf("12. Inverse un nombre entier\n");
        printf("13. Afficher une valeur en binaire et en hexadecimale\n");
        printf("0. Quitter\n");
        printf("\n -------------------------------------------------------------- \n\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choice);
         ViderTamponEntree(); 
        switch (choice) {
            case 1:
               AffichageInformations();
            break;
            case 2:
                ConversionTemperature();
            break;
            case 3:
                ConversionDistance();
            break;
            case 4:
                ConversionVitesse();
            break;
            case 5:
                AffichageTemperatureEtat();
            break;
            case 6:
                Calcul();
            break;
            case 7:
                MoyennePonderee();
            break;
            case 8:
                calculMoyenGeometrique();
                break;
            case 9 :
                calculDistanceEntreDeuxPoint(); 
                break;
            case 10 :
                VolumeSphere();
                break;
            case 11 :
                SurfaceRectangle();
                break;
            case 12 :
                NombreEntierInverse();
                break;
            case 13 :
                AfficherValeurBinaireHexadecimale();
                break;
            case 0:
                 printf("Au revoir\n");
            break;
            default:
                printf("Choix non valide\n");
            }
            } while (choice != 0);
          

            return 0;
}

/*Challenge 1 : Affichage Informations
Écrivez un programme en C qui va permettre d'afficher vos informations personnelles : nom, prénom, âge, sexe, et adresse email. Les données sont saisies à partir du clavier.
*/


//exo1
void AffichageInformations() {
    char nom[50];
    char prenom[50];
    int age;
    char email[50];
    char sexe; 

    printf("******** Veuillez  Entrer vos informations *********\n");
    printf("Nom : ");
    fgets(nom, sizeof(nom), stdin);
    printf("Prenom : ");
    fgets(prenom, sizeof(prenom), stdin);
    printf("Email : ");
    fgets(email, sizeof(email), stdin);
    printf("Age : ");
    scanf("%d", &age);
    printf("Sexe (M/F) : ");
    scanf(" %c", &sexe); 

    printf("******** Affichage *********\n");
    printf("{Nom : %s \n", nom);
    printf("Prenom : %s \n", prenom);
    printf("Age : %d \n", age);
    printf("Sexe : %c \n", sexe);
    printf("Email : %s }\n", email);
}
// exo 2
/* Challenge 2 : Conversion de la température
Écrivez un programme qui demande la température en Celsius et la transforme en Kelvin.
Formule :
K = C + 273.15*/


void ConversionTemperature(){
    printf("******** Conversion de la Temperature *********\n");
    float cel, kel;
    printf("Veuillez saisir la temperature en *C : ");
    scanf("%.2f", &cel);
    kel = cel + 273.15;
    printf("La temperature en Kelvin  : %f \n", kel);
}
/*
// exo 3
Challenge 3 : Conversion de la distance
Écrivez un programme qui demande la distance en kilomètres et la transforme en yards.
Formule :
Yards = Km * 1093.61*/

void ConversionDistance(){
    printf("******** Conversion de la Distance *********\n");
    float  Yards , Km;
    printf("Veuillez saisir la distance en KM : ");
    scanf("%.2f", &Km);
    Yards = Km * 1093.61; 
    printf("La distance en Yard  : %.2f \n", Yards);
}

// exo 4

/*Challenge 4 : Conversion de la vitesse
Écrivez un programme qui demande la vitesse en kilomètres par heure (km/h) et la transforme en mètres par seconde (m/s).
Formule :
m/s = km/h * 0.27778*/
void ConversionVitesse(){
    printf("******** Conversion de la Vitesse *********\n");
    float  ms , kmh;
    printf("Veuillez saisir la vitesse en KM/H : ");
    scanf("%f", &kmh);
    ms = kmh * 0.27778;
    printf("La vitesse en Metre/seconde : %.2f \n", ms);
}

// exo 5
/*Challenge 5 : Affichage Température
Écrivez un programme qui demande la température en Celsius et affiche l'état de l'eau à cette température (solide, liquide, gaz).
Règle :

C < 0 : Solide
0 <= C < 100 : Liquide
C >= 100 : Gaz*/


void AffichageTemperatureEtat(){

    printf("\n******** Challenge 5 : Affichage Température : Etat(solid / liquide / gaz) *********\n");
    float  tp;
    printf("Veuillez saisir la temperature cl : ");
    scanf("%.2f", &tp);
     if (tp<0){
         printf("%d inferieur 0 : Solide", tp);
     } 
     else if (tp <100  && tp >0 ){
        printf("%d entre 0 et 100 Liquide", tp);
     }
     else  {
        printf("%d superieur Gaz", tp);
     } 
   
}

// exo 6
// Challenge 6 : Calcul et affichage des résultats
//Deux nombres réels, a et b, sont saisis au clavier. Calculez et affichez a + b, a - b, a * b, et a / b avec précision décimale.

void Calcul(){
    printf("\n******** Challenge 6 : Calcul et affichage des résultats *********\n");
    float  nb1 , nb2;
    printf("Veuillez saisir a , b  : ");
    scanf("%f  %f", &nb1 , &nb2);
    printf(" a + b  = %.2f \n", nb1 + nb2);
     printf(" a - b = %.2f  \n", nb1 - nb2);
      printf(" a * b = %.2f   \n", nb1 * nb2);
    if (nb2 =! 0)
            {printf(" a / b = %.2f  \n", nb1 / nb2);}
    else 
            {printf("on divise pas sur  0  \n");}

}
//exo 7 
/*Challenge 7 : Moyenne pondérée de trois nombres
Écrivez un programme en C pour calculer la moyenne pondérée de trois nombres donnés par l'utilisateur avec les pondérations suivantes :

1er nombre : pondération 2
2ème nombre : pondération 3
3ème nombre : pondération 5  */

void MoyennePonderee(){
    printf("\n******** Challenge 7 : Moyenne pondérée de trois nombres *********\n");
    float  nb1 , nb2 , nb3;
    float p1 = 2, p2 = 3, p3 = 5;
    printf("Veuillez saisir les nombres  a , b , c : ");
    scanf("%f %f %f",  &nb1 , &nb2 , &nb3);
    float moyenne = (nb1*p1 + nb2*p2 + nb3*p3) /(p1 + p2 +p3) ;
    printf("La moyenne ponderee est : %.2f \n", moyenne);

}

//exo 8
/*Challenge 8 : Calcul de la moyenne géométrique
Écrivez un programme en C pour trouver la moyenne géométrique de trois nombres saisis par l'utilisateur.
Formule :
Moyenne géométrique = (a * b * c)^(1/3)*/

 void calculMoyenGeometrique(){ 
    printf("\n******** Challenge 8 :  calcul de la Moyenne Geometrique  *********\n");
     float nb1, nb2, nb3;
     printf("Veuillez saisir les nombres a, b, c : ");
     scanf("%f %f %f" , &nb1 , &nb2 , &nb3);
     float moyenne = pow((nb1 * nb2  * nb3 ) , (1.0/3.0));
     printf("La moyenne geometrique est : %.2f \n", moyenne);
 }

//exo 9 
/*Challenge 9 : Calcul de la distance entre deux points dans un espace 3D
Écrivez un programme C pour trouver la distance entre deux points donnés dans un espace 3D.
Formule :
Distance = √((x2-x1)² + (y2-y1)² + (z2-z1)²)*/
void calculDistanceEntreDeuxPoint(){
     printf("\n******** Challenge 9 :   Calcul de la distance entre deux points dans un espace 3D  *********\n");
     float x1, x2, y1 , y2 , z1 , z2;
     printf("Veuillez saisir les coordonnees des deux points A, B )\n");
     printf("ponit A ( x , y , z) ");
     scanf("%f %f %f", &x1, &y1, &z1);
     printf("point B ( x , y , z)");
     scanf("%f %f %f", &x2, &y2, &z2); 
     float distance = sqrt(pow(x2 - x1, 2) + pow((y2 -y1) , 2) +pow((z2 -z1) , 2)) ; 
     printf("La distance entre A et B  est : %.2f \n", distance);
}

/*### Challenge 10 : Volume d'une sphère
Écrivez un programme pour trouver le volume d'une sphère. Prenez le rayon de la sphère en entrée de l'utilisateur.
Formule pour le volume d'une sphère :
```
Volume = (4/3) * π * r³
```*/
void VolumeSphere(){
     printf("\n******** Challenge 10 :   Volume d'une sphere  *********\n");
    const float pi = 3.1416;
    float r, volume;
     printf("Veuillez saisir le rayon :");
     scanf("%f", &r);
     volume = (4.0 / 3.0) * pi * pow(r, 3);
     printf("le volume de votre sphere  est : %.2f \n", volume);
}

/*### Challenge 11 : Surface d'un rectangle
Écrivez un programme pour trouver la surface d'un rectangle. Prenez la longueur et la largeur du rectangle en entrée de l'utilisateur.
Formule pour la surface d'un rectangle :
```
Surface = longueur * largeur
```*/
void SurfaceRectangle(){
    printf("\n******** Challenge 11 :   Surface d'un rectangle  *********\n");
    float lng, lrg, surface;
    printf("Veuillez saisir la longueur et la largeur  : ");
    scanf("%f %f", &lng, &lrg);
    surface = lng * lrg;
    printf("La surface du rectangle est : %.2f \n", surface);
    }

/*### Challenge 12 : Nombre entier à quatre chiffres en ordre inverse
Écrivez un programme C pour afficher un nombre entier à quatre chiffres dans l'ordre inverse sans utiliser de boucle. Par exemple, si le nombre entier est 1234, son inverse est 4321.
*/
void NombreEntierInverse() {
    printf("\n******** Challenge 12 :   Nombre entier à quatre chiffres en ordre ************ \n");
    int nb, nbInverse = 0 , rest = 0 ;

    printf("Veuillez saisir un nombre entier a quatre chiffres : \n");
    scanf("%d", &nb); //1234
       do{
           rest = nb % 10;
           nb = nb / 10 ;
           nbInverse = nbInverse * 10 + rest;

        }while(nb%10!=0) ;

        printf("Le nombre entier a quatre chiffres en ordre inverse est : %d " , nbInverse ) ;

}

/*### Challenge 13 : Affichage des valeurs binaire et hexadécimale équivalentes
Écrivez un programme C pour afficher la valeur équivalente en binaire et en hexadécimal.
 Entrez un nombre entier et affichez ses valeurs équivalentes en binaire et en hexadécimal.*/

 void AfficherValeurBinaireHexadecimale() {
    printf("\n******** Challenge 13 :   Afficher les valeurs binaire et hexadécimale *************/\n");
    int nb, index = 0;
    char binaire[33], hex[9]; 

    printf("Veuillez saisir un nombre : ");
    scanf("%d", &nb);

   
    for (int i = 0; i < 32; i++) {
        binaire[i] = '0';
    }
    binaire[32] = '\0'; 

   
    for (int i = 0; i < 8; i++) {
        hex[i] = '0';
    }
    hex[8] = '\0'; 

    /* Conversion binaire */
    int nbr_binaire = nb; 

    while (nbr_binaire > 0) {
        binaire[31 - index] = (nbr_binaire % 2) + '0';   // l ajout de '0' pour converti le chiffre nbr_binaire / 2 en code ascii  
        nbr_binaire = nbr_binaire / 2; 
        index++;
    }


 /* Conversion hexadécimale */
    int nbr_hex = nb;
    index = 0; 
    while (nbr_hex > 0) {
        int reste = nbr_hex % 16; 
        switch (reste) {
            case 10: 
               hex[7 - index] = 'A'; break;
            case 11: 
               hex[7 - index] = 'B'; break;
            case 12: 
               hex[7 - index] = 'C'; break;
            case 13: 
                hex[7 - index] = 'D'; break;
            case 14: 
                hex[7 - index] = 'E'; break;
            case 15: 
                hex[7 - index] = 'F'; break;
            default :
                hex[7 - index] = reste + '0'; break;

        }
        nbr_hex = nbr_hex / 16; 
        index++;
    }

   
    printf("La valeur binaire de %d est : %s\n", nb, binaire);
    printf("La valeur hexadecimale de %d est : 0X%s\n", nb, hex + (8 - index)); 
}

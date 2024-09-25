#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>


void paireImpaire();
void Voyelle();
void SommedeDeuxValeurs();
void EquationSecondDegre();
void ConversionAnnee();
void PositifNegatif();
void AlphabetMajuscule();
void MentionObtenue();
void VerificationAlphabet();
void FormatageDate();
void JourSemaineAleatoire();
void ComparaisonInstant();
void PointSegment();

int main(){

 int choix;

    do {
        // Display the menu
        printf("\n************ Menu ************\n");
        printf("1. Challenge 1 : Paire ou Impaire\n");
        printf("2. Challenge 2 : Voyelle ou Non\n");
        printf("3. Challenge 3 : Somme de Deux Valeurs\n");
        printf("4. Challenge 4 : Equation du Deuxième Degré\n");
        printf("5. Challenge 5 : Conversion d'Année\n");
        printf("6. Challenge 6 : Positif, Négatif ou Nul\n");
        printf("7. Challenge 7 : Alphabet Majuscule\n");
        printf("8. Challenge 8 : Mention Obtenue\n");
        printf("9. Challenge 9 : Vérification d'Alphabet\n");
        printf("10. Challenge 10 : Formatage de la Date\n");
        printf("11. Challenge 11 : Jour de la Semaine\n");
        printf("12. Challenge 12 : Comparaison d'Instants\n");
         printf("12. Challenge 13 : Point sur un Segment\n");
        printf("0. Quitter\n");
        printf("Choisissez une option : ");
        scanf("%d", &choix);

        // Call the corresponding function based on user choice
        switch (choix) {
            case 1:
                paireImpaire();
                break;
            case 2:
                Voyelle();
                break;
            case 3:
                SommedeDeuxValeurs();
                break;
            case 4:
                EquationSecondDegre();
                break;
            case 5:
                ConversionAnnee();
                break;
            case 6:
                PositifNegatif();
                break;
            case 7:
                AlphabetMajuscule();
                break;
            case 8:
                MentionObtenue();
                break;
            case 9:
                VerificationAlphabet();
                break;
            case 10:
                FormatageDate();
                break;
            case 11:
                JourSemaineAleatoire();
                break;
            case 12:
                ComparaisonInstant();
                break;
            case 13:
                PointSegment();
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }
    } while (choix != 0);
}

//Exercices sur les Conditions
/*Challenge 1 : Paire ou Impaire
Écrivez un programme qui demande un nombre et affiche si ce nombre est pair ou impair.
*/
void paireImpaire(){
     printf("******** *Challenge 1 : Paire ou Impaire*********\n");
    int nb ;
    printf("Veuillez saisir un nombre : ");
    scanf("%d", &nb);
    if (nb % 2 == 0)
    {
       printf("Le nombre est PAIRE ");
    }else { printf("Le nombre est IMPAIRE ");}
}



/*Challenge 2 : Voyelle ou Non
Écrivez un programme en C qui vérifie si un caractère saisi par l'utilisateur est une voyelle ou non en utilisant l'instruction switch case.
*/
void Voyelle() {
    printf("********* Challenge 2 : Voyelle ou Non *********\n");
    char c;
    printf("Veuillez saisir un caractere : ");
    scanf(" %c", &c);  

    switch (c) {
        case 'a': case 'e': case 'i': case 'o': case 'u':
        case 'A': case 'E': case 'I': case 'O': case 'U':  
            printf("Le caractere est une voyelle.\n");
            break;
        default:
            printf("Le caractere n'est pas une voyelle.\n");
            break;
    }
}


/*Challenge 3 : Somme de Deux Valeurs
Écrivez un programme C pour calculer la somme de deux valeurs entières données. Si les deux valeurs sont identiques, le programme doit renvoyer le triple de leur somme.
*/

void SommedeDeuxValeurs (){
    printf("\n******** Challenge 3 : Somme de Deux Valeurs *********\n");
    float  nb1 , nb2;
    printf("Veuillez saisir a , b  : ");
    scanf("%f  %f", &nb1 , &nb2);
    if (nb2 == nb1 )
            {
                printf(" a * 3  = %.2f \n", nb1 * 3);
             }
    else 
             { printf(" a + b  = %.2f \n", nb1 + nb2);} ;

}

/* 
Challenge 4 : Equation du Deuxième Degré
Écrivez un programme C qui permet de calculer les solutions possibles d’une équation du deuxième degré.
*/

void EquationSecondDegre() {
    printf("\n******** Challenge 4 : Equation du Deuxieme Degre *********\n");
    float a, b, c,  x1, x2 , delta;
    printf("Veuillez entrer les coefficients a, b et c : ");
    scanf("%f %f %f", &a, &b, &c);
    delta = (b * b) - 4 * a * c;
    
    if (delta > 0) {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
         printf("Delta :%.2f > 0 alors \n" , delta);
        printf(" x1 = %.2f et x2 = %.2f\n", x1, x2);
    }
    else if (delta == 0) {
        x1 = -b / (2 * a);
         printf("Delta :%.2f = 0 alors \n" , delta);
        printf(" x1 = x2 = %.2f\n", x1);
    }
    else {
        printf("Solution Vide:\n");
    }
}


/*
Challenge 5 : Conversion d'Année
Écrivez un programme C piloté par menu pour convertir une année donnée en :
Mois
Jours
Heures
Minutes
Secondes
Pour plus de simplicité, n'incluez pas l'année bissextile (sauf si vous êtes courageux pour le faire). 1 an = 365 jours, 1 mois = 30 jours.
*/
void ConversionAnnee() {
    float annee, mois, jours, heures, minutes, secondes;

    printf("\n******** Challenge 5 : Conversion d'Annee *********\n");
    printf("Veuillez entrer le nombre d'annees : ");
    scanf("%f", &annee);

    mois = annee * 12;
    jours = annee * 365;
    heures = annee * 365 * 24;
    minutes = annee * 365 * 24 * 60;
    secondes = annee * 365 * 24 * 60 * 60;

    printf("%.2f annees correspondent à ");
    printf("%.2f mois.\n",mois);
    printf("%.2f jours.\n",jours);
    printf("%.2f heures.\n", heures);
    printf("%.2f minutes.\n",minutes);
    printf("%.2f secondes.\n", secondes);



}



/*
Challenge 6 : Positif, Négatif ou Nul
Écrivez un programme pour vérifier si le nombre donné est positif, négatif ou nul. 
Si le nombre est inférieur à zéro, alors le nombre est négatif et
 si le nombre est supérieur à zéro, alors le nombre est positif. 
 Si les deux conditions sont fausses, le nombre est égal à zéro.*/

 void PositifNegatif() {
    printf("\n******** Challenge 6 : Positif, Negatif ou Nul *********\n");
    float nb;
    printf("Veuillez entrer un nombre : ");
    scanf("%f", &nb);
    if (nb > 0) {
        printf("%.2f est un nombre positif.\n", nb);
    } else if (nb < 0) {
        printf("%.2f est un nombre negatif.\n", nb);
    } else {
        printf("Le nombre est nul.\n");
    }
} 

/*
Challenge 7 : Alphabet Majuscule
Écrivez un programme pour vérifier si le caractère donné est un alphabet majuscule ou non 
en utilisant l'instruction conditionnelle if-else. 
Les lettres majuscules vont de 'A' à 'Z'.
 Les valeurs ASCII de 'A' et 'Z' sont respectivement 65 et 90. 
 Si la valeur ASCII d'un caractère est comprise entre 65 et 90, il s'agit d'un alphabet majuscule.
*/

void AlphabetMajuscule() {
    printf("********* Challenge 7 : Alphabet Majuscule *********\n");
    char c;
    printf("Veuillez saisir un caractere : ");
    scanf(" %c", &c);  

   if(c>=65 && c<=90){
      printf("Le caractere est un alphabet majuscule.\n");
   }
   else {
    printf("Le caractere n'est pas un alphabet majuscule.\n");
   }
}






/*
Challenge 8 : Mention Obtenue
Nous désirons afficher la mention obtenue par un élève en fonction de la moyenne de ses notes. 
S’il a une moyenne strictement inférieure à 10, il est recalé.
 S’il a une moyenne entre 10 (inclus) et 12, il obtient la mention passable. 
 S’il a une moyenne entre 12 (inclus) et 14, il obtient la mention assez bien. 
 S’il a une moyenne entre 14 (inclus) et 16, il obtient la mention bien.
 S’il a une moyenne supérieure à 16 (inclus) il obtient la mention très bien. 
  Écrire les instructions nécessaires.
*/
void MentionObtenue() {
    float moy;
    printf("********* Challenge 8 : Mention Obtenue *********\n");
    printf("Veuillez entrer la moyenne: ");
    scanf("%f", &moy);
    // Vérification de la moyenne et affichage de la mention
    if (moy< 10) {
        printf("Recale\n");
    } else if (moy >= 10 && moy < 12) {
        printf("Mention Passable\n");
    } else if (moy >= 12 && moy < 14) {
        printf("Mention Assez Bien\n");
    } else if (moy >= 14 && moy < 16) {
        printf("Mention Bien\n");
    } else if (moy>= 16) {
        printf("Mention Très Bien\n");

}
}


/*Challenge 9 : Vérification d'Alphabet
Écrivez un programme C qui lit un caractère et détermine s'il fait partie des alphabets ou non.
 Et s'il l'est, dire en plus s’il est une minuscule ou une majuscule.
*/
void VerificationAlphabet()
{
     printf("********* Challenge 9 : Verification d'Alphabet *********\n");
    char c;
    printf("Veuillez saisir un caractere : ");
    scanf(" %c", &c);  
    if(c>=65 && c<= 90)  {
        printf("Le caractere est un alphabet majuscule.\n");
    }else if (c>=97 && c<= 122){
        printf("Le caractere est un alphabet minuscle.\n");
    } else {
        printf("Le caractere n'est pas un alphabet.\n");
    }
}


/*
Challenge 10 : Formatage de la Date
Écrivez un programme C qui lit une date au format 15/09/2012 
et l'affiche sous le format suivant : 15-Septembre-2012.
*/


void FormatageDate() {
    printf("********* Challenge 10 : Formatage de la Date *********\n");
    int jour, mois, annee;
    char moisLettre[100]; 

    printf("Veuillez entrer une date au format JJ/MM/AAAA : ");
    scanf("%d/%d/%d", &jour, &mois, &annee);

    switch (mois) {
        case 1:
            strcpy(moisLettre, "Janvier");
            break;
        case 2:
            strcpy(moisLettre, "Fevrier");
            break;
        case 3:
            strcpy(moisLettre, "Mars");
            break;
        case 4:
            strcpy(moisLettre, "Avril");
            break;
        case 5:
            strcpy(moisLettre, "Mai");
            break;
        case 6:
            strcpy(moisLettre, "Juin");
            break;
        case 7:
            strcpy(moisLettre, "Juillet");
            break;
        case 8:
            strcpy(moisLettre, "Août");
            break;
        case 9:
            strcpy(moisLettre, "Septembre");
            break;
        case 10:
            strcpy(moisLettre, "Octobre");
            break;
        case 11:
            strcpy(moisLettre, "Novembre");
            break;
        case 12:
            strcpy(moisLettre, "Decembre");
            break;
        default:
            printf("Mois invalide\n");
    }

    // Afficher la date formatée
    printf("%d-%s-%d\n", jour, moisLettre, annee);
}



/*Challenge 11 : Jour de la Semaine
Écrivez un programme C qui affiche d'une manière aléatoire un des jours 
de la semaine.
*/
void JourSemaineAleatoire(){
    printf("********* Challenge 11 : Jour de la Semaine *********\n");
   printf("le Jour est : ");
    srand(time(NULL)); 
    int jourSemaine = rand() % 7; 
    switch (jourSemaine) {
        case 0:  printf("Dimanche\n"); 
            break;
        case 1:  printf("Lundi\n"); 
            break;
        case 2:  printf("Mardi\n"); 
            break;
        case 3:  printf("Mercredi\n"); 
            break;
        case 4:  printf("Jeudi\n"); 
            break;
        case 5:  printf("Vendredi\n"); 
            break;
        case 6:  printf("Samedi\n");
            break;
        default:
            printf("Erreur dans le jour de la semaine\n");
            break;
    }

}




/*Challenge 12 : Comparaison d'Instants
Écrivez un programme C qui lit deux instants dans le format HH:MM:SS et affiche un des messages suivants :
Le premier instant vient avant le deuxième ;
Le deuxième instant vient avant le premier ;
Il s'agit du même instant.*/
void ComparaisonInstant(){
    printf("********* /*Challenge 12 : Comparaison d'Instants*********\n");
    int heure1, minute1, seconde1, heure2, minute2, seconde2;
    printf("Entrez l'heure 1 (HH:MM:SS) : ");
    scanf("%d:%d:%d", &heure1, &minute1, &seconde1);
    printf("Entrez l'heure 2 (HH:MM:SS) : ");
    scanf("%d:%d:%d", &heure2, &minute2, &seconde2);


    if (heure1 < heure2 || (heure1 == heure2 && minute1 < minute2) || (heure1 == heure2 && minute1 == minute2 && seconde1 < seconde2)) {
        printf("Le premier instant vient avant le deuxieme\n");
    } else if (heure1 == heure2 && minute1 == minute2 && seconde1 == seconde2) {
        printf("Il s'agit du meme instant\n");
    } else {
        printf("Le deuxieme instant vient avant le premier\n");
    }
}


/*Challenge 13 : Point sur un Segment
Écrivez un programme C qui lit les coordonnées des deux extrémités d'un segment,
 et lit ensuite les coordonnées d'un point dans le plan et dit si ce dernier se trouve ou non sur le segment.
*/
//
void PointSegment(){
  printf("********* Challenge 13 : Point sur un Segment *********\n");
   float x1, y1, x2, y2 ,  px, py;         

    printf("A(x1, y1) : ");
    scanf("%f %f", &x1, &y1);
    printf("B(x2, y2) : ");
    scanf("%f %f", &x2, &y2);
    printf("X(px, py) : ");
    scanf("%f %f", &px, &py);


    float determinant = (y2 - y1) * (px - x1) - (x2 - x1) * (py - y1);


    if (determinant == 0) {
        if ((px >= x1 && px <= x2 || px >= x2 && px <= x1) &&  (py >= y1 && py <= y2 || py >= y2 && py <= y1)) {
            printf("Le point X se trouve sur le segment.\n");
        } else {
            printf("Le point X ne se trouve pas sur le segment.\n");
        }
    } else {
        printf("Le point X ne se trouve pas sur le segment.\n");
    }


}
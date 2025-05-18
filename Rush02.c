/**
 * RUSH 4 - C - Piscine Codeloccol
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

// Définition des couleurs ANSI (fonctionne sur la plupart des terminaux)
#define ROUGE "\033[1;31m"
#define VERT "\033[1;32m"
#define JAUNE "\033[1;33m"
#define BLEU "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define RESET "\033[0m"

// Prototypes des fonctions (déclarations)
void clearScreen();      // Efface l'écran
void afficherMenu();     // Affiche le menu principal
void calculatrice();     // Gère les calculs de base
bool estPremier(int n);  // Vérifie si un nombre est premier
void fibonacci();        // Génère la suite Fibonacci
long factoriel(int n);   // Calcule le factoriel
void pause();           // Met en pause le programme

/* 
 * Fonction principale
 * Point d'entrée du programme
 */
int main() {
    afficherMenu(); // Lance le menu principal
    return 0;      // Fin normale du programme
}

/*
 * Efface l'écran du terminal
 * Fonction multi-plateforme (Windows/Linux/Mac)
 */
void clearScreen() {
    #ifdef _WIN32
        system("cls");  // Commande Windows
    #else
        system("clear"); // Commande Unix
    #endif
}

/*
 * Met le programme en pause
 * Attend que l'utilisateur appuie sur Entrée
 */
void pause() {
    printf(JAUNE "\n  Appuyez sur Entree pour revenir au menu..." RESET);
    while(getchar() != '\n'); // Vide le buffer
    getchar(); // Attend l'appui sur Entrée
}

/*
 * Affiche le menu principal
 * Design compact avec bordures ||
 */
void afficherMenu() {
    int choix; // Stocke le choix de l'utilisateur
    
    do {
        clearScreen(); // Nettoie l'écran avant d'afficher
        
        // Affichage du menu compact
        printf(BLEU "\n");
        printf("  ||================================||\n");
        printf("  ||          " VERT "RUSH 4 - C" BLEU "            ||\n");
        printf("  ||--------------------------------||\n");
        printf("  || " VERT "1." BLEU " Calculatrice                ||\n");
        printf("  || " VERT "2." BLEU " Nombres premiers            ||\n");
        printf("  || " VERT "3." BLEU " Suite Fibonacci             ||\n");
        printf("  || " VERT "4." BLEU " Factoriel                   ||\n");
        printf("  || " ROUGE "5." BLEU " Quitter                     ||\n");
        printf("  ||================================||\n" RESET);
        
        printf(BLEU "\n  Choix (1-5) : " RESET);
        
        // Gestion des erreurs de saisie
        if(scanf("%d", &choix) != 1) {
            while(getchar() != '\n'); // Vide le buffer si erreur
            choix = 0; // Force à redemander
        }
        
        clearScreen(); // Nettoie avant d'afficher le résultat
        
        // Gestion des choix utilisateur
        switch(choix) {
            case 1:
                calculatrice(); // Lance la calculatrice
                pause();
                break;
                
            case 2: {
                // Test de nombre premier
                int nombre;
                printf(MAGENTA "\n  ||=== TEST NOMBRE PREMIER ===||\n\n" RESET);
                printf("  Entrez un nombre : ");
                scanf("%d", &nombre);
                printf("\n  || Resultat : %d %s %spremier" RESET " ||\n", 
                      nombre, 
                      estPremier(nombre) ? "est" : "n'est pas",
                      estPremier(nombre) ? VERT : ROUGE);
                pause();
                break;
            }
                
            case 3:
                fibonacci(); // Génère Fibonacci
                pause();
                break;
                
            case 4: {
                // Calcul du factoriel
                int nombre;
                printf(MAGENTA "\n  ||=== CALCUL FACTORIEL ===||\n\n" RESET);
                printf("  Entrez un nombre : ");
                scanf("%d", &nombre);
                if(nombre < 0) {
                    printf(ROUGE "\n  || Erreur : Impossible pour negatifs! ||\n" RESET);
                } else {
                    printf(VERT "\n  || %d! = %-19ld ||\n" RESET, nombre, factoriel(nombre));
                }
                pause();
                break;
            }
                
            case 5:
                // Quitter le programme
                printf(JAUNE "\n|| Merci d'avoir utilise RUSH 4 - C!||\n");
                printf("  \nA BIENTÔT \n\n" RESET);
                break;
                
            default:
                // Gestion des choix invalides
                printf(ROUGE "\n  || Choix invalide! (1-5 seulement) ||\n" RESET);
                pause();
        }
        
    } while(choix != 5); // Continue jusqu'à sélection de Quitter
}

/*
 * Fonction calculatrice complète
 * Gère +, -, *, / avec vérification des erreurs
 */
void calculatrice() {
    int nombre1, nombre2;
    char operation;

    printf(MAGENTA "\n  ||=== CALCULATRICE ===||\n\n" RESET);
    printf("  Premier nombre : ");
    scanf("%d", &nombre1);
    printf("  Deuxieme nombre : ");
    scanf("%d", &nombre2);
    printf("  Operation (+, -, *, /) : ");
    scanf(" %c", &operation);

    printf(JAUNE "\n  ==========================\n" RESET);
    printf(BLEU "  Resultat : " RESET);
    
    // Exécution de l'opération demandée
    switch(operation) {
        case '+':
            printf(VERT "%d + %d = %-8d" RESET "\n", nombre1, nombre2, nombre1 + nombre2);
            break;
            
        case '-':
            printf(VERT "%d - %d = %-8d" RESET "\n", nombre1, nombre2, nombre1 - nombre2);
            break;
            
        case '*':
            printf(VERT "%d * %d = %-8d" RESET "\n", nombre1, nombre2, nombre1 * nombre2);
            break;
            
        case '/':
            // Vérification division par zéro
            if(nombre2 != 0) {
                printf(VERT "%d / %d = %-8.2f" RESET "\n", nombre1, nombre2, (float)nombre1 / nombre2);
            } else {
                printf(ROUGE "Erreur: Division par 0!" RESET "\n");
            }
            break;
            
        default:
            printf(ROUGE "Operation inconnue!    " RESET "\n");
    }
    printf(JAUNE "  ==========================\n" RESET);
}

/*
 * Vérifie si un nombre est premier
 * @param n Le nombre à tester
 * @return true si premier, false sinon
 */
bool estPremier(int n) {
    if(n <= 1) return false;  // 0 et 1 non premiers
    if(n == 2) return true;   // 2 est premier
    if(n % 2 == 0) return false; // Pas de pairs > 2
    
    // On teste jusqu'à la racine carrée pour optimiser
    int racine = sqrt(n);
    for(int i = 3; i <= racine; i += 2) {
        if(n % i == 0) return false;
    }
    return true;
}

/*
 * Génère la suite de Fibonacci
 * Affiche les termes demandés
 */
void fibonacci() {
    int nbTermes, terme1 = 0, terme2 = 1, termeSuivant;

    printf(MAGENTA "\n  ||=== SUITE FIBONACCI ===||\n\n" RESET);
    printf("  Nombre de termes : ");
    scanf("%d", &nbTermes);

    if(nbTermes <= 0) {
        printf(ROUGE "\n  || Erreur : Entrez un nombre > 0 ||\n" RESET);
        return;
    }

    printf(VERT "\n  || Suite : ");
    
    // Génération des termes
    for(int i = 1; i <= nbTermes; i++) {
        printf("%d ", terme1);
        termeSuivant = terme1 + terme2;
        terme1 = terme2;
        terme2 = termeSuivant;
    }
    printf(VERT " ||\n");
}

/*
 * Calcule le factoriel d'un nombre
 * @param n Le nombre dont on veut le factoriel
 * @return n! (factoriel de n)
 */
long factoriel(int n) {
    if(n == 0) return 1; // Par définition
    long resultat = 1;
    for(int i = 1; i <= n; i++) {
        resultat *= i;
    }
    return resultat;
}

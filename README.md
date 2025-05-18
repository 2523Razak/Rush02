# RUSH02-CodeCalc C (Projet Piscine Codeloccol)

- **Type** : Application Console en C  

- **Contexte** : Projet hebdomadaire de la Piscine Codeloccol (Semaine 2)  

- **Langage** : C

- **Bibliothèques** : `<stdio.h>`, `<stdbool.h>`, `<math.h>`, `<stdlib.h>`

# Présentation du projet 
Ce projet est une application console interactive codée en  **langage C**, qui propose plusieurs fonctionnalités mathématiques. Il a été réalisé dans le cadre de la Rush de validation à la piscine C de Codeloccol.


# Fonctionnalités du programme

**Le programme contient 4 grandes fonctionnalités :**

***1. Une calculatrice basique (addition, soustraction, multiplication, division)***

***2. Un test pour savoir si un nombre est premier***

***3. Une fonction pour afficher la suite de Fibonacci***

***4. Le calcul de la factorielle d’un nombre***

Chaque fonctionnalité a été réalisée par un membre de l’équipe.

### Système de Couleurs ANSI
```c
#define ROUGE "\033[1;31m"  // Erreurs
#define VERT "\033[1;32m"    // Succès
#define JAUNE "\033[1;33m"   // Pause 
#define BLEU "\033[1;34m"    // Interface
#define MAGENTA "\033[1;35m" // Titres
#define RESET "\033[0m"      // Reset
```
### Fonction 1 – Calculatrice

Cette fonction permet d’effectuer des opérations simples entre deux nombres : **+, -, *, /**.

### Code 
```C
void calculatrice() {
    double a, b;
    char op;

    printf("Entrez une opération (exemple : 5 + 2) : ");
    scanf("%lf %c %lf", &a, &op, &b); // Lecture de l’expression

    switch(op) {
        case '+':
            printf("Résultat : %.2lf\n", a + b);
            break;
        case '-':
            printf("Résultat : %.2lf\n", a - b);
            break;
        case '*':
            printf("Résultat : %.2lf\n", a * b);
            break;
        case '/':
            if (b != 0)
                printf("Résultat : %.2lf\n", a / b); // Division normale
            else
                printf("Erreur : Division par zéro !\n"); // Erreur gérée
            break;
        default:
            printf("Opérateur invalide.\n"); // Si l’utilisateur entre un caractère inconnu
    }
}
```
- On demande à l’utilisateur d’entrer une opération.
  
- Ensuite, on utilise un switch pour détecter l’opérateur.
  
- On gère l’erreur de division par zéro pour éviter les crash.


### Fonction 2 – Tester si un nombre est premier

Cette fonction permet de savoir si un nombre est **premier ou non** (c’est-à-dire divisible uniquement par 1 et lui-même).

### Code :
```C
bool estPremier(int n) {
    if (n < 2) return false; // Tous les nombres < 2 ne sont pas premiers

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false; // Si on trouve un diviseur, ce n’est pas premier
    }
    return true; // Aucun diviseur trouvé, donc c’est un nombre premier
}
```
```C
void testPremier() {
    int n;
    printf("Entrez un entier : ");
    scanf("%d", &n);

    if (estPremier(n))
        printf("%d est un nombre premier.\n", n);
    else
        printf("%d n’est pas un nombre premier.\n", n);
}
```
- Un nombre premier ne peut être divisé que par 1 et lui-même.
  
-  On optimise la boucle en s’arrêtant à la racine carrée du nombre (sqrt(n)), ce qui évite les calculs inutiles.


### Fonction 3 – Suite de Fibonacci

Cette fonction affiche les n premiers éléments de la suite de Fibonacci, une suite célèbre en mathématiques.

### Code :
```C
void fibonacci() {
    int n;
    printf("Combien de termes ? ");
    scanf("%d", &n);

    int a = 0, b = 1;
    printf("Suite : ");

    for (int i = 0; i < n; i++) {
        printf("%d ", a);      // Affiche le terme courant
        int temp = a + b;      // Calcule le prochain terme
        a = b;                 // Décalage : b devient a
        b = temp;              // Le terme suivant devient b
    }
    printf("\n");
}
```
- La suite commence par 0 et 1.
  
- Chaque terme suivant est la somme des deux précédents.
  
- On utilise des variables temporaires pour ne pas perdre les anciennes valeurs.


### Fonction 4 – Calcul de la factorielle

Cette fonction calcule la factorielle d’un entier, c’est-à-dire le produit de tous les nombres de 1 à n.

### Code :
```C
long factoriel(int n) {
    if (n < 0) return 0; // Par convention, factorielle de nombre négatif n’existe pas

    unsigned long long resultat = 1;
    for (int i = 1; i <= n; i++) {
        resultat *= i; // On multiplie les nombres de 1 jusqu’à n
    }
    return resultat;
}
```
```C
void calculerFactoriel() {
    int n;
    printf("Entrez un entier : ");
    scanf("%d", &n);

    unsigned long long f = factoriel(n);
    printf("Factoriel de %d est : %llu\n", n, f);
}
```
- Utilisation d’un type unsigned long long pour pouvoir stocker de grands résultats.
  
- Le calcul se fait par une boucle simple.

### Fonction principale : Menu interactif

Permet de naviguer entre les différentes fonctionnalités du programme.

### Code :
```C
Design compact avec bordures ||
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
```

## Installation & Exécution

**1. Rendez-le exécutable** :
   ```c
   clang Rush02.c -o Rush02
   ```
**2. Lancez le jeu** :
   ```c
   ./Rush02
   ```
## Exemple d'Exécution
```C
||======== MENU ========||
|| 1. Calculatrice      ||
|| 2. Nombres premiers  ||
|| 3. Fibonacci         ||
|| 4. Factoriel         ||
|| 5. Quitter           ||
||======================||

Choix : 3

||===SUITE FIBONACCI===||

Nombre de termes : 5

|| Suite : 0 1 1 2 3 ||
```
# Organisation de l’équipe

- ***ABDALLAH_AM*** : Calculatrice

- ***Boureima_Issa_Adamou_R*** : Suite de Fibonacci

- ***LAOULI_MH*** : Test de nombre premier

- ***TOGUYENI_E*** : Calcul de factoriel

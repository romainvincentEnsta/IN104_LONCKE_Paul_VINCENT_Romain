#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define hauteur 20
#define largeur 20
#define longueur_serpent_initiale 3

char grille[hauteur][largeur];  //Pour représenter la grille de jeu
int snakeX[hauteur * largeur];  //Pour reperer le serpent
int snakeY[hauteur * largeur];
int longueur_serpent;
int foodX, foodY;               //Coordonnées de food
int gameOver = 0;               //Booléen pour vérifier la terminaison de la partie

void initializeBoard() {
    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur; j++) {
            if (i == 0 || i == hauteur - 1 || j == 0 || j == largeur - 1) {
                grille[i][j] = '#'; // Murs
            } else {
                grille[i][j] = ' '; // Espaces vides
            }
        }
    }
}

void initializeSnake() {
    int startX = largeur / 2;
    int startY = hauteur / 2;

    for (int i = 0; i < longueur_serpent_initiale; i++) {
        snakeX[i] = startX;
        snakeY[i] = startY;
    }

    longueur_serpent = longueur_serpent_initiale;
}

void placeFood() {
    do {
        foodX = 1 + rand() % (largeur - 2);
        foodY = 1 + rand() % (hauteur - 2);
    } while (grille[foodY][foodX] != ' ');

    grille[foodY][foodX] = 'X'; // Nourriture
}

void displayBoard() {
    system("clear"); //On efface le dernier affichage sur l'écran

    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur; j++) {
            int isSnake = 0;
            for (int k = 0; k < longueur_serpent; k++) {
                if (i == snakeY[k] && j == snakeX[k]) {
                    isSnake = 1;    //On repère le serpent 
                    break;
                }
            }
            if (isSnake) {
                printf("O ");     //Si correspondance alors on affiche le corps du serpent
            } else {
                printf("%c ", grille[i][j]);
            }
        }
        printf("\n");
    }
}

void updateSnakePosition(char direction) {
    //On efface le corps du serpent précédent
    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur; j++) {
            if (grille[i][j] == 'O') {
                grille[i][j] = ' ';
            }
        }
    }

    //On déplace le corps du serpent
    for (int i = longueur_serpent - 1; i > 0; i--) {
        snakeX[i] = snakeX[i - 1];
        snakeY[i] = snakeY[i - 1];
    }

    //On déplace la tête du serpent basé sur la commande de l'utilisateur dans les tableaux snake
    switch (direction) {
        case 'z': snakeY[0]--; break;
        case 's': snakeY[0]++; break;
        case 'q': snakeX[0]--; break;
        case 'd': snakeX[0]++; break;
    }

    //On actualise la position du serpent sur la grille 
    for (int i = 0; i < longueur_serpent; i++) {
        grille[snakeY[i]][snakeX[i]] = 'O';
    }
}


void checkCollision() {
    //On regarde la collision avec les murs
    if (snakeX[0] <= 0 || snakeX[0] >= largeur-1 || snakeY[0] <= 0 || snakeY[0] >= hauteur-1) {
        gameOver = 1;
    }
    
    //On regarde la collision avec lui même
    for (int i = 1; i < longueur_serpent; i++) {
        if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i]) {
            gameOver = 1;
        }
    }
}


void checkFood() {
    if (snakeX[0] == foodX && snakeY[0] == foodY) {
        //Augmenter la taille du serpent
        longueur_serpent++;

        //Ajout d'un nouveau segment au serpent 
        snakeX[longueur_serpent - 1] = snakeX[longueur_serpent - 2];
        snakeY[longueur_serpent - 1] = snakeY[longueur_serpent - 2];

        //On génère une nouvelle food
        placeFood();
    }
}


int main() {
    srand(time(NULL)); 

    initializeBoard();
    initializeSnake();
    placeFood();

    while (!gameOver) {
        displayBoard();

        char direction;
        printf("Choississez une direction : \n z : haut\n q : gauche\n d : droite\n s : bas\n");
        scanf(" %c", &direction);


        updateSnakePosition(direction);
        checkCollision();
        checkFood();

        usleep(200000); //Attendre 200 ms
    }

    printf("Game Over!\n");

    return 0;
}

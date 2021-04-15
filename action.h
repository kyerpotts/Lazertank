#ifndef ACTION_H
#define ACTION_H

/* INCLUDES */
#include "boundaries.h"
#include "defines.h"
/* PROTOTYPES */
void determineAction(char** canvas, int rows, int columns,
        char* userInput, int playerLoc[2],
        int enemyLoc[2], char* unit);
static void move(char** canvas, char dir, int playerLoc[2], char* player);
static void moveUp(char **canvas, int playerLoc[2], char *unit);
static void moveDown(char **canvas, int playerLoc[2], char *unit);
static void moveLeft(char **canvas, int playerLoc[2], char *unit);
static void moveRight(char **canvas, int playerLoc[2], char *unit);
static void changeDirection(char** canvas, char dir, int playerLoc[2],
        char* player);
static boolean canMove(int rows, int columns, int playerLoc[2],
        int enemyLoc[2]);

#endif

#ifndef CANVAS_H
#define CANVAS_H

/* INCLUDES */
#include <stdio.h>
#include <stdlib.h>
#include "boundaries.h"
#include "defines.h"

/* PROTOTYPES */
static void initCanvas(char** canvas, int rows, int columns);
char** drawCanvas(int rows, int columns);
void initPlayer(char** canvas, int playerLoc[2], char playerDir);
void initEnemy(char** canvas, int enemyLoc[2], char enemyDir);

#endif

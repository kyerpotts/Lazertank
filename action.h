#ifndef ACTION_H
#define ACTION_H

/* INCLUDES */
#include "boundaries.h"
#include "defines.h"
#include "newSleep.h"
/* PROTOTYPES */
void determineAction(char** canvas, int rows, int columns, int playerLoc[2], int enemyLoc[2]);
char* findUnit(char **canvas, int unitLoc[2]);
void fireLaser(char **canvas, int unitLoc[2], int rows, int columns);
#endif

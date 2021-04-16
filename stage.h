#ifndef STAGE_H
#define STAGE_H

/* INCLUDES */
#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "action.h"

/* PROTOTYPES */
void printStage(char** canvas, int rows, int columns);
void printActionList();
boolean checkWinCondition(char** canvas, int enemyLoc[]);
boolean checkGameEndCondition(char** canvas, int playerLoc[2], int enemyLoc[2]);
boolean checkEnemyFire(char **canvas, int playerLoc[2], int enemyLoc[2]);

#endif

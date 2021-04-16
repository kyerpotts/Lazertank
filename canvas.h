#ifndef CANVAS_H
#define CANVAS_H

/* INCLUDES */
#include <stdio.h>
#include <stdlib.h>
#include "boundaries.h"
#include "defines.h"

/* PROTOTYPES */
char** drawCanvas(int rows, int columns);
void initUnit(char** canvas, int unitLoc[2], char unit);

#endif

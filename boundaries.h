#ifndef BOUNDARIES_H
#define BOUNDARIES_H

/* INCLUDES */
#include <stdio.h>
#include <stdlib.h>
#include "defines.h"

/* PROTOTYPES */
boolean isBoundary(int rows, int columns, int rowLoc, int colLoc);
boolean elementOverlap(int firstLoc[2], int secondLoc[2]);

#endif

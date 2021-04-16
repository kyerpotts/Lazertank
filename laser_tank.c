#include "laser_tank.h"
#include "stage.h"
#include <stdlib.h>

int main(int argc, char** argv)
{
    int numOfArgs;
    int rowSize;
    int colSize;
    int freeMemCounter;
    int playerLoc[2];
    int enemyLoc[2];
    char playerDir;
    char enemyDir;
    char** canvas;

    numOfArgs = 9;
    if (argc != numOfArgs)
    {
        printf("Invalid arguments; Please run the program with the following arguments:\n");
        printf("<row_size> <col_size> ");
        printf("<player_row> <player_col> <player_direction> ");
        printf("<enemy_row> <enemy_col> <enemy_direction>) ");
    }
    else
    {
        rowSize = atoi(argv[1]);
        colSize = atoi(argv[2]);
        playerLoc[0] = atoi(argv[3]);
        playerLoc[1] = atoi(argv[4]);
        playerDir = *argv[5];
        enemyLoc[0] = atoi(argv[6]);
        enemyLoc[1] = atoi(argv[7]);
        enemyDir = *argv[8];
        canvas = drawCanvas(rowSize, colSize);
        initUnit(canvas, playerLoc,  playerDir);
        initUnit(canvas, enemyLoc,  enemyDir);
        system("clear");
        printStage(canvas, rowSize, colSize);
        printActionList();

        while(!(checkGameEndCondition(canvas, playerLoc, enemyLoc)))
        {
            determineAction(canvas, rowSize, colSize, playerLoc, enemyLoc);
            system("clear");
            printStage(canvas, rowSize, colSize);
            printActionList();
            if(checkEnemyFire(canvas, playerLoc,  enemyLoc))
            {
                fireLaser(canvas, enemyLoc, rowSize, colSize);
            }
        }

        if(checkWinCondition(canvas, enemyLoc))
        {
            printf("\nYOU WIN!!!");
        } else
        {
            printf("\nYOU LOST...");
        }

        for ( freeMemCounter = 0; freeMemCounter < rowSize; freeMemCounter++ )
        {
            /* TO DO: might not be correct, fix later */
            free(canvas[freeMemCounter]);
        }
        free(canvas);
        
    }

    return 0;
}

#include "laser_tank.h"
#include "stage.h"
#include <stdlib.h>

int main(int argc, char** argv)
{
    int playerLoc[2] = {6, 7};
    char player = 'r';
    int enemyLoc[2] = {2, 8};
    char enemy = 'l';
    char** canvas = drawCanvas(10, 20);
    initUnit(canvas, playerLoc,  player);
    initUnit(canvas, enemyLoc,  enemy);
    system("clear");
    printStage(canvas, 10, 20);
    printActionList();

    while(!(checkGameEndCondition(canvas, playerLoc, enemyLoc)))
    {
        determineAction(canvas, 10, 20, playerLoc, enemyLoc);
        system("clear");
        printStage(canvas, 10, 20);
        printActionList();
        if(checkEnemyFire(canvas, playerLoc,  enemyLoc))
        {
            fireLaser(canvas, enemyLoc, 10, 20);
        }
    }

    if(checkWinCondition(canvas, enemyLoc))
    {
        printf("\nYOU WIN!!!");
    }
    else
    {
        printf("\nYOU LOST...");
    }

    return 0;
}

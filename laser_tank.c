#include "laser_tank.h"

int main(int argc, char** argv)
{
    int playerLoc[2] = {6, 7};
    char player = argv[5][0];
    int enemyLoc[2] = {2, 8};
    char enemy;
    char** canvas = drawCanvas(10, 20);
    initPlayer(canvas, playerLoc,  player);
    initEnemy(canvas, enemyLoc,  player);

    printStage(canvas, 10, 20);
    printActionList();
    return 0;
}

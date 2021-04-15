#include "action.h"
#include "boundaries.h"
#include "defines.h"




void determineAction(char** canvas, int rows, int columns,
        char* userInput, int playerLoc[2],
        int enemyLoc[2], char* unit)
{
    int tempPlayerLoc[2] = {playerLoc[0], playerLoc[1]};
    switch(*userInput)
    {
        case 'w':
            /* Create another function that determins whether player needs to */
            /*     change direction or move, shouldn't be hard */
            if (*unit != '^')
            {
                changeDirection(canvas, '^', playerLoc, unit);
            }
            else
            {
                tempPlayerLoc[0]--;
                if (canMove(rows, columns, tempPlayerLoc,  enemyLoc))
                {
                    move(canvas, '^',  playerLoc,  unit);
                }
            }
        case 's':
            if (*unit != 'v')
            {
                changeDirection(canvas, 'v', playerLoc, unit);
            }
            else
            {
                tempPlayerLoc[0]++;
                if (canMove(rows, columns, tempPlayerLoc,  enemyLoc))
                {
                    move(canvas, 'v',  playerLoc,  unit);
                }
            }
        case 'a':
            if (*unit != '<')
            {
                changeDirection(canvas, '<', playerLoc, unit);
            }
            else
            {
                tempPlayerLoc[1]--;
                if (canMove(rows, columns, tempPlayerLoc,  enemyLoc))
                {
                    move(canvas, '<',  playerLoc,  unit);
                }
            }
        case 'd':
            if (*unit != '>')
            {
                changeDirection(canvas, '>', playerLoc, unit);
            }
            else
            {
                tempPlayerLoc[1]++;
                if (canMove(rows, columns, tempPlayerLoc,  enemyLoc))
                {
                    move(canvas, '>',  playerLoc,  unit);
                }
            }
    }
}




static void move(char** canvas, char dir, int playerLoc[2], char* unit)
{
    switch(dir)
    {
        case '^':
           moveUp(canvas, playerLoc, unit);
           break;
        case 'v':
           moveDown(canvas, playerLoc, unit);
           break;
        case '<':
           moveLeft(canvas, playerLoc, unit);
           break;
        case '>':
           moveRight(canvas, playerLoc, unit);
           break;
    }
}



static void moveUp(char **canvas, int playerLoc[2], char *unit)
{
    /* Move player one row up */
    playerLoc[0]--;
    canvas[playerLoc[0]][playerLoc[1]] = *unit;
    /* Set the space moved from to empty */
    canvas[playerLoc[0] + 1][playerLoc[1]] = ' ';
}



static void moveDown(char **canvas, int playerLoc[2], char *unit)
{
    /* Move player one row down */
    playerLoc[0]++;
    canvas[playerLoc[0]][playerLoc[1]] = *unit;
    /* Set the space moved from to empty */
    canvas[playerLoc[0] - 1][playerLoc[1]] = ' ';
}



static void moveLeft(char **canvas, int playerLoc[2], char *unit)
{
    /* Move player one column left */
    playerLoc[1]--;
    canvas[playerLoc[0]][playerLoc[1]] = *unit;
    /* Set the space moved from to empty */
    canvas[playerLoc[0]][playerLoc[1] + 1] = ' ';
}



static void moveRight(char **canvas, int playerLoc[2], char *unit)
{
    /* Move player one column right */
    playerLoc[1]++;
    canvas[playerLoc[0]][playerLoc[1]] = *unit;
    /* Set the space moved from to empty */
    canvas[playerLoc[0]][playerLoc[1] - 1] = ' ';
}



static void changeDirection(char** canvas, char dir, int playerLoc[2],
        char* unit)
{
    *unit = dir;
    canvas[playerLoc[0]][playerLoc[1]] = *unit;
}



static boolean canMove(int rows, int columns, int playerLoc[2],
        int enemyLoc[2])
{
    boolean canMove = TRUE;
    if(isBoundary(rows, columns, playerLoc[0], playerLoc[1]))
    {
        canMove = FALSE;
    }
    else if (elementOverlap(playerLoc, enemyLoc))
    {
        canMove = FALSE;
    }
    return canMove;
}


void fireLaser()
{

}

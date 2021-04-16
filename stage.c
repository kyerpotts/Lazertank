#include "stage.h"
#include "action.h"
#include "defines.h"




void printStage(char** canvas, int rows, int columns)
{
    int i;
    int j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
                printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}




void printActionList()
{
    printf("w to go/face up\n");
    printf("s to go/face down\n");
    printf("a to go/face right\n");
    printf("d to go/face left\n");
    printf("f to shoot laser\n");
    printf("action:");
}




boolean checkEnemyFire(char **canvas, int playerLoc[2], int enemyLoc[2])
{
    boolean enemyFire = FALSE;
    char enemy = *findUnit(canvas,  enemyLoc);
    switch (enemy)
    {
        case '^':
            if(playerLoc[0] < enemyLoc[0] && playerLoc[1] == enemyLoc[1])
            {
                enemyFire = TRUE;
            }
            break;
        case 'v':
            if(playerLoc[0] > enemyLoc[0] && playerLoc[1] == enemyLoc[1])
            {
                enemyFire = TRUE;
            }
            break;
        case '<':
            if(playerLoc[1] < enemyLoc[1] && playerLoc[0] == enemyLoc[0])
            {
                enemyFire = TRUE;
            }
        case '>':
            if(playerLoc[1] > enemyLoc[1] && playerLoc[0] == enemyLoc[0])
            {
                enemyFire = TRUE;
            }
    }
    return enemyFire;
}



boolean checkWinCondition(char** canvas, int enemyLoc[])
{
    boolean winLoss = FALSE;
    if (canvas[enemyLoc[0]][enemyLoc[1]] == 'X')
    {
        winLoss = TRUE;
    }
    return winLoss;
}




boolean checkGameEndCondition(char** canvas, int playerLoc[2], int enemyLoc[2])
{
    boolean endgame = FALSE;
    if (canvas[playerLoc[0]][playerLoc[1]] == 'X'
            || canvas[enemyLoc[0]][enemyLoc[1]] == 'X')
    {
        endgame = TRUE;
    }
    return endgame;
}

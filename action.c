#include "action.h"
#include "boundaries.h"
#include "defines.h"
#include "newSleep.h"

static char receiveInput();
static void move(char** canvas, char dir, int playerLoc[2], char* unit);
static void moveUp(char **canvas, int playerLoc[2], char *unit);
static void moveDown(char **canvas, int playerLoc[2], char *unit);
static void moveLeft(char **canvas, int playerLoc[2], char *unit);
static void moveRight(char **canvas, int playerLoc[2], char *unit);
static void changeDirection(char** canvas, char dir, int playerLoc[2],
        char* player);
static boolean canMove(int rows, int columns, int playerLoc[2],
        int enemyLoc[2]);
static void shootUp(char **canvas, int unitLoc[2], int rows, int columns);
static void shootDown(char **canvas, int unitLoc[2], int rows, int columns);
static void shootLeft(char **canvas, int unitLoc[2], int rows, int columns);
static void shootRight(char **canvas, int unitLoc[2], int rows, int columns);
static void printLaser(char** canvas, int unitLoc[2], int rows, int columns, fpColourPicker);
static void redLaser();
static void greenLaser();


void determineAction(char** canvas, int rows, int columns, int playerLoc[2], int enemyLoc[2])
{
    int tempPlayerLoc[2];
    char userInput = receiveInput();
    char *playerUnit = findUnit(canvas, playerLoc);
    tempPlayerLoc[0] = playerLoc[0];
    tempPlayerLoc[1] = playerLoc[1];
    switch(userInput)
    {
        case 'w':
            /* Create another function that determins whether player needs to */
            /*     change direction or move, shouldn't be hard */
            if (*playerUnit != '^')
            {
                changeDirection(canvas, '^', playerLoc, playerUnit);
            }
            else
            {
                tempPlayerLoc[0]--;
                if (canMove(rows, columns, tempPlayerLoc,  enemyLoc))
                {
                    move(canvas, '^',  playerLoc,  playerUnit);
                }
            }
            break;
        case 's':
            if (*playerUnit != 'v')
            {
                changeDirection(canvas, 'v', playerLoc, playerUnit);
            }
            else
            {
                tempPlayerLoc[0]++;
                if (canMove(rows, columns, tempPlayerLoc,  enemyLoc))
                {
                    move(canvas, 'v',  playerLoc,  playerUnit);
                }
            }
            break;
        case 'a':
            if (*playerUnit != '<')
            {
                changeDirection(canvas, '<', playerLoc, playerUnit);
            }
            else
            {
                tempPlayerLoc[1]--;
                if (canMove(rows, columns, tempPlayerLoc,  enemyLoc))
                {
                    move(canvas, '<',  playerLoc,  playerUnit);
                }
            }
            break;
        case 'd':
            if (*playerUnit != '>')
            {
                changeDirection(canvas, '>', playerLoc, playerUnit);
            }
            else
            {
                tempPlayerLoc[1]++;
                if (canMove(rows, columns, tempPlayerLoc,  enemyLoc))
                {
                    move(canvas, '>',  playerLoc,  playerUnit);
                }
            }
            break;
        case 'f':
            fireLaser(canvas, playerLoc, rows, columns);
            break;
        default:
            break;
    }
}




char* findUnit(char **canvas, int unitLoc[2])
{
    char *unit;
    unit = &canvas[unitLoc[0]][unitLoc[1]];
    return unit;
}



static char receiveInput()
{
    char userInput;
    scanf(" %c", &userInput);
    return userInput;
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
    else if (checkOverlap(playerLoc, enemyLoc))
    {
        canMove = FALSE;
    }
    return canMove;
}


void fireLaser(char **canvas, int unitLoc[2], int rows, int columns)
{
    char unitDirection = *findUnit(canvas, unitLoc);
    switch (unitDirection)
    {
        case '^':
            shootUp(canvas, unitLoc, rows, columns);
            break;
        case 'v':
            shootDown(canvas, unitLoc, rows, columns);
            break;
        case '<':
            shootLeft(canvas, unitLoc, rows, columns);
            break;
        case '>':
            shootRight(canvas, unitLoc, rows, columns);
            break;
        default:
            break;
    }
}




static void shootUp(char **canvas, int unitLoc[2], int rows, int columns)
{
    int laserLoc[2];
    char laserChar = '|';
    fpColourPicker fpColour = NULL;
    laserLoc[0] = unitLoc[0] - 1;
    laserLoc[1] = unitLoc[1];
    while(canvas[laserLoc[0]][laserLoc[1]] == ' ')
    {
        canvas[laserLoc[0]][laserLoc[1]] = laserChar;
        system("clear");
        printLaser(canvas, laserLoc, rows, columns, fpColour);
        laserLoc[0]--;
        newSleep(0.2);
        canvas[laserLoc[0] + 1][laserLoc[1]] = ' ';
    }
    if(canvas[laserLoc[0]][laserLoc[1]] != '*')
    {
        canvas[laserLoc[0]][laserLoc[1]] = 'X';
    }
}
static void shootDown(char **canvas, int unitLoc[2], int rows, int columns)
{
    int laserLoc[2];
    char laserChar = '|';
    fpColourPicker fpColour = NULL;
    laserLoc[0] = unitLoc[0] + 1;
    laserLoc[1] = unitLoc[1];
    while(canvas[laserLoc[0]][laserLoc[1]] == ' ')
    {
        canvas[laserLoc[0]][laserLoc[1]] = laserChar;
        system("clear");
        printLaser(canvas, laserLoc, rows, columns, fpColour);
        laserLoc[0]++;
        newSleep(0.2);
        canvas[laserLoc[0] - 1][laserLoc[1]] = ' ';
    }
    if(canvas[laserLoc[0]][laserLoc[1]] != '*')
    {
        canvas[laserLoc[0]][laserLoc[1]] = 'X';
    }
}
static void shootLeft(char **canvas, int unitLoc[2], int rows, int columns)
{
    int laserLoc[2];
    char laserChar = '-';
    fpColourPicker fpColour = NULL;
    laserLoc[0] = unitLoc[0];
    laserLoc[1] = unitLoc[1] - 1;
    while(canvas[laserLoc[0]][laserLoc[1]] == ' ')
    {
        canvas[laserLoc[0]][laserLoc[1]] = laserChar;
        system("clear");
        printLaser(canvas, laserLoc, rows, columns, fpColour);
        laserLoc[1]--;
        newSleep(0.2);
        canvas[laserLoc[0]][laserLoc[1] + 1] = ' ';
    }
    if(canvas[laserLoc[0]][laserLoc[1]] != '*')
    {
        canvas[laserLoc[0]][laserLoc[1]] = 'X';
    }
}
static void shootRight(char **canvas, int unitLoc[2], int rows, int columns)
{
    int laserLoc[2];
    char laserChar = '-';
    fpColourPicker fpColour = NULL;
    laserLoc[0] = unitLoc[0];
    laserLoc[1] = unitLoc[1] + 1;
    while(canvas[laserLoc[0]][laserLoc[1]] == ' ')
    {
        canvas[laserLoc[0]][laserLoc[1]] = laserChar;
        system("clear");
        printLaser(canvas, laserLoc, rows, columns, fpColour);
        laserLoc[1]++;
        newSleep(0.2);
        canvas[laserLoc[0]][laserLoc[1] - 1] = ' ';
    }
    if(canvas[laserLoc[0]][laserLoc[1]] != '*')
    {
        canvas[laserLoc[0]][laserLoc[1]] = 'X';
    }
}



static void printLaser(char** canvas, int unitLoc[2], int rows, int columns, fpColourPicker fpColour)
{
    int i;
    int j;
    if((*fpColour) == &redLaser)
    {
        fpColour = &greenLaser;
    }
    else {
        fpColour = &redLaser;
    }
    for (i = 0; i < unitLoc[0]; i++)
    {
        for (j = 0; j < columns; j++)
        {
            printf("%c", canvas[i][j]);
        }
        for (; j < rows; j++)
        {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
    for(j = 0; j < unitLoc[1]; j++)
    {
        printf("%c", canvas[unitLoc[0]][j]);
    }
    fpColour();
    printf("%c", canvas[unitLoc[0]][unitLoc[1]]);
    printf("\033[0m");
    for(j = unitLoc[1] + 1; j < columns; j++)
    {
        printf("%c", canvas[unitLoc[0]][j]);
    }
    printf("\n");
    for (i = unitLoc[0] + 1; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}


static void redLaser()
{
    printf("\033[0;31m");
}
static void greenLaser()
{
    printf("\033[0;32m");
}

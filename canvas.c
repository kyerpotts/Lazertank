#include "canvas.h"




char** drawCanvas(int rows, int columns)
{
    int i;
    char** canvas = (char**)malloc(sizeof(char*) * rows);
    for (i = 0; i < rows; i++)
    {
        canvas[i] = (char*)malloc(sizeof(char) * columns);
    }
    initCanvas(canvas, rows, columns);
    return canvas;
}




void initPlayer(char** canvas, int playerLoc[2], char player)
{
    switch (player)
    {
        case 'u':
            player = '^';
            break;
        case 'd':
            player = 'v';
            break;
        case 'l':
            player = '<';
            break;
        case 'r':
            player = '>';
            break;
    }
    canvas[playerLoc[0]][playerLoc[1]] = player;
}




void initEnemy(char** canvas, int enemyLoc[2], char enemy)
{
    switch (enemy)
    {
        case 'u':
            enemy = '^';
            break;
        case 'd':
            enemy = 'v';
            break;
        case 'l':
            enemy = '<';
            break;
        case 'r':
            enemy = '>';
            break;
    }
    canvas[enemyLoc[0]][enemyLoc[1]] = enemy;
}




static void initCanvas(char** canvas, int rows, int columns)
{
    int i;
    int j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            if (isBoundary(rows, columns, i, j))
            {
                canvas[i][j] = '*';
            }
            else
            {
                canvas[i][j] = ' ';
            }
        }
    }
}

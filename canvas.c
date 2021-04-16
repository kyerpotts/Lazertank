#include "canvas.h"


static void initCanvas(char** canvas, int rows, int columns);


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




void initUnit(char** canvas, int unitLoc[2], char unit)
{
    switch (unit)
    {
        case 'u':
            unit = '^';
            break;
        case 'd':
            unit = 'v';
            break;
        case 'l':
            unit = '<';
            break;
        case 'r':
            unit = '>';
            break;
    }
    canvas[unitLoc[0]][unitLoc[1]] = unit;
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

#include "boundaries.h"
#include "defines.h"




int rowMinMax(int rows)
{
    if (rows > MAXROWS)
    {
        rows = MAXROWS;
    }
    else if (rows < MINROWS)
    {
        rows = MINROWS;
    }
    return rows;
}




int columnMinMax(int columns)
{
    if (columns > MAXCOLUMNS)
    {
        columns = MAXCOLUMNS;
    }
    else if (columns < MINCOLUMNS)
    {
        columns = MINCOLUMNS;
    }
    return columns;
}




boolean isBoundary(int rows, int columns, int rowLoc, int colLoc)
{
    boolean boundary = FALSE;
    if ((rowLoc == 0 || rowLoc == rows - 1) || 
            (colLoc == 0 || colLoc == columns - 1))
    {
        boundary = TRUE;
    }
    return boundary;
}





boolean checkOverlap(int firstLoc[2], int secondLoc[2])
{
    boolean overlap = FALSE;
    if(firstLoc[0] == secondLoc[0] && firstLoc[1] == secondLoc[1])
    {
        overlap = TRUE;
    }
    return overlap;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXH 1000
#define MAXW 1000
#define WHITE 2
#define GRAY 1
#define BLACK 0
#define myInfinite 2147483647
#define NIL -1

struct cell 
{
    int coord_x;
    int coord_y;
};

struct cell Q[MAXW * MAXH + 1];

struct cell readMaze (char maze[][MAXW + 1], int W, int H) {
    char line [MAXW + 1];
    int idRow, idColumn;
    struct cell source;
    
    for (idRow = 1; idRow <= H; idRow++) {
        scanf ("%s", line);
        
        for (idColumn = 1; idColumn <= W; idColumn++) {
            maze[idRow][idColumn] = line[idColumn - 1];
            
            if (line[idColumn - 1] == '@') {
                source.coord_x = idColumn;
                source.coord_y = idRow;
                maze[idRow][idColumn] = '.';
            }
        }
    }
    
    return source;
}

void initializerMovements (struct cell movements[]) {
    movements[0].coord_x = 0;
    movements[0].coord_y = 0;
    movements[1].coord_x = 0;
    movements[1].coord_y = 1;
    movements[2].coord_x = -1;
    movements[2].coord_y = 0;
    movements[3].coord_x = 1;
    movements[3].coord_y = 0;
    movements[4].coord_x = 0;
    movements[4].coord_y = -1;
}

int BFS_Maze (char maze[][MAXW + 1], int W, int H, struct cell source, 
                int color[][MAXW + 1], int d[][MAXW + 1], struct cell pi[][MAXW + 1])
{
    int idRow, idColumn, head = 1, tail = 1, idMovement;
    struct cell NILFather, u, v, movements[5];
    
    initializerMovements (movements);
    NILFather.coord_x = NIL;
    NILFather.coord_y = NIL;
    
    for (idRow = 1; idRow <= H; idRow++) {
        for (idColumn = 1; idColumn <= W; idColumn++) {
            color[idRow][idColumn] = WHITE;
            d[idRow][idColumn] = myInfinite;
            pi[idRow][idColumn] = NILFather;
        }
    }
    
    color[source.coord_y][source.coord_x] = GRAY;
    d[source.coord_y][source.coord_x] = 0;
    pi[source.coord_y][source.coord_x] = NILFather;
    
    Q[tail] = source;
    tail++;
    
    while (head < tail) {
        u = Q[head];
        head++;
        for (idMovement = 1; idMovement <= 4; idMovement++) {
            v.coord_x = u.coord_x + movements[idMovement].coord_x;
            v.coord_y = u.coord_y + movements[idMovement].coord_y;
            if ((v.coord_x >= 1 && v.coord_x <= W) && 
                (v.coord_y >= 1 && v.coord_y <= H) && 
                (maze[v.coord_y][v.coord_x] == '.') &&
                (color[v.coord_y][v.coord_x] == WHITE))
            {
                color[v.coord_y][v.coord_x] = GRAY;
                d[v.coord_y][v.coord_x] = d[u.coord_y][u.coord_x] + 1;
                pi[v.coord_y][v.coord_x] = u;
                Q[tail] = v;
                tail++;
            }
        }
        
        color[u.coord_y][u.coord_x] = BLACK;
    }
    
    return tail - 1;
}

void solver (char maze[][MAXW + 1], int W, int H, struct cell source) {
    int color[MAXH + 1][MAXW + 1], d[MAXH + 1][MAXW + 1], idWord, saveCoord_X;
    int biggestNumber, totalBiggestNumber = 0, idQueue , idFirstFarthestCell, idLastFarthestCell;
    struct cell pi[MAXH + 1][MAXW + 1], actualCell;

    idQueue = BFS_Maze (maze, W, H, source, color, d, pi);
    idLastFarthestCell = idQueue;
    biggestNumber = d[Q[idQueue].coord_y][Q[idQueue].coord_x];
    
    while (d[Q[idQueue].coord_y][Q[idQueue].coord_x] == biggestNumber) {
        totalBiggestNumber++;
        idQueue--;
    }
    printf ("%d %d\n", totalBiggestNumber, biggestNumber);
    
    char saveWord[H * W + 1];
    
    idQueue++;
    idFirstFarthestCell = idQueue;
    
    for (idQueue = idFirstFarthestCell; idQueue <= idLastFarthestCell; idQueue++) {
        actualCell.coord_x = Q[idQueue].coord_x;
        actualCell.coord_y = Q[idQueue].coord_y;

        idWord = biggestNumber;
        while (idWord > 0) {
            
            if (pi[actualCell.coord_y][actualCell.coord_x].coord_y < actualCell.coord_y)
                //printf ("D");
                saveWord[idWord - 1] = 'D';
            else if (pi[actualCell.coord_y][actualCell.coord_x].coord_x > actualCell.coord_x)
                //printf ("L");
               saveWord[idWord - 1] = 'L';
            else if (pi[actualCell.coord_y][actualCell.coord_x].coord_x < actualCell.coord_x)
                //printf ("R");
                saveWord[idWord - 1] = 'R';
            else if (pi[actualCell.coord_y][actualCell.coord_x].coord_y > actualCell.coord_y)
                //printf ("U");
                saveWord[idWord - 1] = 'U';
            
            saveCoord_X = actualCell.coord_x;
            actualCell.coord_x = pi[actualCell.coord_y][actualCell.coord_x].coord_x;
            actualCell.coord_y = pi[actualCell.coord_y][saveCoord_X].coord_y;

            idWord--;
        }
        for (idWord = 0; idWord < biggestNumber; idWord++)
            printf ("%c", saveWord[idWord]);
        printf ("\n");
    }    
}

int main () {
    char maze[MAXH + 1][MAXW + 1];
    int T, W, H, idCase;
    struct cell source;
    
    scanf ("%d", &T);
    for (idCase = 1; idCase <= T; idCase++) {
        scanf ("%d %d", &W, &H);
        source = readMaze (maze, W, H);
        printf ("Case %d:\n", idCase);
        solver (maze, W, H, source);
    }

    return 0;
}

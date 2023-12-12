#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXH 100
#define MAXW 100
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

void printMaze (char maze[][MAXW + 1], int W, int H) {
    int idRow, idColumn;
    printf ("\nThe original maze without source position:\n\n");
    
    for (idRow = 1; idRow <= H; idRow++) {
        for (idColumn = 1; idColumn <= W; idColumn++)
            printf ("%c", maze[idRow][idColumn]);
        printf ("\n");
    }
    printf ("\n");
}

void initializerMovements (struct cell movements[]) {
    movements[0].coord_x = 0;
    movements[0].coord_y = 0;
    movements[1].coord_x = 0;
    movements[1].coord_y = -1;
    movements[2].coord_x = 0;
    movements[2].coord_y = 1;
    movements[3].coord_x = 1;
    movements[3].coord_y = 0;
    movements[4].coord_x = -1;
    movements[4].coord_y = 0;
}

void DFS_Visit (char maze[][MAXW + 1], int W, int H, struct cell u, int *time, int d[][MAXW + 1], 
                int f[][MAXW + 1], int color[][MAXW + 1], struct cell pi[][MAXW + 1])
{
    int idMovement;
    struct cell movements[5], v;
    initializerMovements (movements);
    
    color[u.coord_y][u.coord_x] = GRAY;
    (*time)++;
    d[u.coord_y][u.coord_x] = *time;
    
    for (idMovement = 1; idMovement <= 4; idMovement++) {
        v.coord_x = u.coord_x + movements[idMovement].coord_x;
        v.coord_y = u.coord_y + movements[idMovement].coord_y;
        
        if ((v.coord_x >= 1 && v.coord_x <= W) && (v.coord_y >= 1 && v.coord_y <= H) && (maze[v.coord_y][v.coord_x] == '.' && color[v.coord_y][v.coord_x] == WHITE)) {
            pi[v.coord_y][v.coord_x] = u;
            DFS_Visit (maze, W, H, v, &(*time), d, f, color, pi);
        }
    }
    
    color[u.coord_y][u.coord_x] = BLACK;
    (*time)++;
    f[u.coord_y][u.coord_x] = *time;
}

void DFS (char maze[][MAXW + 1], int W, int H, int d[][MAXW + 1], 
            int f[][MAXW + 1], int color[][MAXW + 1], struct cell pi[][MAXW + 1])
{
    int time = 0, idRow, idColumn;
    struct cell NILFather, u;
    
    NILFather.coord_x = NIL;
    NILFather.coord_y = NIL;
    
    for (idRow = 1; idRow <= H; idRow++) {
        for (idColumn = 1; idColumn <= W; idColumn++) {
            color[idRow][idColumn] = WHITE;
            pi[idRow][idColumn] = NILFather;
        }
    }
    
    for (idRow = 1; idRow <= H; idRow++) {
        for (idColumn = 1; idColumn <= W; idColumn++) {
            if (maze[idRow][idColumn] == '.' && color[idRow][idColumn] == WHITE) {
                u.coord_x = idColumn;
                u.coord_y = idRow;
                DFS_Visit (maze, W, H, u, &time, d, f, color, pi);
            }
        }
    }
}

void solver (char maze[][MAXW + 1], int W, int H) {
    int color[MAXH + 1][MAXW + 1], d[MAXH + 1][MAXW + 1], f[MAXH + 1][MAXW + 1], idRow, idColumn;
    struct cell pi[MAXH + 1][MAXW + 1];
    
    DFS (maze, W, H, d, f, color, pi);
    
    printf("Matrix of colors:\n\n");
    for(idRow = 1; idRow <= H; idRow++)
    {
        for(idColumn=1; idColumn <= W; idColumn++)
        {
            if(color[idRow][idColumn] == WHITE)
                printf(" W");
            if(color[idRow][idColumn] == GRAY)
                printf(" G");
            if(color[idRow][idColumn] == BLACK)
                printf(" B");
        }
        printf("\n");
    }
    printf("\n");
    
    printf("Matrix of time:\n\n");
    for(idRow = 1; idRow <= H; idRow++)
    {
        for(idColumn=1; idColumn <= W; idColumn++)
            printf ("%d %d\t\t", d[idRow][idColumn], f[idRow][idColumn]);
        printf("\n");
    }
    printf("\n");
    
    printf("Matrix of fathers:\n\n");
    for(idRow=1; idRow<=H; idRow++)
    {
        for(idColumn=1; idColumn<=W; idColumn++)
        {
            if(pi[idRow][idColumn].coord_x == NIL)
                printf(" [ -1, -1]");
            else
            {
                if(pi[idRow][idColumn].coord_x < 10)
                    printf(" [  %d,", pi[idRow][idColumn].coord_x);
                else
                    printf(" [ %d,", pi[idRow][idColumn].coord_x);
                if(pi[idRow][idColumn].coord_y < 10)
                    printf("  %d]", pi[idRow][idColumn].coord_y);
                else
                    printf(" %d]", pi[idRow][idColumn].coord_y);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main () {
    char maze[MAXH + 1][MAXW + 1];
    int T, W, H, idCase;
    struct cell source;
    
    scanf ("%d", &T);
    for (idCase = 1; idCase <= T; idCase++) {
        scanf ("%d %d", &W, &H);
        source = readMaze (maze, W, H);
        printMaze (maze, W, H);
        solver (maze, W, H);
    }

    return 0;
}

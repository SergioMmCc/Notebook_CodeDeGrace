#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXH 500
#define MAXW 500
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
            
            if (line[idColumn - 1] == 'S') {
                source.coord_x = idColumn;
                source.coord_y = idRow;
                maze[idRow][idColumn] = '.';
            }
        }
    }
    
    return source;
}

struct cell searchDestination (char maze [][MAXW + 1], int W, int H) {
    struct cell destination;
    int idRow, idColumn;
    
    for (idRow = 1; idRow <= H; idRow++) {    
        for (idColumn = 1; idColumn <= W; idColumn++) {
            if (maze[idRow][idColumn] == 'X') {
                destination.coord_x = idColumn;
                destination.coord_y = idRow;
                maze[idRow][idColumn] = '.';
            }
        }
    }
    return destination;
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
    movements[2].coord_x = 1;
    movements[2].coord_y = 0;
    movements[3].coord_x = -1;
    movements[3].coord_y = 0;
    movements[4].coord_x = 0;
    movements[4].coord_y = 1;
}

void BFS_Maze (char maze[][MAXW + 1], int W, int H, struct cell source, 
                int color[][MAXW + 1], int d[][MAXW + 1], struct cell pi[][MAXW + 1])
{
    int idRow, idColumn, head = 1, tail = 1, idMovement;
    struct cell NILFather, Q[H * W], u, v, movements[5];
    
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
}

void solver (char maze[][MAXW + 1], int W, int H, struct cell source, struct cell destination) {
    int color[MAXH + 1][MAXW + 1], d[MAXH + 1][MAXW + 1], distance, saveCoord_x, idDistance;
    struct cell pi[MAXH + 1][MAXW + 1];
    char result[W * H + 1];
    
    BFS_Maze (maze, W, H, source, color, d, pi);
    
    if (d[destination.coord_y][destination.coord_x] == myInfinite)
        printf ("No exit\n");
    else {
        distance = d[destination.coord_y][destination.coord_x];
        idDistance = distance;
        
        while (idDistance > 0) {
            if (pi[destination.coord_y][destination.coord_x].coord_y > destination.coord_y)
                result[idDistance - 1] = 'U';
            else if (pi[destination.coord_y][destination.coord_x].coord_x < destination.coord_x)
                result[idDistance - 1] = 'R';
            else if (pi[destination.coord_y][destination.coord_x].coord_x > destination.coord_x)
                result[idDistance - 1] = 'L';
            else if (pi[destination.coord_y][destination.coord_x].coord_y < destination.coord_y)
                result[idDistance - 1] = 'D';
            
            saveCoord_x = destination.coord_x;
            destination.coord_x = pi[destination.coord_y][destination.coord_x].coord_x;
            destination.coord_y = pi[destination.coord_y][saveCoord_x].coord_y;
            
            idDistance--;
        }
        
        for (int index = 0; index < distance; index++) 
            printf ("%c", result[index]);
        printf ("\n");
    }
}

int main () {
    char maze[MAXH + 1][MAXW + 1];
    int T, W, H, idCase;
    struct cell source;
    struct cell destination;
    
    scanf ("%d", &T);
    for (idCase = 1; idCase <= T; idCase++) {
        scanf ("%d %d", &H, &W);
        source = readMaze (maze, W, H);
        destination = searchDestination (maze, W, H);
        solver (maze, W, H, source, destination);
    }

    return 0;
}

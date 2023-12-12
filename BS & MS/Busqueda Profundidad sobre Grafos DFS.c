#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define WHITE 2
#define GRAY 1
#define BLACK 0
#define NIL -1
#define myPositiveInfinite 2147483647
#define MAXV 1000

struct edge
{
    int vertex;
	// int weight;
    struct edge *next;
};

struct graph
{
    int n_vertex;
    int m_edges;
    struct edge *Adj[MAXV + 1];
};

struct graph *readGraph (int vertices, int edges) {
    int idVertex, idEdge, u, v;
    struct graph *G;
    struct edge *tempEdge;

    G = (struct graph *) malloc(sizeof(struct graph));
    G->n_vertex = vertices;
    G->m_edges = edges;

    for(idVertex = 1; idVertex <= G->n_vertex; idVertex++)
        G->Adj[idVertex] = NULL;

    for(idEdge = 1; idEdge <= G->m_edges; idEdge++) {
        scanf("%d %d", &u, &v);
        tempEdge = (struct edge *) malloc(sizeof(struct edge));
        tempEdge->vertex = v;
        tempEdge->next = G->Adj[u];
        G->Adj[u] = tempEdge;

        if(u != v)
        {
            tempEdge = (struct edge *) malloc(sizeof(struct edge));
            tempEdge->vertex = u;
            tempEdge->next = G->Adj[v];
            G->Adj[v] = tempEdge;
        }
    }
    return G;
}

void printGraph (struct graph *G) {
    int idVertex;
    struct edge *tempEdge;

    if (G != NULL)
    {
        printf("Representation for graph's adjacent lists: \n");
        for(idVertex = 1; idVertex <= G->n_vertex; idVertex++)
        {
            printf("[%d]: ", idVertex);
            tempEdge = G->Adj[idVertex];
            while(tempEdge != NULL)
            {
                printf(" -> %d", tempEdge->vertex);
                tempEdge = tempEdge->next;
            }
            printf(" -> NULL\n");
        }
    }
    else
        printf("Empty Graph.\n");
}

struct graph *deleteGraph (struct graph *G) {
    int idVertex;
    struct edge *actualEdge, *nextEdge;

    for (idVertex = 1; idVertex <= G->n_vertex; idVertex++) {
        actualEdge = G->Adj[idVertex];
        while(actualEdge != NULL)
        {
            nextEdge = actualEdge->next;
            free (actualEdge);
            actualEdge = nextEdge;
        }
    }
    free (G);
    G = NULL;
    return G;
}

void DFS_Visit (struct graph *G, int u, int *time, int d[], int f[], int color[],  int pi[]) {
    int v;
    struct edge *temporalEdge;
    
    color[u] = GRAY;
    (*time)++;
    d[u] = *time;
    
    temporalEdge = G->Adj[u];
    while (temporalEdge != NULL) {
        v = temporalEdge->vertex;
        if (color[v] == WHITE) {
            pi[v] = u;
            DFS_Visit (G, v, &(*time), d, f, color, pi);
        }
        temporalEdge = temporalEdge->next;
    }
    color[u] = BLACK;
    (*time)++;
    f[u] = *time;
}

void DFS (struct graph *G, int d[], int f[], int color[], int pi[]) {
    int time = 0, u;
    
    for (u = 1; u <= G->n_vertex; u++) {
        color[u] = WHITE;
        pi[u] = NIL;
    }
    
    for (u = 1; u <= G->n_vertex; u++) {
        if (color[u] == WHITE)
            DFS_Visit (G, u, &time, d, f, color, pi);
    }
}


void solver (struct graph *G) {
    int color[MAXV + 1], d[MAXV + 1], f[MAXV + 1], pi [MAXV + 1], idVertex;
    
    DFS (G, d, f, color, pi);
    
    printf ("\n");
    for (idVertex = 1; idVertex <= G->n_vertex; idVertex++) {
        
        if (color[idVertex] == WHITE)
            printf ("color[%d] = WHITE\n", idVertex);
        else if (color[idVertex] == GRAY)
            printf ("color[%d] = GRAY\n", idVertex);
        else
            printf ("color[%d] = BLACK\n", idVertex);
    }
    printf ("\n");
    
    for (idVertex = 1; idVertex <= G->n_vertex; idVertex++) 
        printf ("d[%d] = %d, f[%d] = %d\n", idVertex, d[idVertex], idVertex, f[idVertex]);
    printf ("\n");
    
    for (idVertex = 1; idVertex <= G->n_vertex; idVertex++) {
        if (pi[idVertex] == NIL)
            printf ("pi[%d] = NIL\n", idVertex);
        else
            printf ("pi[%d] = %d\n", idVertex, pi[idVertex]);
    }
    printf ("\n");
}

int main () {
    int vertices, edges;
    struct graph *G;

    while (scanf ("%d %d", &vertices, &edges) != EOF) {
        G = readGraph (vertices, edges);
        printGraph (G);
        solver (G);
        G = deleteGraph (G);
        printGraph (G);
    }
    return 0;
}

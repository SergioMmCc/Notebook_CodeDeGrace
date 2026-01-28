#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define WHITE 2
#define GRAY 1
#define BLACK 0
#define NIL -1
#define myPositiveInfinite 2147483647
#define MAXV 10000

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

int solver (struct graph *G) {
    int color[MAXV], d[MAXV + 1], f[MAXV + 1], pi [MAXV + 1], idVertex, totalTrees = 0;
    
    DFS (G, d, f, color, pi);
    
    for (idVertex = 1; idVertex <= G->n_vertex; idVertex++) {
        if (pi[idVertex] == NIL)
            totalTrees++;
    }
    return (totalTrees * (totalTrees - 1))/2;
}

int main () {
    int vertices, edges, cases;
    struct graph *G;
    
    scanf ("%d", &cases);
    while (cases--) {
        scanf ("%d %d", &vertices, &edges);
        G = readGraph (vertices, edges);
        
        printf ("%d\n", solver(G));
        G = deleteGraph (G);
    }

    return 0;
}

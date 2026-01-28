#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXV 100000
#define myInfinite 9223372036854775807
#define NIL -1

struct edge {
    int vertex;
    int weight;
    struct edge *next;
};

struct graph {
    int n_vertex;
    int m_edges;
    struct edge *Adj[MAXV + 1];
};

struct nodePQ {
    int vertex;
    long long int distance;
};


int Parent (int i) {
    return i >> 1; /* return i / 2; */
}


int Left (int i) {
    return i << 1; /* return 2 * i; */
}


int Right (int i) {
    return (i << 1) + 1; /* return 2 * i + 1; */
}


void MinHeapify (struct nodePQ Q[], int i, int heapSize, int positionVertex[]) {
    int l, r, least, tempPosition;
    struct nodePQ tempNode;
    l = Left(i);
    r = Right(i);

    if((l <= heapSize) && (Q[l].distance < Q[i].distance))
        least = l;
    else
        least = i;

    if((r <= heapSize) && (Q[r].distance < Q[least].distance))
        least = r;

    if(least != i) {
        tempPosition = positionVertex[Q[i].vertex];
        tempNode = Q[i];

        positionVertex[Q[i].vertex] = positionVertex[Q[least].vertex];
        Q[i] = Q[least];

        positionVertex[Q[least].vertex] = tempPosition;
        Q[least] = tempNode;

        MinHeapify(Q, least, heapSize, positionVertex);
    }
}


int MinPQ_Extract(struct nodePQ Q[], int *heapSize, int positionVertex[]) {
    int myMin = 0;

    if(*heapSize >= 1) {
        myMin = Q[1].vertex;

        positionVertex[Q[*heapSize].vertex] = 1;
        Q[1] = Q[*heapSize];

        *heapSize = *heapSize - 1;
        MinHeapify(Q, 1, *heapSize, positionVertex);
    }
    return myMin;
}


void MinPQ_DecreaseKey(struct nodePQ Q[], int i, long long int key, int positionVertex[]) {
    int tempPosition;
    struct nodePQ tempNode;

    if(key < Q[i].distance) {
        Q[i].distance = key;

        while((i > 1) && (Q[Parent(i)].distance > Q[i].distance)) {
            tempPosition = positionVertex[Q[i].vertex];
            tempNode = Q[i];

            positionVertex[Q[i].vertex] = positionVertex[Q[Parent(i)].vertex];
            Q[i] = Q[Parent(i)];

            positionVertex[Q[Parent(i)].vertex] = tempPosition;
            Q[Parent(i)] = tempNode;

            i = Parent(i);
        }
    }
}


void MinPQ_Insert(struct nodePQ Q[], long long int key, int vertex, int *heapSize, int positionVertex[]) {
    *heapSize = *heapSize + 1;
    Q[*heapSize].distance = myInfinite;
    Q[*heapSize].vertex = vertex;
    positionVertex[vertex] = *heapSize;
    MinPQ_DecreaseKey(Q, *heapSize, key, positionVertex);
}


struct graph *readGraph(int vertices, int edges) {
    int idVertex, idEdge, u, v, w;
    struct graph *G;
    struct edge *tempEdge;

    G = (struct graph *) malloc(sizeof(struct graph));
    G->n_vertex = vertices;
    G->m_edges = edges;

    for(idVertex = 1; idVertex <= G->n_vertex; idVertex++)
        G->Adj[idVertex] = NULL;

    for(idEdge = 1; idEdge <= G->m_edges; idEdge++) {
        scanf("%d %d %d", &u, &v, &w);
/*
        u++;
        v++;
*/
        tempEdge = (struct edge *) malloc(sizeof(struct edge));
        tempEdge->vertex = v;
        tempEdge->weight = w;
        tempEdge->next = G->Adj[u];
        G->Adj[u] = tempEdge;

        if(u != v) {
            tempEdge = (struct edge *) malloc(sizeof(struct edge));
            tempEdge->vertex = u;
            tempEdge->weight = w;
            tempEdge->next = G->Adj[v];
            G->Adj[v] = tempEdge;
        }
    }
    return G;
}

struct graph *deleteGraph(struct graph *G) {
    int idVertex;
    struct edge *actualEdge, *nextEdge;

    for(idVertex = 1; idVertex <= G->n_vertex; idVertex++) {
        actualEdge = G->Adj[idVertex];
        while (actualEdge != NULL) {
            nextEdge = actualEdge->next;
            free(actualEdge);
            actualEdge = nextEdge;
        }
    }
    free(G);
    G = NULL;
    return G;
}


void dijkstra (struct graph *G, long long int d[], int pi[], int s) {
    int u, v, w, heapSize = 0;
    struct nodePQ Q[MAXV + 1];
    int positionVertex[MAXV + 1];
    struct edge *tempEdge;

    for(u = 1; u <= G->n_vertex; u++) {
        pi[u] = NIL;

        if(u == s) {
            MinPQ_Insert(Q, 0, s, &heapSize, positionVertex);
            d[s] = 0;
        }
        else {
            MinPQ_Insert(Q, myInfinite, u, &heapSize, positionVertex);
            d[u] = myInfinite;
        }
    }

    while(heapSize >= 1) {
        u = MinPQ_Extract(Q, &heapSize, positionVertex);

        if(d[u] == myInfinite)
            break;

        tempEdge = G->Adj[u];
        while(tempEdge != NULL) {
            v = tempEdge->vertex;
            w = tempEdge->weight;

            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pi[v] = u;
                MinPQ_DecreaseKey(Q, positionVertex[v], d[v], positionVertex);
            }
            tempEdge = tempEdge->next;
        }
    }
}

void skipDijkstra (struct graph *G, long long int d[], int pi[], int s, int skip) {
    int u, v, w, heapSize = 0;
    struct nodePQ Q[MAXV + 1];
    int positionVertex[MAXV + 1];
    struct edge *tempEdge;

    for(u = 1; u <= G->n_vertex; u++) {
        pi[u] = NIL;

        if(u == s) {
            MinPQ_Insert(Q, 0, s, &heapSize, positionVertex);
            d[s] = 0;
        }
        else if (u != skip) {
            MinPQ_Insert(Q, myInfinite, u, &heapSize, positionVertex);
            d[u] = myInfinite;
        }
    }

    while(heapSize >= 1) {
        u = MinPQ_Extract(Q, &heapSize, positionVertex);

        if(d[u] == myInfinite)
            break;

        tempEdge = G->Adj[u];
        while(tempEdge != NULL) {
            v = tempEdge->vertex;
            w = tempEdge->weight;

            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pi[v] = u;
                MinPQ_DecreaseKey(Q, positionVertex[v], d[v], positionVertex);
            }
            tempEdge = tempEdge->next;
        }
    }
}

void solver(struct graph *G, int source, int destiny) {
    long long int d[MAXV + 1], neededDistance, dSkip[MAXV + 1];
    int pi[MAXV + 1], idVertex, piSkip[MAXV + 1];
    int countResults = 0, results[MAXV + 1], index;
    
    dijkstra (G, d, pi, source);
    skipDijkstra (G, dSkip, piSkip, source, destiny);
    neededDistance = 2 * d[destiny];

    for (idVertex = 1; idVertex <= G->n_vertex; idVertex++) {
        if (d[idVertex] == neededDistance && d[idVertex] < dSkip[idVertex]) {
            countResults++;
            results[countResults] = idVertex;
        }
    }
    
    if (countResults == 0)
        printf ("*\n");
    else {
        for (index = 1; index < countResults; index++)
            printf ("%d ", results[index]);
        printf ("%d\n", results[countResults]);
    }
}


int main() {
    int vertices, edges, source, destiny;
    struct graph *G;

    scanf("%d %d", &vertices, &edges);
    scanf ("%d %d", &source, &destiny);
    G = readGraph(vertices, edges);
    solver(G, source, destiny);
    G = deleteGraph(G);
    
    return 0;
}

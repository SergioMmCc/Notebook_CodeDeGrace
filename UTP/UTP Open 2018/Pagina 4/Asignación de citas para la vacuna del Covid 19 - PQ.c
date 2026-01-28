#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define myPositiveInfinite 1000000000000000000
#define myNegativeInfinite -1000000000000000000
#define MAXT 1000000

typedef struct {
    char name [21];
    long long int priority;
} queue;

int Parent (int i) {
    return i / 2;
}

int Left (int i) {
    return 2 * i;
}

int Right (int i) {
    return 2 * i + 1;
}

void MaxHeapify (queue Q[], int i, int heapSize) {
    int l, r, least;
    queue temp;
    l = Left(i);
    r = Right(i);
    if((l <= heapSize) && (Q[l].priority > Q[i].priority))
        least = l;
    else
        least = i;
    if((r <= heapSize) && (Q[r].priority > Q[least].priority))
        least = r;
    if(least != i) {
        temp = Q[i];
        Q[i] = Q[least];
        Q[least] = temp;
        MaxHeapify(Q, least, heapSize);

    }
}

queue MaxPQ_Minimum (queue Q[]) {
    return Q[1];
}

queue MaxPQ_Extract (queue Q[], int *heapSize) {
    queue max;
    max.priority = myPositiveInfinite;
    if (*heapSize < 1)
        printf("Heap underflow.\n");
    else {
        max = Q[1];
        Q[1] = Q[*heapSize];
        *heapSize = *heapSize - 1;
        MaxHeapify(Q, 1, *heapSize);
    }
    return max;
}

void MaxPQ_IncreaseKey (queue Q[], int i, queue key) {
    queue temp;
    if (key.priority < Q[i].priority)
        printf("New key is lower than current key.\n");
    else {
        Q[i] = key;
        while ((i > 1) && (Q[Parent(i)].priority < Q[i].priority)) {
            temp = Q[i];
            Q[i] = Q[Parent(i)];
            Q[Parent(i)] = temp;
            i = Parent(i);
        }
    }
}

void MaxPQ_Insert (queue Q[], queue key, int *heapSize) {
    *heapSize = *heapSize + 1;
    Q[*heapSize].priority = myNegativeInfinite;
    MaxPQ_IncreaseKey(Q, *heapSize, key);
}

int main() {
    int heapSize = 0, idLine = 1000001;
    char name [21];
    queue Q[MAXT + 1], addUser, next;
    long long int priority;

    while (scanf ("%s", name) != EOF)
    {
        idLine--;
        if (strcmp(name, "V") == 0)
        {
            if (heapSize == 0)
                printf ("\n");
            else
            {
                next = MaxPQ_Extract(Q, &heapSize);
                printf ("%s\n", next.name);
            }
        }
        else
        {
            strcpy (addUser.name, name);
            scanf ("%lld", &priority);
            addUser.priority = priority * 10000000 + idLine;
            MaxPQ_Insert (Q, addUser, &heapSize);
        }
    }

    return 0;
}


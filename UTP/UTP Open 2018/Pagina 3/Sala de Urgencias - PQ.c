#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define myPositiveInfinite 2147483647
#define myNegativeInfinite -2147483647
#define MAXT 200000

typedef struct {
    char name [21];
    int triage, arrivalTime;
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

void MinHeapify (queue Q[],int i, int heapSize) {
    int l, r, least;
    queue temp;
    l = Left(i);
    r = Right(i);
    if((l <= heapSize) && (Q[l].triage < Q[i].triage))
        least = l;
    else 
        least = i;
    if((r <= heapSize) && (Q[r].triage < Q[least].triage))
        least = r;
    if(least != i) {
        temp = Q[i];
        Q[i] = Q[least];
        Q[least] = temp;
        MinHeapify(Q, least, heapSize);
        
    }
}

queue MinPQ_Minimum (queue Q[]) {
    return Q[1];
}

queue MinPQ_Extract (queue Q[], int *heapSize) {
    queue min;
    min.triage = myNegativeInfinite;
    if (*heapSize < 1)
        printf("Heap underflow.\n");
    else {
        min = Q[1];
        Q[1] = Q[*heapSize];
        *heapSize = *heapSize - 1;
        MinHeapify(Q, 1, *heapSize);
    }
    return min;
} 

void MinPQ_DecreaseKey (queue Q[], int i, queue key) {
    queue temp;
    if (key.triage > Q[i].triage)
        printf("New key is higher than currente key.\n");
    else {
        Q[i] = key;
        while ((i > 1) && (Q[Parent(i)].triage > Q[i].triage)) {
            temp = Q[i];
            Q[i] = Q[Parent(i)];
            Q[Parent(i)] = temp;
            i = Parent(i);
        }
    }
}

void MinPQ_Insert (queue Q[], queue key, int *heapSize) {
    *heapSize = *heapSize + 1;
    Q[*heapSize].triage = myPositiveInfinite;
    MinPQ_DecreaseKey(Q, *heapSize, key);
}

int main() {
    int n, idLine, time, triage, index, operation, heapSize;
    queue Q [MAXT + 1], addPerson, nextPerson;
    char name [21];
    
    while (scanf ("%d", &n) != EOF) {
        idLine = 200001;
        heapSize = 0;
        for (index = 1; index <= n; index++) {
            scanf ("%d %d", &operation, &time);
            if (operation == 1) {
                scanf ("%d %s", &triage, name);
                triage = triage*200000 - idLine;
                addPerson.triage = triage;
                addPerson.arrivalTime = time;
                strcpy (addPerson.name, name);
                
                MinPQ_Insert (Q, addPerson, &heapSize);

                idLine--;
            }
            else {
                nextPerson = MinPQ_Extract (Q, &heapSize);
                printf ("%d %d %d %s\n", nextPerson.arrivalTime, time, time - nextPerson.arrivalTime, nextPerson.name);
            }
                
        }
    }
    
    return 0;
}

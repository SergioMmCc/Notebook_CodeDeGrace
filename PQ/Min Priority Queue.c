#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define myPositiveInfinite 2147483647
#define myNegativeInfinite -2147483647
#define MAXQ 2000000
#define MAXT 1000000

int Parent (int i) {
    return i / 2;
}

int Left (int i) {
    return 2 * i;
}

int Right (int i) {
    return 2 * i + 1;
}

void MinHeapify (int Q[],int i, int heapSize) {
    int l, r, least, temp;
    l = Left(i);
    r = Right(i);
    if((l <= heapSize) && (Q[l] < Q[i]))
        least = l;
    else 
        least = i;
    if((r <= heapSize) && (Q[r] < Q[least]))
        least = r;
    if(least != i) {
        temp = Q[i];
        Q[i] = Q[least];
        Q[least] = temp;
        MinHeapify(Q, least, heapSize);
        
    }
}

int MinPQ_Minimum (int Q[]) {
    return Q[1];
}

int MinPQ_Extract (int Q[], int *heapSize) {
    int min = myNegativeInfinite;
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

void MinPQ_DecreaseKey (int Q[], int i, int key) {
    int temp;
    if (key > Q[i])
        printf("New key is higher than currente key.\n");
    else {
        Q[i] = key;
        while ((i > 1) && (Q[Parent(i)] > Q[i])) {
            temp = Q[i];
            Q[i] = Q[Parent(i)];
            Q[Parent(i)] = temp;
            i = Parent(i);
        }
    }
}

void MinPQ_Insert (int Q[], int key, int *heapSize) {
    *heapSize = *heapSize + 1;
    Q[*heapSize] = myPositiveInfinite;
    MinPQ_DecreaseKey(Q, *heapSize, key);
}

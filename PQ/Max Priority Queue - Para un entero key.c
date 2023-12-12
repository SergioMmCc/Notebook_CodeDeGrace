#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define myPositiveInfinite 2147483647
#define myNegativeInfinite -2147483647

struct node
{
    int key;
    struct node *next;
};

int Parent (int i) {
    return i / 2;
}

int Left (int i) {
    return 2 * i;
}

int Right (int i) {
    return 2 * i + 1;
}

void MaxHeapify (int Q[], int i, int heapSize) {
    int l, r, least;
    int temp;
    l = Left(i);
    r = Right(i);
    if((l <= heapSize) && (Q[l] > Q[i]))
        least = l;
    else
        least = i;
    if((r <= heapSize) && (Q[r] > Q[least]))
        least = r;
    if(least != i) {
        temp = Q[i];
        Q[i] = Q[least];
        Q[least] = temp;
        MaxHeapify(Q, least, heapSize);

    }
}

int MaxPQ_Minimum (int Q[]) {
    return Q[1];
}

int MaxPQ_Extract (int Q[], int *heapSize) {
    int max;
    max = myPositiveInfinite;
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

void MaxPQ_IncreaseKey (int Q[], int i, int key) {
    int temp;
    if (key < Q[i])
        printf("New key is lower than current key.\n");
    else {
        Q[i] = key;
        while ((i > 1) && (Q[Parent(i)] < Q[i])) {
            temp = Q[i];
            Q[i] = Q[Parent(i)];
            Q[Parent(i)] = temp;
            i = Parent(i);
        }
    }
}

void MaxPQ_Insert (int Q[], int key, int *heapSize) {
    *heapSize = *heapSize + 1;
    Q[*heapSize] = myNegativeInfinite;
    MaxPQ_IncreaseKey(Q, *heapSize, key);
}

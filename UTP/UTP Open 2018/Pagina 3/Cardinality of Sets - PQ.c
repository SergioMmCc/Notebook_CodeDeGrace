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

int main() {
    int Q [MAXQ + 1], m, n, A [MAXT + 1], B [MAXT + 1], heapSize;
    int intersections, setsIndex, extractMin, extractNext;
    
    while (scanf ("%d %d", &m, &n) && (n != 0)) {
        heapSize = 0;
        intersections = 0;
        
        for (setsIndex = 1; setsIndex <= m; setsIndex++) {
            scanf ("%d", &A[setsIndex]);
            MinPQ_Insert (Q, A[setsIndex], &heapSize);
        }   
        for (setsIndex = 1; setsIndex <= n; setsIndex++) {
            scanf ("%d", &B[setsIndex]);
            MinPQ_Insert (Q, B[setsIndex], &heapSize);
        }
        
        while (heapSize > 1) {
            extractMin = MinPQ_Extract (Q, &heapSize);
            extractNext = MinPQ_Minimum (Q);
            
            if (extractMin == extractNext) {
                intersections++;
                extractNext = MinPQ_Extract (Q, &heapSize);
            }
        }
        
        printf ("%d %d %d %d\n", m - intersections, intersections, n - intersections, m + n - intersections);

    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define myPositiveInfinite 12147483647
#define myNegativeInfinite 2147483647
#define MAXT 5000

int Parent(int i) {
    return i / 2;
}

int Left(int i) {
    return 2 * i;
}

int Right(int i) {
    return 2 * i + 1;
}

void MinHeapify(long long int Q[],int i, int heapSize) {
    long long int l, r, least, temp;
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

long long int MinPQ_Minimum (long long int Q[]) {
    return Q[1];
}

long long int MinPQ_Extract(long long int Q[], int *heapSize) {
    long long int min = myNegativeInfinite;
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


void MinPQ_DecreaseKey(long long int Q[], int i, long long int key) {
    long long int temp;
    if(key > Q[i])
        printf("New key is higher than currente key.\n");
    else {
        Q[i] = key;
        while((i > 1) && (Q[Parent(i)] > Q[i])) {
            temp = Q[i];
            Q[i] = Q[Parent(i)];
            Q[Parent(i)] = temp;
            i = Parent(i);
        }
    }
}

void MinPQ_Insert(long long int Q[], long long int key, int *heapSize) {
    *heapSize = *heapSize + 1;
    Q[*heapSize] = myPositiveInfinite;
    MinPQ_DecreaseKey(Q, *heapSize, key);
}

int main(){
    int n, idElement, heapSize;
    long long int Q[MAXT + 1], element, value1, value2, result;
    
    while(scanf("%d", &n) && (n > 0)) {
        heapSize = 0;
        result = 0;
        for (idElement=1; idElement<=n; idElement++) {
            scanf ("%lld", &element);
            MinPQ_Insert (Q, element, &heapSize);
        }
        
        while (heapSize >= 2) {
            value1 = MinPQ_Extract (Q, &heapSize);
            value2 = MinPQ_Extract (Q, &heapSize);
            result += (value1 + value2);
            MinPQ_Insert (Q, value1 + value2, &heapSize);
        }
        
        printf ("%lld\n", result);
    }    
    
    return 0;
}
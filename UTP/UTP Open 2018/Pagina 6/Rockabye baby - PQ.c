#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define myPositiveInfinite 9223372036854775807
#define myNegativeInfinite -9223372036854775807
#define MAXT 100000

typedef struct {
    char name [16];
    long long int startingTime, nextTime;
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
    if((l <= heapSize) && (Q[l].nextTime < Q[i].nextTime))
        least = l;
    else 
        least = i;
    if((r <= heapSize) && (Q[r].nextTime < Q[least].nextTime))
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
    min.nextTime = myNegativeInfinite;
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
    if (key.nextTime > Q[i].nextTime)
        printf("New key is higher than currente key.\n");
    else {
        Q[i] = key;
        while ((i > 1) && (Q[Parent(i)].nextTime > Q[i].nextTime)) {
            temp = Q[i];
            Q[i] = Q[Parent(i)];
            Q[Parent(i)] = temp;
            i = Parent(i);
        }
    }
}

void MinPQ_Insert (queue Q[], queue key, int *heapSize) {
    *heapSize = *heapSize + 1;
    Q[*heapSize].nextTime = myPositiveInfinite;
    MinPQ_DecreaseKey(Q, *heapSize, key);
}

int main() {
    int t, n, k, index, heapSize, time;
    char name [16];
    queue Q [MAXT + 1], saveMedicine, nextMedicine;
    
    scanf ("%d", &t);
    
    while (t--) {
        heapSize = 0;
        scanf ("%d %d", &n, &k);
        
        for (index = 1; index <= n; index++) {
            scanf ("%s %d", name, &time);            
            saveMedicine.startingTime = (long long int) time * 1000000;
            saveMedicine.nextTime = (long long int) time * 1000000 + index;
            strcpy (saveMedicine.name, name);
            MinPQ_Insert (Q, saveMedicine, &heapSize);
        }
        
        while (k--) {
            nextMedicine = MinPQ_Extract (Q, &heapSize);
            printf ("%lld %s\n", nextMedicine.nextTime / 1000000, nextMedicine.name);
            saveMedicine.startingTime = nextMedicine.startingTime;
            saveMedicine.nextTime = nextMedicine.nextTime + nextMedicine.startingTime;
            strcpy (saveMedicine.name, nextMedicine.name);
            MinPQ_Insert (Q, saveMedicine, &heapSize);
        }
    }
    
    return 0;
}

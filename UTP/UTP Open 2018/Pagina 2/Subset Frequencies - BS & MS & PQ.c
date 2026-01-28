#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define myInfinite 2147483647
#define myPositiveInfinite 1000000000000000000
#define myNegativeInfinite -1000000000000000000
#define MAXA 1000001
#define MAXT 51

typedef struct 
{
    long long int priority;
    int id;
    int freq;
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

int binarySearch (int *A, int i, int j, int k) {
    int m;
    while (i <= j) {
        m = (i + j) >> 1;
        if (A[m] == k)
           return m;
        else if (k > A[m])
             i = m + 1;
           else
                j = m - 1;
    }
    return -i -1;
}

void myMerge (int *A, int p, int q, int r) {
    int n1 = q-p+1, n2 = r-q, i, j, k;
    int *L, *R;
    L = (int *) malloc (sizeof(int) * (n1 + 2));
    R = (int *) malloc (sizeof(int) * (n2 + 2));
    
    for (i=1; i<=n1; i++)
        L[i] = A[p+i-1];
    for (j=1; j<=n2; j++)
        R[j] = A[q+j];
    L [n1+1] = myInfinite;
    R [n2+1] = myInfinite;
    i=1;
    j=1;
    for (k=p; k<=r; k++) {
        if (L[i] <= R[j]) {
            A[k] = L [i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
    }
}

void MergeSort (int *A, int p, int r) {
    int q;
    if (p<r) {
        q = (p+r)/2;
        MergeSort (A, p, q);
        MergeSort (A, q+1, r);
        myMerge (A, p, q, r);
    }
}

int main() {
    int *A, *S, n, k, index, mid, limit, subIndex, search, result, heapSize = 0;
    queue Q[MAXT], add;
    A = (int *) malloc (sizeof (int) * MAXA);
    S = (int *) malloc (sizeof (int) * MAXT);
    
    scanf ("%d %d", &n, &k);
    for (index = 1; index <= n; index++) 
        scanf ("%d", &A[index]);
    for (index = 1; index <= k; index++) 
        scanf ("%d", &S[index]);
    MergeSort(A, 1, n);
    
    for (index = 1; index <= k; index++) {
        result = 0;
        subIndex = 1;
        mid = S[index]/2;
        if (S[index] % 2 == 1)
            mid++;
        limit = binarySearch(A, 1, n, mid);
        if (limit < 0)
            limit = -limit -1;
        
        while (subIndex < limit) {
            search = binarySearch(A, subIndex, n, S[index] - A[subIndex]);
            if (search > 0)
                result++;
            subIndex++;
        }
        add.freq = result;
        add.id = S[index];
        add.priority = (long long int)result * 1000000000 - add.id;
        
        MaxPQ_Insert(Q, add, &heapSize);
    }
    while (heapSize > 0) {
        add = MaxPQ_Extract(Q, &heapSize);
        printf ("%d %d\n", add.id, add.freq);
    }
    
    return 0;
}

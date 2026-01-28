#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAXT 100000

int binarySearch (int A [], int i, int j, int k) {
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

int binarySearchFirstOccurrence(int A[], int i, int j, int k) {
    int result, result2;
    result = binarySearch(A, i, j, k);
    if (result >= 0) {
        result2 = binarySearch(A, i, result - 1, k);
        while (result2 >= 0) {
            result = result2;
            result2 = binarySearch(A, i, result - 1, k);
        }
    }
    return result;
}

int binarySearchLastOccurrence(int A[], int i, int j, int k) {
    int result, result2;
    result = binarySearch(A, i, j, k);
    if (result >= 0) {
        result2 = binarySearch(A, result + 1, j, k);
        while (result2 >= 0) {
            result = result2;
            result2 = binarySearch(A, result + 1, j, k);
        }
    }
    return result;
}

int main() {
    int A[MAXT + 1], cases, length, queries, sum[MAXT + 1], k, next;
    int saveLastPosition, firstPosition, lastPosition, result, veces;
    sum[0] = 0;
    scanf ("%d", &cases);
    
    while (cases--) {
        scanf ("%d %d", &length, &queries);
        
        for (int index = 1; index <= length; index++) {
            scanf ("%d", &A[index]);
            sum[index] = A[index] + sum[index - 1];
        }
        while (queries--) {
            result = 0;
            saveLastPosition = 1;
            scanf ("%d", &k);
            
            lastPosition = binarySearchLastOccurrence(sum, 1, length, k);
            firstPosition = binarySearchFirstOccurrence(sum, 1, length, k);
            
            if (lastPosition > 0) {
                veces = lastPosition - firstPosition + 1;
                result += veces;
                saveLastPosition = lastPosition;
                
                lastPosition = binarySearchLastOccurrence(sum, 1, firstPosition, 0);
                if (lastPosition > 0) {
                    firstPosition = binarySearchFirstOccurrence(sum, 1, firstPosition, 0);
                    result += veces * (lastPosition - firstPosition + 1);
                }   
            }
            while (saveLastPosition != length) {
                saveLastPosition++;
                
                next = sum[saveLastPosition];
                lastPosition = binarySearchLastOccurrence(sum, saveLastPosition - 1, length, next);
                veces = lastPosition - saveLastPosition + 1;
                saveLastPosition = lastPosition;
                
                lastPosition = binarySearchLastOccurrence(sum, 1, saveLastPosition, next - k);
                if (lastPosition > 0) {
                    firstPosition = binarySearchFirstOccurrence(sum, 1, saveLastPosition, next - k);
                    result += veces * (lastPosition - firstPosition + 1);
                }
            }
            printf ("%d ", result);
        }
        printf ("\n");
    }    
    
    return 0;
}

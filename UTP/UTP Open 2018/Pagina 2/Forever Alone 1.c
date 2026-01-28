#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAXT 100000

int main() {
    int cases, length, l, r, A[61][MAXT + 1], queries, index, result, sum;
    
    for (index = 1; index <= 60; index++)
        A[index][0] = 0;
    for (index = 1; index <= MAXT; index++) 
        A[0][index] = 0;
    
    scanf ("%d", &cases);
    while (cases--) {
        scanf ("%d", &length);
        for (index = 1; index <= length; index++) {
            scanf ("%d", &sum);
            
            for (int jIndex = 1; jIndex <= 60; jIndex++)
                A[jIndex][index] = A[jIndex][index - 1];
            
            A[sum][index] = A[sum][index - 1] + 1;
        }
            
        
        scanf ("%d", &queries);
        while (queries--) {
            result = 0;
            scanf ("%d %d", &l, &r);
            
            for (index = 1; index <= 60; index++) {
                sum = A[index][r] - A[index][l - 1];
                if (sum % 2 == 1)
                    result++;
                
            }
            printf ("%d\n", result);
        }
    }
    
    return 0;
}

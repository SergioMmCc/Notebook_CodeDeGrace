#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAXT 2000000

int BinarySearch (long long int A [], int i, int j, long long int k) {
    int m;
    
    if (i>j)
       return -1*i -1;
    else {
         m = (i+j) / 2;
         if (A[m] == k) 
            return m;
            else {
                 if (k >A[m])
                    return BinarySearch (A, m+1, j, k);
                 else
                     return BinarySearch (A, i, m-1, k);
                 }
         }
}

int main() {

    long long int A[MAXT + 1], a, b;
    int inferior, superior, result;
    
    for (long long int index = 1; index < MAXT; index++) 
        A[index] = index * (index + 1) / 2;
    
    while (scanf ("%lld %lld", &a, &b) && a != 0) {
        inferior = BinarySearch (A, 1, MAXT, a);
        superior = BinarySearch (A, 1, MAXT, b);
        
        if (inferior < 0)
            inferior = inferior *-1 -1;
        if (superior < 0)
            superior = superior * -1 -2;
        
        result = superior - inferior + 1;
        
        printf ("%d\n", result);
    }
    
    return 0;
}

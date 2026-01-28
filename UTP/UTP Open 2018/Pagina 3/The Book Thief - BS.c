#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAXT 14142

int BinarySearch (int A [], int i, int j, int k) {
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

int main () {
    int T [MAXT], s, index, forgottenPage, totalPages, page;

    T[0]=0;
    for (index=1; index<=MAXT; index++)
        T[index] = T[index-1] + index;
        
    while (scanf("%d", &s) && (s>0)) {
        page = BinarySearch (T, 1, MAXT, s);
        if (page>=0) {
            totalPages = page+1;
            forgottenPage = page+1;
        }
        else {
            totalPages = -1*page -1;
            forgottenPage = T[totalPages] -s;
        }
        printf ("%d %d\n", forgottenPage, totalPages);
    }
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


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

int procesarCasosDePrueba() {
    int n, i, triangles = 0, numberLookingFor, lengthSide, numberPosition;
    if (scanf("%d", &n) != 1) {
        return -1;
    }
    
    int points[n], addPoints[n];
    addPoints[0] = 0;
    
    for (i = 1; i <= n; i++) {
        if (scanf("%d", &points[i]) != 1) {
            return -1;
        }
        addPoints[i] = addPoints[i - 1] + points[i];
    }
    
    if (addPoints[n] % 3 != 0) {
        triangles = 0;
    } else {
        lengthSide = addPoints[n] / 3;
        i = 1;
        while (points[i] != 0) {
            numberLookingFor = addPoints[i] + lengthSide;
            points[i] = 0;
            numberPosition = BinarySearch(addPoints, i, n, numberLookingFor);
            
            if (numberPosition < 0) {
                i++;
            } else {
                numberLookingFor = addPoints[numberPosition] + lengthSide;
                points[numberPosition] = 0;
                numberPosition = BinarySearch(addPoints, numberPosition, n, numberLookingFor);
                
                if (numberPosition < 0) {
                    i++;
                } else {
                    points[numberPosition] = 0;
                    triangles++;
                    i++;
                }
            }
        }
    }
    return triangles;
}

int main() {
    int triangles;

    while ((triangles = procesarCasosDePrueba()) != -1) {
        printf("%d\n", triangles);
    }

    return 0;
}

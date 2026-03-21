#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define myInfinite 2147483647

typedef struct
{
    long double x, y;
}point;

int main()
{
    int k, index, jIndex;
    point points [1005];
    long double partialMean, betterMean = myInfinite;
    
    scanf ("%d", &k);
    for (index = 1; index <= k; index++) 
        scanf ("%Lf %Lf", &points[index].x, &points[index].y);
    for (index = 1; index <= k; index ++) {
        partialMean = 0;
        for (jIndex = 1; jIndex <= k; jIndex ++) {
            partialMean += sqrt (pow (points[index].x - points[jIndex].x, 2) + pow (points[index].y - points[jIndex].y, 2));
        }
        partialMean = partialMean / (k - 1);
        
        if (partialMean < betterMean) 
            betterMean = partialMean;
    }
    
    printf ("%0.9Lf\n", betterMean);
    
    return 0;
}

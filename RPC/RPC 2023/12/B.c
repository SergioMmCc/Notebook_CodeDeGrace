#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAXT 1000

int main () {
    int n, first [MAXT + 1], second [MAXT + 1], win1 = 0, win2 = 0, index, jindex;
    
    scanf ("%d", &n);
    for (index = 1; index <= n; index ++) 
        scanf ("%d", &first [index]);
    for (index = 1; index <= n; index ++) 
        scanf ("%d", &second [index]);
    
    for (index = 1; index <= n; index ++) {
        for (jindex = 1; jindex <= n; jindex ++) {
            if (first [index] > second [jindex])
                win1 ++;
            else if (first [index] < second [jindex])
                win2 ++;
        }
    }
    
    if (win1 > win2)
        printf ("first\n");
    else if (win1 < win2)
        printf ("second\n");
    else
        printf ("tie\n");
    
    return 0;
}

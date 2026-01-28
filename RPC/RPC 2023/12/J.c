#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAXT 100000

int main () {
    int n, result = 0, index, save;
    char winner [MAXT + 1], me [MAXT + 1];
    
    scanf ("%d", &n);
    scanf ("%s", winner);
    scanf ("%s", me);
    
    for (index = 0; index < n; index ++) {
        save = abs ((int)winner [index] - (int)me [index]);
        if (save >= 14)
            save = 26 - save;
        
        result += save;
    }
    
    printf ("%d\n", result);
    
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int totalCases, a, b, result, index, completeIndex, add, cifras = 1, diference;
    int calcular2[3500] = {0}, flag2[10005], calcular5[7000] = {0}, flag5[10005] = {0};
    
    calcular2[1] = 1;
    calcular5[1] = 1;
    
    for (completeIndex = 1; completeIndex <= 10000; completeIndex++) {
        for (index = 1; index <= cifras; index++) {
            calcular2[index] *= 2;
            calcular2[index] += add;
            add = 0;
            if (calcular2[index] / 10 > 0) {
                add = calcular2[index]/10;
                calcular2[index] %= 10;
            }     
        }
        if (add > 0) {
            cifras++;
            calcular2[cifras] += add;
            add = 0;
        }
        flag2[completeIndex] = cifras - 1;
    }
    
    cifras = 1;
    for (completeIndex = 1; completeIndex <= 10000; completeIndex++) {
        for (index = 1; index <= cifras; index++) {
            calcular5[index] *= 5;
            calcular5[index] += add;
            add = 0;
            if (calcular5[index] / 10 > 0) {
                add = calcular5[index]/10;
                calcular5[index] %= 10;
            }     
        }
        if (add > 0) {
            cifras++;
            calcular5[cifras] += add;
            add = 0;
        }
        flag5[completeIndex] = cifras - 1;
    }
    
    scanf ("%d", &totalCases);
    
    while (totalCases--) {
        scanf ("%d %d", &a, &b);
        result = 0;
        
        if (a == b)
            result = a + 1;
        else {
            diference = abs (a - b);
            if (a > b) 
                result = b + flag2[diference] + 1;
            else 
                result = a + flag5[diference] + 1;
        }
        printf ("%d\n", result);
    }
    
    return 0;
}

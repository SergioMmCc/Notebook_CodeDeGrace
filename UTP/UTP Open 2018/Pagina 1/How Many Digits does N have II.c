#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int count20[5005] = {0}, count21[5005] = {1}, count22[5005] = {0}, count23[5005] = {0}, count24[5005] = {0}; 
    int count25[5005] = {0}, count26[5005] = {0}, count27[5005] = {0}, count28[5005] = {0}, count29[5005] = {0};
                                                                                               
    int count50[5005] = {0}, count51[5005] = {1}, count52[5005] = {0}, count53[5005] = {0}, count54[5005] = {0};
    int count55[5005] = {0}, count56[5005] = {0}, count57[5005] = {0}, count58[5005] = {0}, count59[5005] = {0};
                                                                                               
    int totalCases, a, b, result, index, completeIndex, add, cifras = 1, diference;
    int calcular2[1600] = {0}, flag2[5005], calcular5[3500] = {0}, flag5[5005] = {0};
    
    int result0, result1;                                                                                               
    
    calcular2[1] = 1;
    calcular5[1] = 1;
    
    for (completeIndex = 1; completeIndex <= 5000; completeIndex++) {
        for (index = 1; index <= cifras; index++) {
            calcular2[index] *= 2;
            calcular2[index] += add;
            add = 0;
            if (calcular2[index] / 10 > 0) {
                add = calcular2[index]/10;
                calcular2[index] %= 10;
            }
            
            if (calcular2[index] == 0)
                count20[completeIndex]++;
            else if (calcular2[index] == 1)
                count21[completeIndex]++;
            else if (calcular2[index] == 2)
                count22[completeIndex]++;
            else if (calcular2[index] == 3)
                count23[completeIndex]++;
            else if (calcular2[index] == 4)
                count24[completeIndex]++;
            else if (calcular2[index] == 5)
                count25[completeIndex]++;
            else if (calcular2[index] == 6)
                count26[completeIndex]++;
            else if (calcular2[index] == 7)
                count27[completeIndex]++;
            else if (calcular2[index] == 8)
                count28[completeIndex]++;
            else if (calcular2[index] == 9)
                count29[completeIndex]++; 
        }
        if (add > 0) {
            cifras++;
            calcular2[cifras] += add;
            add = 0;
            
            if (calcular2[cifras] == 0)
                count20[completeIndex]++;
            else if (calcular2[cifras] == 1)
                count21[completeIndex]++;
            else if (calcular2[cifras] == 2)
                count22[completeIndex]++;
            else if (calcular2[cifras] == 3)
                count23[completeIndex]++;
            else if (calcular2[cifras] == 4)
                count24[completeIndex]++;
            else if (calcular2[cifras] == 5)
                count25[completeIndex]++;
            else if (calcular2[cifras] == 6)
                count26[completeIndex]++;
            else if (calcular2[cifras] == 7)
                count27[completeIndex]++;
            else if (calcular2[cifras] == 8)
                count28[completeIndex]++;
            else if (calcular2[cifras] == 9)
                count29[completeIndex]++;
            
        }
        flag2[completeIndex] = cifras - 1;
    }
    
    cifras = 1;
    for (completeIndex = 1; completeIndex <= 5000; completeIndex++) {
        for (index = 1; index <= cifras; index++) {
            calcular5[index] *= 5;
            calcular5[index] += add;
            add = 0;
            if (calcular5[index] / 10 > 0) {
                add = calcular5[index]/10;
                calcular5[index] %= 10;
            }
            
            if (calcular5[index] == 0)
                count50[completeIndex]++;
            else if (calcular5[index] == 1)
                count51[completeIndex]++;
            else if (calcular5[index] == 2)
                count52[completeIndex]++;
            else if (calcular5[index] == 3)
                count53[completeIndex]++;
            else if (calcular5[index] == 4)
                count54[completeIndex]++;
            else if (calcular5[index] == 5)
                count55[completeIndex]++;
            else if (calcular5[index] == 6)
                count56[completeIndex]++;
            else if (calcular5[index] == 7)
                count57[completeIndex]++;
            else if (calcular5[index] == 8)
                count58[completeIndex]++;
            else if (calcular5[index] == 9)
                count59[completeIndex]++;
        }
        if (add > 0) {
            cifras++;
            calcular5[cifras] += add;
            add = 0;
            
            if (calcular5[cifras] == 0)
                count50[completeIndex]++;
            else if (calcular5[cifras] == 1)
                count51[completeIndex]++;
            else if (calcular5[cifras] == 2)
                count52[completeIndex]++;
            else if (calcular5[cifras] == 3)
                count53[completeIndex]++;
            else if (calcular5[cifras] == 4)
                count54[completeIndex]++;
            else if (calcular5[cifras] == 5)
                count55[completeIndex]++;
            else if (calcular5[cifras] == 6)
                count56[completeIndex]++;
            else if (calcular5[cifras] == 7)
                count57[completeIndex]++;
            else if (calcular5[cifras] == 8)
                count58[completeIndex]++;
            else if (calcular5[cifras] == 9)
                count59[completeIndex]++;
            
        }
        flag5[completeIndex] = cifras - 1;
    }
    
    scanf ("%d", &totalCases);
    
    while (totalCases--) {
        scanf ("%d %d", &a, &b);
        result = 0;
        
        if (a == b) {
            result = a + 1;
            result0 = result - 1;
            result1 = 1;
            printf ("%d\n%d\n0\n0\n0\n0\n0\n0\n0\n0\n", result0, result1);
        } 
        else {
            diference = abs (a - b);
            if (a > b) {
                result = b + flag2[diference] + 1;
                result0 = b + count20[diference];
                result1 = count21[diference];
                
                printf ("%d\n%d\n%d\n%d\n%d\n", result0, result1, count22[diference], count23[diference], count24[diference]);
                printf ("%d\n%d\n%d\n%d\n%d\n", count25[diference], count26[diference], count27[diference], count28[diference], count29[diference]);
            }
                
            else {
                result = a + flag5[diference] + 1;
                result0 = a + count50[diference];
                result1 = count51[diference];
                
                printf ("%d\n%d\n%d\n%d\n%d\n", result0, result1, count52[diference], count53[diference], count54[diference]);
                printf ("%d\n%d\n%d\n%d\n%d\n", count55[diference], count56[diference], count57[diference], count58[diference], count59[diference]);
            }       
        }
        
        printf ("%d\n", result);
    }
    
    return 0;
}

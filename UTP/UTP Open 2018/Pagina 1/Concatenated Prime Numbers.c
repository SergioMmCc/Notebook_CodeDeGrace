#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define limite 10001000

int main() {
    bool es_primo[limite + 1], result;
    int cifras, longitud, evaluate;
    char number[1020], saveNumber[10];
    
    es_primo[0] = es_primo[1] = false;
    for (int i = 2; i <= limite; ++i) 
        es_primo[i] = true;
    
    for (long long int p = 2; p * p <= limite; p++) {
        if (es_primo[p]) {
            for (long long int i = p * p; i <= limite; i += p) 
                es_primo[i] = false;
        }
    }
    
    while (scanf ("%d %s", &cifras, number) != EOF) {
        memset (saveNumber, 0, sizeof(saveNumber));
        longitud = strlen(number) / cifras;
        
        result = true;
        for (int i = 0; i < longitud; i++) {
            evaluate = 0;
            for (int j = 0 + cifras * i, k = 0; k < cifras; j++, k++) 
                saveNumber[k] = number[j];
            evaluate = atoi (saveNumber);
            
            if (!es_primo[evaluate]) {
                result = false;
                printf (":(\n");
                break;
            }  
        }
        
        if (result)
            printf (":)\n");
    }
    
    return 0;
}

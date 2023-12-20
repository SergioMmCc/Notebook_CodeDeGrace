#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define limite 10001000

int main() {
    bool es_primo[limite + 1];
    
    es_primo[0] = es_primo[1] = false;
    for (int i = 2; i <= limite; ++i) 
        es_primo[i] = true;
    
    for (long long int p = 2; p * p <= limite; p++) {
        if (es_primo[p]) {
            for (long long int i = p * p; i <= limite; i += p) 
                es_primo[i] = false;
        }
    }
    
    return 0;
}

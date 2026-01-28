#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main() {
    long long int tiempo, tiempo2, K, T, N;
    scanf ("%lld", &T);
    while (T--) {
        tiempo = tiempo2 = 0;
        scanf ("%lld %lld", &N, &K);
        do {
            tiempo2 = (tiempo2 + K) % 60;
            tiempo ++;
        } while (tiempo % 60 != tiempo2);
        printf ("%lld\n", tiempo * N);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void A (int h, int k, int v, int s) {
    int x;
    while (h > 0) {
        v+=s;
        if (floor (v/10) > 1)
            v -= floor (v/10);
        else
            v --;
        if (v >= k)
            h ++;
        else if (v > 0)
            h --;
        if (v <= 0 || h == 0) {
            v = 0;
            h = 0;
        }
        x+=v;
        if (s>0)
            s--;
    }
    printf ("%d\n", x);
}

int main () {
    int h, k, v, s;
    scanf ("%d %d %d %d", &h, &k, &v, &s);
    A (h, k, v, s);
    return 0;
}

#include <stdio.h>

int main() {
    int x, divisible = 0, contain = 0;
    scanf ("%d", &x);
    if (x % 7 == 0)
        divisible = 1;
    while (x > 0) {
        if (x % 10 == 7) {
            contain = 1;
            break;
        }
        x = x / 10;
    }
    
    if (divisible == 0 && contain == 0)
        printf ("0\n");
    else if (divisible == 1 && contain == 0)
        printf ("1\n");
    else if (divisible == 0 && contain == 1)
        printf ("2\n");
    else
        printf ("3\n");

    return 0;
}

#include <stdio.h>
#include <math.h>


int main ()
{
	unsigned long long int n, k, boxes, x;
	scanf("%llu %llu", &n, &k);
    boxes = n / k;
    if((boxes * k) < n)
        boxes++;
    x = n / boxes;
	printf ("%llu\n", x);
	return 0;
}

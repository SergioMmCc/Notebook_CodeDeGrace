#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <math.h>

int main () {
	int n, modulo;
	unsigned long long int result;
	scanf ("%d", &n);
	
	modulo = n%5;
	result = (unsigned long long int)25*(n/5);
	
	if (modulo != 0) {
		result += (unsigned long long int) pow(modulo, 2);	
	}
	
	printf ("%llu\n", result);
	
	return 0;
}


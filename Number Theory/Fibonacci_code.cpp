#include "../template.h"

const int len = 51; // Para calcular hasta el n-esimo termino
vl fibo(len);

// Calcula Fibonacci. Tomando fibo[0] = 0, fibo[1] = 1
// Complejidad: O(n).
void calcFibo(){
    fibo[1] = 1;
    forlr(i,2,len-1) fibo[i] = fibo[i-2] + fibo[i-1];
}

/* 
- Calcula el codigo de fibonacci de un numero n.
- Todo numero natural n puede ser representado como una secuencia unica
  de numeros de Fibonacci tal que no hay 2 numeros consecutivo iguales.
- El algoritmo itera cada numero de fibonacci f[i] con i desde len hasta
  2, revisa si este es menor o igual a n, en caso de que si asigna 1 en 
  la posicion i-2 del codigo y resta el valor a n, y en caso de que no 
  asigna 0 en la posicion i-2.
- Complejidad: aproximadamente O(log(n)).
*/
vb fiboCode(ll n){
    vb code(len - 1);
    forrl(i,2,len-1){
        if(n >= fibo[i]){
            code[i-2] = 1;
            n -= fibo[i];
        }
    }

    return code;
}

void solver(){
    calcFibo(); // Precalcular Fibonacci

    // Mostrar el codigo de fibonacci de los numeros desde 0 hasta 10
    for0(i,11){
        vb code = fiboCode(i);
        for0(i,12) cout<<code[i];
        cout<<endl;
    }
}
#include "../template.h"

/*
- Un grafo funcional es aquel en el que cada nodo tiene exactamente
  una arista de salida. Cada componente tiene exactamente un ciclo.
- Dado un nodo 'x', halla el tamaño del ciclo que hay en el 
  componente al que peretenece 'x'.
- func[u] dice hacia donde va la arista que sale de 'u'.
- Complejidad: O(n).
*/

// x es el nodo inicial desde el cual se va a buscar un ciclo
int floyd(int x, vi& func){
    int a = func[x];
    int b = func[func[x]];

    // En el momento en que 'a' y 'b' se encuentran, 'a' ha caminado 'k' pasos y 'b' '2k' pasos, 
    // entonces (k % lenCycle = 0)
    while(a != b){
        a = func[a];
        b = func[func[b]];
    }

    // El primer nodo que pertenece al ciclo (partiendo desde 'x') se encuentra moviendo 
    // el puntero 'a' al nodo 'x' y avanazando 'a' y 'b' paso por paso hasta que se encuentran 
    // de nuevo
    a = x;
    while(a != b){
        a = func[a];
        b = func[b];
    }
    int firstCycleNode = a;

    // En este punto tanto 'a' como 'b' estan parados en el nodo inicial del ciclo, entonces 
    // para hallar la longitud del ciclo simplemente se puede avanzar 'b' paso por paso 
    // hasta que se vuelva a encontrar con 'a', la cantidad de pasos dados es la longitud 
    // del ciclo
    b = func[b];
    int len = 1;
    while(a != b){
        b = func[b];
        len++;
    }

    return len;
}
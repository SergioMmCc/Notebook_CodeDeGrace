/* El hashing map sirve para almacenar elementos en un conjunto especifico
Consiste en leer un numero a para almacenar cierto dato en un vector, entonces
al número que tenemos en la posicion a de nuestro vector le hacemos xor con un
número r random, asegurando de esta manera que el valor que tendrá será único */

/* El ejercicio que se encuentra en este archivo consiste en t casos de prueba.
Nos dan n ciudades y todas están conectadas de la forma i con i+1, para i < n,
y para i = n se dice que está conectada con la ciudad 1. Entonces nos dan m 
pares de amigos que pertenecen respectivamente a la ciudad a y a la ciudad b.
Entonces se nos pregunta cual es la minima cantidad de caminos que puede tener
la ciudad de modo que cada par de amigos esté conectado.

Para resolver este ejercicio usamos hashing xor de la siguiente manera:
Se leen los número a y b y al valor que tenía en cada posición se le hace
un XOR con un número random (de 64 bits para evitar colisiones).
Posteriormente, queremos encontrar un número fixAns que sea la mayor cantidad de
números consecutivos iguales, de modo que podamos decir que puedo conectar todas
las ciudades usando n - fixAns caminos. Debido a que nuestro vector tiene guardados
los números a los que les aplicamos XOR, podemos elegir un número arbitrario save
que guarde en dicha posición dentro de un mapa las veces que encontré save. Save va
a cambiar según el número que estamos evaluando del vector y solo volverá a ser el
mismo número que en una iteración anterior cuando cruce por un número en el vector
que sea diferente de 0, o cuando halla pasado por el mayor número a o b que leí
al inicio del ejercicio.*/

/* Link del ejercicio: https://codeforces.com/problemset/problem/1996/G
Para una explicación mas detallada de la logica detrás de está colución, dirigirse
a la editorial, la cual se puede encontrar en el link adjunto*/


#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

// "rng" genera un número random de 64 bits
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solver() {
    int n, m, a, b;
    long long r;
    cin>>n>>m;
    vector<long long> D(n);
    while(m--) {
        cin>>a>>b;
        r = rng();
        D[a-1] ^= r;
        D[b-1] ^= r;
    }
    
    unordered_map<long long, int> conjuntos;
    int fixAns = 0;
    long long save = 0;
    for(long long diag : D)
        fixAns = max(fixAns, conjuntos[save^=diag]++);
        
    cout<<n-fixAns-1<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t;cin>>t;
    while(t--) {
        solver();
    }

    return 0;
}
#include "../template.h"

//Esta función genera numeros aleatorios hasta de 64 bits
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solver(){
    long long x;
    x = rng();
    cout<<x<<endl;
}
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

//Esta función genera numeros aleatorios hasta de 64 bits
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main (){
    long long x;
    x = rng();
    cout<<x<<endl;
}
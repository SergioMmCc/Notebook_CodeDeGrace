#include "../template.h"

// Para un sliding window de minimos. Complejidad O(n)
void sw(vi& a, int k){
    int n = sz(a); // Se asume que n >= k
    deque<pii> dq;

    // Insertar los primeros k-1
    for0(i,k-1){
        // Elimino todos los mayores o iguales que puse antes
        while(!dq.empty() && dq.back().fi >= a[i]) dq.pop_back();
        dq.pb({a[i], i});
    }

    forlr(i,k-1,n-1){
        if(i - dq.front().se == k) dq.pop_front(); // Elimino el elemento que sale de la ventana

        // Elimino todos los mayores o iguales al nuevo elemento
        while(!dq.empty() && dq.back().fi >= a[i]) dq.pop_back(); 
        dq.pb({a[i], i});

        // Elemento menor en esta ventana
        cout<<dq.front().fi<<endl;
    }
}
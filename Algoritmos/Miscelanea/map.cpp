// Como acceder a los elementos de un mapa
map<int, int> T;

// Recorrer por valor o referencia
T[key]; // Accede al valor de key
for(const auto& par : T){
    key = par.first;
    valor = par.second;
}

// Por puntero o iterador
auto it = T.find(key);
if(it != T.end()){
    key = it->first;
    valor = ir->second;
}

// lower_bound y upper_bound en set y map
auto it = T.lower_bound(key);
auto it = T.upper_bound(key);
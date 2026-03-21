#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

using ordered_set = 
    tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update>;

typedef pair<long long, long long> pll;
set<long long> reps;
vector<long long> vecReps;
vector<set<long long>> order(500001);
vector<long long> freq(500001, 0);
ordered_set cities;

int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    long long n, m, q;
    cin>>n>>m>>q;
    long long save;
    for(int i = 0; i < n; i++) {
        cin>>save;
        freq[save]++;
    }

    //En donde tengo cierto numero de repeticiones, lo meto dentro
    //de un set a todas las ciudades que han salido esa misma cantidad
    //de veces. Para saber que indices tengo que recorrer de manera eficiente
    //Guardo en un set (que sera convertido en un vector) cuales numeros
    //tienen al menos una ciudad que solo haya recibido los juegos ese numero
    //de veces
    for(int i = 1; i <= m; i++) {
        order[freq[i]].insert(i);
        reps.insert(freq[i]);
    }

    //Cambiar las repeticiones de un set a un 
    //vector para poder operar con sus indices facilmente
    for(long long i : reps)
        vecReps.push_back(i);
    vecReps.push_back(1e6);

    //Ordenar las queries
    vector<pll> queries;
    long long saveQuery;
    vector<long long> result(q+1);
    for(int i = 1; i <= q; i++) {
        cin>>saveQuery;
        queries.push_back({saveQuery, i});
    }
    sort(queries.begin(), queries.end());
    
    //Agrego los elementos del primer ciclo a mis ciudades
    for(long long i : order[vecReps[0]])
        cities.insert(i);
    
    long long i = 0;
    long long currentRange = n, nextRange = 0;
    for(pll query : queries) {
        while(nextRange < query.first && cities.size() < m) {
            nextRange = currentRange + cities.size()*(vecReps[i+1] - vecReps[i]);
            if(nextRange < query.first || i == vecReps.size()-2) {
                currentRange = nextRange;
                i++;
                for(long long nextCity : order[vecReps[i]])
                    cities.insert(nextCity);
            }
        }
        result[query.second] = *cities.find_by_order((query.first - currentRange - 1) % cities.size()); 
    }

    for(int i = 1; i <= q; i++)
        cout << result[i] << "\n";

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> pll;

void solver() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    unordered_map<long long, vector<long long>> multiplos;
    vector<pll> freq;
    int n;
    long long save, mayor, menor;
    long long m, saveMax = 0, aporte1, aporte2;
    vector<long long> f;
    cin>>n>>m;
    for(int i = 0; i < n; i++) {
        cin>>save;
        f.push_back(save);
    }
    sort(f.begin(), f.end());
    
    //Guardar las frecuencias de cada numero
    for(int i = 0; i < n;) {
        int current = f[i];
        int contador = 0;
        while(current == f[i]) {
            contador++;
            i++;
        }
        freq.push_back({current, contador});
    }
    
    for(int i = 0; i < freq.size(); i++) {
        save = freq[i].first;
        multiplos[save].push_back(0);
        for(long long j = 1; j <= freq[i].second && save*j <= m; j++) 
            multiplos[save].push_back(save*j);
    }
    
    for(int i = freq.size()-1; i >= 0; --i) {
        if(i > 0 && freq[i].first == freq[i-1].first+1) {
            mayor = freq[i].first;
            menor = freq[i-1].first;
            int k = 0;
            for(int j = multiplos[mayor].size()-1; j >= 0; --j) {
                aporte1 = multiplos[mayor][j];
                while(k < multiplos[menor].size() && aporte1 + multiplos[menor][k] < m)
                    k++;
                if(k == multiplos[menor].size() || aporte1 + multiplos[menor][k] > m)
                    k--;
                aporte2 = multiplos[menor][k];
                saveMax = max(saveMax, aporte1 + aporte2);
            }
        }
        
        else {
            int j = multiplos[freq[i].first].size()-1;
            saveMax = max(saveMax, multiplos[freq[i].first][j]);
        }
    }
    cout << saveMax << "\n";
}

int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        solver();
    }

    return 0;
}
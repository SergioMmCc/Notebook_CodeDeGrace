#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define int long long
typedef pair<int, int> pii;

void solver(){
    int n; cin>>n;
    int area = 0;
    map<int, set<int>> lados, alturas;
    for(int i = 1; i <= n; i++){
        int x, y; cin>>x>>y;
        lados[x].insert(y);
        alturas[y].insert(x);
    }

    while(!lados.empty()){
        int minx = lados.begin()->first;
        while(lados[minx].sz > 1){
            set<int>::iterator it1 = lados[minx].begin(), it2 = --lados[minx].end();
            int miny = *it1, maxy = *it2;
            lados[minx].erase(it1), lados[minx].erase(it2);

            // Ahora buscar su contraparte en el lado contrario
            int maxx = lados.rbegin()->first;
            lados[maxx].erase(miny); lados[maxx].erase(maxy);
            if(lados[maxx].empty()) lados.erase(maxx);

            // Eliminar los puntos tambien en el mapa de alturas
            alturas[maxy].erase(minx); alturas[maxy].erase(maxx);
            if(alturas[maxy].empty()) alturas.erase(maxy);
            alturas[miny].erase(minx); alturas[miny].erase(maxx);
            if(alturas[miny].empty()) alturas.erase(miny);

            area = (maxx - minx) * (maxy - miny);
        }

        if(lados[minx].empty()) lados.erase(minx);
        else{ // Quiere decir que cada un punto, el cual corresponde a un rombo
            int yl = *lados[minx].begin();
            int maxx = lados.rbegin()->first; // El punto del otro lado si o si es el mayor y solo puede haber 1
            int yr = *lados[maxx].begin();

            // Ademas, sus otros puntos correspondientes tienen que ser el mas alto y el mas bajo entre todos
            int maxy = alturas.rbegin()->first, miny = alturas.begin()->first;
            int xu = *alturas[maxy].begin(), xd = *alturas[miny].begin();

            // Ahora el borrado
            lados[minx].erase(yl); lados.erase(minx);
            alturas[yl].erase(minx); if(alturas[yl].empty()) alturas.erase(yl);

            lados[maxx].erase(yr); lados.erase(maxx);
            alturas[yr].erase(maxx); if(alturas[yr].empty()) alturas.erase(yr);

            alturas[miny].erase(xd); alturas.erase(miny);
            lados[xd].erase(miny); if(lados[xd].empty()) lados.erase(xd);

            alturas[maxy].erase(xu); alturas.erase(maxy);
            lados[xu].erase(maxy); if(lados[xu].empty()) lados.erase(xu);

            // Ahora el calculo de esa area
            area = sqrt(((maxx - xd) * (maxx - xd) + (yr - miny) * (yr - miny)) * 
                        ((maxx - xu) * (maxx - xu) + (maxy - yr) * (maxy - yr)));
        }
    }

    cout<<area<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<ll, int> pii;

void solver(){
    int n; ll k; cin>>n>>k;
    vector<ll> p(n); vector<int> d(n);
    for(int i = 0; i < n; i++) cin>>p[i];
    for(int i = 0; i < n; i++) cin>>d[i];
    
    int q; cin>>q;
    while(q--){
        vector<vector<vector<bool>>> used(n, vector<vector<bool>>(2, vector<bool>(k)));
        ll start; cin>>start;
        if(start < p[0] || start > p[n-1]){
            cout<<"YES"<<endl;
            continue;
        }
        ll t = 0;
        bool dir = 1;

        auto it = lower_bound(p.begin(), p.end(), start);
        int index = distance(p.begin(), it);

        t += p[index] - start; t %= k;

        bool pos = 0;
        while(1){
            if(used[index][dir][t]) break; // Si vuelvo a una posicion ya visitada en un tiempo ya utilizado quiere decir que no puedo salir

            used[index][dir][t] = 1;
            if(t == d[index]) dir = !dir;

            if(dir){ // derecha
                if(index == n-1){ // Si era el ultimo entonces salgo
                    pos = 1;
                    break;
                }

                // Avanzo al siguiente a la derecha
                t += (p[index + 1] - p[index]);
                t %= k;
                index++;
            }

            else{ // izquierda
                if(!index){ // Si es el primero entonces salgo
                    pos = 1;
                    break;
                }

                // Avanzo a la izquierda
                t += (p[index] - p[index - 1]);
                t %= k;
                index--;
            }
        }

        cout<<(pos ? "YES" : "NO")<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
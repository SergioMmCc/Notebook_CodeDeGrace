#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;
typedef pair<ld, ld> pdd;

ld tonum(string s){
    int ans=0, k=1000;
    bool b=0;
    for(char i : s){
        if(i == '.'){
            b = 1;
            continue;
        }
        ans *= 10;
        ans += i-'0';
        if(b) k /= 10;
    }
    return (ld)ans*k / 1000.0;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // x * 1000;
    int n; string sp; cin>>n>>sp;
    ld p = tonum(sp);

    vector<pdd> vec;
    ld ans = 0.0;
    for(int i = 0; i<n; i++){
        int num; string s; cin>>num>>s;
        ld aux = tonum(s);
        if(aux == p) ans += (ld)num;
        else vec.pb({aux, (ld)num});
    }

    sort(vec.begin(), vec.end());

    // Poner primero los menores a p
    ld aux = 0.0, pp = 0.0;
    for(int i = 0; i < vec.sz; i++){
        ld num = vec[i].se, r = vec[i].fi;

        if(r < p){
            aux += num;
            pp += num * r;
        }

        else{
            // Agregar todo
            if((pp + num * r) / (aux + num) <= p){
                aux += num;
                pp += num * r;
            }

            // Agregar lo maximo para que sea == p
            else{
                aux += (aux * p - pp) / (r - p);
                pp = p;
                break;
            }
        }
    }

    if(pp == p) aux += ans;
    else aux = ans;

    // Poner primero los mayores a p
    ld aux2 = 0.0, pp2 = 0.0;
    for(int i = (int)vec.sz - 1; i >= 0; i--){
        ld num = vec[i].se, r = vec[i].fi;

        if(r > p){
            aux2 += num;
            pp2 += num * r;
        }

        else{
            if((pp2 + num * r) / (aux2 + num) >= p){
                aux2 += num;
                pp2 += num * r;
            }

            else{
                aux2 += (aux2 * p - pp2) / (r - p);
                pp2 = p;
                break;
            }
        }
    }

    if(pp2 == p) aux2 += ans;
    else aux2 = ans;

    ans = max(aux, aux2);
    cout<<fixed<<setprecision(5)<<ans<<endl;
}
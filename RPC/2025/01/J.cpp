#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define int long long
typedef pair<int, int> pii;

vector<int> fibos;
void calcfibos(){
    fibos.pb(1);fibos.pb(2);
    int i = 2;
    while(fibos[i-1] + fibos[i-2] < 2e9){
        fibos.pb(fibos[i-1] + fibos[i-2]);
        i++;
    }
}

void solver(){
    int n, q; cin>>n>>q;
    map<int, int> T; //Number, lastOcurrence
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    vector<map<int, int>> segs(fibos.sz);
    T[a[0]] = 0;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < fibos.sz; j++){
            int fibo = fibos[j];
            int search = fibo - a[i];
            if(T.find(search) == T.end()) continue;
            
            int l = T[search], r = i;
            auto it = segs[j].lower_bound(l);
            if(it != segs[j].end()) continue;
            segs[j][l] = r;
        }

        T[a[i]] = i;
    }

    while(q--){
        int l, r; cin>>l>>r;
        int count = 0;
        for(int j = 0; j < fibos.sz; j++){
            if(segs[j].empty()) continue;
            auto it = segs[j].lower_bound(l);
            if(it == segs[j].end() || it->first > r) continue;
            int index = it->second;
            if(index <= r) count++;
        }

        cout<<count<<endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    calcfibos();
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
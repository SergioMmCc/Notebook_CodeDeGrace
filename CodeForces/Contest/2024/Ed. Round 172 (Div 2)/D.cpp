#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

#define int long long

typedef pair<int, int> pii;
typedef pair<pii, int> piii;

struct compL {
    bool operator () (piii a, piii b){
        if(a.first.first == b.first.first) return a.first.second > b.first.second;
        return a.first.first < b.first.first;
    }
};

struct compR {
    bool operator () (piii a, piii b){
        if(a.first.second == b.first.second) return a.first.first < b.first.first;
        return a.first.second > b.first.second;
    }
};

void solver(){
    int n; cin>>n;
    vector<piii> segments(n);
    for(int i = 0; i < n; i++){
        int l, r; cin>>l>>r;
        segments[i] = {{l, r}, i};
    }

    vector<int> ansL(n), ansR(n);

    // Respuesta para la izquierda de cada vector
    sort(segments.begin(), segments.end(), compL());
    multiset<pii> lr, rl;
    for(int i = 0; i < n; i++){
        int l = segments[i].first.first, r = segments[i].first.second, index = segments[i].second;
        while(!rl.empty() && (*rl.begin()).first < r){
            int eraseL = (*rl.begin()).second, eraseR = (*rl.begin()).first;
            rl.erase({eraseR, eraseL});
            lr.erase({eraseL, eraseR});
        }

        if(lr.empty()) ansL[index] = 0;
        else if(i < n - 1 && l == segments[i+1].first.first && r == segments[i+1].first.second) ansL[index] = 0;
        else ansL[index] = l - (*lr.rbegin()).first;
        lr.insert({l, r}); rl.insert({r, l});
    }

    // Respuesta para la derecha de cada vector
    sort(segments.begin(), segments.end(), compR());
    lr.clear(); rl.clear();
    for(int i = 0; i < n; i++){
        int l = segments[i].first.first, r = segments[i].first.second, index = segments[i].second;
        while(!lr.empty() && (*lr.rbegin()).first > l){
            int eraseL = (*lr.rbegin()).first, eraseR = (*lr.rbegin()).second;
            rl.erase({eraseR, eraseL});
            lr.erase({eraseL, eraseR});
        }

        if(rl.empty()) ansR[index] = 0;
        else if(i < n - 1 && l == segments[i+1].first.first && r == segments[i+1].first.second) ansR[index] = 0;
        else ansR[index] = (*rl.begin()).first - r;
        lr.insert({l, r}); rl.insert({r, l});
    }

    for(int i = 0; i < n; i++) cout<<ansL[i] + ansR[i]<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
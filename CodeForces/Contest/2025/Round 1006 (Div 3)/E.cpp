#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

void solver(){
    int n; cin>>n; if(!n){cout<<0<<endl; return;}

    map<int, int> T;
    vector<int> triangulares;
    for(int i = 1, sum = 2; i <= n; i += sum, sum++){
        triangulares.pb(i);
        T[i] = sum - 1;
    }

    int coordX = -1e9, coordY = -1e9;
    int ans = 0;
    vector<pii> points;
    while(n > 0){
        vector<int>::iterator it = upper_bound(triangulares.begin(), triangulares.end(), n);
        --it;
        int add = T[*it] + 1; ans += add;
        n -= *it;
        for(int i = 0; i < add; i++){
            points.pb({coordX, coordY});
            coordX++;
        }

        coordX++; coordY++;
    }

    cout<<ans<<endl;
    for(int i = 0; i < ans; i++){
        cout<<points[i].first<<' '<<points[i].second<<endl;
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
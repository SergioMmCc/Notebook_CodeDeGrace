#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
using ll = long long;
using ld = long double;
const int N = 1e5 + 1, inf = 1e6;

int n, k;
vector<int> cost(N), color(N);

bool check(int m){
    // cout<<endl<<endl;
    int last = 1e6;
    for(int i = k; i > 0; i--){
        int current = color[i];
        int used = 0;
        while(used < last && m > 0 && current >= cost[m]){
            current -= cost[m];
            m--;
            used++;
        }
        last = used;
    }
    // cout<<endl<<endl;
    if(m == 0) return true;
    else return false;
}

void solver(){cin>>n>>k;
    for(int i = 1; i <= n; i++)
        cin>>cost[i];
    for(int i = 1; i <= k; i++)
        cin>>color[i];
    
    int lo = 1, hi = n, ans = 0;
    while(lo <= hi){
        int m = (lo + hi) / 2;
        // cout<<"lo -> "<<lo<<" hi -> "<<hi<<" m -> "<<m<<endl;
        bool cond = check(m);
        if(cond) {ans = m; lo = m+1;}
        else hi = m - 1;
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
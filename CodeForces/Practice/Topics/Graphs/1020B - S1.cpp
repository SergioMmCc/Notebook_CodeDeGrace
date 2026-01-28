#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

void solver(){
    int n; cin>>n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin>>a[i];

    for(int i = 1; i <= n; i++){
        if(i > 1) cout<<' ';
        vector<bool> visited(n+1);
        bool cond = 0;
        int u = i;
        while(!cond){
            if(visited[u]){
                cout<<u;
                cond = 1;
            }

            else{
                visited[u] = 1;
                u = a[u];
            }
        }
    }

    cout<<endl;
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
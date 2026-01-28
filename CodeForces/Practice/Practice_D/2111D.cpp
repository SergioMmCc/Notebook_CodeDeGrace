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

void solver(){
    int n, m; cin>>n>>m;
    vector<int> a(m);
    for(int i = 0; i < m; i++) cin>>a[i];
    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++){
        for(int j = 1; j < 7; j++){
            if((i + j) % 2) cout<<a[i / 2];
            else cout<<a[m - (i / 2) - 1];
            cout<<' ';
        }

        cout<<endl;
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
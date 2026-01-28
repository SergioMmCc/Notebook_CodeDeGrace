#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

void solver(){
    int n, m; cin>>n>>m;
    vector<int> a(n+1), b(m);
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int j = 0; j < m; j++) cin>>b[j];

    sort(b.begin(), b.end());
    a[1] = min(b[0] - a[1], a[1]);

    for(int i = 2; i <= n; i++){
        int search = a[i-1] + a[i];
        vector<int>::iterator it = lower_bound(b.begin(), b.end(), search);
        if(it == b.end()){
            if(a[i] >= a[i-1]) continue;
            cout<<"No"<<endl;
            return;
        }
        if(a[i] >= a[i-1]){
            a[i] = min(a[i], *it - a[i]);
        }
        else a[i] = *it - a[i];
    }
    
    cout<<"Yes"<<endl;
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
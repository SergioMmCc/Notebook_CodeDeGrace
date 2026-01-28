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
    int n, j, k; cin>>n>>j>>k;
    vector<int> a(n+1);
    int maxi = -1;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        maxi = max(maxi, a[i]);
    }

    if(a[j] == maxi) cout<<"Yes"<<endl;
    else if(k == 1) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
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
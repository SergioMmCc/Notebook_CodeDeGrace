#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

void solver(){
    int n, k; cin>>n>>k;
    vector<int> a(n+1);
    if(k % 2){
        for(int i = 1; i < n - 1; i++) a[i] = n;
    }
    else{
        for(int i = 1; i < n - 1; i++) a[i] = n-1;
    }

    a[n-1] = n;
    a[n] = n-1;
    for(int i = 1; i <= n; i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;
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
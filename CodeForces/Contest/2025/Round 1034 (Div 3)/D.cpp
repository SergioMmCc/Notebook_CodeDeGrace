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
    int n, k; cin>>n>>k;
    string s; cin>>s;
    int count = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1') count++;
    }

    if(count <= k || k > n / 2) cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
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
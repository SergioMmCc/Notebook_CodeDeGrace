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
    int c; cin>>c;
    int n = 0;
    vector<int> a(c);
    for(int i = 0; i < c; i++){
        cin>>a[i];
        n += a[i];
    }

    n /= 3;
    bool cond = 1;
    for(int i = 0; cond && i < c; i++){
        if(a[i] > n) cond = 0;
    }

    cout<<(cond ? "YES" : "NO")<<endl;
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
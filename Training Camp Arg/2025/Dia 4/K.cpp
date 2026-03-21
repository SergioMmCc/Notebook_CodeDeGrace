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

const int inf = 301;

void solver(){
    int n; cin>>n;
    vector<int> tl(n);
    for(int i = 0; i < n; i++){
        string s; int a, b, c; cin>>s>>a>>b>>c;
        if(a == -1) a = inf;
        if(b == -1) b = inf;
        if(c == -1) c = inf;

        tl[i] = min(a, min(b, c));
    }

    sort(tl.begin(), tl.end());
    int count = 0, ans = 0;
    for(int i = 0; count < inf - 1 && i < n; i++){
        if(count + tl[i] < inf) ans++;
        count += tl[i];
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
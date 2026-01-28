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
#define int long long

void solver(){
    int n, s, x; cin>>n>>s>>x;
    vector<int> a(n+1), ps(n+1);
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        ps[i] = a[i] + ps[i-1];
    }

    map<int, int> sum;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] > x){
            sum.clear();
            continue;
        }
        
        if(a[i] == x){
            sum[ps[i-1]]++;
            for(int j = i - 1; a[j] < x && j > 0; j--){
                sum[ps[j-1]]++;
            }
        }

        if(sum.count(ps[i] - s)) ans += sum[ps[i] - s];
    }

    cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
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
    int n; cin>>n;
    vector<int> a(n+1), mini(n+1, 1e7), maxi(n+2, 0);
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        mini[i] = min(a[i], mini[i-1]);
    }

    for(int i = n; i > 0; i--) maxi[i] = max(a[i], maxi[i+1]);

    string ans = "";
    for(int i = 1; i <= n; i++){
        if(mini[i-1] < a[i] && maxi[i+1] > a[i]) ans += '0';
        else ans += '1';
    }

    cout<<ans<<endl;
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
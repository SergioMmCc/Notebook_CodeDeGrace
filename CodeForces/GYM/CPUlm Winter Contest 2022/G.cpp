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
    vector<int> a(n), b(n);
    vector<pii> ab(n-1);
    int hog = 1;
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++){
        cin>>b[i];
        if(!i){
            hog = a[0] * b[0];
            continue;
        }

        ab[i-1] = {a[i] * b[i], i};
    }

    sort(ab.begin(), ab.end());
    vector<int> ans(n, 1);

    for(int i = 0; i < n-1; i++){
        int valor = ab[i].fi * (n - i), index = ab[i].se;
        if(valor < hog){
            cout<<"impossible"<<endl;
            return;
        }

        ans[index] = n - i;
    }

    for(int i = 0; i < n; i++){
        if(i) cout<<' ';
        cout<<ans[i];
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
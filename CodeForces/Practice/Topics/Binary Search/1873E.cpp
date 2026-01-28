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
    int n; ll x; cin>>n>>x;
    vector<ll> a(n+1);
    for(int i = 1; i <= n; i++) cin>>a[i];
    sort(a.begin(), a.end());

    ll h = 1, elements = 0, ft = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] == h){
            elements++;
            continue;
        }

        if(ft + (a[i] - h) * elements < x){
            ft += (a[i] - h) * elements;
            h = a[i];
            elements++;
        }

        else{
            h += (x - ft) / elements;
            ft = x;
            break;
        }
    }

    h += (x - ft) / n;
    cout<<h<<endl;
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
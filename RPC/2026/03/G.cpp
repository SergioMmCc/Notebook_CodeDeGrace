#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pqueue priority_queue
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solver(){
    ll p, q; cin>>p>>q;
    for(ll r = 1; r <= 1e6; r++){
        ll a = p, b = 2*p*r - 2*r*q - p, c = p*r*r - p*r;
        ll disc = b*b - 4*a*c;
        ll sr = sqrt(disc);
        if(sr * sr != disc) continue;
        if(-b - sr > 0 && (-b - sr) % (2*a) == 0){
            cout<<r<<' '<<(-b - sr) / (2*a)<<endl;
            return;
        }
        if(-b + sr > 0 && (-b + sr) % (2*a) == 0){
            cout<<r<<' '<<(-b + sr) / (2*a)<<endl;
            return;
        }
    }

    cout<<"impossible"<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
    // freopen("name.out", "w", stdout);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
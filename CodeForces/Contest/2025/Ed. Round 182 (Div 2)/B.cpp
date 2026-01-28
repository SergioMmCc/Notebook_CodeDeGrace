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
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solver(){
    int a, b; cin>>a>>b;
    int auxa = a, auxb = b, st = 1;

    bool turn = 0;
    int cnt = 0;
    while(1){
        if(!turn){
            if(auxa < st) break;
            auxa -= st;
            turn = 1;
        }

        else{
            if(auxb < st) break;
            auxb -= st;
            turn = 0;
        }
        st *= 2;
        cnt++;
    }

    int ans = cnt;
    turn = 1;
    cnt = 0;
    auxa = a;
    auxb = b;
    st = 1;
    while(1){
        if(!turn){
            if(auxa < st) break;
            auxa -= st;
            turn = 1;
        }

        else{
            if(auxb < st) break;
            auxb -= st;
            turn = 0;
        }
        st *= 2;
        cnt++;
    }

    cout<<max(ans, cnt)<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
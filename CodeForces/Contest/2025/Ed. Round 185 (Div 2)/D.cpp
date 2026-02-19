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
    int n, q; cin>>n>>q;
    string s; cin>>s;
    int atake = 0, aalter = 0, anor = 0, ares = 0, asig = 0, carry = 0;
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(s[i] != '?'){
            anor += aalter; aalter = 0;
            if(s[i] == 'X') sum += 10;
            else if(s[i] == 'V') sum += 5;
            else{
                if(i < n-1 && (s[i+1] == 'X' || s[i+1] == 'V')) sum--;
                else sum++;
            }
            continue;
        }
        asig++;

        if(i < n-1 && (s[i+1] == 'V' || s[i+1] == 'X') && i && s[i-1] == 'I'){
            sum -= 2;
            anor++;
            anor += aalter;
            aalter = 0;
        }
        else if(i < n - 1 && (s[i+1] == 'V' || s[i+1] == 'X')) atake++, anor += aalter, aalter = 0;
        else if(i && s[i-1] == 'I') ares++, anor += aalter, aalter = 0;
        else if((i == n-1 || s[i+1] == 'I') && (!i || s[i-1] == 'V' || s[i-1] == 'X')) anor++, anor += aalter, aalter = 0;
        else{
            aalter++;
            if(aalter == 2) carry += 2, aalter = 0;
        }
    }
    if(aalter) anor++;

    while(q--){
        int ans = sum;
        int take = atake, alter = carry, nor = anor, res = ares;
        int aux;
        int x, v, i; cin>>x>>v>>i;

        // take
        aux = min(take, i);
        ans -= aux;
        take -= aux;
        i -= aux;

        // Alter
        aux = min(i, alter / 2);
        ans += aux;
        i -= aux;
        res += aux;
        nor += alter - 2*aux;
        alter = 0;

        // Nor
        aux = min(i, nor);
        ans += aux;
        i -= aux;
        nor -= aux;

        // res
        aux = min(res, i);
        ans += aux;
        res -= aux;
        i -= aux;

        // Completar con V
        aux = min(res, v);
        ans += 3*aux;
        v -= aux;
        res -= aux;

        aux = min(take, v);
        ans += 5*aux;
        v -= aux;
        take -= aux;

        aux = min(nor, v);
        ans += 5*aux;
        v -= aux;
        nor -= aux;

        // Completar con X
        ans += 8*res;
        ans += 10*take;
        ans += 10*nor;


        cout<<ans<<endl;
    }
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
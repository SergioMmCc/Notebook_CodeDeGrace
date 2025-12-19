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

const int limite = 1000;

vector<bool> esPrimo(limite + 1, 1);
vector<int> primos;

void sieve(){
    esPrimo[0] = esPrimo[1] = 0;
    for(ll p = 2; p * p <= limite; p++){
        if(esPrimo[p]){
            for(ll i = p * p; i <= limite; i += p) esPrimo[i] = 0;
        }
    }

    for(int i = 2; i < limite; i++)
        if(esPrimo[i]) primos.pb(i); 
}

int calc(int a, int k){
    if(a == 1) return 0;
    if(a <= k) return 1;

    vector<int> div;
    for(int i = 1; i * i <= a; i++){
        if(a % i == 0){
            div.pb(i);
            div.pb(a / i);
        }
    }
    int r = sqrt(a);
    if(r * r == a) div.pb(r);
    int n = sz(div);

    sort(all(div));
    map<int, int> c, b;
    for(int i = 0; i < n; i++){
        c[i] = div[i];
        b[div[i]] = i;
    }

    vector<int> dp(n, 21);
    for(int i = 1; i < n; i++){
        int num = c[i];
        if(num <= k){
            dp[i] = 1;
            continue;
        }
        for(int j = 1; j < i; j++){
            int den = c[j];
            if(num % den) continue;
            dp[i] = min(dp[i], dp[j] + dp[b[num / den]]);
        }
    }

    return dp[n-1];
}

void solver(){
    int x, y, k; cin>>x>>y>>k;

    vector<int> px(sz(primos)), py(sz(primos));

    int aux = x, addx = 1;
    for(int i = 0; i < sz(primos); i++){
        int p = primos[i];
        while(aux % p == 0){
            px[i]++;
            aux /= p;
        }
    }
    addx = aux;

    aux = y;
    int addy = 1;
    for(int i = 0; i < sz(primos); i++){
        int p = primos[i];
        while(aux % p == 0){
            py[i]++;
            aux /= p;
        }
    }
    addy = aux;

    int maxx = 1;
    int numx = 1, numy = 1;
    for(int i = 0; i < sz(primos); i++){
        while(px[i] > py[i]){
            maxx = max(maxx, primos[i]);
            numx *= primos[i];
            px[i]--;
        }
        while(py[i] > px[i]){
            maxx = max(maxx, primos[i]);
            numy *= primos[i];
            py[i]--;
        }
    }

    if(addx != addy){
        maxx = max(maxx, max(addx, addy));
        numx *= addx;
        numy *= addy;
    }

    if(maxx > k){
        cout<<-1<<endl;
        return;
    }

    int ans = calc(numx, k) + calc(numy, k);
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    sieve();
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
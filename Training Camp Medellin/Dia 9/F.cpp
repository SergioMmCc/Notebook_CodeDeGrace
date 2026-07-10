#include <bits/stdc++.h>
#include <ios>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i=0; i< (int)n; ++i)
#define for1(i,n) for(int i=1; i<= (int)n; ++i)
#define fore(i,l,r) for(int i=(int)l; i<= (int)r; ++i)
#define ford(i,n) for(int i=(int)(n) - 1; i>= 0; --i)
#define fored(i,l,r) for(int i=(int)r; i>= (int)l; --i)
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pqueue priority_queue
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<pii> vii;

/// 1000234999, 1000567999, 1000111997, 1000777121, 999727999, 1070777777
const int MOD[] = { 1001864327, 1001265673 }, N = 1e6 + 10;
const pii BASE(257, 367), ZERO(0, 0), ONE(1, 1);
inline int add(int a, int b, int mod) { return a+b >= mod ? a+b-mod : a+b; }
inline int sbt(int a, int b, int mod) { return a-b < 0 ? a-b+mod : a-b; }
inline int mul(int a, int b, int mod) { return ll(a) * b % mod;} 
inline ll operator ! (const pii a) { return (ll(a.fi) << 32) | a.se; }
inline pii operator + (const pii& a, const pii& b) {
  return {add(a.fi, b.fi, MOD[0]), add(a.se, b.se, MOD[1])};}
inline pii operator - (const pii& a, const pii& b) {
  return {sbt(a.fi, b.fi, MOD[0]), sbt(a.se, b.se, MOD[1])};}
inline pii operator * (const pii& a, const pii& b) {
  return {mul(a.fi, b.fi, MOD[0]), mul(a.se, b.se, MOD[1])};}

pii base[N]{ONE};
void prepare() { for1(i, N-1) base[i] = base[i-1] * BASE; }
template <class type>
struct hashing {   /// HACELEEE PREPAREEEE!!!
  vii ha;       // ha[i] = t[i]*p0 + t[i+1]*p1 + t[i+2]*p2 + ..
  hashing(type &t): ha(sz(t)+1, ZERO){
    for(int i = sz(t) - 1; i >= 0; --i) ha[i] = ha[i+1] * BASE + pii{t[i], t[i]};
  }
  pii query(int l, int r){ return ha[l] - ha[r+1] * base[r-l+1]; } //[l,r]
};

bool compare(hashing<string>& hl, hashing<string>& hr, int l, int r, int n){
    if(hl.query(l, r) == hr.query(n - r - 1, n - l - 1)) return 1;
    return 0;
}

void solver(){
    string s; cin>>s;
    int n = sz(s);
    for(int i = 0; i < n/2; i++){
        if(s[i] != s[n-i-1]){
            cout<<"YES"<<endl<<1<<endl<<s<<endl;
            return;
        }
    }

    string srev = s;
    reverse(all(srev));
    hashing<string> hl(s), hr(srev);
    for(int i = 1; i < n-2; i++){
        if(!compare(hl, hr, 0, i, n) && !compare(hl, hr, i+1, n-1, n)){
            cout<<"YES"<<endl<<2<<endl;
            for(int j = 0; j <= i; j++) cout<<s[j];
            cout<<' ';
            for(int j = i+1; j < n; j++) cout<<s[j];
            cout<<endl;
            return;
        }
    }


    cout<<"NO"<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    prepare();
	int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}

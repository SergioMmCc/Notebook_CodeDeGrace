#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

const ll mod = 1e9 + 7;
const ll MAXN = 1e7;
vector<ll> pow2(MAXN + 1);

typedef pair<ll, int> pli;

void calculatePow2(){
    pow2[0] = 1;
    for(int i = 1; i < MAXN; i++)
        pow2[i] = (pow2[i-1] * 2) % mod;
}

void solver() {
    int n;cin>>n;
    vector<ll> a(n);
    vector<int> pot(n);
    for(int i = 0; i < n; i++){
        ll save; cin>>save;
        int count = 0;
        while(save % 2 == 0){
            count++;
            save /= 2;
        }
        a[i] = save; pot[i] = count;
    }
    ll ans = 0;
    stack<pli> st;
    for(int i = 0; i < n; i++){
        ll num1 = a[i]; int pot1 = pot[i];
        while(!st.empty()){
            pli aux = st.top();
            ll num2 = aux.first; int pot2 = aux.second;
            bool bigger = 0;
            if(pot1 > 31)bigger = 1;
            else if(num2 <= (num1 << pot1))
                    bigger = 1;
            if(bigger){
                pot1 += pot2;
                ll rest = (num2 * pow2[pot2]) % mod;
                ans = (ans + mod - rest) % mod;
                ans = (ans + num2) % mod;
                st.pop();
            }
            else break;
        }
        ans = (ans + (num1 * pow2[pot1]) % mod) % mod;
        st.push({num1, pot1});

        if(i > 0)cout<<' ';
        cout<<ans;
    }
    cout<<endl;
}

int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    calculatePow2();
    int t;
    cin>>t;
    while(t--) {
        solver();
    }

    return 0;
}
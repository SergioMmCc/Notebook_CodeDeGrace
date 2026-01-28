#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

bool check(int m, int n, int k, string s, vector<int>& a){
    
    int lastTake = -2;
    for(int i = 0; i < n; i++){
        if(lastTake == i-1){
            if(s[i] == 'R' && a[i] > m) lastTake = -1;
            else lastTake = i;
        }
        else{
            if(s[i] == 'B' && a[i] > m){
                k--;
                lastTake = i;
            }
        }
    }

    if(k < 0) return 0;
    return 1;
}

void solver(){
    int n, k; cin>>n>>k;
    string s; cin>>s;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    int lo = 0, hi = 1e9;
    while(lo < hi){
        int m = (lo + hi) / 2;
        if(check(m, n, k, s, a)) hi = m;
        else lo = m + 1;
    }

    cout<<lo<<endl;
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
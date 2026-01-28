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
    int n, k; cin>>n>>k;
    vector<int> a(n), b(n);

    int mayor = -1, menor = k+1;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        mayor = max(mayor, a[i]);
        menor = min(menor, a[i]);
    }

    bool cond = 0;
    int goal = 0;
    bool pos = 1;
    for(int i = 0; i < n; i++){
        cin>>b[i];
        if(b[i] != -1){
            if(!cond) goal = a[i] + b[i];
            else{
                if(a[i] + b[i] != goal) pos = 0;
            }
            cond = 1;
        }
    }

    if(cond && pos){
        for(int i = 0; pos && i < n; i++){
            if(b[i] != -1) continue;
            if(goal - a[i] > k || a[i] > goal) pos = 0;
        }
    }

    else if(pos){
        int ans = max(menor + k - mayor + 1, 0);
        cout<<ans<<endl;
        return;
    }

    cout<<(pos ? 1 : 0)<<endl;
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
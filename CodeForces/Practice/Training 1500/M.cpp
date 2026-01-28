#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

typedef pair<int, int> pii;

void solver(){
    int n; cin>>n;
    vector<int> p(n), q(n);
    for(int i = 0; i < n; i++) cin>>p[i];
    bool peak = 0, cond = 0;
    for(int i = 1; !cond && i < n - 1; i++){
        if(p[i] == 1){
            if(p[i-1] == n || p[i+1] == n){
                peak = (i + 1) % 2;
                cond = 1;
            }
        }
    }


    if(!cond){
        int maxn = 0, maxi = -1;
        for(int i = 1; i < n - 1; i++){
            if(p[i] > maxn){
                maxn = p[i];
                maxi = i;
            }
        }

        peak = maxi % 2;
    }

    priority_queue<pii, vector<pii>, less<pii>> pql; // Mayor primero
    priority_queue<pii, vector<pii>, greater<pii>> pqg; // Menor primero

    if(!peak){
        for(int i = 1; i < n; i++){
            if(i % 2 == 0) pqg.push({p[i], i});
            else pql.push({p[i], i});
        }
    }

    else{
        for(int i = 0; i < n - 1; i++){
            if(i % 2 == 0) pql.push({p[i], i});
            else pqg.push({p[i], i});
        }
    }

    int l = 1, r = n;
    while(!pqg.empty()){
        pii aux = pqg.top(); pqg.pop();
        q[aux.second] = r;
        r--;
    }

    while(!pql.empty()){
        pii aux = pql.top(); pql.pop();
        q[aux.second] = l;
        l++;
    }

    if(!peak) q[0] = r;
    else q[n-1] = r;

    for(int i = 0; i < n; i++){
        if(i) cout<<' ';
        cout<<q[i];
    }

    cout<<endl;
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
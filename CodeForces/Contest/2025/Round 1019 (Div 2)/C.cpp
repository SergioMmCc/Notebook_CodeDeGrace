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

bool check(vector<int>& ps, vector<int>& a, int n){
    if(ps[2] == 2) return 1;

    set<int> num;
    for(int i = 1; i < n; i++){
        if(ps[i] < 0) continue;

        if(num.find(ps[i]) != num.end()) return 1;
        else if(!num.empty()){
            auto it = num.rbegin();
            if(ps[i] > *it) return 1;
        }

        num.insert(ps[i]);
    }
    
    return 0;
}

void solver(){
    int n, k; cin>>n>>k;
    vector<int> a(n+1), ps(n+1);
    for(int i = 1; i <= n; i++){
        int save; cin>>save;
        a[i] = (save > k ? -1 : 1);
        ps[i] = ps[i-1] + a[i];
    }

    bool cond = check(ps, a, n);
    if(cond){
        cout<<"YES"<<endl;
        return;
    }

    reverse(a.begin() + 1, a.end());
    for(int i = 1; i <= n; i++){
        ps[i] = ps[i-1] + a[i];
    }

    if(check(ps, a, n)){
        cout<<"YES"<<endl;
        return;
    }

    int count = 0, index = 0;
    for(int i = 1; i < n - 1; i++){
        count += a[i];
        if(count >= 0){
            index = i;
            break;
        }
    }

    if(!index){
        cout<<"NO"<<endl;
        return;
    }

    count = 0;
    for(int i = n; i > index + 1; i--){
        count += a[i];
        if(count >= 0){
            cout<<"YES"<<endl;
            return;
        }
    }

    cout<<"NO"<<endl;
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
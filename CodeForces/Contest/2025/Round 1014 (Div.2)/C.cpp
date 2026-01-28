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
    int n; cin>>n;
    vector<ll> a(n);

    int countP = 0, countI = 0;
    ll total = 0, maxi = 0;
    for(int i = 0; i < n; i++){
        ll save; cin>>save;
        total += save;
        if(save % 2) countI++;
        else countP++;

        maxi = max(maxi, save);
    }

    if(!countP || !countI){
        cout<<maxi<<endl;
        return;
    }

    cout<<total - countI + 1<<endl;
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
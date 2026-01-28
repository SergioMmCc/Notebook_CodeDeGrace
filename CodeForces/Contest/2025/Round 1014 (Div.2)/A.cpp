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
    int maxi = 0, mini = 1e9;
    int n; cin>>n;
    for(int i = 0; i < n; i++){
        int save; cin>>save;
        mini = min(save, mini);
        maxi = max(save, maxi);
    }

    cout<<maxi - mini<<endl;
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
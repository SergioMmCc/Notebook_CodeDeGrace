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
    int n, x; cin>>n>>x;
    
    int num = 0;
    for(int i = 0; i < n - 1; i++){
        if(i == x) num++;
        cout<<num<<' ';
        num++;
    }
    if(x == n) cout<<n-1<<endl;
    else cout<<x<<endl;
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
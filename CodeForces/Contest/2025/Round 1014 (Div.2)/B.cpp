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
    int n; string a, b; cin>>n>>a>>b;

    int countP = 0, countI = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == '0'){
            if(i % 2) countI++;
            else countP++;
        }
    }

    for(int i = 1; i <= n; i++){
        if(b[i-1] == '0'){
            if(i % 2) countI++;
            else countP++;
        }
    }

    if((n + 1) / 2 <= countP && n / 2 <= countI) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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
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
    int count = 1;
    if(n % 2 == 0){
        for(int i = 1; i <= n; i += 2){
            count += i;
        }
    }
    else{
        for(int i = 2; i <= n; i += 2){
            count += i;
        }
    }

    cout<<count<<endl;
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
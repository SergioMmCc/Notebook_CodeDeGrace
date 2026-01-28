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
    int countOdd = 0; bool even = 0;
    for(int i = 0; i < n; i++){
        int save; cin>>save;
        if(save % 2) countOdd++;
        else even = 1;
    }

    if(!countOdd) cout<<1<<endl;
    else cout<<(even ? countOdd + 1 : countOdd - 1)<<endl;
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
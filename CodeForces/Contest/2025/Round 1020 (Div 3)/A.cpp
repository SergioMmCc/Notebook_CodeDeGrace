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
    string s; cin>>s;
    int count0 = 0, count1 = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0') count0++;
        else count1++;
    }

    cout<<count0 + count1 * (n - 1)<<endl;
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
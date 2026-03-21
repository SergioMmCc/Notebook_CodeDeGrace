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
    int n; string s; cin>>n>>s;
    vector<int> p(n+1);
    int count = 0;
    for(int i = 1; i <= n; i++){
        cin>>p[i];
        if(p[i] != i) count++;
    }

    if(n == 2){
        cout<<"Alice"<<endl;
        return;
    }

    if(n == 3 && count == 3){
        cout<<(s == "Alice" ? "Bob" : "Alice")<<endl;
        return;
    }

    if(count == 2){
        cout<<s<<endl;
        return;
    }

    cout<<"Bob"<<endl;
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
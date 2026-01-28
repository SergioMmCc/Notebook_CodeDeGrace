#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define int long long
typedef pair<int, int> pii;

void solver(){
    int n, x, k; cin>>n>>x>>k; int count = 0;
    string s; cin>>s;

    int aux = x;
    for(int i = 0; i < n; i++){
        if(s[i] == 'L') aux--;
        else aux++;
        if(!aux){
            count++;
            k -= i + 1;
            break;
        }
    }

    if(aux){
        cout<<0<<endl;
        return;
    }

    int cycle = -1;
    for(int i = 0; i < n; i++){
        if(s[i] == 'L') aux--;
        else aux++;
        if(!aux){
            cycle = i+1;
            break;
        }
    }

    if(cycle == -1){
        cout<<1<<endl;
        return;
    }

    count += k / cycle;
    cout<<count<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
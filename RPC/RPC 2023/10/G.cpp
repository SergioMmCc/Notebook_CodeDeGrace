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

    int cifras = 0, aux = n;
    vector<int> num;
    while(aux > 0){
        cifras++;
        num.pb(aux % 10);
        aux /= 10;
    }

    if(num.sz == 1){
        cout<<num[0] + 1<<endl;
        return;
    }

    reverse(num.begin(), num.end());
    int ans = 10 * (cifras - 1);
    int last = num[0];

    bool cond = 0;
    for(int i = 1; i < num.sz; i++){
        int next = num[i];
        if(next > last || (next == last && i == num.sz - 1)){
            cond = 1;
            break;
        }
        if(next < last) break;
    }

    ans += last;
    if(!cond) ans--;
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
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
    vector<int> a(n+1);
    multiset<int> right;
    int mex = 0, count0 = 0, pos0 = -1;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        right.insert(a[i]);
        if(a[i] == mex){
            mex++;
            while(right.find(mex) != right.end()) mex++;
        }
        if(!a[i]){
            count0++;
            if(pos0 == -1) pos0 = i;
        }
    }
    if(n == 1 || !count0){
        cout<<n<<endl;
        return;
    }

    int ans = n - count0 + 1;
    int minL = 2e9;
    bool cond = 0;
    for(int i = 1; !cond && i < pos0; i++){
        // Sacar el elemento de right
        multiset<int>::iterator it = right.find(a[i]);
        right.erase(it);
        if(a[i] < mex){ // Si el elemento era el mex, actualizarlo
            if(right.find(a[i]) == right.end()) mex = a[i];
        }
        minL = min(minL, a[i]);
        if(minL < mex) cond = 1;
    }

    if(cond) ans--;
    cout<<ans<<endl;
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
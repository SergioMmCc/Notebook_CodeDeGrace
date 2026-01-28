#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

void solver(){
    int n, m; cin>>n>>m;
    multiset<int> a; queue<int> b;
    for(int i = 0; i < n; i++){
        int save; cin>>save;
        a.insert(save);
    }

    for(int i = 0; i < m; i++){
        int save; cin>>save;
        b.push(save);
    }

    while(a.sz && b.sz && b.sz <= a.sz){
        int test = b.front(); b.pop();
        multiset<int>::iterator it;
        it = a.find(test);
        if(it != a.end()) a.erase(it);
        else{
            b.push(test / 2);
            b.push((test + 1) / 2);
        }
    }

    if(!a.sz && !b.sz) cout<<"YES"<<endl;
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
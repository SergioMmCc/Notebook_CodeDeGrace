#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;

void solver(){
    int n; cin>>n;
    vector<int> p(n);
    int son1 = 2;
    set<int> roots;
    while(son1 < n){
        cout<<"? 1 "<<son1<<endl;
        roots.insert(son1);
        int r; cin>>r;
        if(!r){
            p[son1] = 1;
            break;
        }

        son1++;
    }


    for(int i = son1 + 1; roots.sz > 1 && i < n; i++){
        int r = 1;
        while(r){
            int num = *(roots.begin());
            roots.erase(roots.begin());
            cout<<"? "<<num<<' '<<i<<endl;
            cin>>r;
            if(!r) p[i] = num;
        }

        roots.insert(i);
    }

    if(!roots.empty()){
        auto it = roots.end(); --it;
        int last = *it;
        for(int next = last + 1; next < n; next++){
            p[next] = last;
            last = next;
        }
    }

    cout<<"!";
    for(int i = 1; i < n; i++){
        cout<<' '<<p[i];
    }
    cout<<endl;
}

int main(){
    // ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
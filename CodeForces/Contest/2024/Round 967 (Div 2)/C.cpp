#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

void solver() {
    int n; cin>>n;
    int a, b, ans;
    set<int> ya, no;
    vector<pii> edges;
    ya.insert(1);
    for(int i = 2; i <= n; i++)
        no.insert(i);
    while(no.size() > 0){
        bool cond = false;
        a = *no.begin();
        b = 1;
        while(!cond){
            cout<<"? "<<a<<' '<<b<<endl;
            cin>>ans;
            if(ans == a){
                cond = true;
                no.erase(a);
                ya.insert(a);
                edges.push_back({a, b});
            }
            else if(no.find(ans) != no.end())
                a = ans;
            else
                b = ans;
        }
    }
    
    cout<<'!';
    for(int i = 0; i < edges.size(); i++)
        cout<<' '<<edges[i].first<<' '<<edges[i].second;
    cout<<endl;
}

int main () {
    // ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        solver();
    }
    
    return 0;
}
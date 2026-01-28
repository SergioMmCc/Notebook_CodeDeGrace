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
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    map<int, int> freq;
    pii rep1 = {0, 0}, rep2 = {0, 0};
    for(int i = 0; i < n; i++){
        freq[a[i]]++;
        if(freq[a[i]] % 2 == 0){
            if(rep1.first){
                rep2 = {a[i], a[i]};
                cout<<rep1.first<<' '<<rep1.second<<' '<<rep2.first<<' '<<rep2.second<<endl;
                return;
            }
            rep1 = {a[i], a[i]};
        }
    }

    if(!rep1.first){
        cout<<-1<<endl;
        return;
    }

    int count = 0;
    for(int i = 0; count < 2 && i < n; i++){
        if(a[i] == rep1.first){
            a[i] = 0;
            count++;
        }
    }

    sort(a.begin(), a.end());
    bool cond = 0;
    for(int i = 1; !cond && i < n; i++){
        if(!a[i] || !a[i-1]) continue;
        int dif = (a[i] - a[i-1]) / 2;
        if(rep1.first > dif){
            rep2 = {a[i], a[i-1]};
            cond = 1;
        }
    }

    if(!cond){
        cout<<-1<<endl;
        return;
    }

    cout<<rep1.first<<' '<<rep1.second<<' '<<rep2.first<<' '<<rep2.second<<endl;
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
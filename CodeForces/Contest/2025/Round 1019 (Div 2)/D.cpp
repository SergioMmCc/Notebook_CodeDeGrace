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
    vector<int> a(n+1);
    int maxi = 0, winner = 0;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        maxi = max(maxi, a[i]);
        if(a[i] == -1) winner = i;
    }

    a[winner] = maxi + 1;

    vector<vector<int>> pos(maxi + 2);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= a[i]; j++)
            pos[j].pb(i);
    }

    int mayor = n, menor = 1;
    vector<int> ans(n+1);
    for(int i = 1; i < pos.sz - 1; i++){
        bool change = 0;
        int next;

        if(i % 2) next = mayor - (int)pos[i].sz + (int)pos[i+1].sz + 1;
        else next = menor + (int)pos[i].sz - (int)pos[i+1].sz - 1;

        for(int j = 0; j < pos[i].sz; j++){
            if(!change && a[pos[i][j]] > i){
                change = 1;
                if(i % 2) mayor = next - 1;
                else menor = next + 1;
                continue;
            }
            if(a[pos[i][j]] > i) continue;

            if(i % 2){
                if(!change){
                    ans[pos[i][j]] = mayor;
                    mayor--;
                }
                else{
                    ans[pos[i][j]] = next;
                    next++;
                }
            }
            else{
                if(!change){
                    ans[pos[i][j]] = menor;
                    menor++;
                }
                else{
                    ans[pos[i][j]] = next;
                    next--;
                }
            }
        }
    }
    ans[winner] = mayor;
    for(int i = 1; i <= n; i++){
        if(i > 1) cout<<' ';
        cout<<ans[i];
    }
    cout<<endl;
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
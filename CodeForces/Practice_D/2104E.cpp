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
    int n, k; cin>>n>>k;
    string s; cin>>s;

    vector<vector<int>> pos(k);
    for(int i = 0; i < n; i++){
        int num = s[i] - 'a';
        pos[num].pb(i);
    }

    vector<int> preCalc(n + 2);
    for(int in = n - 1; in >= 0; in--){
        int index = in;
        int j = index;
        for(int i = 0; j < n && i < k; i++){
            vector<int>::iterator it = upper_bound(pos[i].begin(), pos[i].end(), index);
            int aux = (it == pos[i].end() ? n : *it);
            j = max(j, aux);
        }

        index = j;

        preCalc[in] = preCalc[index] + 1;
    }

    int q; cin>>q;
    while(q--){
        string c; cin>>c;
        int index = -1;
        for(int i = 0; index < n && i < c.sz; i++){
            int search = c[i] - 'a';
            vector<int>::iterator it = upper_bound(pos[search].begin(), pos[search].end(), index);
            index = (it == pos[search].end() ? n : *it);
        }

        cout<<preCalc[index]<<endl;
    }
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
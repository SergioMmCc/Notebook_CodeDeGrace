#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

const int maxn = 27, inf = 1e9;
int d[maxn][maxn];

void floyd(int n){
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

void solver(){
    string s1, s2; cin>>s1>>s2;
    int n; cin>>n;
    for(int i = 0; i < 26; i++){
        for(int j = i + 1; j < 27; j++){
            d[i][j] = d[j][i] = inf;
        }
    }
    for(int i = 0; i < n; i++){
        char a, b; int w; cin>>a>>b>>w;
        int u = a - 'a', v = b - 'a';
        if(d[u][v] > w) d[u][v] = w;
    }

    if(s1.sz != s2.sz){
        cout<<-1<<endl;
        return;
    }

    int len = s1.sz;
    floyd(27);

    int total = 0; string ans = "";
    for(int i = 0; i < len; i++){
        if(s1[i] == s2[i]){
            ans += s1[i];
            continue;
        }
        int u = s1[i] - 'a', v = s2[i] - 'a';
        
        int mind = inf; int add = -1;
        for(int k = 0; k < 27; k++){
            if(d[u][k] + d[v][k] < mind){
                mind = d[u][k] + d[v][k];
                add = k;
            }
        }

        if(mind == inf){
            cout<<-1<<endl;
            return;
        }

        total += mind;
        ans += (char) add + 'a';
    }

    cout<<total<<endl<<ans<<endl;
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
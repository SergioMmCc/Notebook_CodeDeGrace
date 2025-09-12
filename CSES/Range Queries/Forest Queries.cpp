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

const int maxn = 1001;
vector<string> a(maxn);
int s[maxn][maxn];

void solver(){
    int n, q; cin>>n>>q;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        for(int j = 1; j <= n; j++){
            int sum = a[i][j-1] == '*' ? 1 : 0;
            s[i][j] = sum + s[i-1][j] + s[i][j-1] - s[i-1][j-1];
        }
    }

    while(q--){
        int y1, x1, y2, x2; cin>>y1>>x1>>y2>>x2;
        cout<<s[y2][x2] - s[y1-1][x2] - s[y2][x1-1] + s[y1-1][x1-1]<<endl;
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
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

const int maxn = 501;
char maze[maxn][maxn];
int a[maxn][maxn], s[maxn][maxn];

void solver(){
    int n, m, k; cin>>n>>m>>k;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            a[i][j] = 0;
            s[i][j] = 0;
        }
    }

    int total = 0;
    for(int i = 1; i <= n; i++){
        string line; cin>>line;
        for(int j = 1; j <= m; j++){
            maze[i][j] = line[j-1];
            if(maze[i][j] == 'g'){
                total++;
                a[i][j] = 1;
            }

            s[i][j] = a[i][j] + s[i-1][j] + s[i][j-1] - s[i-1][j-1];
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(maze[i][j] != '.') continue;

            int y2 = min(n, i + k - 1), x2 = min(m, j + k - 1), y1 = max(1, i - k + 1), x1 = max(1, j - k + 1);
            int gold = s[y2][x2] - s[y1-1][x2] - s[y2][x1-1] + s[y1-1][x1-1];
            ans = max(ans, total - gold);
        }
    }

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
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
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solver(){
    int n, m; cin>>n>>m;
    vector<string> a(n);
    vector<vector<string>> b(m, vector<string>(n));

    for(int i = 0; i < n; i++) cin>>a[i];
    vector<bool> pos(n);

    int maxi = 0;
    for(int i = 0; i < m; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            cin>>b[i][j];
            if(b[i][j] == a[j]){
                count++;
                pos[j] = 1;
            }
        }

        maxi = max(maxi, count);
    }

    for(int i = 0; i < n; i++){
        if(!pos[i]){
            cout<<-1<<endl;
            return;
        }
    }

    cout<<3*n - 2*maxi<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
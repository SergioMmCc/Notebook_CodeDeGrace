#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pqueue priority_queue
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solver(){
    int n; cin>>n;
    vector<vi> a(n, vi(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cin>>a[i][j];
        }
    }

    bool cond = 0;
    for(int k = 0; !cond && k < n*n; k++){
        bool aux = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= i; j++){
                if(i < n-1){
                    if(a[i+1][j] != 100 && a[i+1][j+1] != 100){
                        int sum = a[i+1][j] + a[i+1][j+1];
                        if(sum < -99 || sum > 99 || (a[i][j] != 100 && a[i][j] != sum)){
                            cout<<"no solution"<<endl;
                            return;
                        }
                        a[i][j] = sum;
                    }
                }
                if(i && j < i){
                    if(a[i-1][j] != 100 && a[i][j+1] != 100){
                        int sum = a[i-1][j] - a[i][j+1];
                        if(sum < -99 || sum > 99 || (a[i][j] != 100 && a[i][j] != sum)){
                            cout<<"no solution"<<endl;
                            return;
                        }
                        a[i][j] = sum;
                    }
                }
                if(i && j){
                    if(a[i-1][j-1] != 100 && a[i][j-1] != 100){
                        int sum = a[i-1][j-1] - a[i][j-1];
                        if(sum < -99 || sum > 99 || (a[i][j] != 100 && a[i][j] != sum)){
                            cout<<"no solution"<<endl;
                            return;
                        }
                        a[i][j] = sum;
                    }
                }

                if(a[i][j] == 100) aux = 0;
            }
        }

        cond = aux;
    }

    if(!cond) cout<<"ambiguous"<<endl;
    else{
        cout<<"solvable"<<endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= i; j++){
                if(j) cout<<' ';
                cout<<a[i][j];
            }
            cout<<endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
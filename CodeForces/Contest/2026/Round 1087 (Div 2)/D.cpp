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

void res(string ans, vs& T){
    for(int i = 0; i < sz(ans); i++){
        cout<<T[ans[i] - '0'];
    }
    cout<<endl;
}

void solver(){
    vi aux(3);
    vs T(3);
    cin>>aux[0]>>aux[1]>>aux[2];
    if(aux[0] <= aux[1] && aux[0] <= aux[2]){
        T[0] = 'R';
        if(aux[1] <= aux[2]){
            T[1] = 'G';
            T[2] = 'B';
        }
        else{
            T[2] = 'G';
            T[1] = 'B';
        }
    }
    else if(aux[1] <= aux[2] && aux[1] <= aux[0]){
        T[0] = 'G';
        if(aux[0] <= aux[2]){
            T[1] = 'R';
            T[2] = 'B';
        }
        else{
            T[1] = 'B';
            T[2] = 'R';
        }
    }
    else{
        T[0] = 'B';
        if(aux[0] <= aux[1]){
            T[1] = 'R';
            T[2] = 'G';
        }
        else{
            T[1] = 'G';
            T[2] = 'R';
        }
    }

    sort(all(aux));
    int a = aux[0], b = aux[1], c = aux[2];

    if(c >= a+b){
        string ans = "";
        while(a){
            ans += "20";
            a--;
            c--;
        }
        while(b){
            ans += "21";
            b--;
            c--;
        }
        if(c) ans += "2";

        res(ans, T);
        return;
    }

    string ans = "";
    while(a + b > c && a){
        ans += "01";
        a--;
        b--;
    }
    while(b){
        ans += "21";
        b--;
        c--;
    }
    while(a){
        ans += "20";
        c--;
        a--;
    }
    if(c){
        ans += "2";
        c--;
    }
    if(c && ans[0] != '2' && sz(ans) > 1 && ans[2] != '2'){
        ans = "2" + ans;
    }

    res(ans, T);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
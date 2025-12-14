#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
#define pb push_back
#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

int query(vector<int>& ask, int j){
    cout<<"? 132";
    int pot2 = 1;
    for(int x = 0; x < 6; x++){
        for(int y = 0; y < pot2; y++){
            cout<<' '<<ask[x];
        }
        for(int y = 0; y <= pot2; y++){
            cout<<' '<<j;
        }

        pot2 *= 2;
    }
    cout<<endl;

    int ans; cin>>ans;
    return ans;
}

void solver(){
    int n; cin>>n;
    int i = 0, j = 0;

    vector<char> s(n);
    cout<<"? 3 1 2 1"<<endl;
    int ans; cin>>ans;
    if(ans){
        cout<<"? 2 1 2"<<endl;
        cin>>ans;
        if(ans){
            i = 1;
            j = 2;
        }
        else{
            i = 2;
            j = 1;
        }
        s[i-1] = '(';
        s[j-1] = ')';
    }
    else{
        int l = 3, r = n;
        while(l < r){
            int m = (l + r) / 2;

            cout<<"? "<<2*(m - l + 1) + 1<<' '<<1;
            for(int x = l; x <= m; x++) cout<<' '<<x<<' '<<1;
            cout<<endl;
            cin>>ans;
            if(ans) r = m;
            else l = m + 1;
        }

        cout<<"? 2 1 "<<l<<endl;
        cin>>ans;
        if(ans){
            i = 1;
            j = l;
        }
        else{
            i = l;
            j = 1;
        }

        s[i-1] = '(';
        s[j-1] = ')';
    }

    int idx = 0;
    int k = 0;
    vector<int> ask(6, 1);
    while(idx < n){
        idx++;
        if(idx == i || idx == j) continue;
        ask[k] = idx;
        k++;
        if(k == 6){
            ans = query(ask, j);
            for(int x = 0; x < 6; x++){
                if(ans & (1 << x)) s[ask[x] - 1] = '(';
                else s[ask[x] - 1] = ')';
            }
            k = 0;
        }
    }

    ans = query(ask, j);
    for(int x = 0; x < 6; x++){
        if(ans & (1 << x)) s[ask[x] - 1] = '(';
        else s[ask[x] - 1] = ')';
    }
    k = 0;


    cout<<"! ";
    for(int x = 0; x < n; x++) cout<<s[x];
    cout<<endl;
}

int main(){
    // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
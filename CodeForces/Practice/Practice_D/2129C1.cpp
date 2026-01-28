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

    int next = 1;
    int l = 0, r = 0;
    while(next <= n){
        if(next == i || next == j){
            next++;
            continue;
        }
        if(!l){
            l = next;
            next++;
            continue;
        }
        r = next;
        cout<<"? 6 "<<i<<' '<<l<<' '<<r<<' '<<j<<' '<<r<<' '<<j<<endl;
        cin>>ans;
        if(ans == 1){
            s[l-1] = ')';
            s[r-1] = ')';
        }
        else if(ans == 2){
            s[l-1] = '(';
            s[r-1] = ')';
        }
        else if(ans == 3){
            s[l-1] = '(';
            s[r-1] = '(';
        }
        else if(ans == 6){
            s[l-1] = ')';
            s[r-1] = '(';
        }
        
        l = 0; r = 0;
        next++;
    }

    if(l){
        cout<<"? 2 "<<i<<' '<<l<<endl;
        cin>>ans;
        if(ans) s[l-1] = ')';
        else s[l-1] = '(';
    }

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
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
    string a, b, c; cin>>a>>b>>c;
    string ans = "";
    int i = 0, j = 0, k = 0;
    for(; i < a.sz && j < b.sz && k < c.sz;){
        if(a[i] == b[j]){
            ans += a[i];
            i++;
            j++;
        }
        else if(a[i] == c[k]){
            ans += a[i];
            i++;
            k++;
        }
        else if(b[j] == c[k]){
            ans += b[j];
            j++;
            k++;
        }
    }

    if(i < a.sz){
        while(i < a.sz){
            ans += a[i];
            i++;
        }
    }
    
    else if(j < b.sz){
        while(j < b.sz){
            ans += b[j];
            j++;
        }
    }
    else if(k < c.sz){
        while(k < c.sz){
            ans += c[k];
            k++;
        }
    }

    cout<<ans<<endl;
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
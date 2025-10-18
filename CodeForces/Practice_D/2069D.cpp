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
    string s; cin>>s;
    deque<char> q;
    for(int i = 0; i < s.sz; i++) q.push_back(s[i]);

    while(!q.empty() && q.front() == q.back()){
        q.pop_front();
        q.pop_back();
    }

    if(q.empty()){ // La original es palindromo
        cout<<0<<endl;
        return;
    }

    s = "";
    while(!q.empty()){
        s += q.front();
        q.pop_front();
    }
    // cout<<s<<endl;

    int n = s.sz;
    vector<vector<int>> use(27);
    for(int i = 0; i < n; i++){
        // if(s[i] == s[n - i - 1]) continue;
        use[s[i] - 'a'].pb(i);
    }

    int mini = n;
    for(int i = 0; i < 27; i++){
        int l = 0, r = use[i].sz - 1;
        while(l < r){
            if(use[i][l] != n - use[i][r] - 1) mini = min(mini, use[i][r]);
            l++;
            r--;
        }
    }

    int ans = n - mini;
    // cout<<"orden -> "<<s<<' '<<ans<<endl;

    reverse(s.begin(), s.end());
    for(int i = 0; i < 27; i++) use[i].clear();

    for(int i = 0; i < n; i++){
        // if(s[i] == s[n - i - 1]) continue;
        use[s[i] - 'a'].pb(i);
    }

    mini = n;
    for(int i = 0; i < 27; i++){
        int l = 0, r = use[i].sz - 1;
        while(l < r){
            if(use[i][l] != n - use[i][r] - 1) mini = min(mini, use[i][r]);
            l++;
            r--;
        }
    }

    ans = min(ans, n - mini);
    cout<<ans<<endl;
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
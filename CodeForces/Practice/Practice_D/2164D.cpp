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
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solver(){
    int n, k; cin>>n>>k;
    string s, t; cin>>s>>t;

    vector<vector<int>> arr(26, vector<int>(1, -1));
    for(int i = 0; i < n; i++) arr[s[i] - 'a'].pb(i);

    vector<int> cnt(n);
    int maxi = 0;

    int lim = n-1;
    for(int j = n-1; j >= 0; j--){
        int num = t[j] - 'a';
        lim = min(lim, j);
        auto it = ub(all(arr[num]), lim);
        --it;

        int idx = *it;
        if(idx == -1){
            cout<<-1<<endl;
            return;
        }

        cnt[j] = j - idx;
        maxi = max(maxi, cnt[j]);
        if(maxi > k){
            cout<<-1<<endl;
            return;
        }
        lim = min(lim, idx);
    }

    cout<<maxi<<endl;
    while(maxi--){
        string cop = "";
        for(int i = 0; i < n; i++){
            if(cnt[i]){
                cop += s[i-1];
                cnt[i]--;
            }
            else cop += s[i];
        }

        s = cop;
        cout<<s<<endl;
    }
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
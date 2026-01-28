#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
#define int long long
typedef pair<int, int> pii;

void solver(){
    int n, m; cin>>n>>m;
    vector<int> a(m);
    for(int i = 0; i < m; i++){
        cin>>a[i];
        if(a[i] == n) a[i]--;
    }

    sort(a.begin(), a.end());
    vector<int> formas(m);
    vector<int> elements(m);
    vector<bool> used(m);

    for(int i = 1; i < m; i++){
        formas[i] = formas[i-1] + (a[i] - a[i-1]) * elements[i-1];
        elements[i] = elements[i-1];

        if(a[i] + a[i-1] >= n){
            formas[i] += a[i] + a[i-1] + 1 - n;
            elements[i]++;
            used[i-1] = 1;
        }
        else continue;

        int search = n - a[i];
        if(search > a[i]) continue;

        vector<int>::iterator it = lower_bound(a.begin(), a.end(), search);
        int index = distance(a.begin(), it);
        while(index < i && !used[index]){
            // cout<<"here"<<endl;
            formas[i] += a[i] + a[index] + 1 - n;
            elements[i]++;
            used[index] = 1;
            index++;
        }
    }

    ll ans = 0;
    for(int i = 1; i < m; i++){
        ans += 2 * formas[i];
    }

    cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
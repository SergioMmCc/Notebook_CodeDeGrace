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

void solver(){
    int n; cin>>n;
    vector<int> a(n+1), b(n+1);
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i <= n; i++) cin>>b[i];

    queue<pii> ans;

    // Ordenar a
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            if(a[j+1] < a[j]){
                ans.push({1, j});
                swap(a[j], a[j+1]);
            }
        }
    }

    // Ordenar b
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            if(b[j+1] < b[j]){
                ans.push({2, j});
                swap(b[j], b[j+1]);
            }
        }
    }

    // Swapear a y b
    for(int i = 1; i <= n; i++){
        if(a[i] > b[i]){
            ans.push({3, i});
            swap(a[i], b[i]);
        }
    }

    // cout<<"Case -> "<<endl;
    // for(int i = 1; i <= n; i++) cout<<a[i]<<' ';
    // cout<<endl;
    // for(int i = 1; i <= n; i++) cout<<b[i]<<' ';
    // cout<<endl<<endl;

    cout<<ans.sz<<endl;
    while(!ans.empty()){
        cout<<ans.front().fi<<' '<<ans.front().se<<endl;
        ans.pop();
    }
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
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
const int top=1e6, INF=1e9;
int vec[top+7];

void solver(){
    int n;
    cin>>n; 
    for(int i=1; i<=n; i++)cin>>vec[i];

    vector<int> minn(n+3, INF), maxx(n+3, -INF);
    for(int i=1, j=n; i<=n; i++, j--){
            maxx[i] = max(vec[i], maxx[i-1]);
            minn[j] = min(vec[j], minn[j+1]);
    }

    vector<int> ans;
    int k=0;
    for(int i=1; i<=n; i++){
        if(maxx[i-1] <= vec[i] && vec[i] < minn[i+1]){
            if(ans.size() < 100) ans.push_back(vec[i]);
            k++;
        }
    }

    cout<<k;
    if(!ans.empty()) cout<<" ";
    for(int i=0; i<ans.size(); i++){
        if(i)cout<<" ";
        cout<<ans[i];
    }cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);

        solver();
    

    return 0;
}
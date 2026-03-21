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
    int ans[n][n];

    int num = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if((i / 12) % 2 == 0){
                ans[i][j] = (j / 12) + num;
            }

            else{
                ans[i][j] = ((j + 6) / 12) + num;
            }
        }

        if(i % 12 == 11) num = ans[i][n-1] + 1;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j) cout<<' ';
            cout<<ans[i][j] + 1;
        }
        cout<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
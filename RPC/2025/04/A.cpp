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
    int r, c; cin>>r>>c;

    vector<string> s(r);
    for(int i = 0; i < r; i++) cin>>s[i];

    char ans[r][c];
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            ans[i][j] = '.';
        }
    }

    int count = 0;
    for(int i = 0; i < r; i++){
        int len = s[i].sz, skip;
        if((c - len) % 2){
            count++;
            skip = (c - len) / 2;
            if(!(count % 2)) skip++;
        }

        else skip = (c - len) / 2;

        for(int j = skip, k = 0; k < len; j++, k++){
            ans[i][j] = s[i][k];
        }
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout<<ans[i][j];
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
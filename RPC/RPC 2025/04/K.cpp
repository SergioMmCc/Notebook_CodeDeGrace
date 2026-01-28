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

int val[21][21];
char mat[21][21];

int calc(int x, int y, int s, int t){
    int ans = 0;
    for(int i = 0; i < s; i++){
        for(int j = 0; j < t; j++){
            if(mat[i][j] == '.') continue;
            ans += val[i+x][j+y];
        }
    }

    return ans;
}

void sw(int s, int t){

    // Copiar
    char aux[21][21];
    for(int i = 0; i < s; i++){
        for(int j = 0; j < t; j++){
             aux[i][j] = mat[i][j];
        }
    }

    // Cambiar
    for(int i = 0; i < s; i++){
        int id = s - i - 1;
        for(int j = 0; j < t; j++){
            mat[j][id] = aux[i][j];
        }
    }
}

void prin(int s, int t){
    for(int i = 0; i < s; i++){
        for(int j = 0; j < t; j++){
            cout<<mat[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

void solver(){
    int r, c; cin>>r>>c;
    int total = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin>>val[i][j];
            total += val[i][j];
        }
    }

    int s, t; cin>>s>>t;
    for(int i = 0; i < s; i++){
        cin>>mat[i];
    }

    int ans = 0;
    for(int i = 0; i < 4; i++){
        // cout<<s<<' '<<t<<endl;
        // prin(s, t);
        for(int i = 0; i + s <= r; i++){
            for(int j = 0; j + t <= c; j++){
                int au = total - calc(i, j, s, t);
                // cout<<"i -> "<<i<<" j -> "<<j<<" au -> "<<au<<endl;
                ans = max(ans, au);
            }
        }

        if(i == 3) break;
        sw(s, t);
        swap(s, t);
    }

    cout<<ans<<endl;
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
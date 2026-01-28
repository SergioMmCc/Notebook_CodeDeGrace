#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

void solver(){
    int n, m; cin>>n>>m;
    char matriz[n][m];
    for(int i = 0; i < n; i++){
        cin>>matriz[i];
    }

    int badR = 0, badC = 0;
    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < m; j++){
            if(matriz[i][j] == '1') count++;
        }

        if(count % 2) badC++;
    }

    for(int j = 0; j < m; j++){
        int count = 0;
        for(int i = 0; i < n; i++){
            if(matriz[i][j] == '1') count++;
        }

        if(count % 2) badR++;
    }

    cout<<max(badC, badR)<<endl;
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
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
    map<int, int> vert, diag;
    for(int i = 0; i < n; i++){
        int x, y; cin>>x>>y;
        vert[x]++;
        diag[x+y]++;
    }

    int coordX, coordy;
    for(map<int, int>::iterator it = vert.begin(); it != vert.end(); ++it){
        if(it->second % 2){
            coordX = it->first;
            break;
        }
    }

    for(map<int, int>::iterator it = diag.begin(); it != diag.end(); ++it){
        if(it->second % 2){
            coordy = it->first - coordX;
            break;
        }
    }

    cout<<coordX<<' '<<coordy<<endl;
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
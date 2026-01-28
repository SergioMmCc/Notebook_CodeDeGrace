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
    int d, c; cin>>d>>c;
    if(c >= d){
        cout<<0<<endl;
        return;
    }
    if(d > 2*c - 2){
        cout<<"impossible"<<endl;
        return;
    }

    int y = d - c;
    int f = 2, v = y + 1;
    for(int dia = y - 1; dia > 0; dia--){
        if(v + f >= c){
            v = v + f - c + dia + 1;
            f++;
        }
        else v += f;
    }

    cout<<f-1<<endl;
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
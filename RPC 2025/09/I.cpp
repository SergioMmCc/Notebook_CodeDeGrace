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
    vector<int> d1(6), d2(6), d3(6);
    for(int i = 0; i < 6; i++) cin>>d1[i];
    for(int i = 0; i < 6; i++) cin>>d2[i];
    for(int i = 0; i < 6; i++) cin>>d3[i];

    // 1 y 2
    int total = 0, wa = 0;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(d1[i] == d2[j]) continue;
            total++;
            if(d1[i] > d2[j]) wa++;
        }
    }
    int cond12 = 2*wa >= total;
    if(!total) cond12 = 2;

    // 1 y 3
    total = 0, wa = 0;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(d1[i] == d3[j]) continue;
            total++;
            if(d1[i] > d3[j]) wa++;
        }
    }
    int cond13 = 2*wa >= total;
    if(!total) cond13 = 2;

    // 2 y 3
    total = 0, wa = 0;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(d2[i] == d3[j]) continue;
            total++;
            if(d2[i] > d3[j]) wa++;
        }
    }
    int cond23 = 2*wa >= total;
    if(!total) cond23 = 2;

    if(cond12 == 1 && cond13 == 1) cout<<1<<endl;
    else if(!cond12 && cond23 == 1) cout<<2<<endl;
    else if(!cond13 && !cond23) cout<<3<<endl;
    else cout<<"No dice"<<endl;
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
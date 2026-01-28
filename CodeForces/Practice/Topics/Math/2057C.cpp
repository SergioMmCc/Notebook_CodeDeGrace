#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

void solver(){
    int l, r; cin>>l>>r;

    int laux = l, raux = r;
    bool cond = 0;
    int add = 0;
    while(!cond){
        int pot2 = 1;
        while(pot2 <= raux) pot2 <<= 1;
        pot2 >>= 1;

        if(pot2 > laux){
            pot2 += add;
            cout<<pot2<<' '<<pot2 - 1<<' ';
            bool number = 0;
            for(int i = l; !number; i++){
                if(i != pot2 - 1 & i != pot2){
                    cout<<i<<endl;
                    number = 1;
                }
                cond = 1;
            }
        }

        else{
            add += pot2;
            laux -= pot2;
            raux -= pot2;
        }
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
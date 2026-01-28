#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

vector<int> pot2(31);

void calcPot2(){
    pot2[0] = 1;
    for(int i = 1; i < 31; i++) pot2[i] = 2 * pot2[i-1];
}

int calcMSB(int x){
    for(int i = 30; i >= 0; i--){
        if(x >= pot2[i]) return i;
    }
}

void solver(){
    int n, q; cin>>n>>q;
    vector<int> appear[31];
    vector<int> preCalcXor(n), weight;
    for(int i = 0; i < n; i++){
        int save; cin>>save;
        weight.pb(save);
    }

    reverse(weight.begin(), weight.end());
    for(int i = 0; i < n; i++){
        if(i) preCalcXor[i] = weight[i] ^ preCalcXor[i-1];
        else preCalcXor[i] = weight[i];

        int aux = weight[i];
        bool cond = 0;
        for(int j = 30; !cond && j >= 0; j--){
            if(aux >= pot2[j]){
                appear[j].pb(i);
                cond = 1;
                for(int k = 0; k < j; k++) appear[k].pb(i);
            }
        }
    }

    while(q--){
        int lastIndex = 0;
        int x; cin>>x;
        int aux = x;
        bool cond = 1;
        while(cond){
            int bit = calcMSB(aux);
            vector<int>::iterator it = lower_bound(appear[bit].begin(), appear[bit].end(), lastIndex);
            if(it == appear[bit].end()){
                cout<<n;
                if(q > 0) cout<<' ';
                cond = 0;
            }
            
            else{
                int index = *it;
                if(index > 0) aux = x ^ preCalcXor[index-1];
                if(aux > weight[index]){
                    lastIndex = index + 1;
                    aux = x ^ preCalcXor[index];
                    if(index == n-1){
                        cout<<n;
                        if(q > 0) cout<<' ';
                        cond = 0;
                    }
                }
                else if(aux == weight[index]){
                    cout<<index + 1;
                    if(q > 0) cout<<' ';
                    cond = 0;
                }
                else{
                    cout<<index;
                    if(q > 0) cout<<' ';
                    cond = 0;
                }
            }
        }
    }

    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    calcPot2();
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
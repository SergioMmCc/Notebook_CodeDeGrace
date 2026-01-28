#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

void solver(){
    int n; cin>>n;
    vector<int> freq(n+1);
    for(int i = 0; i < n; i++){
        int save; cin>>save;
        freq[save]++;
    }
    for(int i = n; i > 0; i--){
        if(freq[i] % 2 == 0) freq[i] = 0;
        else{
            bool cond = 1;
            int necesidades = 3;
            for(int j = i - 1; cond && j >= 0; j--){
                if(!j){
                    cout<<"No"<<endl;
                    return;
                }
                if(freq[j] < necesidades){
                    necesidades = 3 + necesidades - 1 - freq[j];
                    freq[j] = 0;
                }
                else{
                    freq[j] -= necesidades;
                    cond = 0;
                }
            }
        }
    }

    cout<<"Yes"<<endl;
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
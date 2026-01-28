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
    int n, q; cin>>n>>q;
    vector<int> a(n+1), px(n+1);
    vector<set<int>> nums(30);
    for(int i = n; i > 0; i--) cin>>a[i];
    for(int i = 1; i <= n; i++){
        px[i] = px[i-1] ^ a[i];
        for(int j = 0; j < 30; j++){
            if(a[i] & (1 << j)) nums[j].insert(i);
        }
    }

    while(q--){
        int x; cin>>x;
        int aux = x;
        int pos = 0;
        int mini = n+1;
        int bigg = 29;

        while(1){
            while(!(aux & (1 << bigg))){
                auto it = nums[bigg].upper_bound(pos);
                if(it == nums[bigg].end()){
                    bigg--;
                    continue;
                }
                bigg--;
                int index = *it;
                mini = min(index, mini);
            }
            auto it = nums[bigg].upper_bound(pos);
            if(it == nums[bigg].end() || *it >= mini){
                mini--;
                break;
            }

            int index = *it;
            int valor = x ^ px[index - 1];
            if(valor > a[index]){
                if(index == n){
                    mini = n;
                    break;
                }
                pos = index;
                aux = x ^ px[index];

                if(!aux){
                    mini = index;
                    break;
                }
            }
            else if(valor == a[index]){
                mini = index;
                break;
            }
            else{
                mini = index - 1;
                break;
            }
        }

        cout<<min(n, mini)<<' ';
    }
    cout<<endl;
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
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

void solver(){
    int n; cin>>n;
    vector<int> freq(n+1);
    for(int i = 0; i < n; i++){
        int save; cin>>save;
        freq[save]++;
    }

    int count1 = 0, countRest = 0, ans = 0;
    for(int i = 1; i <= n; i++){
        if(freq[i]){
            if(freq[i] == 1) count1++;
            else countRest++;
        }
    }

    ans = ((count1 + 1) / 2) * 2 + countRest;
    cout<<ans<<endl;
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
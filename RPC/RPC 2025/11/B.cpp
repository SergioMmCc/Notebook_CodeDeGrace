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
    string s; cin>>s;
    vector<int> freq(10);
    for(int i = 0; i < 5; i++){
        freq[s[i] - '0']++;
    }

    bool cond1 = 0, cond2 = 0;
    for(int i = 0; i < 10; i++){
        if(freq[i] == 3) cond1 = 1;
        else if(freq[i] == 2) cond2 = 1;
    }

    cout<<(cond1 && cond2 ? "YES" : "NO")<<endl;
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
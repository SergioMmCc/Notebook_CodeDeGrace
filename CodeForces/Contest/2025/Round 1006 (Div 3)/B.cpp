#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define int long long
typedef pair<int, int> pii;

void solver(){
    int n; string s; cin>>n>>s;

    int countD = 0, countU = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '-') countU++;
        else countD++;
    }

    int left, right;
    if(countU % 2){
        left = countU / 2;
        right = (countU + 1) / 2;
    }
    else left = right = countU / 2;

    cout<<left*right*countD<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
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
    string s; cin>>s;
    char last = '0';
    int moves = 0;
    for(int i = 0; i < n; i++){
        if(s[i] != last){
            moves++;
            last = s[i];
        }
    }

    cout<<moves<<endl;
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
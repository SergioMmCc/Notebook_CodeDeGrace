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
    vector<int> a(n+1), freq(n+1);
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        freq[a[i]]++;
    }
    int l = -1, r = n+1;
    int auxL = l, auxR = r;
    for(int i = 1; i <= n; i++){
        if(freq[a[i]] == 1){
            auxL = i;
            while(i <= n && freq[a[i]] == 1){
                i++;
            }
            auxR = i-1;
            if(l == -1 || auxR - auxL > r - l){
                l = auxL;
                r = auxR;
            }
        }
    }

    if(l == -1) cout<<0<<endl;
    else cout<<l<<' '<<r<<endl;
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
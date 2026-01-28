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
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin>>a[i];

    int maxN = 0, l = 1, r = 1; 
    for(int i = 1; i < n; i++){
        int aux = 0;
        for(int j = i + 1; j <= n; j++){
            if(a[i] < a[j]) aux--;
            else if(a[i] > a[j]) aux++;

            if(aux > maxN){
                maxN = aux;
                l = i;
                r = j;
            }
        }
    }

    cout<<l<<' '<<r<<endl;
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
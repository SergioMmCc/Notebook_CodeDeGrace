#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;
#define int long long

void solver(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    int ans = 0, parcialNeg = 0, totalNeg = 0, totalPos = 0, parcialPos = 0;
    bool sign = 1; //Positivo
    for(int i = 0; i < n; i++){
        if(sign){
            if(a[i] > 0){
                totalPos += a[i];
                parcialPos += a[i];
            }
            else{
                sign = 0;
                parcialNeg -= a[i];
                totalNeg -= a[i];
                ans = max(ans - a[i], parcialPos + parcialNeg);
            }
        }
        else{
            if(a[i] > 0){
                sign = 1;
                parcialPos = a[i];
                totalPos += a[i];
                parcialNeg = 0;
            }
            else{
                parcialNeg -= a[i];
                totalNeg -= a[i];
                ans = max(ans - a[i], parcialPos + parcialNeg);
            }
        }

        ans = max(ans, totalPos);
        ans = max(ans, totalNeg);
    }

    cout<<ans<<endl;
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
#include <bits/stdc++.h>
#define ll long long
#define all(x) (x).begin(), (x).end()
using namespace std;
int INF=1E9, MOD=1E9+7;

int calc(vector<int> &vec, vector<int> &ot){
    int n=vec.size();

    int v=0;
    for(int i=0, j=0; i<n; i++, j++){
        while(i < n && vec[i] != 1) i++;
        while(j < n && ot[j] != 1) j++;

        v += abs(i-j);
    }
    return v;
}

void solve(){
    int n; cin>>n;
    vector<int> vec(n);
    int one=0, zero=0;
    for(int i=0; i<n; i++){
        cin>>vec[i];
        vec[i] %= 2;
        zero += (vec[i]==0);
        one += (vec[i]==1);
    }

    int dif = one-zero;

    if(abs(dif) > 1){
        cout<<"-1\n";
        return;
    }

    if(dif != 0){
        vector<int> a(n);
        for(int i=0; i<n; i+=2) a[i] = 1;

        if(dif == -1){
            for(int i=0; i<n; i++){
                vec[i] ^= 1;
            }
        }

        cout<<calc(vec, a)<<"\n";
        return;
    }



    vector<int> a(n), b(n);
    int va=0, vb=0;
    for(int i=0; i<n; i+=2) a[i] = 1;
    for(int i=1; i<n; i+=2) b[i] = 1;
    va = calc(vec, a);
    vb = calc(vec, b);
    
    cout<<min(va, vb)<<"\n";
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
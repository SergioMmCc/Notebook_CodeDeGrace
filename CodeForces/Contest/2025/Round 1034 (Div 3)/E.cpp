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
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a.begin(), a.end());

    int mex = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == mex) mex++;
        else if(a[i] > mex) break;
    }

    vector<int> freq(mex+1), ps(mex+1), psa(mex+1);
    for(int i = 0; i < n; i++){
        if(a[i] >= mex) break;
        freq[a[i]]++;
    }

    ps[0] = freq[0]; psa[0] = freq[0] - 1;
    for(int i = 1; i <= mex; i++){
        ps[i] = ps[i-1] + freq[i];
        psa[i] = psa[i-1] + freq[i] - 1;
    }
    psa[mex] = psa[mex - 1];

    // cout<<"mex -> "<<mex<<endl;
    // for(int i = 0; i <= mex; i++) cout<<freq[i]<<' '; cout<<endl;
    // for(int i = 0; i <= mex; i++) cout<<ps[i]<<' '; cout<<endl;
    // for(int i = 0; i <= mex; i++) cout<<psa[i]<<' '; cout<<endl;
    
    vector<int> calc(n + 2);
    for(int i = 0; i <= mex; i++){
        int l = freq[i];
        int r = n - ps[i] + freq[i];
        if(i) r += psa[i-1];

        calc[l]++;
        calc[r+1]--;
    }

    vector<int> ans(n+1); ans[0] = calc[0];
    for(int i = 1; i <= n; i++){
        ans[i] = ans[i-1] + calc[i];
    }

    for(int i = 0; i <= n; i++){
        if(i) cout<<' ';
        cout<<ans[i];
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
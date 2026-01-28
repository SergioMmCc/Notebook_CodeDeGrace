#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
        ios_base::sync_with_stdio(0);cin.tie(NULL);
        long long n, k, ans = 0;
        cin>>n>>k;
        vector<long long> mn, ones;
        mn.push_back(1);
        ones.push_back(0);
        for(int i=1; i<=k; i++){
                mn.push_back(mn[i-1] * k + 1);
                ones.push_back(mn[i-1]);
                if(mn[i] >= n)
                break;
        }

        if(n > mn[mn.size()-1])
        ans += ones[ones.size()-1] + n - mn[mn.size()-1];
        else{
                for(int i=mn.size()-1; i>=0 && n>0; i--){
                        if(n >= mn[i]){
                                ans += ones[i] * (n / mn[i]);
                                n %= mn[i];
                        }
                }
        }
        cout<<ans<<endl;
}
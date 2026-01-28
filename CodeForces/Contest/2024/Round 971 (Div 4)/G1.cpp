#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solver(){
    int n, k, q;cin>>n>>k>>q;
    vector<int> a(n), ans(n+1);
    map<int, int> freq, nFreq;

    for(int i = 0; i < n; i++){
        cin>>a[i];
        a[i] += n-i;
    }
        
    for(int i = 0; i < k; i++)
        freq[a[i]]++;
    
    for(map<int, int>::iterator it = freq.begin(); it != freq.end(); ++it){
        nFreq[(*it).second]++;
    }
    map<int, int>::iterator it = nFreq.end(); --it;
    ans[1] = (*it).first;

    for(int i = 1; i <= n - k; i++){
        int take = a[i-1], add = a[i+k-1];
        map<int, int>::iterator upd = freq.find(take);
        int updFreq = (*upd).second;
        map<int, int>::iterator rest = nFreq.find(updFreq);

        if((*rest).first > 1) nFreq[(*rest).first - 1]++;
        if((*rest).second == 1) nFreq.erase((*rest).first);
        else (*rest).second--;
        
        if((*upd).second == 1)freq.erase((*upd).first);
        else (*upd).second--;

        freq[add]++;
        upd = freq.find(add);
        updFreq = (*upd).second;

        nFreq[updFreq]++;
        updFreq--;
        if(nFreq[updFreq] > 1) nFreq[updFreq]--;
        else nFreq.erase(updFreq);

        it = nFreq.end(); --it;
        ans[i+1] = (*it).first;
    }
    
    while(q--){
        int l, r;
        cin>>l>>r;
        cout<<k-ans[l]<<endl;
    }
}


int main (){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
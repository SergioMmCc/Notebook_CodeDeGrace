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
    int n, k; cin>>n>>k;
    vector<int> a(n), freq(n+1);
    for(int i = 0; i < n; i++){
        cin>>a[i];
        freq[a[i]]++;
    }

    int total = 0, last = 0;
    for(int i = 1; i <= n; i++){
        if(total + freq[i] < k){
            total += freq[i];
            last = i;
        }
        else break;
    }

    vector<int> test;
    for(int i = 0; i < n; i++){
        if(a[i] <= last) test.pb(a[i]);
    }

    bool cond = 1;
    for(int i = 0; cond && i < total / 2; i++){
        if(test[i] != test[total - i - 1]) cond = 0;
    }

    if(!cond){
        cout<<"NO"<<endl;
        return;
    }

    if(total == k - 1){
        cout<<"YES"<<endl;
        return;
    }

    int i = 0, j = n - 1, aux = total;
    for(int count = 0; count < (aux + 1) / 2; count++){
        int ci = 0, cj = 0;
        while(a[i] >= last + 1){
            if(a[i] == last + 1) ci++;
            i++;
        }
        i++;
        while(a[j] >= last + 1){
            if(a[j] == last + 1) cj++;
            j--;
        }
        j--;

        total += 2 * min(ci, cj);
    }

    if(aux % 2 == 0){
        while(i < n && a[i] >= last + 1){
            if(a[i] == last + 1) total++;
            i++;
        }
    }

    cout<<(total >= k - 1 ? "YES" : "NO")<<endl;
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
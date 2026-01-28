#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;

void pans(int a, int b){
    cout<<"! "<<a<<' '<<b<<endl;
}

void nans(){
    cout<<"! -1"<<endl;
}

int ask(int a, vector<int>& val){
    if(val[a]) return val[a];
    cout<<"? "<<a<<endl;
    cin>>val[a];
    return val[a];
}

void solver(){
    int n, k; cin>>n>>k;
    if(n == 2*k){
        pans(k, k);
        return;
    }
    if(k == 1){
        nans();
        return;
    }

    vector<int> val(n+1);
    vector<int> a(k+1), b(k+1);
    for(int i = 1; i <= k; i++) a[i] = ask(i, val);

    int x = n / k;
    for(int i = 1; i <= k; i++){
        int j = x * k + i;
        if(j > n) j -= k;
        b[i] = ask(j, val);
    }

    int c = 0;
    for(int i = 1; !c && i <= k; i++){
        if(a[i] != b[i]) c = i;
    }

    if(!c){
        nans();
        return;
    }
    
    int l = 0, r = x - 1;
    int s = -1;
    while(s == -1){
        int ml = (l + r) / 2; int mr = ml + 1;

        int ans1 = ask(k * ml + c, val), ans2 = ask(k * mr + c, val);

        if(ans1 == ans2){
            if(ans1 == a[c]){
                l = mr;
            }
            else{
                r = ml;
            }
        }
        else{
            s = ml;
        }
    }

    l = s*k + c; r = (s+1)*k + c;
    while(ask(l, val) == a[l % k == 0 ? k : l % k]) l++;
    l--;

    while(ask(r, val) == b[r % k == 0 ? k : r % k]) r--;
    r++;

    r = max(k+1, r);
    l = min(n - k, l);
    if(l + 1 == r) pans(l, n - l);
    else nans();
}

int main(){
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
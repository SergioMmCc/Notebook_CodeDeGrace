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

int n;

void updateTree(int update, vector<int>& tree){
    tree[n + update]++;
    update += n;
    for (int i = update; i > 1; i >>= 1) tree[i>>1] = tree[i] + tree[i ^ 1]; //Si i es el hijo por izquierda de i/2, entonces i ^ 1 es el hijo por derecha, y viceversa
    //i >> i -> i/2
}

// La implementacion es [l, r)
int query(int l, int r, vector<int>& tree){
    int ans = 0;
    l += n; r += n; 
    while (l < r) {
        if (l & 1) ans += tree[l++];
        if (r & 1) ans += tree[--r];
        l >>= 1; r >>= 1;
    }
    
    return ans;
}

void solver(){
    cin>>n; n = 2*n + 10;
    int i0 = n / 2, i1 = n / 2;
    vector<int> tree0(4 * n + 1), tree1(4 * n + 1);
    string s; cin>>s;

    ll ans = 0, carry = 0;
    for(int i = 0; i < s.sz; i++){
        ll add = 0;
        if(s[i] == '0'){
            i0++;
            i1--;
            updateTree(i0, tree0);

            add = query(0, i0 + 1, tree0) + query(i1 + 2, n, tree1);
        }
        else{
            i1++;
            i0--;
            updateTree(i1, tree1);

            add = query(0, i1 + 1, tree1) + query(i0 + 2, n, tree0);
        }

        carry += add;
        ans += carry;
    }

    cout<<ans<<endl;
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
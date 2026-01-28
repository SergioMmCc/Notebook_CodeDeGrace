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

const int inf = 1000000001;
ll inv = 0;

void myMerge (vector<int>& A, int p, int q, int r) {
    int n1 = q-p+1, n2 = r-q, i, j, k;
    vector<int> L(n1+2), R(n2+2);
    for (i=1; i<=n1; i++)
        L[i] = A[p+i-1];
    for (j=1; j<=n2; j++)
        R[j] = A[q+j];
    L[n1+1] = inf;
    R[n2+1] = inf;
    i=1;
    j=1;
    for (k=p; k<=r; k++) {
        if (L[i] <= R[j]) {
            A[k] = L [i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
            inv += n1 - i + 1;
        }
    }
}

void MergeSort (vector<int>& A, int p, int r) {
    int q;
    if (p<r) {
        q = (p+r)/2;
        MergeSort (A, p, q);
        MergeSort (A, q+1, r);
        myMerge (A, p, q, r);
    }
}

void solver(){
    inv = 0;
    int n; cin>>n;
    vector<int> par, impar, a(n+1);
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        if(i % 2) impar.pb(a[i]);
        else par.pb(a[i]);
    }
    if(n <= 3){
        for(int i = 1; i <= n; i++){
            if(i > 1) cout<<' ';
            else cout<<a[i];
        }
        cout<<endl;
        return;
    }

    sort(par.begin(), par.end());
    sort(impar.begin(), impar.end());
    MergeSort(a, 1, n); 
    ll save = inv % 2;
    inv = 0;
    vector<int> ans(n+1);
    int pari = 0, impari = 0;
    for(int i = 1; i <= n - 3; i++){
        if(i % 2){
            ans[i] = impar[impari];
            impari++;
        }
        else{
            ans[i] = par[pari];
            pari++;
        }
    }

    int mid, l, r;
    if(n % 2){
        mid = par[pari];
        l = impar[impari];
        r = impar[impari + 1];
    }
    else{
        mid = impar[impari];
        l = par[pari];
        r = par[pari + 1];
    }

    vector<int> aux = ans;
    if(l < mid){
        aux[n-2] = l;
        if(mid < r){
            aux[n-1] = mid;
            aux[n] = r;
        }
        else{
            aux[n-1] = r;
            aux[n] = mid;
        }
    }
    else{
        aux[n-2] = mid;
        aux[n-1] = l;
        aux[n] = r;
    }
    MergeSort(aux, 1, n);
    inv += save;
    inv %= 2;

    if(mid > l && mid < r){
        if(inv){
            ans[n-2] = r;
            ans[n-1] = mid;
            ans[n] = l;
        }
        else{
            ans[n-2] = l;
            ans[n-1] = mid;
            ans[n] = r;
        }
    }
    else if(mid > l && mid > r){
        if(inv){
            ans[n-2] = l;
            ans[n-1] = mid;
            ans[n] = r;
        }
        else{
            ans[n-2] = r;
            ans[n-1] = mid;
            ans[n] = l;
        }
    }
    else{
        if(inv){
            ans[n-2] = l;
            ans[n-1] = mid;
            ans[n] = r;
        }
        else{
            ans[n-2] = r;
            ans[n-1] = mid;
            ans[n] = l;
        }
    }

    for(int i = 1; i <= n; i++){
        if(i > 1) cout<<' ';
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
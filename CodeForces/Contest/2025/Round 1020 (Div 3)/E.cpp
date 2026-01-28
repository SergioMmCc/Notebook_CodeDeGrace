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

int binarySearch(int l, int r, int num, int n, int pos, vector<int>& a){
    int nBig = 0, nSmall = 0, big = 0, small = 0;

    int m = (l + r) / 2;
    while(l <= r && m != pos){
        if(m > pos){
            if(a[m] < num) nBig++;
            else big++;
            r = m - 1;
        }
        else{
            if(a[m] > num) nSmall++;
            else small++;
            l = m + 1;
        }

        m = (l + r) / 2;
    }

    if(nBig + big > n - num || nSmall + small > num - 1) return -1;

    return 2 * (nSmall + nBig - min(nSmall, nBig));
}

void solver(){
    int n, q; cin>>n>>q;
    vector<int> pos(n+1), a(n+1);
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        pos[a[i]] = i;
    }

    while(q--){
        int l, r, num; cin>>l>>r>>num;
        if(pos[num] > r || pos[num] < l){
            cout<<-1<<' ';
            continue;
        }

        cout<<binarySearch(l, r, num, n, pos[num], a)<<' ';
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
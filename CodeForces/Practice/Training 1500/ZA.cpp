#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

typedef pair<int, int> pii;

struct comparator {
    bool operator() (const pii& a, const pii& b) const {
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    }
};

void solver(){
    int n, m; cin>>n>>m;
    set<int> nums;
    set<pii> segments;
    set<pii, comparator> procesed;
    for(int i = 0; i < n; i++){
        int l, r; cin>>l>>r;
        segments.insert({l, r});
        nums.insert(l); nums.insert(r);
    }

    int ans = 0;
    int count1 = 0, countm = 0;
    for(int num : nums){
        while(!segments.empty() && (*segments.begin()).first <= num){
            if((*segments.begin()).first == 1) count1++;
            if((*segments.begin()).second == m) countm++;
            procesed.insert(*segments.begin());
            segments.erase(segments.begin());
        }
        while(!procesed.empty() && (*procesed.begin()).second < num){
            if((*procesed.begin()).first == 1) count1--;
            if((*procesed.begin()).second == m) countm--;
            procesed.erase(*procesed.begin());
        }

        int aux = max(procesed.sz - count1, procesed.sz - countm);
        ans = max(aux, ans);
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
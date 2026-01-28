#include<bits/stdc++.h>
using namespace std;
 
typedef pair<double, int> pli;

double dischargeTime (long long a, long long b){
    return (double) a / (double) b;
}
 
struct comparator {
    bool operator() (pli a, pli b) {return a.first > b.first;}
};
priority_queue<pli, vector<pli>, comparator> pq;
vector<long long> currentCharge(200001), dischargeSpeed(200001);
 
bool test(long long r, int k) {
    priority_queue<pli, vector<pli>, comparator> caso = pq;
    int available = 0;
    for(int timer = 0; timer < k - 1; timer++) {
        available++;
        while(((long long)caso.top().first) == timer) {
            if(available <= 0)
                return false;
            available--;
            int student = caso.top().second;
            double nextTime = caso.top().first + dischargeTime(r, dischargeSpeed[student]);
            caso.pop();
            caso.push({nextTime, student});
        }
    }
    while(!caso.empty()) 
        caso.pop();
    
    return true;
}
 
int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int n, k;
    cin >> n >> k;
 
    for(int i = 0; i < n; i++) 
        cin >> currentCharge[i];
    for(int i = 0; i < n; i++) {
        cin >> dischargeSpeed[i];
        pq.push({dischargeTime(currentCharge[i], dischargeSpeed[i]), i});
    }
 
    long long i = 0, j = k * 1e7, ans = 1e18;
    while(i <= j) {
        long long r = (j+i) >> 1;
        if(test(r, k)) {
            j = r-1;
            ans = r;
        }
        else i = r+1;
    }
 
    if(ans == 1e18)
        cout << "-1\n";
    else
        cout << ans << "\n";
    return 0;
}
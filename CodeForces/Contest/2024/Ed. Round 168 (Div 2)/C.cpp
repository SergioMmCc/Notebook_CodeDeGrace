#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solver() {
    long long n;cin>>n;
    string a;cin>>a;
    long long op = 0;
    priority_queue<long long> pq;
    long long ans = 0;
    
    int next = 0;
    for(long long i = 0; i < n; i++) {
        if(a[i] == '('){
            op++;
            pq.push(i);
        }
        else if(a[i] == ')') {
            op--;
            next = pq.top(); pq.pop();
            ans += i - next;
        }
        else {
            if(op > 0) {
                op--;
                next = pq.top(); pq.pop();
                ans += i-next;
            }
            else {
                op++;
                pq.push(i);
            }
        }
    }
    
    cout<<ans<<endl;
}

int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        solver();
    }

    return 0;
}
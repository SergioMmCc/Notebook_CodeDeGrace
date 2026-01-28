#include<bits/stdc++.h>
using namespace std;
 
map<int, priority_queue<long long>> subject;
vector<int> sumaParcial(100001, 0);
 
int main() {
    int n, m, s;
    long long e, ans = 0, aux = 0;
    
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d %lld", &s, &e);
        subject[s].push(e);
        
    }
    bool flag = false;
    int a;
    while(!subject.empty()) {
        aux = 0;
        for(auto it = subject.begin(); it != subject.end(); it++) {
            if (flag) {
                subject.erase(a);
                flag = false;
            }
            a = it->first;
            sumaParcial[a] += it->second.top();
            if(sumaParcial[a] <= 0) {
                if (it == prev(subject.end())) {
                    subject.erase(a);
                    break;
                }
                flag = true;
                continue;
            }
            aux += sumaParcial[a];
            it->second.pop();
            if (it->second.empty()) {
                if (it == prev(subject.end())) {
                    subject.erase(a);
                    break;
                }
                flag = true;
            }
        }
        ans = max(ans, aux);
    }
    
    printf("%lld\n", ans);
 
    return 0;
}
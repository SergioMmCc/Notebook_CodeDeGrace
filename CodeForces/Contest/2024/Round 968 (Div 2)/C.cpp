#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

typedef pair<int, int> pii;

void solver (){
    vector<pii> freq(27, {0, 0});
    for(int i = 0; i < 27; i++)
        freq[i].second = i;
    int n; cin>>n;
    string a; cin>>a;
    for(int i = 0; i < n; i++)
        freq[a[i] - 'a'].first++;
    priority_queue<pii> pq;
    for(int i = 0; i < 27; i++){
        if(freq[i].first == 0)
            continue;
        pq.push(freq[i]);
    }
    int left = 1, right = n-1;
    vector<char> ans(n+1, '*');
    pii maxN = pq.top();pq.pop();
    ans[0] = (char)(maxN.second + 'a');
    if(maxN.first > 1)pq.push({maxN.first - 1, maxN.second});
    while(!pq.empty()){
        maxN = pq.top();pq.pop();
        if(ans[left-1] == (char)(maxN.second + 'a')){
            if(ans[right+1] == (char)(maxN.second + 'a')){
                ans[left] = (char)(maxN.second + 'a');
                left++;
            }
            else{
                ans[right] = (char)(maxN.second + 'a');
                right--;
            }
        }
        else{
            ans[left] = (char)(maxN.second + 'a');
            left++;
        }
        if(maxN.first > 1)
            pq.push({maxN.first-1, maxN.second});
    }
    for(int i = 0; i < n; i++)
        cout<<ans[i];
    cout<<endl;
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
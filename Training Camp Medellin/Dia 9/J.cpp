#include <bits/stdc++.h>
#include <ios>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pqueue priority_queue
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s; cin>>s;
    vector<bool> a(26);
    for(int i = 0; i < sz(s); i++) a[s[i] - 'a'] = 1;
    int cnt = 0;
    for(int i = 0; i < 26; i++) if(a[i]) cnt++;
    cout<<(cnt % 2 == 0 ? "CHAT WITH HER!" : "IGNORE HIM!")<<endl; 
}

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solver() {
    string s, t; cin>>s>>t;
    int x = s.size();
    int ready = t.size()-1, count = 0;
    for(int i = 0; i < x; i++) {
        if(s[i] != '?') {
            if(count <= ready && s[i] == t[count]) {
                count++;
            }
            continue;
        }
        if(count <= ready) {
            s[i] = t[count];
            count++;
        }
        else
            s[i] = 'a';
    }
    if(count == t.size()) {
        cout<<"YES"<<endl;
        cout<<s<<endl;
    }
    else
        cout<<"NO"<<endl;
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
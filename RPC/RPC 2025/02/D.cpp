#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

map<char, int> T;
void fillT(){
    T['a'] = 2;
    T['b'] = 2;
    T['c'] = 2;
    T['d'] = 3;
    T['e'] = 3;
    T['f'] = 3;
    T['g'] = 4;
    T['h'] = 4;
    T['i'] = 4;
    T['j'] = 5;
    T['k'] = 5;
    T['l'] = 5;
    T['m'] = 6;
    T['n'] = 6;
    T['o'] = 6;
    T['p'] = 7;
    T['q'] = 7;
    T['r'] = 7;
    T['s'] = 7;
    T['t'] = 8;
    T['u'] = 8;
    T['v'] = 8;
    T['w'] = 9;
    T['x'] = 9;
    T['y'] = 9;
    T['z'] = 9;
}

void solver(){
    int n, q; cin>>n>>q;
    vector<string> words(n);
    for(int i = 0; i < n; i++) cin>>words[i];
    sort(words.begin(), words.end());

    while(q--){
        string codigo; cin>>codigo; int len = codigo.sz;
        vector<string> possible;

        for(string test : words){
            if(len != test.sz) continue;
            bool cond = 1;
            for(int i = 0; cond && i < len; i++){
                int num = (int) codigo[i] - '0';
                if(T[test[i]] != num) cond = 0;
            }

            if(cond) possible.pb(test);
        }

        cout<<possible.sz;
        for(string pos : possible) cout<<' '<<pos;
        cout<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    fillT();
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
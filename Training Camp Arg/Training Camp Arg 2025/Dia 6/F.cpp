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

void solver(){
    string s; cin>>s;
    int n = s.sz;
    if(n == 1){
        cout<<"YES"<<endl<<s<<endl;
        return;
    }

    vector<int> freq(27);
    for(int i = 0; i < n; i++) freq[s[i] - 'a']++;

    int count = 0;
    for(int i = 0; i < 27; i++){
        if(freq[i]) count++;
    }

    if(count == 1){
        cout<<"NO"<<endl;
        return;
    }

    if(count == 2){
        if(n == 2){
            cout<<"YES"<<endl<<s<<endl;
            return;
        }

        char big = '*', sma = '*';
        for(int i = 0; i < 27; i++){
            if(freq[i] == 1) sma = 'a' + i;
            if(freq[i] > 1){
                if(big != '*'){
                    cout<<"NO"<<endl;
                    return;
                }
                big = 'a' + i;
            }
        }

        cout<<"YES"<<endl<<sma;
        for(int i = 1; i < n; i++) cout<<big; cout<<endl;
        return;
    }

    cout<<"YES"<<endl;
    count = 0;
    while(count < n){
        for(int i = 0; i < 27; i++){
            if(freq[i]){
                count++;
                freq[i]--;
                cout<<(char)('a' + i);
            }
        }
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
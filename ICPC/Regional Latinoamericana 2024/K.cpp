#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back

typedef pair<char, pair<int, int>> pcii;

char swapNumber(char c){
    if(c == '0') return '1';
    return '0';
}

void solver(){
    int k; string s; cin>>k>>s;
    int ans = 0; string a = s;
    if(k == 2){
        int aux0 = 0; string test0 = s;
        for(int i = 0; i < s.size(); i++){
            if(i % 2 == 0 && s[i] == '1'){aux0++; test0[i] = '0';}
            else if(i % 2 == 1 && s[i] == '0'){aux0++; test0[i] = '1';}
        }
        int aux1 = 0; string test1 = s;
        for(int i = 0; i < s.size(); i++){
            if(i % 2 == 0 && s[i] == '0'){aux1++; test1[i] = '1';}
            else if(i % 2 == 1 && s[i] == '1'){aux1++; test1[i] = '0';}
        }

        if(aux0 <= aux1){ans = aux0; a = test0;}
        else {ans = aux1; a = test1;}
    }
    else {
        vector<pcii> ranges;
        char lastLetter = s[0];
        int lastIndex = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != lastLetter){
                if(i - lastIndex >= k) ranges.pb({lastLetter, {lastIndex, i-1}});
                lastLetter = s[i];
                lastIndex = i;
            }
        }

        if(s.size() - lastIndex >= k) ranges.pb({lastLetter, {lastIndex, s.size()-1}});

        for(pcii range : ranges){
            int l = range.second.first, r = range.second.second;
            for(int i = l; i <= r; i++){
                if((i - l + 1) % k == 0){
                    ans++;
                    if(i == r) a[i-1] = swapNumber(s[i-1]);
                    else a[i] = swapNumber(s[i]);
                }
            }
        }
    }

    cout<<ans<<' '<<a<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
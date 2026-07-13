#include <bits/stdc++.h>
#define ll long long
#define all(x) (x).begin(), (x).end()
using namespace std;
int INF=1E9, MOD=1E9+7;
string s;
int n;

string algo1(map<char, int> f){
    //[aa]bacadaddddddd

    char a = f.begin()->first;
    int va = f.begin()->second;
    f.erase(f.begin());
    string ans="";

    ans.push_back(a); va--;

    while(va){
        ans.push_back(a); va--;
        if(f.empty()) break;
        ans.push_back(f.begin()->first);
        f.begin()->second--;
        if(f.begin()->second == 0) f.erase(f.begin());
    }

    while(!f.empty()){
        ans.push_back(f.begin()->first);
        f.begin()->second--;
        if(f.begin()->second == 0) f.erase(f.begin());
    }

    while(va){
        ans.push_back(a); va--;
    }


    return ans;
}

string algo2(map<char, int> f){ // |a| >= |*| - |a| + 2
    //aabbbbbbbbbaaaaaaaaa
    char a = f.begin()->first;
    int va = f.begin()->second;
    f.erase(f.begin());
    string ans="";


    if(f.size() == 1){
        char b = f.begin()->first;
        int vb = f.begin()->second;

        ans.push_back(a); va--;
        for(int i=0; i<vb; i++){
            ans.push_back(b);
        }
        for(int i=0; i<va; i++){
            ans.push_back(a);
        }
    }else{
        return s;
    }
    return ans;
}

string algo3(map<char, int> f){
    // abbbbaaaaaaaccccc
    char a = f.begin()->first;
    int va = f.begin()->second;
    f.erase(f.begin());
    string ans="";


    // a is more, wiht f > 2 char
    ans.push_back(a); va--;
    for(int i=0; i<f.begin()->second; i++){
        ans.push_back(f.begin()->first);
    }
    f.erase(f.begin());
    for(int i=0; i<va; i++){
        ans.push_back(a);
    }
    for(auto [c, v] : f){
        for(int i=0; i<v; i++){
            ans.push_back(c);
        }
    }
    return ans;
}

string algo4(map<char, int> f){ 
    //[aba]aaaaaaaaacbbbbbbbcccccccddddddd
    char a = f.begin()->first;
    int va = f.begin()->second;
    f.erase(f.begin());
    string ans="";


    if(f.size() > 1){
        char b = f.begin()->first;
        int vb = f.begin()->second;
        f.erase(f.begin());

        ans.push_back(a); va--;
        ans.push_back(b); vb--;

        for(int i=0; i<va; i++){
            ans.push_back(a);
        }

        ans.push_back(f.begin()->first); f.begin()->second--;
        if(f.begin()->second == 0) f.erase(f.begin());
        for(int i=0; i<vb; i++){
            ans.push_back(b);
        }

        while(!f.empty()){
            ans.push_back(f.begin()->first);
            f.begin()->second--;
            if(f.begin()->second == 0) f.erase(f.begin());
        }
        
    }else{
        return s;
    }
    return ans;
}

string algo5(map<char, int> f){ 
    //[x]aaaabbbccc
    string ans="";
    pair<char, int> mn {'a', INF};
    for(auto [c, v] : f){
        if(v < mn.second){
            mn = {c, v};
        }
    }

    while(f[mn.first]){
        ans.push_back(mn.first); f[mn.first]--;
    }

    for(auto [c, v] : f){
        while(v){
            ans.push_back(c); v--;
        }
    }
    return ans;

    
}


int kmp(string &ss){
    int j=0, m=0;
    vector<int> p(n+1);
    for(int i=1; i<n; i++){
        while(j>0 && ss[i]!=ss[j]) j=p[j-1];
        j += (ss[i]==ss[j]);
        p[i]=j;
        m = max(m, p[i]);
    }
    return m;
}



void solve(){
    
    cin>>s;
    n = s.size();
    map<char, int> f;
    for(char c : s){
        f[c]++;
    }

    if(f.size() == 1){
        cout<<s<<"\n";
        return;
    }


    vector<pair<int, string>> ag(5);

    ag[0].second = algo1(f); ag[0].first = kmp(ag[0].second);
    ag[1].second = algo2(f); ag[1].first = kmp(ag[1].second);
    ag[2].second = algo3(f); ag[2].first = kmp(ag[2].second);
    ag[3].second = algo4(f); ag[3].first = kmp(ag[3].second);
    ag[4].second = algo5(f); ag[4].first = kmp(ag[4].second);

    
    /*
    cout<<ag[0].first<<" -> "<<ag[0].second<<"\n";
    cout<<ag[1].first<<" -> "<<ag[1].second<<"\n";
    cout<<ag[2].first<<" -> "<<ag[2].second<<"\n";
    cout<<ag[3].first<<" -> "<<ag[3].second<<"\n";
    cout<<ag[4].first<<" -> "<<ag[4].second<<"\n";
    cout<<"======= ";
    */

    sort(all(ag));

    cout<<ag[0].second<<"\n";




}

int main() {
    //ios::sync_with_stdio(false);cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
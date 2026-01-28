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
    int n; cin>>n;
    string s; cin>>s;
    int L = 0, I = 0, T = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'L') L++;
        else if(s[i] == 'T') T++;
        else I++;
    }

    if((!I && !T) || (!T && !L) || (!I && !L)){
        cout<<-1<<endl;
        return;
    }

    vector<int> ans;
    while(I != L || I != T){
        // cout<<"tamaño -> "<<s.sz<<endl;
        string aux = "";
        if(I <= L && I <= T){
            bool cond = 0;
            for(int i = 0; !cond && i < s.sz - 1; i++){
                if((s[i] == 'L' && s[i+1] == 'T') || (s[i] == 'T' && s[i+1] == 'L')){
                    ans.pb(i); cond = 1;
                    // cout<<"add 1 - > "<<i<<endl;
                    I++;
                    for(int j = 0; j <= s.sz; j++){
                        if(j <= i) aux += s[j];
                        else if(j == i+1) aux += 'I';
                        else aux += s[j-1];
                    }
                }
            }

            if(!cond){
                if(T <= L){
                    for(int i = 0; !cond && i < s.sz - 1; i++){
                        if((s[i] == 'I' && s[i+1] == 'L') || (s[i] == 'L' && s[i+1] == 'I')){
                            ans.pb(i); cond = 1;
                            // cout<<"add 2 - > "<<i<<endl;
                            T++;
                            for(int j = 0; j <= s.sz; j++){
                                if(j <= i) aux += s[j];
                                else if(j == i+1) aux += 'T';
                                else aux += s[j-1];
                            }
                        }
                    }
                }

                else{
                    for(int i = 0; !cond && i < s.sz - 1; i++){
                        if((s[i] == 'I' && s[i+1] == 'T') || (s[i] == 'T' && s[i+1] == 'I')){
                            ans.pb(i); cond = 1;
                            // cout<<"add 3 - > "<<i<<endl;
                            L++;
                            for(int j = 0; j <= s.sz; j++){
                                if(j <= i) aux += s[j];
                                else if(j == i+1) aux += 'L';
                                else aux += s[j-1];
                            }
                        }
                    }
                }
            }
        }

        else if(T <= L && T <= I){
            bool cond = 0;
            for(int i = 0; !cond && i < s.sz - 1; i++){
                if((s[i] == 'L' && s[i+1] == 'I') || (s[i] == 'I' && s[i+1] == 'L')){
                    ans.pb(i); cond = 1;
                    // cout<<"add 4 - > "<<i<<endl;
                    T++;
                    for(int j = 0; j <= s.sz; j++){
                        if(j <= i) aux += s[j];
                        else if(j == i+1) aux += 'T';
                        else aux += s[j-1];
                    }
                }
            }

            if(!cond){
                if(I <= L){
                    for(int i = 0; !cond && i < s.sz - 1; i++){
                        if((s[i] == 'T' && s[i+1] == 'L') || (s[i] == 'L' && s[i+1] == 'T')){
                            ans.pb(i); cond = 1;
                            // cout<<"add 5 - > "<<i<<endl;
                            I++;
                            for(int j = 0; j <= s.sz; j++){
                                if(j <= i) aux += s[j];
                                else if(j == i+1) aux += 'I';
                                else aux += s[j-1];
                            }
                        }
                    }
                }

                else{
                    for(int i = 0; !cond && i < s.sz - 1; i++){
                        if((s[i] == 'I' && s[i+1] == 'T') || (s[i] == 'T' && s[i+1] == 'I')){
                            ans.pb(i); cond = 1;
                            // cout<<"add 6 - > "<<i<<endl;
                            L++;
                            for(int j = 0; j <= s.sz; j++){
                                if(j <= i) aux += s[j];
                                else if(j == i+1) aux += 'L';
                                else aux += s[j-1];
                            }
                        }
                    }
                }
            }
        }

        else{ // L menor
            bool cond = 0;
            for(int i = 0; !cond && i < s.sz - 1; i++){
                if((s[i] == 'I' && s[i+1] == 'T') || (s[i] == 'T' && s[i+1] == 'I')){
                    ans.pb(i); cond = 1;
                    // cout<<"add 7 - > "<<i<<endl;
                    L++;
                    for(int j = 0; j <= s.sz; j++){
                        if(j <= i) aux += s[j];
                        else if(j == i+1) aux += 'L';
                        else aux += s[j-1];
                    }
                }
            }

            if(!cond){
                if(T <= I){
                    for(int i = 0; !cond && i < s.sz - 1; i++){
                        if((s[i] == 'I' && s[i+1] == 'L') || (s[i] == 'L' && s[i+1] == 'I')){
                            ans.pb(i); cond = 1;
                            // cout<<"add 8 - > "<<i<<endl;
                            T++;
                            for(int j = 0; j <= s.sz; j++){
                                if(j <= i) aux += s[j];
                                else if(j == i+1) aux += 'T';
                                else aux += s[j-1];
                            }
                        }
                    }
                }

                else{
                    for(int i = 0; !cond && i < s.sz - 1; i++){
                        if((s[i] == 'L' && s[i+1] == 'T') || (s[i] == 'T' && s[i+1] == 'L')){
                            ans.pb(i); cond = 1;
                            // // cout<<"add 9 - > "<<i<<endl;
                            I++;
                            for(int j = 0; j <= s.sz; j++){
                                if(j <= i) aux += s[j];
                                else if(j == i+1) aux += 'I';
                                else aux += s[j-1];
                            }
                        }
                    }
                }
            }
        }

        s = aux;
    }

    cout<<ans.sz<<endl;
    for(int i = 0; i < ans.sz; i++) cout<<ans[i] + 1<<endl;
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
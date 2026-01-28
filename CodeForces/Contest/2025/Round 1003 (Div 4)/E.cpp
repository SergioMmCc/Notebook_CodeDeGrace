#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

void solver(){
    int n, m, k; cin>>n>>m>>k;
    if(abs(n - m) > k){
        cout<<-1<<endl;
        return;
    }
    if(n < k && m < k){
        cout<<-1<<endl;
        return;
    }
    string ans = "";

    if(n != m){
        bool next = 0;
        if(n > m){
            for(int i = 0; i < k; i++){
                ans += '0';
                n--;
            }
    
            next = 1;

            while((next && m) || (!next && n)){
                if(next){
                    ans += '1';
                    m--;
                    next = 0;
                }
                else{
                    ans += '0';
                    n--;
                    next = 1;
                }
            }
            while(m--) ans += '1';
            cout<<ans<<endl;
            return;
        }
    
        else if(m > n){
            for(int i = 0; i < k; i++){
                ans += '1';
                m--;
            }
    
            next = 0;

            while((next && m > 0) || (!next && n > 0)){
                if(next){
                    ans += '1';
                    m--;
                    next = 0;
                }
                else{
                    ans += '0';
                    n--;
                    next = 1;
                }
            }

            while(n--) ans += '0';
            cout<<ans<<endl;
            return;
        }
    }

    else{
        for(int i = 0; i < k; i++){
            ans += '0';
            n--;
        }
        
        bool next = 1;
        while(n > 0){
            if(next){
                ans += '1';
                m--;
                next = 0;
            }
            else{
                ans += '0';
                n--;
                next = 1;
            }
        }

        while(m > 0){
            ans += '1';
            m--;
        }
        cout<<ans<<endl;
    }
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
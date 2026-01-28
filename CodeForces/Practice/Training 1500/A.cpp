#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

void solver(){
    int n; cin>>n;
    char ans[n];
    int cur, last;
    cout<<"? "<<1<<' '<<n<<endl;
    cin>>last;
    if(last == 0){
        cout<<"! IMPOSSIBLE"<<endl;
        return;
    }
    if(n == 2 && last){
        cout<<"! 01"<<endl;
        return;
    }

    for(int i = n - 1; i > 1; i--){
        cout<<"? "<<1<<' '<<i<<endl;
        cin>>cur;
        if(cur == last) ans[i] = '0';
        else{
            ans[i] = '1';
            if(!cur){
                i--;
                while(last > 0){
                    ans[i] = '0';
                    last--;
                    i--;
                }
                while(i >= 0){
                    ans[i] = '1';
                    i--;
                }
            }
        }

        if(cur > 0 && i == 2){
            ans[1] = '1';
            ans[0] = '0';
        }

        last = cur;
    }

    cout<<"! ";
    for(int i = 0; i < n; i++) cout<<ans[i];
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
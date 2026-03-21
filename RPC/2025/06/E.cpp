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
const int top=1e6, INF=1e9;


bool ver(string& s){
    for(int i=1; i<s.size(); i++){
        if(s[i] == 'O' && s[i-1] == 'O') return 0;
    }

    if(s.back() != 'O') return 0;
    
    return 1;
}


long long init(long long n){
    return ((1<<(2*n+2))-1)/3;
}


void solver(){
    string s;
    cin>>s;
    int n=s.size();

    if(!ver(s)){
        cout<<"INVALID\n";
        return;
    }

    for(int i=1; i<31; i++){
        long long x = init(i);
        //cout<<i<<": "<<x<<"\n";
        bool can=1;

        for(int p=n-2; p>=0; p--){
            if(s[p] == 'O'){
                if((x-1) % 3 != 0){
                    can = 0;
                    break;
                }
                x = (x-1)/3;
            }
            if(s[p] == 'E'){
                x <<= 1;
            }
           // cout<<x<<" -\n";
        }

        if(can){
            
            cout<<x<<"\n";
            return;
        }
        //cout<<"------------\n";
    }
    //cout<<"***\n";
    cout<<"INVALID\n";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);

        solver();
    

    return 0;
}
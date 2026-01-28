#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

void solver(){
    ll n; cin>>n;
    ll k = sqrt(n-1) / 2 + 1;

    ll point = 4*(k-1)*(k-1) + 1;
    ll x = 2*k - 2, y = -k + 1;

    if(n == point){
        cout<<x<<' '<<y<<endl;
        return;
    }
    
    if(n <= point + 4*k - 3){
        x -= n - point;
        cout<<x<<' '<<y<<endl;
        return;
    }

    point += 4*k - 3;
    x -= 4*k - 3;
    if(n <= point + 2*k - 1){
        x += n - point;
        y += n - point;
        cout<<x<<' '<<y<<endl;
        return;
    }
    
    x += 2*k - 1;
    y += 2*k - 1;
    point += 2*k - 1;
    x += n - point;
    y -= n - point;
    cout<<x<<' '<<y<<endl;
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
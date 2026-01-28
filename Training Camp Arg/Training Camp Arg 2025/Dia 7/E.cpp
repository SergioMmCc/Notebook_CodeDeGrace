#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;

void solver(){
    int n, m; cin>>n>>m;
    int a, b;
    cout<<"SCAN "<<1<<' '<<1<<endl;
    cin>>a;
    cout<<"SCAN "<<n<<' '<<1<<endl;
    cin>>b;
    int sx = (a + b) / 2 - n + 3;
    int sy = (a - b) / 2 + n + 1;
    int c, d;
    cout<<"SCAN "<<1<<' '<<sx / 2<<endl;
    cin>>c;
    cout<<"SCAN "<<sy / 2<<' '<<1<<endl;
    cin>>d;

    // cout<<"a -> "<<a<<" b -> "<<b<<" c -> "<<c<<" d -> "<<d<<endl;

    int x1 = ((a + b) / 2 - n + 3 - c + sy - 2) / 2;
    int x2 = ((a +  b) / 2 - n + 3 + c - sy + 2) / 2;
    int y1 = ((a - b) / 2 + n + 1 - d + sx - 2) / 2;
    int y2 = ((a - b) / 2 + n + 1 + d - sx + 2) / 2;

    // cout<<"x1 -> "<<x1<<" x2 -> "<<x2<<" y1 -> "<<y1<<" y2 -> "<<y2<<endl;

    cout<<"DIG "<<y1<<' '<<x1<<endl;
    int pos; cin>>pos;
    if(pos){
        cout<<"DIG "<<y2<<' '<<x2<<endl;
        cin>>pos;
    }
    else{
        cout<<"DIG "<<y1<<' '<<x2<<endl;
        cin>>pos;
        cout<<"DIG "<<y2<<' '<<x1<<endl;
        cin>>pos;
    }
}

int main(){
    // ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
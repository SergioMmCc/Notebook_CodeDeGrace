#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

typedef pair<ld, ld> pdd;
pdd nil = {-1, -1};

void solver(){
    int n, m; cin>>n>>m;
    int b1, b2, b3;

    cout<<"? "<<1<<' '<<1<<endl;
    cin>>b1;
    if(!b1){
        cout<<"! "<<1<<' '<<1<<endl;
        return;
    }
    b1++; b1 *= -1;

    cout<<"? "<<1<<' '<<m<<endl;
    cin>>b2;
    if(!b2){
        cout<<"! "<<1<<' '<<m<<endl;
        return;
    }
    b2 = b2 - m + 1;

    cout<<"? "<<n<<' '<<1<<endl;
    cin>>b3;
    if(!b3){
        cout<<"! "<<n<<' '<<1<<endl;
        return;
    }
    b3 = n - b3 - 1;

    // Calcular la interseccion entre r1 y r2
    pdd cross12;
    if(abs(b1 - b2) % 2 == 0) cross12 = nil;
    else{
        ld x = (b2 - b1) / 2.0;
        ld y = -x - b1;
        x += 0.5; y += 0.5;

        if(x < 1 || x > n || y < 1 || y > m) cross12 = nil;
        else cross12 = {x, y};
    }

    // Calcular la interseccion entre r1 y r3
    pdd cross13;
    if(abs(b1 - b3) % 2 == 0) cross13 = nil;
    else{
        ld x = (b3 - b1) / 2.0;
        ld y = -x - b1;
        x += 0.5; y += 0.5;

        if(x < 1 || x > n || y < 1 || y > m) cross13 = nil;
        else cross13 = {x, y};
    }

    if(b2 == b3){
        cout<<"! "<<(int)cross12.first<<' '<<(int)cross12.second<<endl;
        return;
    }

    if(cross12 == nil){
        cout<<"! "<<(int)cross13.first<<' '<<(int)cross13.second<<endl;
        return;
    }

    if(cross13 == nil){
        cout<<"! "<<(int)cross12.first<<' '<<(int)cross12.second<<endl;
        return;
    }

    int leer;
    cout<<"? "<<(int)cross12.first<<' '<<(int)cross12.second<<endl;
    cin>>leer;
    if(!leer) cout<<"! "<<(int)cross12.first<<' '<<(int)cross12.second<<endl;
    else cout<<"! "<<(int)cross13.first<<' '<<(int)cross13.second<<endl;
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
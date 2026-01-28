#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solver() {
    int n;cin>>n;
    string in;cin>>in;
    int a = 0, b = 0, c = 0, d = 0;
    for(int i = 0; i < 4*n; i++){
        if(in[i] == 'A' && a < n)
            a++;
        else if(in[i] == 'B' && b < n)
            b++;
        else if(in[i] == 'C' && c < n)
            c++;
        else if(in[i] == 'D' && d < n)
            d++;
    }
    cout<<a+b+c+d<<endl;
}

int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        solver();
    }
    
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    double a, b, c, d;
    cin >> a >> b;
    c = 100 - a;
    d = 100 - b;
    double factor = d/c;
    cout << setprecision(9) << ((a/b)) * factor << endl;
}
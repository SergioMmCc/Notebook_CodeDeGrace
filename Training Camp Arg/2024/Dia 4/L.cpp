#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int a1, b1, c1, a2, b2, c2;
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;
    
    int sobran = 0;
    int faltan = 0;
    
    if (a1 > a2) 
        sobran += (a1 - a2) / 2;
    else if (a2 > a1) 
        faltan += a2 - a1;
    
    if (b1 > b2) 
        sobran += (b1 - b2) / 2;
    else if (b2 > b1) 
        faltan += b2 - b1;
    
    if (c1 > c2) 
        sobran += (c1 - c2) / 2;
    else if (c2 > c1) 
        faltan += c2 - c1;
        
    if(sobran >= faltan) cout << "Yes\n";
    else cout << "No\n";
 
    return 0;
}
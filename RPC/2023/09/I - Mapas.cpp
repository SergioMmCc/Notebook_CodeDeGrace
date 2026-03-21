#include <iostream>
#include <map>
using namespace std;

int main(){
    int n, q;
    string c, s1, s2;
    map <string, int> street_id;
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> c;
        street_id[c] = i;
    }
    while (q--) {
        cin >> s1 >> s2;
        cout << abs (street_id[s1] - street_id[s2]) - 1 << endl;
    }
    return 0;
}
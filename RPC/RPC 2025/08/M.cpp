#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define graph vector<vector<int>>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int sq, s, c;
    cin >> sq >> s >> c;

    int total = 2*sq;

    if(c > 1 && s){
        total += 3 + 2*s;
        c -= 2;
    }

    total += 3 * (c / 2);

    cout << total << endl;

    return 0;
}

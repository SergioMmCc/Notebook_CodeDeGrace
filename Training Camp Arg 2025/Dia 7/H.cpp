#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define graph vector<vector<int>>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> p(n);

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        p[i] = {x, y};
    }

    sort(p.begin(), p.end());

    cout << "YES" << endl;
    for(int i = 0; i < n - 1; i++)
        cout << p[i].first << " " << p[i].second << endl;

    return 0;
}

#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define graph vector<vector<int>>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, ans = 0;
    cin >> n >> m;

    priority_queue<int> q;

    for(int i = 0; i < min(n, m - 1); i++){
        int f;
        cin >> f;

        while(!q.empty() && q.top() >= m - i)
            q.pop();

        if (f < m)
            q.push(f - i);

        ans = max((int)q.size(), ans);
    }

    cout << ans << endl;

    return 0;
}

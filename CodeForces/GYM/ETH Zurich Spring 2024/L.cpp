#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    stack<int> a;
    stack<int> b;

    cin >> n;
    int aux;
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        a.push(aux);
    }
    int nans = 0;
    vector<string> ans;
    int next = 1;

    while (!a.empty())
    {
        nans++;

        if (!b.empty() && b.top() == next)
        {
            next++;
            b.pop();
            ans.push_back("B C");
            continue;
        }

        if (!a.empty() && a.top() == next)
        {
            next++;
            a.pop();
            ans.push_back("A C");
            continue;
        }

        ans.push_back("A B");
        b.push(a.top());
        a.pop();
    }

    if (!b.empty())
    {

        while (!b.empty())
        {
            nans++;
            if (b.top() == next)
            {
                next++;
                b.pop();
                ans.push_back("B C");
            }

            else
            {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << nans << endl;
    for (int i = 0; i < nans; i++)
    {
        cout << ans[i] << endl;
    }
}
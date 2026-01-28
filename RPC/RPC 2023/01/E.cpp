#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    deque<pii> terraces;
    long long totalLenght = 0;
    int height;
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> height;
        while (!terraces.empty() && height > terraces.back().second)
            terraces.pop_back();
        if (!terraces.empty() && height == terraces.back().second) {
            totalLenght += (i - terraces.back().first - 1);
            terraces.back().first = i;
        } else
            terraces.emplace_back(i, height);
    }
    cout << totalLenght << endl;
}
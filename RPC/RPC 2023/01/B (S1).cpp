#include <bits/stdc++.h>
using namespace std;
#define maxN 10000
vector<int> weights(maxN), visited(maxN, -1);
vector<vector<pair<int, int>>> graph(maxN, vector<pair<int, int>>());
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> Q;

int main (){
    int n, m, a, b, c;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
        Q.push({weights[i], {i, i}});
    }
    while (m--) {
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    while (!Q.empty()) {
        int w = Q.top().first, s = Q.top().second.first, v = Q.top().second.second;
        Q.pop();
        if (v == -1) {
            printf("%lld\n", w);
            return 0;
        }
        if (visited[v] == -2 || visited[v] == s)
            continue;
        visited[v] = visited[v] == -1 ? s : -2;
        if (s != v)
            Q.push({w + weights[v], {-1, -1}});
        for (auto& u : graph[v])
            Q.push({w + u.second, {s, u.first}});
    }
}
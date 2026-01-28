#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

typedef pair<int, int> pii;
vector<pii> coord;

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        coord.push_back(make_pair(x, y));
    }
    long double distance = 1e6;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            long double test;
            test = sqrt((coord[i].first - coord[j].first)*(coord[i].first - coord[j].first) + (coord[i].second - coord[j].second)*(coord[i].second - coord[j].second));
            if (test < distance)
                distance = test;
        }
    }
    cout << fixed << setprecision(5) << distance << "\n";
    
    return 0;
}

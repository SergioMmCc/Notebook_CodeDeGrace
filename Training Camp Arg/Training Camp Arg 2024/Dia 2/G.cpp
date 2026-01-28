#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef pair<int, int> pii;

struct comparator{
	bool operator() (pii a, pii b){
		return a.first < b.first;
	}
};

int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int n;
    long long answer = 0;
    cin>>n;
    vector<pii> cities(n);
    for (int i = 0; i < n; i++) {
        cin>>cities[i].first>>cities[i].second;
        answer += cities[i].second;
    }
    sort(cities.begin(), cities.end(), comparator());
    int maxBeauty = cities[0].first;
    for (auto& city : cities) {
        if (city.first > maxBeauty)
            answer += (city.first - maxBeauty);
        maxBeauty = max(maxBeauty, city.first + city.second);
    }
    cout<<answer<<endl;
}
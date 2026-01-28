#include<bits/stdc++.h>
using namespace std;
#define ednl '\n'
#define inf 2e9

struct Speedup {
	int start, final, vel, time;
	Speedup() : start(0), final(0), vel(0), time(0) {}
	Speedup(int _start, int _vel, int _time) : start(_start), final(_start + _vel * _time), vel(_vel), time(_time) {}
};

bool sortByStartAsc(const Speedup& a, const Speedup& b){ return a.start < b.start; }

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n, L; cin>>n>>L;
	vector<Speedup> v(n+1);
	v[0] = Speedup(0, 0, 0);
	for(int i=1; i<=n; i++){
		int start, vel, time;
		cin>>start>>vel>>time;
		v[i] = Speedup(start,vel,time);
	}
	sort(v.begin()+1, v.end(), sortByStartAsc);

	long double ans = inf;
	vector<long double> dp(n+1);
	dp[0] = 0;
	for(int i=1; i<=n; i++){
		long double mintime = inf;
		long double timeI = min((long double)v[i].time, (long double)(L-v[i].start) / v[i].vel);
		for(int j=0; j<i; j++){
			int dist = v[i].start - v[j].final;
			if(dist >= 0)
			mintime = min(mintime, dp[j] + dist + timeI);
		}
		dp[i] = mintime;
	}

	for(int i=0; i<=n; i++){
		int dist = max(0, L - v[i].final);
		ans = min(ans, dp[i] + dist);
	}
	cout<<fixed<<setprecision(10)<<ans<<endl;
}
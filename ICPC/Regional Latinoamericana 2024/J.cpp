#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

typedef pair<int, int> pii;
const double pi = 3.1415926;

bool comparator (const pii& a, const pii& b){
    return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    double ang;
    int n;
    cin>>ang>>n;
    vector<pii> a;
    for(int i = 0; i < n; i++){
        int x, h; cin>>x>>h;
        a.push_back({x, h});
    }

    double den = tan(ang * pi / 180.0);
    sort(a.begin(), a.end(), comparator);
    
    double ans = 0;
    double last = 0;
    for(int i = 0; i < n; i++){
        double x = (double)a[i].first, h = (double)a[i].second;
        double ca = h / den;
        double y = ca + x;
        if(y < last)continue;
        if(last > x){
            ans += y - last;
            last = y;
        }
        else{
            ans += ca;
            last = y;
        }
    }

    cout<<fixed<<setprecision(6)<<ans<<endl;
}
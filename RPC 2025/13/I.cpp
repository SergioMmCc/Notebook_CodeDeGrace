#include <bits/stdc++.h>
#define p first
#define h second
using namespace std;
long double DELTA=0.00000001;
int n;
long double w;

vector<pair<long double, long double>> mill;

bool op(long double x){
    long double cant=0;
    for(int i=0; i<n; i++){
        cant += max(0.0l, (x - mill[i].h)) * mill[i].p;
    }
    //cout<<x<<" ---> "<<cant<<" >= "<<w<<"  \n";
    return cant >= w;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>w;
    mill.resize(n);
    
    long double maxx=0;
    for(int i=0; i<n; i++){
        cin>>mill[i].p>>mill[i].h;
        mill[i].h *= 2;
    }
    
    
    // BIN
    long double l=0, r=1e10;
    while(r-l > DELTA){
        long double mid = (l+r)/2;
        
        if(op(mid)){
            r = mid;
        }else{
            l = mid + DELTA;
        }
        //cout<<l<<", "<<r<<" | \n";
    }
    cout<<fixed<<setprecision(7)<<l<<"\n";
    return 0;
}
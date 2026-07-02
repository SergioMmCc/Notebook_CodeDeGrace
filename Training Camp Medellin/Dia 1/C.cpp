#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pqueue priority_queue
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<pll> vll;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

bool pointInBox(ld x, ld y, ld x0, ld y0, ld x1, ld y1){
    return min(x0, x1) <= x && x <= max(x0, x1) && 
           min(y0, y1) <= y && y <= max(y0, y1);
}

int direction(int x1, int y1, int x2, int y2, int x3, int y3){
    return (x3 - x1) * (y2 - y1) - (y3 - y1) * (x2 - x1);
}

bool segmentIntersection(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
    int d1 = direction(x3, y3, x4, y4, x1, y1);
    int d2 = direction(x3, y3, x4, y4, x2, y2);
    int d3 = direction(x1, y1, x2, y2, x3, y3);
    int d4 = direction(x1, y1, x2, y2, x4, y4);
    
    bool b1 = (d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0);
    bool b2 = (d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0);
    if(b1 && b2) return 1;

    if(d1 == 0 && pointInBox(x1, y1, x3, y3, x4, y4)) return 1;
    if(d2 == 0 && pointInBox(x2, y2, x3, y3, x4, y4)) return 1;
    if(d3 == 0 && pointInBox(x3, y3, x1, y1, x2, y2)) return 1;
    if(d4 == 0 && pointInBox(x4, y4, x1, y1, x2, y2)) return 1;

    return 0;
}

void rotarSQ(vii& a){
    int xl = min(min(a[0].fi, a[1].fi), min(a[2].fi, a[3].fi));
    int xr = max(max(a[0].fi, a[1].fi), max(a[2].fi, a[3].fi));

    int yd = min(min(a[0].se, a[1].se), min(a[2].se, a[3].se));
    int yu = max(max(a[0].se, a[1].se), max(a[2].se, a[3].se));

    a = {{xl, yd}, {xl, yu}, {xr, yu}, {xr,yd}};
}

void rotarRombo(vii& a){
    int xl = min(min(a[0].fi, a[1].fi), min(a[2].fi, a[3].fi));
    int xr = max(max(a[0].fi, a[1].fi), max(a[2].fi, a[3].fi));
    int xm;
    for(int i = 0; i < 4; i++) if(a[i].fi != xl && a[i].fi != xr) xm = a[i].fi;

    int yd = min(min(a[0].se, a[1].se), min(a[2].se, a[3].se));
    int yu = max(max(a[0].se, a[1].se), max(a[2].se, a[3].se));
    int ym;
    for(int i = 0; i < 4; i++) if(a[i].se != yd && a[i].se != yu) ym = a[i].se;

    a = {{xm, yd}, {xl, ym}, {xm, yu}, {xr, ym}};
}

void solver(){
    vii a(4), b(4);
    for(int i = 0; i < 4; i++) cin>>a[i].fi>>a[i].se;
    for(int i = 0; i < 4; i++) cin>>b[i].fi>>b[i].se;

    // Ordenar
    rotarSQ(a);
    rotarRombo(b);

    // for(int i = 0; i < 4; i++) cout<<a[i].fi<<' '<<a[i].se<<'\t'; cout<<endl;
    // for(int i = 0; i < 4; i++) cout<<b[i].fi<<' '<<b[i].se<<'\t'; cout<<endl;


    // Probar esquina de rombo dentro del cuadrado
    for(int i = 0; i < 4; i++){
        int x = b[i].fi, y = b[i].se;
        if(x >= a[0].fi && x <= a[2].fi && y >= a[0].se && y <= a[2].se){
            cout<<"Yes"<<endl;
            return;
        }
    }

    // Probar esquina de cuadrado dentro del rombo
    int r01 = b[0].fi + b[0].se, r23 = b[2].fi + b[2].se, r12 = b[1].se - b[1].fi, r30 = b[3].se - b[3].fi;
    for(int i = 0; i < 4; i++){
        int x = a[i].fi, y = a[i].se;
        int sum = x+y, take = y - x;
        if(sum >= r01 && sum <= r23 && take >= r30 && take <= r12){
            cout<<"Yes"<<endl;
            return;
        }
    }

    // Probar si se intersecta en alguna recta
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(segmentIntersection(a[i].fi, a[i].se, a[(i+1)%4].fi, a[(i+1)%4].se, b[j].fi, b[j].se, b[(j+1)%4].fi, b[(j+1)%4].se)){
                cout<<"Yes"<<endl;
                return;
            }
        }
    }

    cout<<"No"<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
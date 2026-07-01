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

/*
  Retorna si el punto (x, y) esta dentro (o en el borde) de la caja definida por los puntos
  (x0, y0) y (x1, y1)
*/
bool pointInBox(ld x, ld y, ld x0, ld y0, ld x1, ld y1){
    return min(x0, x1) <= x && x <= max(x0, x1) && 
           min(y0, y1) <= y && y <= max(y0, y1);
}

/*
  Retorna el producto cruz del segmento que va desde {x1, y1} hasta {x3, y3} con el segmento que
  va de {x1, y1} hasta {x2, y2}.
*/
int direction(int x1, int y1, int x2, int y2, int x3, int y3){
    return (x3 - x1) * (y2 - y1) - (y3 - y1) * (x2 - x1);
}

/*
  Como saber si dos segmentos de recta [{x1, y1}, {x2, y2}] y [{x3, y3}, {x4, y4}] se intersectan
  (no halla el punto exacto de interseccion).
  Tambien funciona para segmentos paralelos, donde en caso de que compartan puntos infinitos, se
  toma como que si se intersectan.
*/
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

void solver(){
    int x1, y1, x2, y2, x3, y3, x4, y4; cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    cout<<segmentIntersection(x1, y1, x2, y2, x3, y3, x4, y4)<<endl;
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
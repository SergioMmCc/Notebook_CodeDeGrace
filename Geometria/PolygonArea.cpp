#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back

// Estructura Point con campos "x" y "y" y operaciones entre puntos
struct Point {
    ll x, y;

    Point(ll x_, ll y_): x(x_), y(y_) {}

    bool operator < (const Point& p) const {
        return tie(x, y) < tie(p.x, p.y);
    }

    Point operator - (const Point& p) const {
        return Point(x - p.x, y - p.y);
    }

    ll cross (const Point & p) const {
        return x * p.y - y * p.x;
    }

    ll cross (const Point & p, const Point & q) const {
        return (p - *this).cross(q - *this);
    }

    ll half () const {
        return ll(y < 0 || (y == 0 && x < 0));
    }
};

//P es un polígono ordenado anticlockwise.
//Si es clockwise, retorna el area negativa.
//P[0] != P[n-1]
ld PolygonArea(const vector<Point> &p){
    ld r = 0.0;
    for (ll i=0; i<p.size(); ++i){
        ll j = (i+1) % p.size();
        r += p[i].x*p[j].y - p[j].x*p[i].y;
    }
    return r/2.0;
}
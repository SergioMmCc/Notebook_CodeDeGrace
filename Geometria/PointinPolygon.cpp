#include "../template.h"

struct P {
    ll x, y;

    P operator-(P o) {
        return {x - o.x, y - o.y};
    }
};

using i128 = __int128_t;

i128 cross(P a, P b) {
    return (i128)a.x * b.y - (i128)a.y * b.x;
}

bool onSegment(P a, P b, P c) {
    if(cross(b - a, c - a) != 0) return false;

    return min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) &&
           min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
}

string pointInPolygon(vector<P>& poly, P p) {
    int n = poly.size();
    bool inside = false;

    for0(i, n) {
        P a = poly[i];
        P b = poly[(i + 1) % n];

        if(onSegment(a, b, p))
            return "BOUNDARY";

        if((a.y > p.y) != (b.y > p.y)) {
            i128 cr = cross(b - a, p - a);
            if((b.y > a.y && cr > 0) || 
               (b.y < a.y && cr < 0)) {
                inside = !inside;
            }
        }
    }

    return inside ? "INSIDE" : "OUTSIDE";
}
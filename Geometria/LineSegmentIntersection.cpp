#include "../../template.h"

struct Point {
    int x, y;

    Point operator-(const Point& a) const {
        return {x - a.x, y - a.y};
    }

    long long cross(const Point& other) const {
        return (1LL * x * other.y) - (1LL * y * other.x);
    }
};

struct Segment {
    Point p1, p2;


    /**
     * Verifica si un punto 'x' que es colineal con el segmento (a, b) 
     * se encuentra físicamente dentro del rectángulo delimitado por los extremos del segmento.
     */
    bool PointOnSegment(const Point& p) const {
        return min(p1.x, p2.x) <= p.x && p.x <= max(p1.x, p2.x) &&
               min(p1.y, p2.y) <= p.y && p.y <= max(p1.y, p2.y);
    }
};

long long cruz(Point p1, Point p2) {
    return p1.cross(p2);
}

int sign(long long x) {
    return (x > 0) - (x < 0);
}

/**
 * Determina la orientación del triplete de puntos (a, b, c):
 *   0  -> Los puntos son colineales.
 *   1  -> Giro en sentido antihorario (Counter-Clockwise).
 *  -1  -> Giro en sentido horario (Clockwise).
 */
int orientation(Point a, Point b, Point c) {
    return sign(cruz(c - a, b - a));
}



void solver() {
    int n;
    cin >> n;
    Point p1, p2, p3, p4;
    while (n--) {
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
        Segment s1{p1, p2}, s2{p3, p4};
        
        // Evalúa la orientación relativa de los puntos de un segmento respecto al otro.
        int a = orientation(p1, p2, p3);
        int b = orientation(p1, p2, p4);
        int c = orientation(p3, p4, p1);
        int d = orientation(p3, p4, p2);

        // Verifica si los segmentos se intersectan:
        // 1. Intersección general: los extremos del segmento 2 quedan a lados opuestos del segmento 1 (a != b) 
        //    y viceversa (c != d).
        // 2. Casos especiales (colinealidad): un extremo de un segmento descansa sobre el otro segmento.
        if ((a != b && c != d) ||
            (a == 0 && s1.PointOnSegment(p3)) ||
            (b == 0 && s1.PointOnSegment(p4)) ||
            (c == 0 && s2.PointOnSegment(p1)) ||
            (d == 0 && s2.PointOnSegment(p2))) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
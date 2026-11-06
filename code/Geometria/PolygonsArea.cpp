#include "../template.h"

struct Point {
    double x, y;

    double cross(const Point& other) const {
        return x * other.y - y * other.x;
    }
};

/**
 * Calcula el área de un polígono simple ordenado mediante la fórmula de 
 * Gauss / Shoelace:
 *                    | n-1                     
 *    Área(P) = 1/2 * | SUM (Pi x P((i+1)%n)    
 *                    | i=0                     
 */
double polygonArea(vector<Point>& poly) {
    int n = poly.size();
    if (n < 3) return 0.0; // Un polígono debe tener al menos 3 vértices

    double cross_sum = 0.0;
    for (int i = 0; i < n; ++i) {
        cross_sum += poly[i].cross(poly[(i + 1) % n]);
    }
    // abs porque dependiendo si esta ordenado clockwise o anticlockwise 
    // retornaria positivo o negativo
    return abs(cross_sum) / 2.0;
}

#include "../template.h"

///////////////////////////////////////////////////
// TEMPLATE DE GEOMETRIA 2D (C++17)
//
//  1. Basicos ............ EPS, sgn, Point/Vector, distancias, orient
//  2. Rectas y segmentos .. proyeccion, distancias, interseccion de rectas y segmentos, struct Segment
//  3. Circulos ............ struct Circle, intersecciones, tangentes, areas, circulo minimo
//  4. Triangulos .......... struct Triangle, puntos notables, colision de triangulos
//  5. Poligonos ........... area, punto en poligono, convex hull, semiplanos, Minkowski, etc.
//  6. Esfera .............. distancia sobre una esfera (haversine)
//
// Convencion: positivo = sentido antihorario (CCW). Funciones con "template<T>" sirven con
// ld (flotante) y ll (entero). Las demas trabajan solo con pt (= Point<ld>).
//////////////////////////////////////////////////


////////////////////////////////////////////////////
// 1. BASICOS
///////////////////////////////////////////////////

const ld PI = acosl(-1);

// Tolerancia: 1e-9 para flotantes, 0 para enteros (asi el mismo codigo sirve para ambos)
template<typename T>
constexpr T EPS = is_floating_point_v<T> ? 1e-9 : 0;

// Signo de x respetando la tolerancia: devuelve 1, 0 o -1
template<typename T>
int sgn(T x) {
    return (x > EPS<T>) - (x < -EPS<T>);
}

template<typename T = ld>
struct Point {
    T x, y;

    Point() : x(0), y(0) {}
    Point(T _x, T _y) : x(_x), y(_y) {}

    // Operadores aritmeticos
    Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
    Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
    Point operator*(T d) const { return Point(x * d, y * d); }
    Point operator/(T d) const { return Point(x / d, y / d); }

    Point& operator+=(const Point& p) { x += p.x; y += p.y; return *this; }
    Point& operator-=(const Point& p) { x -= p.x; y -= p.y; return *this; }
    Point& operator*=(T d) { x *= d; y *= d; return *this; }
    Point& operator/=(T d) { x /= d; y /= d; return *this; }

    // Orden EXACTO (por x y luego y): seguro para sort, set y map
    bool operator<(const Point& p) const { return tie(x, y) < tie(p.x, p.y); }

    // Igualdad con tolerancia (EPS) en flotantes
    bool operator==(const Point& p) const { return sgn(x - p.x) == 0 && sgn(y - p.y) == 0; }
    bool operator!=(const Point& p) const { return !(*this == p); }

    // Producto punto: a . b = |a||b|cos(theta)      (atajo: a * b)
    T dot(const Point& p) const { return x * p.x + y * p.y; }
    T operator*(const Point& p) const { return dot(p); }

    // Producto cruz 2D: a x b = |a||b|sin(theta)    (atajo: a % b)
    T cross(const Point& p) const { return x * p.y - y * p.x; }
    T operator%(const Point& p) const { return cross(p); }

    // Norma al cuadrado (exacta en enteros) y longitud
    T sq() const { return x * x + y * y; }
    ld len() const { return sqrtl((ld)sq()); }

    // Vector unitario (misma direccion, largo 1)
    Point<ld> unit() const {
        ld l = len();
        return Point<ld>(x / l, y / l);
    }

    // Vector perpendicular (rotado 90 grados antihorario)
    Point perp() const { return Point(-y, x); }

    // Angulo polar del vector, en [-PI, PI]
    ld angle() const { return atan2l(y, x); }

    // Rotacion antihoraria por theta radianes
    Point<ld> rotate(ld theta) const {
        return Point<ld>(x * cosl(theta) - y * sinl(theta),
                         x * sinl(theta) + y * cosl(theta));
    }

    friend istream& operator>>(istream& is, Point& p) { return is >> p.x >> p.y; }
    friend ostream& operator<<(ostream& os, const Point& p) { return os << p.x << " " << p.y; }
};

template<typename T = ld>
using Vector = Point<T>;

using pt = Point<ld>;
using ptll = Point<ll>;
using vec = Vector<ld>;
using vecll = Vector<ll>;

// Distancia al cuadrado entre dos puntos (exacta con enteros)
template<typename T>
T dist2(const Point<T>& a, const Point<T>& b) {
    return (a - b).sq();
}

// Distancia euclidiana entre dos puntos
template<typename T>
ld dist(const Point<T>& a, const Point<T>& b) {
    return (a - b).len();
}

// Orientacion de c respecto a la recta dirigida a->b: (b - a) x (c - a)
//   > 0: c a la izquierda (giro CCW)   < 0: a la derecha (CW)   = 0: colineales
template<typename T>
T orient(const Point<T>& a, const Point<T>& b, const Point<T>& c) {
    return (b - a).cross(c - a);
}

// Angulo entre dos vectores, en [0, PI]
ld angle_between(const pt& a, const pt& b) {
    return atan2l(fabsl(a.cross(b)), a.dot(b));
}

// acos protegido contra errores numericos (argumento fuera de [-1, 1])
ld safe_acos(ld x) {
    return acosl(max((ld)-1, min((ld)1, x)));
}


///////////////////////////////////////////////
// 2. RECTAS Y SEGMENTOS
//    Un segmento se representa con Segment (extremos a y b). Cuando una funcion habla de una
//    RECTA tambien recibe un Segment: la recta infinita que pasa por sus dos extremos.
//////////////////////////////////////////////

// Declaraciones adelantadas (las definiciones estan mas abajo)
template<typename T> struct Segment;
template<typename T> bool on_segment(const Point<T>& p, const Segment<T>& s);
template<typename T> bool segments_intersect(const Segment<T>& s, const Segment<T>& t);
template<typename T> vector<pt> segment_intersection_points(const Segment<T>& s, const Segment<T>& t);
template<typename T> ld dist_point_segment(const Point<T>& p, const Segment<T>& s);

template<typename T = ld>
struct Segment {
    Point<T> a, b;   // extremo inicial y final

    Segment() : a(), b() {}
    Segment(Point<T> _a, Point<T> _b) : a(_a), b(_b) {}
    Segment(T x1, T y1, T x2, T y2) : a(x1, y1), b(x2, y2) {}

    // Vector direccion a -> b
    Vector<T> dir() const { return b - a; }

    // Longitud (y su cuadrado, exacto con enteros)
    ld length() const { return dist(a, b); }
    T length2() const { return dist2(a, b); }

    // Punto medio
    Point<ld> midpoint() const {
        return Point<ld>((ld)(a.x + b.x) / 2, (ld)(a.y + b.y) / 2);
    }

    // Lado en que cae p respecto a la recta a->b: 1 izquierda, -1 derecha, 0 sobre la recta
    int side(const Point<T>& p) const { return sgn(orient(a, b, p)); }

    // Atajos a las funciones de abajo (se pueden usar de cualquiera de las dos formas)
    bool contains(const Point<T>& p) const { return on_segment(p, *this); }
    bool intersects(const Segment& s) const { return segments_intersect(*this, s); }
    vector<pt> intersection_points(const Segment& s) const { return segment_intersection_points(*this, s); }
    ld dist_to(const Point<T>& p) const { return dist_point_segment(p, *this); }

    friend istream& operator>>(istream& is, Segment& s) { return is >> s.a >> s.b; }
    friend ostream& operator<<(ostream& os, const Segment& s) { return os << "[" << s.a << "] -> [" << s.b << "]"; }
};

using seg = Segment<ld>;
using segll = Segment<ll>;

// Proyeccion del vector v sobre el vector u
pt proj_vec(const pt& v, const pt& u) {
    return u * (v.dot(u) / u.sq());
}

// Proyeccion del punto p sobre la recta l (pie de la perpendicular)
pt proj_point_line(const pt& p, const seg& l) {
    pt ab = l.dir();
    return l.a + ab * ((p - l.a).dot(ab) / ab.sq());
}

// Reflexion (simetrico) del punto p respecto a la recta l
pt reflect_point_line(const pt& p, const seg& l) {
    return proj_point_line(p, l) * 2 - p;
}

// Distancia de p a la recta infinita l
ld dist_point_line(const pt& p, const seg& l) {
    return fabsl(orient(l.a, l.b, p)) / l.length();
}

// Distancia de p al segmento cerrado s (funciona aunque s sea un punto)
template<typename T>
ld dist_point_segment(const Point<T>& p, const Segment<T>& s) {
    pt q(p.x, p.y), a(s.a.x, s.a.y), b(s.b.x, s.b.y);
    pt ab = b - a;
    ld t = ab.dot(q - a);
    if (t <= 0) return dist(q, a);              // el punto mas cercano es el extremo a
    if (t >= ab.sq()) return dist(q, b);        // el punto mas cercano es el extremo b
    return dist_point_line(q, seg(a, b));       // cae dentro del segmento
}

// Verifica si p pertenece al segmento cerrado s (colineal y entre los extremos)
template<typename T>
bool on_segment(const Point<T>& p, const Segment<T>& s) {
    return sgn(orient(s.a, s.b, p)) == 0 && sgn((s.a - p).dot(s.b - p)) <= 0;
}

// Verifica si los segmentos cerrados s y t tienen al menos un punto en comun
template<typename T>
bool segments_intersect(const Segment<T>& s, const Segment<T>& t) {
    int o1 = sgn(orient(s.a, s.b, t.a));
    int o2 = sgn(orient(s.a, s.b, t.b));
    int o3 = sgn(orient(t.a, t.b, s.a));
    int o4 = sgn(orient(t.a, t.b, s.b));

    // Cruce propio: los extremos de cada segmento quedan a lados opuestos del otro
    if (o1 * o2 < 0 && o3 * o4 < 0) return true;

    // Casos de borde: un extremo toca al otro segmento (incluye colineales)
    return on_segment(t.a, s) || on_segment(t.b, s) ||
           on_segment(s.a, t) || on_segment(s.b, t);
}

// Puntos de interseccion de los segmentos s y t:
//   0 puntos (no se tocan), 1 punto, o 2 puntos (segmentos colineales solapados: extremos del solape)
template<typename T>
vector<pt> segment_intersection_points(const Segment<T>& s, const Segment<T>& t) {
    pt a(s.a.x, s.a.y), b(s.b.x, s.b.y), c(t.a.x, t.a.y), d(t.b.x, t.b.y);
    seg ab(a, b), cd(c, d);

    ld oa = orient(c, d, a), ob = orient(c, d, b);
    ld oc = orient(a, b, c), od = orient(a, b, d);

    // Cruce propio: un unico punto, se calcula por proporcion de las distancias con signo
    if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0) {
        return {(a * ob - b * oa) / (ob - oa)};
    }

    // Caso degenerado: recolectar extremos que caen sobre el otro segmento
    vector<pt> res;
    if (on_segment(c, ab)) res.push_back(c);
    if (on_segment(d, ab)) res.push_back(d);
    if (on_segment(a, cd)) res.push_back(a);
    if (on_segment(b, cd)) res.push_back(b);
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    return res;
}

// Interseccion de las RECTAS l1 y l2. Devuelve false si son paralelas; si no, guarda el punto en res
bool intersect_lines(const seg& l1, const seg& l2, pt& res) {
    ld cp = l1.dir().cross(l2.dir());
    if (sgn(cp) == 0) return false;
    ld t = (l2.a - l1.a).cross(l2.dir()) / cp;
    res = l1.a + l1.dir() * t;
    return true;
}

// Distancia minima entre dos segmentos (0 si se tocan)
ld dist_segment_segment(const seg& s, const seg& t) {
    if (s.intersects(t)) return 0;
    // Si no se cruzan, la distancia minima siempre ocurre en algun extremo
    return min(min(s.dist_to(t.a), s.dist_to(t.b)),
               min(t.dist_to(s.a), t.dist_to(s.b)));
}

//////////////////////////////////////////////
// 3. CIRCULOS
/////////////////////////////////////////////

struct Circle {
    pt o;   // centro
    ld r;   // radio

    Circle() : o(pt(0, 0)), r(0) {}
    Circle(pt _o, ld _r) : o(_o), r(_r) {}
    Circle(ld x, ld y, ld _r) : o(pt(x, y)), r(_r) {}

    // Posicion de un punto: 1 (dentro), 0 (en el borde), -1 (fuera)
    int contains(const pt& p) const { return sgn(r - dist(o, p)); }

    ld area() const { return PI * r * r; }                                  // pi * r^2
    ld perimeter() const { return 2 * PI * r; }                             // 2 * pi * r
    ld sector_area(ld theta) const { return 0.5 * r * r * theta; }          // sector de angulo theta
    ld segment_area(ld theta) const { return 0.5 * r * r * (theta - sinl(theta)); } // segmento circular
};

// Interseccion RECTA l - circulo: devuelve 0, 1 o 2 puntos
vector<pt> intersect_circle_line(const Circle& c, const seg& l) {
    pt p = proj_point_line(c.o, l);             // pie de la perpendicular desde el centro
    ld h2 = c.r * c.r - (p - c.o).sq();         // (semicuerda)^2
    if (sgn(h2) < 0) return {};                 // la recta no toca el circulo
    if (sgn(h2) == 0) return {p};               // tangente
    pt u = l.dir().unit() * sqrtl(h2);
    return {p - u, p + u};
}

// Interseccion SEGMENTO - circulo: devuelve 0, 1 o 2 puntos (solo los que caen dentro del segmento)
vector<pt> intersect_circle_segment(const Circle& c, const seg& s) {
    vector<pt> res;
    for (auto& p : intersect_circle_line(c, s)) {
        if (s.contains(p)) res.push_back(p);
    }
    return res;
}

// Interseccion circulo - circulo: devuelve 0, 1 o 2 puntos (vacio si son concentricos)
vector<pt> intersect_circle_circle(const Circle& c1, const Circle& c2) {
    pt d = c2.o - c1.o;
    ld D = d.len();
    if (sgn(D) == 0) return {};                             // concentricos
    if (sgn(D - c1.r - c2.r) > 0) return {};                // muy lejos
    if (sgn(D - fabsl(c1.r - c2.r)) < 0) return {};         // uno dentro del otro

    ld a = (c1.r * c1.r - c2.r * c2.r + D * D) / (2 * D);   // distancia de c1.o a la cuerda comun
    ld h2 = c1.r * c1.r - a * a;
    pt mid = c1.o + d * (a / D);                            // punto medio de la cuerda comun
    if (sgn(h2) <= 0) return {mid};                         // tangentes

    pt off = d.perp() / D * sqrtl(h2);
    return {mid + off, mid - off};
}

// Area de la interseccion (lente) de dos circulos
ld circle_circle_intersection_area(const Circle& c1, const Circle& c2) {
    ld d = dist(c1.o, c2.o);
    if (d >= c1.r + c2.r) return 0;                         // disjuntos
    if (d <= fabsl(c1.r - c2.r)) {                          // uno contiene al otro
        ld r = min(c1.r, c2.r);
        return PI * r * r;
    }
    ld a = safe_acos((d * d + c1.r * c1.r - c2.r * c2.r) / (2 * d * c1.r));  // semiangulo en c1
    ld b = safe_acos((d * d + c2.r * c2.r - c1.r * c1.r) / (2 * d * c2.r));  // semiangulo en c2
    return c1.r * c1.r * (a - sinl(2 * a) / 2) + c2.r * c2.r * (b - sinl(2 * b) / 2);
}

// Tangentes comunes a dos circulos. Cada tangente es un segmento {a = punto de contacto en c1, b = punto de contacto en c2}.
//   inner = false: tangentes EXTERNAS (hasta 2)      inner = true: tangentes INTERNAS (hasta 2)
vector<seg> tangents_circle_circle(const Circle& c1, const Circle& c2, bool inner = false) {
    ld r2 = inner ? -c2.r : c2.r;       // truco: radio negativo da las tangentes internas
    pt d = c2.o - c1.o;
    ld dr = c1.r - r2;
    ld d2 = d.sq();
    ld h2 = d2 - dr * dr;
    if (sgn(d2) == 0 || sgn(h2) < 0) return {};

    vector<seg> res;
    for (ld s : {-1, 1}) {
        pt v = (d * dr + d.perp() * sqrtl(max((ld)0, h2)) * s) / d2;
        res.push_back(seg(c1.o + v * c1.r, c2.o + v * r2));
    }
    if (sgn(h2) == 0) res.pop_back();   // las dos tangentes coinciden
    return res;
}

// Puntos de contacto de las tangentes desde un punto p al circulo c (0 si p esta dentro, 1 si en el borde, 2 si fuera)
vector<pt> tangents_point_circle(const pt& p, const Circle& c) {
    vector<pt> res;
    for (auto& t : tangents_circle_circle(Circle(p, 0), c)) res.push_back(t.b);
    return res;
}

// Circulo circunscrito del triangulo abc (pasa por los 3 vertices). Requiere puntos no colineales
Circle circumcircle(const pt& a, const pt& b, const pt& c) {
    pt u = b - a, v = c - a;
    pt center = a + (u * v.sq() - v * u.sq()).perp() / u.cross(v) / 2;
    return Circle(center, dist(center, a));
}

// Circulo inscrito del triangulo abc (tangente a los 3 lados)
Circle incircle(const pt& a, const pt& b, const pt& c) {
    ld la = dist(b, c), lb = dist(a, c), lc = dist(a, b);   // longitud del lado opuesto a cada vertice
    ld perimeter = la + lb + lc;
    pt center = (a * la + b * lb + c * lc) / perimeter;     // promedio ponderado por lados
    ld radius = fabsl(orient(a, b, c)) / perimeter;         // r = area / semiperimetro
    return Circle(center, radius);
}

// Area de la interseccion entre el circulo c y un poligono simple (cualquier orientacion)
ld circle_polygon_intersection_area(const Circle& c, const vector<pt>& poly) {
    // Angulo orientado entre dos vectores
    auto arg = [](const pt& p, const pt& q) { return atan2l(p.cross(q), p.dot(q)); };

    // Area con signo de (triangulo O-p-q) ∩ circulo centrado en el origen
    auto tri = [&](pt p, pt q) -> ld {
        ld half_r2 = c.r * c.r / 2;
        pt d = q - p;
        if (sgn(d.sq()) == 0) return 0;                     // arista degenerada

        // Se resuelve |p + d*t|^2 = r^2 para hallar donde la arista entra/sale del circulo
        ld a = d.dot(p) / d.sq();
        ld b = (p.sq() - c.r * c.r) / d.sq();
        ld det = a * a - b;
        if (det <= 0) return arg(p, q) * half_r2;           // la recta no corta: solo sector

        ld s = max((ld)0, -a - sqrtl(det));                 // parametro de entrada
        ld t = min((ld)1, -a + sqrtl(det));                 // parametro de salida
        if (t < 0 || 1 <= s) return arg(p, q) * half_r2;    // corta fuera del segmento: solo sector

        pt u = p + d * s, v = p + d * t;                    // tramo interior = triangulo; extremos = sectores
        return arg(p, u) * half_r2 + u.cross(v) / 2 + arg(v, q) * half_r2;
    };

    ld total = 0;
    int n = poly.size();
    for (int i = 0; i < n; i++) {
        total += tri(poly[i] - c.o, poly[(i + 1) % n] - c.o);
    }
    return fabsl(total);
}

// Circulo minimo que contiene todos los puntos (Welzl iterativo, esperado O(n))
Circle min_enclosing_circle(vector<pt> ps) {
    mt19937 rng(712367);
    shuffle(ps.begin(), ps.end(), rng);     // el orden aleatorio garantiza el O(n) esperado

    const ld slack = 1 + 1e-8;              // tolerancia relativa
    Circle c(ps[0], 0);
    int n = ps.size();
    for (int i = 0; i < n; i++) {
        if (dist(c.o, ps[i]) <= c.r * slack) continue;
        c = Circle(ps[i], 0);                                       // ps[i] debe estar en el borde
        for (int j = 0; j < i; j++) {
            if (dist(c.o, ps[j]) <= c.r * slack) continue;
            c = Circle((ps[i] + ps[j]) / 2, dist(ps[i], ps[j]) / 2); // ps[i], ps[j] en el borde
            for (int k = 0; k < j; k++) {
                if (dist(c.o, ps[k]) <= c.r * slack) continue;
                c = circumcircle(ps[i], ps[j], ps[k]);               // los tres en el borde
            }
        }
    }
    return c;
}


/////////////////////////////////////////////
// 4. TRIANGULOS
////////////////////////////////////////////

template<typename T = ld>
struct Triangle {
    Point<T> a, b, c;

    Triangle() : a(), b(), c() {}
    Triangle(Point<T> _a, Point<T> _b, Point<T> _c) : a(_a), b(_b), c(_c) {}

    // Area con signo: > 0 si a->b->c es antihorario, < 0 si es horario
    ld signed_area() const { return (ld)orient(a, b, c) / 2; }

    // Area (siempre >= 0)
    ld area() const { return fabsl(signed_area()); }

    // Perimetro
    ld perimeter() const { return dist(a, b) + dist(b, c) + dist(c, a); }

    // Posicion del punto p: 1 (interior estricto), 0 (en el borde o vertice), -1 (exterior)
    int contains(const Point<T>& p) const {
        int s1 = sgn(orient(a, b, p));
        int s2 = sgn(orient(b, c, p));
        int s3 = sgn(orient(c, a, p));

        bool has_neg = (s1 < 0 || s2 < 0 || s3 < 0);
        bool has_pos = (s1 > 0 || s2 > 0 || s3 > 0);
        if (has_neg && has_pos) return -1;              // lados distintos de alguna arista: afuera
        if (s1 == 0 || s2 == 0 || s3 == 0) return 0;    // sobre una arista
        return 1;
    }

    // Baricentro: promedio de los vertices
    Point<ld> centroid() const {
        return Point<ld>((ld)(a.x + b.x + c.x) / 3, (ld)(a.y + b.y + c.y) / 3);
    }

    // Circuncentro: centro del circulo que pasa por los 3 vertices
    Point<ld> circumcenter() const {
        return circumcircle(pt(a.x, a.y), pt(b.x, b.y), pt(c.x, c.y)).o;
    }

    // Incentro: centro del circulo inscrito
    Point<ld> incenter() const {
        return incircle(pt(a.x, a.y), pt(b.x, b.y), pt(c.x, c.y)).o;
    }

    // Ortocentro: interseccion de las alturas (recta de Euler: H = 3G - 2O)
    Point<ld> orthocenter() const {
        return centroid() * 3 - circumcenter() * 2;
    }

    friend istream& operator>>(istream& is, Triangle& t) { return is >> t.a >> t.b >> t.c; }
    friend ostream& operator<<(ostream& os, const Triangle& t) {
        return os << "[" << t.a << "] [" << t.b << "] [" << t.c << "]";
    }
};

using tri = Triangle<ld>;
using trill = Triangle<ll>;

// Verifica si dos triangulos comparten al menos un punto (choque de bordes o uno dentro del otro)
template<typename T>
bool triangles_intersect(const Triangle<T>& t1, const Triangle<T>& t2) {
    Point<T> p1[3] = {t1.a, t1.b, t1.c};
    Point<T> p2[3] = {t2.a, t2.b, t2.c};

    // 1. Alguna arista de t1 toca alguna arista de t2 (9 pares)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Segment<T> e1(p1[i], p1[(i + 1) % 3]);
            Segment<T> e2(p2[j], p2[(j + 1) % 3]);
            if (segments_intersect(e1, e2)) return true;
        }
    }

    // 2. Sin tocarse los bordes, uno puede estar completamente dentro del otro
    return t1.contains(t2.a) >= 0 || t2.contains(t1.a) >= 0;
}


//////////////////////////////////////////////
// 5. POLIGONOS
//    (un poligono es un vector<Point<T>> con los vertices en orden)
////////////////////////////////////////////

// DOBLE del area con signo (formula del cordon / shoelace). > 0 si el poligono es CCW.
// Se devuelve el doble para que sea exacto con enteros: area = abs(polygon_area2(p)) / 2
template<typename T>
T polygon_area2(const vector<Point<T>>& poly) {
    T s = 0;
    int n = poly.size();
    for (int i = 0; i < n; i++) s += poly[i].cross(poly[(i + 1) % n]);
    return s;
}

// Centroide (centro de masa) de un poligono simple
pt polygon_centroid(const vector<pt>& poly) {
    pt c;
    ld area6 = 0;   // 3 * (doble del area)
    int n = poly.size();
    for (int i = 0; i < n; i++) {
        pt a = poly[i], b = poly[(i + 1) % n];
        ld w = a.cross(b);
        c = c + (a + b) * w;
        area6 += w;
    }
    return c / (3 * area6);
}

// Posicion de p respecto a un poligono simple: 1 (dentro), 0 (en el borde), -1 (fuera). O(n)
template<typename T>
int point_in_polygon(const Point<T>& p, const vector<Point<T>>& poly) {
    int n = poly.size();
    bool inside = false;
    for (int i = 0; i < n; i++) {
        Segment<T> edge(poly[i], poly[(i + 1) % n]);
        if (edge.contains(p)) return 0;
        // Rayo horizontal desde p: se cuenta cada arista que cruza hacia la derecha de p
        if (((p.y < edge.a.y) - (p.y < edge.b.y)) * orient(p, edge.a, edge.b) > 0) inside = !inside;
    }
    return inside ? 1 : -1;
}

// Envolvente convexa (Andrew / monotone chain), O(n log n).
// Resultado en sentido antihorario, sin puntos colineales ni duplicados.
template<typename T>
vector<Point<T>> convex_hull(vector<Point<T>> pts) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    int n = pts.size(), k = 0;
    if (n < 3) return pts;

    vector<Point<T>> h(2 * n);
    for (int i = 0; i < n; i++) {                       // cadena inferior
        while (k >= 2 && sgn(orient(h[k - 2], h[k - 1], pts[i])) <= 0) k--;
        h[k++] = pts[i];
    }
    for (int i = n - 2, t = k + 1; i >= 0; i--) {       // cadena superior
        while (k >= t && sgn(orient(h[k - 2], h[k - 1], pts[i])) <= 0) k--;
        h[k++] = pts[i];
    }
    h.resize(k - 1);
    return h;
}

// Diametro de un poligono convexo CCW (rotating calipers): devuelve la distancia^2 maxima entre vertices
template<typename T>
T convex_diameter_sq(const vector<Point<T>>& hull) {
    int n = hull.size();
    int j = (n < 2) ? 0 : 1;
    T best = 0;
    for (int i = 0; i < j; i++) {       // j crece mientras recorremos: el limite se reevalua
        for (;; j = (j + 1) % n) {
            best = max(best, (hull[i] - hull[j]).sq());
            // Avanzar j mientras el siguiente vertice siga alejandose de i
            if (sgn((hull[(j + 1) % n] - hull[j]).cross(hull[i + 1] - hull[i])) >= 0) break;
        }
    }
    return best;
}

// Par de puntos mas cercano (barrido con set), O(n log n). Requiere n >= 2
template<typename T>
pair<Point<T>, Point<T>> closest_pair(vector<Point<T>> pts) {
    sort(pts.begin(), pts.end(), [](const Point<T>& a, const Point<T>& b) { return a.y < b.y; });

    set<Point<T>> active;                   // puntos dentro de la franja vertical actual, ordenados por x
    ld best = 4e18;                         // mejor distancia^2 encontrada
    pair<Point<T>, Point<T>> ans;
    int left = 0;

    for (auto& p : pts) {
        Point<T> d((T)(sqrtl(best) + 1), 0);        // radio de busqueda
        while (pts[left].y <= p.y - d.x) {          // sacar puntos demasiado abajo
            active.erase(pts[left++]);
        }
        auto lo = active.lower_bound(p - d);
        auto hi = active.upper_bound(p + d);
        for (; lo != hi; ++lo) {
            ld e = (*lo - p).sq();
            if (e < best) { best = e; ans = {*lo, p}; }
        }
        active.insert(p);
    }
    return ans;
}

// Ordena puntos/vectores por angulo polar en [0, 2*PI) respecto al origen (sin usar atan2)
template<typename T>
void polar_sort(vector<Point<T>>& pts) {
    // half = 0 para el semiplano superior (angulo en [0, PI)), 1 para el inferior
    auto half = [](const Point<T>& p) { return sgn(p.y) < 0 || (sgn(p.y) == 0 && sgn(p.x) < 0); };
    sort(pts.begin(), pts.end(), [&](const Point<T>& a, const Point<T>& b) {
        if (half(a) != half(b)) return half(a) < half(b);
        return sgn(a.cross(b)) > 0;     // misma mitad: a va antes si b esta a su izquierda
    });
}

// Recorta un poligono CONVEXO conservando solo la parte a la izquierda de la recta l (dirigida a->b)
vector<pt> cut_convex_polygon(const vector<pt>& poly, const seg& l) {
    vector<pt> res;
    int n = poly.size();
    for (int i = 0; i < n; i++) {
        pt c = poly[i], d = poly[(i + 1) % n];
        ld sc = orient(l.a, l.b, c), sd = orient(l.a, l.b, d);
        if (sgn(sc) >= 0) res.push_back(c);                              // c se queda
        if (sgn(sc) * sgn(sd) < 0) res.push_back(c + (d - c) * (sc / (sc - sd)));  // la arista cruza la recta
    }
    return res;
}

// Semiplano: region a la IZQUIERDA de la recta dirigida a->b
struct HalfPlane {
    pt p, d;    // un punto de la recta y su direccion
    ld ang;     // angulo de la direccion (para ordenar)

    HalfPlane(const pt& a, const pt& b) : p(a), d(b - a), ang(atan2l(d.y, d.x)) {}
    HalfPlane(const seg& l) : HalfPlane(l.a, l.b) {}    // izquierda de la recta que va de l.a a l.b

    // true si q queda estrictamente fuera (a la derecha)
    bool out(const pt& q) const { return sgn(d.cross(q - p)) < 0; }
};

// Punto donde se cortan las rectas de dos semiplanos
pt halfplane_inter(const HalfPlane& s, const HalfPlane& t) {
    return s.p + s.d * ((t.p - s.p).cross(t.d) / s.d.cross(t.d));
}

// Interseccion de semiplanos, O(n log n). Devuelve los vertices del poligono resultante (CCW),
// o vacio si la interseccion es vacia. Si puede ser no acotada, agrega 4 semiplanos de una caja enorme.
vector<pt> half_plane_intersection(vector<HalfPlane> H) {
    sort(H.begin(), H.end(), [](const HalfPlane& a, const HalfPlane& b) { return a.ang < b.ang; });
    deque<HalfPlane> dq;

    for (auto& h : H) {
        // Quitar semiplanos del final/inicio cuyo vertice ya quedo fuera del nuevo semiplano
        while (dq.size() > 1 && h.out(halfplane_inter(dq.back(), dq[dq.size() - 2]))) dq.pop_back();
        while (dq.size() > 1 && h.out(halfplane_inter(dq[0], dq[1]))) dq.pop_front();

        // Rectas paralelas
        if (!dq.empty() && sgn(h.d.cross(dq.back().d)) == 0) {
            if (h.d.dot(dq.back().d) < 0) return {};            // direcciones opuestas: interseccion vacia
            if (h.out(dq.back().p)) dq.pop_back();              // mismo sentido: nos quedamos con el mas restrictivo
            else continue;
        }
        dq.push_back(h);
    }

    // Limpieza final entre el inicio y el final del deque
    while (dq.size() > 2 && dq[0].out(halfplane_inter(dq.back(), dq[dq.size() - 2]))) dq.pop_back();
    while (dq.size() > 2 && dq.back().out(halfplane_inter(dq[0], dq[1]))) dq.pop_front();
    if (dq.size() < 3) return {};

    vector<pt> res;
    for (size_t i = 0; i < dq.size(); i++) {
        res.push_back(halfplane_inter(dq[i], dq[(i + 1) % dq.size()]));
    }
    return res;
}

// Suma de Minkowski de dos poligonos convexos CCW: {a + b | a en A, b en B}
template<typename T>
vector<Point<T>> minkowski_sum(vector<Point<T>> A, vector<Point<T>> B) {
    // Rotar cada poligono para que empiece en su vertice mas bajo (y luego mas a la izquierda)
    auto reorder = [](vector<Point<T>>& v) {
        auto it = min_element(v.begin(), v.end(), [](const Point<T>& a, const Point<T>& b) {
            return tie(a.y, a.x) < tie(b.y, b.x);
        });
        rotate(v.begin(), it, v.end());
    };
    reorder(A);
    reorder(B);
    A.push_back(A[0]); A.push_back(A[1]);   // centinelas para no salirse del rango
    B.push_back(B[0]); B.push_back(B[1]);

    vector<Point<T>> res;
    size_t i = 0, j = 0;
    while (i < A.size() - 2 || j < B.size() - 2) {
        res.push_back(A[i] + B[j]);
        int c = sgn((A[i + 1] - A[i]).cross(B[j + 1] - B[j]));  // cual arista tiene menor angulo
        if (c >= 0 && i < A.size() - 2) i++;
        if (c <= 0 && j < B.size() - 2) j++;
    }
    return res;
}

// Teorema de Pick para poligono con vertices enteros: A = I + B/2 - 1
// Devuelve {I = puntos enteros interiores, B = puntos enteros en el borde}
pair<ll, ll> pick_theorem(const vector<ptll>& poly) {
    ll boundary = 0;
    int n = poly.size();
    for (int i = 0; i < n; i++) {
        ptll d = poly[(i + 1) % n] - poly[i];
        boundary += __gcd(llabs(d.x), llabs(d.y));      // puntos enteros en cada arista
    }
    ll interior = (llabs(polygon_area2(poly)) - boundary + 2) / 2;
    return {interior, boundary};
}


/////////////////////////////////////////////
// 6. ESFERA
////////////////////////////////////////////
// Distancia sobre la superficie de una esfera de radio R (haversine).
// Latitud y longitud en RADIANES (grados * PI / 180).
ld sphere_distance(ld lat1, ld lon1, ld lat2, ld lon2, ld R = 1) {
    ld s_lat = sinl((lat2 - lat1) / 2);
    ld s_lon = sinl((lon2 - lon1) / 2);
    ld a = s_lat * s_lat + cosl(lat1) * cosl(lat2) * s_lon * s_lon;
    return 2 * R * asinl(min((ld)1, sqrtl(a)));
}
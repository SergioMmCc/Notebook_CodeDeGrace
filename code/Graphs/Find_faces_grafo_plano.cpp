#include "../template.h"

/*
- Complejidad: O(E * log(E))
- Encuentra las caras de un grafo plano.
- Un grafo plano es uno en el cual cada vertice tiene unas
  coordenadas 'x', 'y' y las aristas que hay entre estos vertices
  jamas se intersectan (excepto en sus extremos).
- Debe ser un grafo conexo.
- Las caras de un grafo plano son las regiones en las que sus
  aristas dividen el plano. Cada region es minima, es decir,
  ninguna arista la atraviesa. La region exterior a todas las 
  aristas tambien es una cara.
- faces[0] es la cara exterior.
- En cada cara los vertices estan odenados en sentido antihorario, 
  excepto la exterior que se guarda en sentido horario.
- La cantidad de caras es: F = E - V + 2.
- Un grafo conexo sin ciclos (un arbol) tiene una sola cara, la
  exterior.

Ejemplo:
A=(0,0)  B=(1,0)  C=(1,1)  D=(0,1)
D ------- C
|       / |
|     /   |
|   /     |
A ------- B
Tiene 3 caras:
    1. Triangulo A-B-C
    2. Triangulo A-C-D
    3. Cara exterior (region infinita), borde A-B-C-D
*/

struct Point {
    ll x, y;

    Point(ll x_, ll y_): x(x_), y(y_) {}

    bool operator < (const Point& p) const {
        return tie(x, y) < tie(p.x, p.y);
    }

    Point operator - (const Point& p) const {
        return Point(x - p.x, y - p.y);
    }

    ll cross (const Point & p) const { // Ciudado con el overflow
        return x * p.y - y * p.x;
    }

    ll cross (const Point & p, const Point & q) const {
        return (p - *this).cross(q - *this);
    }

    ll half () const {
        return ll(y < 0 || (y == 0 && x < 0));
    }
};

// Hallar las caras de un grafo plano
vector<vl> find_faces(vector<Point> vertices, vector<vl> adj){
    ll n = vertices.size();
    vector<vector<char>> used(n);
    for0(i,n){
        used[i].assign(sz(adj[i]), 0);
        auto compare = [&](ll l, ll r){
            Point pl = vertices[l] - vertices[i];
            Point pr = vertices[r] - vertices[i];
            if(pl.half() != pr.half())
                return pl.half() < pr.half();
            return pl.cross(pr) > 0;
        };
        sort(all(adj[i]), compare);
    }
    vector<vl> faces;
    for0(i,n){
        for(ll edge_id = 0; edge_id < sz(adj[i]); edge_id++){
            if(used[i][edge_id]) continue;
            vl face;
            ll v = i, e = edge_id;
            while(!used[v][e]){
                used[v][e] = 1;
                face.pb(v);
                ll u = adj[v][e];
                ll e1 = lower_bound(all(adj[u]), v, [&](ll l, ll r) {
                    Point pl = vertices[l] - vertices[u];
                    Point pr = vertices[r] - vertices[u];
                    if(pl.half() != pr.half())
                        return pl.half() < pr.half();
                    return pl.cross(pr) > 0;
                }) - adj[u].begin() + 1;
                if(e1 == sz(adj[u])){
                    e1 = 0;
                }
                v = u;
                e = e1;
            }
            reverse(all(face));
            ll sign = 0;
            for(ll j = 0; j < sz(face); j++){
                ll j1 = (j + 1) % sz(face);
                ll j2 = (j + 2) % sz(face);
                ll val = vertices[face[j]].cross(vertices[face[j1]], vertices[face[j2]]);
                if(val > 0){
                    sign = 1;
                    break;
                }else if(val < 0){
                    sign = -1;
                    break;
                }
            }
            if(sign <= 0){
                faces.insert(faces.begin(), face);
            } else{
                faces.emplace_back(face);
            }
        }
    }
    return faces;
}

void solver(){
	int n; cin>>n; // Nos van a dar n aristas

    // Almacenamiento de vertices y aristas para llamar el algoritmo de findFaces
    vector<Point> vertices;
    vector<vector<ll>> adj;
    map<Point, ll> appear;
    // Si pueden haber aristas duplicadas o loops tocaria eliminarlas
	for(ll i = 0; i < n; i++){
        ll x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        Point save1(x1, y1), save2(x2, y2);
        ll index1, index2;
        map<Point, ll>::iterator it1, it2;
        it1 = appear.find(save1);
        it2 = appear.find(save2);
        if(it1 == appear.end()) {
            index1 = appear[save1] = sz(vertices);
            vertices.pb(save1);
            adj.emplace_back();
        }
        else 
            index1 = it1->second;

        if(it2 == appear.end()) {
            index2 = appear[save2] = sz(vertices);
            vertices.pb(save2);
            adj.emplace_back();
        }
        else 
            index2 = it2->second;
        
        adj[index1].pb(index2);
        adj[index2].pb(index1);
    }

    vector<vl> faces = find_faces(vertices, adj);
}
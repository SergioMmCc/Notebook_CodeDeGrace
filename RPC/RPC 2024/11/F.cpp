#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back

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

vector<vector<ll>> find_faces(vector<Point> vertices, vector<vector<ll>> adj) {
    ll n = vertices.size();
    vector<vector<char>> used(n);
    for (ll i = 0; i < n; i++) {
        used[i].resize(adj[i].size());
        used[i].assign(adj[i].size(), 0);
        auto compare = [&](ll l, ll r) {
            Point pl = vertices[l] - vertices[i];
            Point pr = vertices[r] - vertices[i];
            if (pl.half() != pr.half())
                return pl.half() < pr.half();
            return pl.cross(pr) > 0;
        };
        sort(adj[i].begin(), adj[i].end(), compare);
    }
    vector<vector<ll>> faces;
    for (ll i = 0; i < n; i++) {
        for (ll edge_id = 0; edge_id < adj[i].size(); edge_id++) {
            if (used[i][edge_id]) {
                continue;
            }
            vector<ll> face;
            ll v = i;
            ll e = edge_id;
            while (!used[v][e]) {
                used[v][e] = true;
                face.push_back(v);
                ll u = adj[v][e];
                ll e1 = lower_bound(adj[u].begin(), adj[u].end(), v, [&](ll l, ll r) {
                    Point pl = vertices[l] - vertices[u];
                    Point pr = vertices[r] - vertices[u];
                    if (pl.half() != pr.half())
                        return pl.half() < pr.half();
                    return pl.cross(pr) > 0;
                }) - adj[u].begin() + 1;
                if (e1 == adj[u].size()) {
                    e1 = 0;
                }
                v = u;
                e = e1;
            }
            reverse(face.begin(), face.end());
            ll sign = 0;
            for (ll j = 0; j < face.size(); j++) {
                ll j1 = (j + 1) % face.size();
                ll j2 = (j + 2) % face.size();
                ll val = vertices[face[j]].cross(vertices[face[j1]], vertices[face[j2]]);
                if (val > 0) {
                    sign = 1;
                    break;
                } else if (val < 0) {
                    sign = -1;
                    break;
                }
            }
            if (sign <= 0) {
                faces.insert(faces.begin(), face);
            } else {
                faces.emplace_back(face);
            }
        }
    }
    return faces;
}

//P es un pol´ıgono ordenado anticlockwise.
//Si es clockwise, retorna el area negativa.
//Si no esta ordenado retorna pura mierda.
//P[0] != P[n-1]
ld PolygonArea(const vector<Point> &p){
    ld r = 0.0;
    for (ll i=0; i<p.size(); ++i){
        ll j = (i+1) % p.size();
        r += p[i].x*p[j].y - p[j].x*p[i].y;
    }
    return r/2.0;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	ll n; cin>>n;
    vector<Point> vertices;
    vector<vector<ll>> adj;
    map<Point, ll> appear;
	for(ll i = 0; i < n; i++){
        ll x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        Point save1(x1, y1), save2(x2, y2);
        ll index1, index2;
        map<Point, ll>::iterator it1, it2;
        it1 = appear.find(save1);
        it2 = appear.find(save2);
        if(it1 == appear.end()) {
            index1 = appear[save1] = vertices.size();
            vertices.pb(save1);
            adj.emplace_back();
        }
        else 
            index1 = it1->second;

        if(it2 == appear.end()) {
            index2 = appear[save2] = vertices.size();
            vertices.pb(save2);
            adj.emplace_back();
        }
        else 
            index2 = it2->second;
        
        adj[index1].pb(index2);
        adj[index2].pb(index1);
    }

    vector<vector<ll>> faces = find_faces(vertices, adj);

    ld ans = 0;
    for(ll i = 0; i < faces.size(); i++){
        vector<Point> aux;
        for(ll u : faces[i]) {
            aux.pb(vertices[u]);
        }
        ld sum = PolygonArea(aux);
        if(sum < 0)continue;
        sum *= sum;
        ans += sum;
    }

    cout<<fixed<<setprecision(10)<<ans<<endl;

	return 0;
}
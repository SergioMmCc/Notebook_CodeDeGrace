#include "../../template.h"

const ll INFL = 1e18;
const int INF = 1e9;

struct Event {
    int x, type, y1, y2;
    bool operator<(const Event& other) const {
        if (x != other.x) return x < other.x;
        return type < other.type; // 0: start, 1: query, 2: end
    }
};

// FenWick Tree Implementation
const int MAX_Y = 2000010;
int bit[MAX_Y];

void add(int idx, int val) {
    for (; idx < MAX_Y; idx += idx & -idx) bit[idx] += val;
}

int query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx) sum += bit[idx];
    return sum;
}

int query(int l, int r) {
    return query(r) - query(l - 1);
}

void solver(){
    int n;
    cin>>n;
    
    vector<Event> events;
    int XSTART=0; // start of a horizontal segment
    int YLINE=1; // vertical segment
    int XEND=2;  // end of a horizontal segment
    for0(i, n) {
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);
        
        // Desplazamiento (offset) para manejar coordenadas negativas en el BIT
        int offset = 1e6 + 5;
        
        if (y1 == y2) 
        { // horizontal segment, query at start and end of the segment
            int y = y1 + offset;
            events.pb({x1, XSTART, y, y});
            events.pb({x2, XEND, y, y});
        }
        else if (x1 == x2) 
        { //vertical segment
            int x = x1;
            int y_low = y1 + offset;
            int y_high = y2 + offset;
            events.pb({x, YLINE, y_low, y_high});
        }
    }

    sort(all(events));

    // Cuenta cuantos segmentos horizontales están activos en cada punto de la línea vertical
    ll ans = 0;
    for (const auto& e : events) {
        if (e.type == XSTART) {
            add(e.y1, 1);
        } else if (e.type == YLINE) {
            ans += query(e.y1, e.y2); 
        } else if (e.type == XEND) {
            add(e.y1, -1);
        }
    }

    cout<<ans<<"\n";
}

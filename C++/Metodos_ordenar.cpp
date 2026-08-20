// En este caso se ordena revisando cual de los second es menor y si son iguales
// se revisa cual de los first es menor
struct comparator {
    bool operator () (pii a, pii b){
        if(a.se == b.se) return a.fi < b.fi;
        return a.se < b.se;
    }
}

// Usar en:
sort(all(vec), comparator());
pqueue<pii, vector<pii>, comparator> pq;
set<pii, comparator> mySet;
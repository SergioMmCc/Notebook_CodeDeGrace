/***********************************************************************************************
Para query suma y update suma */
    ll updateOp(ll a, ll b, ll len){
        if(b == neutro) return a;
        if(a == neutro) return b*len;
        return a + b*len;
    }
    ll calcOp(ll a, ll b){
        if(a == neutro) return b;
        if(b == neutro) return a;
        return a + b;
    }
/**********************************************************************************************/

/***********************************************************************************************
Para query minimo y update suma */
    ll updateOp(ll a, ll b, ll len){
        if(b == neutro) return a;
        if(a == neutro) return b;
        return a + b;
    }
    ll calcOp(ll a, ll b){
        if(a == neutro) return b;
        if(b == neutro) return a;
        return min(a, b);
    }
/**********************************************************************************************/

/***********************************************************************************************
Para arrays de 1s y 0s y updates de invertir los valores */
    int updateOp(int a, int len){
        return len - a;
    }

    void propagate(int v, int tl, int tr){
        if(tr - tl == 1 || !lazy[v]) return;
        int tm = (tr + tl) / 2;
        lazy[2*v + 1] = !lazy[2*v + 1];
        lazy[2*v + 2] = !lazy[2*v + 2];
        applyUpdOp(tree[2*v + 1], tm - tl);
        applyUpdOp(tree[2*v + 2], tr - tm);
        lazy[v] = 0;
    }

    // [l, r)
    void update(int l, int r, int v, int tl, int tr){
        propagate(v, tl, tr);
        if(tl >= r || l >= tr) return;
        if(tl >= l && tr <= r){
            lazy[v] = 1;
            applyUpdOp(tree[v], tr - tl);
            return;
        }
        
        int tm = (tl + tr) / 2;
        update(l, r, 2*v + 1, tl, tm);
        update(l, r, 2*v + 2, tm, tr);
        tree[v] = calcOp(tree[2*v + 1], tree[2*v + 2]);
    }
/**********************************************************************************************/

/***********************************************************************************************
- Si se llega a pedir update de diferentes tipos, toca tener cuidado con la propagacion. Ejemplo con
  update de asignacion (operacion identificada con 1) y de suma (operacion identificada con 0): */
    // Updates:
    ll updateOp(ll a, ll b, ll len, int op){ // op -> assign, !op -> suma
        if(op == -1) return neutro;
        if(b == neutro) return a;
        if(a == neutro) return b * len;
        return op ? b * len : a + b * len;
    }
    // Propagacion:
    void propagate(int v, int tl, int tr){
        if(tr - tl == 1 || lazy[v].se == -1) return;
        int tm = (tr + tl) / 2;
        
        lazy[2*v + 1].fi = updateOp(lazy[2*v + 1].fi, lazy[v].fi, 1, lazy[v].se);
        if(lazy[2*v + 1].se == -1) lazy[2*v + 1].se = lazy[v].se;
        else lazy[2*v + 1].se = min(1, lazy[2*v + 1].se + lazy[v].se); // La asignacion prevalece ya que se le suma al valor que se debe asignar

        tree[2*v + 1] = updateOp(tree[2*v + 1], lazy[v].fi, tm - tl, lazy[v].se);


        lazy[2*v + 2].fi = updateOp(lazy[2*v + 2].fi, lazy[v].fi, 1, lazy[v].se);
        if(lazy[2*v + 2].se == -1) lazy[2*v + 2].se = lazy[v].se;
        else lazy[2*v + 2].se = min(1, lazy[2*v + 2].se + lazy[v].se);

        tree[2*v + 2] = updateOp(tree[2*v + 2], lazy[v].fi, tm - tl, lazy[v].se);
        lazy[v] = {neutro, -1};
    }
#include "./SegTree_sparse.h"

// 0-index
// Copiar el segtree Sparse
// Para cambiar la operacion modificar el sparse
// Complejidad temporal: O(log²(SZ)) para updates y calcs
// Complejidad espacial: O(n*log²(SZ)) (Puede ser necesario comprimir ambas coordenadas)

template<class T> struct Node {
	node<T> seg; 
    Node* c[2];
	Node() { c[0] = c[1] = NULL; }

	void upd(int x, int y, T v, int L = 0, int R = SZ-1){ // Asigna v en (x,y)
		if(L == x && R == x){ 
            seg.upd(y,v); 
            return; 
        }
		int M = (L+R) / 2;
		if(x <= M){
			if(!c[0]) c[0] = new Node();
			c[0]->upd(x,y,v,L,M);
		} 
        else{
			if (!c[1]) c[1] = new Node();
			c[1]->upd(x,y,v,M+1,R);
		}
		seg.UPD(y, c[0] ? &c[0]->seg : NULL, c[1] ? &c[1]->seg : NULL);
	}

    // Query rectangle [(x1, y1), (x2, y2)]
	T calc(int x1, int x2, int y1, int y2, int L = 0, int R = SZ-1){
		if(x1 <= L && R <= x2) return seg.calc(y1,y2);
		if(x2 < L || R < x1) return neutro<T>();
		
        int M = (L+R) / 2; 
        T lv = c[0] ? c[0]->calc(x1, x2, y1, y2, L, M) : neutro<T>();
        T rv = c[1] ? c[1]->calc(x1, x2, y1, y2, M+1, R) : neutro<T>();
		return oper(lv, rv);
	}
};

void solver(){
    // Inicializar
    Node<ll> st;

    // Update
    int x, y; ll val;
    st.upd(x, y, val);

    // Calc
    int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
    ll ans = st.calc(x1, x2, y1, y2);
    if(ans == neutro<ll>()) cout<<0<<endl; // Rango sin valores asignados
    else cout<<ans<<endl;
}
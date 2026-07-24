#include "../../template.h"

// 0-index
// Implementacion ejemplo con suma
// Recordar que si los indices son muy grandes, cambiar SZ, L, R por ll

const int SZ = 1 << 17; // Techo del log2 del maximo indice

template<class T>
T neutro(){
    return 0; // Change
}

template<class T>
T oper(T a, T b){
    if(a == neutro<T>()) return b;
    if(b == neutro<T>()) return a;
    return a + b; // Change
}

template<class T> struct node {
	T val = neutro<T>(); 
    node<T>* c[2];
	node() { c[0] = c[1] = NULL; }
	void upd(int ind, T v, int L = 0, int R = SZ-1){ // asignar v
		if(L == ind && R == ind){ 
            val = v; 
            return; 
        }
		int M = (L+R) / 2;
		if(ind <= M){
			if(!c[0]) c[0] = new node();
			c[0]->upd(ind,v,L,M);
		} 
        else{
			if(!c[1]) c[1] = new node();
			c[1]->upd(ind,v,M+1,R);
		}
        T lv = c[0] ? c[0]->val : neutro<T>();
        T rv = c[1] ? c[1]->val : neutro<T>();
		val = oper(lv, rv);
	}

    // [lo, hi]
	T calc(int lo, int hi, int L = 0, int R = SZ-1){
		if(hi < L || R < lo) return neutro<T>();
		if(lo <= L && R <= hi) return val;
		int M = (L+R) / 2;
        T lv = c[0] ? c[0]->calc(lo, hi, L, M) : neutro<T>();
        T rv = c[1] ? c[1]->calc(lo, hi, M+1, R) : neutro<T>();
		return oper(lv, rv);
	}

    // for 2D segtree
	void UPD(int ind, node* c0, node* c1, int L = 0, int R = SZ-1){ 
		if(L != R){
			int M = (L+R) / 2;
			if(ind <= M){
				if(!c[0]) c[0] = new node();
				c[0]->UPD(ind, c0 ? c0->c[0] : NULL, c1 ? c1->c[0] : NULL, L, M);
			} 
            else{
				if(!c[1]) c[1] = new node();
				c[1]->UPD(ind, c0 ? c0->c[1] : NULL, c1 ? c1->c[1] : NULL, M+1, R);
			}
		} 
		val = oper((c0 ? c0->val : neutro<T>()), (c1 ? c1->val : neutro<T>()));
	}
};

void solver(){
    // Inicializar
    node<ll> st;

    // Update
    int idx; ll val;
    st.upd(idx, val);

    // Calc
    int lo, hi; cin>>lo>>hi;
    ll ans = st.calc(lo, hi);
    if(ans == neutro<ll>()) cout<<0<<endl; // Rango sin valores asignados
    else cout<<ans<<endl;
}
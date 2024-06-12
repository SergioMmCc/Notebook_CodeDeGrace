#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAXT = 100000;
const int myNegativeInfinite = -2e9;

vector<int> tree(MAXT*2 + 1);
int n;

void buildTree(vector<int>& A) {
    for (int i = 0; i < n; i++)tree[i + n] = A[i];
    for (int i = n - 1; i > 0; --i)tree[i] = max(tree[i << 1], tree[(i << 1) ^ 1]); //i << 1 -> i*2
    // Si i << 1 es el hijo izquierdo, (i << 1) ^ 1 es el hijo derecho y viceversa
}

void updateTree(int update, int value) {
    tree[n + update] = value;
    update += n;
    for (int i = update; i > 1; i >>= 1) tree[i>>1] = max(tree[i], tree[i ^ 1]); //Si i es el hijo por izquierda de i/2, entonces i ^ 1 es el hijo por derecha, y viceversa
    //i >> i -> i/2
}

int query(int l, int r) {
    int ans = myNegativeInfinite;
    l += n; r += n; 
    while (l < r) {
        if (l & 1)ans = max(ans, tree[l++]);
        if (r & 1)ans = max(ans, tree[--r]);
        l >>= 1; r >>= 1;
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int q; cin >> n >> q;
    vector<int> A; int save;
    for (int i = 0; i < n; i++) {
        cin >> save;
        A.push_back(save);
    }
    buildTree(A);
    
    int op;
    while (q--) {
        cin >> op;
        if (op == 1) {
            int x, w;cin >> x >> w;
            updateTree(x-1, tree[n+x-1]+w);
        }
        else {
            int l, r;cin >> l >> r;
            cout << query(l-1, r) << endl; //La implementacion es [l, r), entonces a r no le resto 1 porque en el ejercicio si necesito incluirlo
        }
    }

    return 0;
}
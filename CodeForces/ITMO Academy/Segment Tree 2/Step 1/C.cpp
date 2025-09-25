#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

struct SegTree {
    int n;
    vector<int> tree, setLazy, begin, end;
    void prop(int i) {
        if (setLazy[i] != -100) {
            setLazy[2 * i + 1] = setLazy[2 * i] = setLazy[i];
            tree[2 * i] = tree[2 * i + 1] =
                setLazy[i] * (end[2 * i + 1] - begin[2 * i + 1] + 1);
            setLazy[i] = -100;
        }
    }
    SegTree(int nn) {
        n = 1;
        while (n < nn) n *= 2;
        tree.resize(2 * n);
        setLazy.resize(2 * n, -100);
        begin.resize(2 * n);
        end.resize(2 * n);
        for (int i = n; i < 2 * n; i++) {
            begin[i] = end[i] = i - n;
        }
        for (int i = n - 1; i > 0; i--) {
            begin[i] = begin[2 * i];
            end[i] = end[2 * i + 1];
        }
    }
    void rangeSet(int i, int amt, int lo, int hi) {
        if (i < n) prop(i);
        if (begin[i] == lo && end[i] == hi) {
            tree[i] = amt * (hi - lo + 1);
            setLazy[i] = amt;
            return;
        }
        if (begin[2 * i] <= hi && end[2 * i] >= lo) {
            rangeSet(2 * i, amt, lo, min(hi, end[2 * i]));
        }
        if (begin[2 * i + 1] <= hi && end[2 * i + 1] >= lo) {
            rangeSet(2 * i + 1, amt, max(lo, begin[2 * i + 1]), hi);
        }
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
    int query(int i, int lo, int hi) {
        if (i < n) prop(i);
        if (begin[i] == lo && end[i] == hi) return tree[i];
        int ans = 0;
        if (begin[2 * i] <= hi && end[2 * i] >= lo) {
            ans += query(2 * i, lo, min(end[2 * i], hi));
        }
        if (begin[2 * i + 1] <= hi && end[2 * i + 1] >= lo) {
            ans += query(2 * i + 1, max(lo, begin[2 * i + 1]), hi);
        }
        return ans;
    }
};

int main (){
    ios_base::sync_with_stdio(0);cin.tie(NULL);

    int n, m; cin>>n>>m;

    //Inicializacion del Segment Tree
    SegTree st(n);

    while(m--){
        int op; cin>>op;
        if(op == 1){
            int l, r, v; cin>>l>>r>>v;
            r--;
            st.rangeSet(1, v, l, r);
        }
        else{
            int i; cin>>i;
            cout<<st.query(1, i, i)<<endl;
        }
    }
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

typedef pair<int, int> pii;

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

void solver(){
    int n, k, q;cin>>n>>k>>q;
    vector<int> a(n), ans(n+1);
    map<int, int> freq, nFreq;

    for(int i = 0; i < n; i++){
        cin>>a[i];
        a[i] += n-i;
    }
        
    for(int i = 0; i < k; i++)
        freq[a[i]]++;
    
    for(map<int, int>::iterator it = freq.begin(); it != freq.end(); ++it){
        nFreq[(*it).second]++;
    }
    map<int, int>::iterator it = nFreq.end(); --it;
    ans[0] = k-(*it).first;

    for(int i = 1; i <= n - k; i++){
        int take = a[i-1], add = a[i+k-1];
        map<int, int>::iterator upd = freq.find(take);
        int updFreq = (*upd).second;
        map<int, int>::iterator rest = nFreq.find(updFreq);

        if((*rest).first > 1) nFreq[(*rest).first - 1]++;
        if((*rest).second == 1) nFreq.erase((*rest).first);
        else (*rest).second--;
        
        if((*upd).second == 1)freq.erase((*upd).first);
        else (*upd).second--;

        freq[add]++;
        upd = freq.find(add);
        updFreq = (*upd).second;

        nFreq[updFreq]++;
        updFreq--;
        if(nFreq[updFreq] > 1) nFreq[updFreq]--;
        else nFreq.erase(updFreq);

        it = nFreq.end(); --it;
        ans[i] = k-(*it).first;
    }

    vector<array<int, 3>> queries(q);
    for(int i = 0; i < q; i++){
        queries[i][2] = i;
        cin>>queries[i][0]>>queries[i][1];
        queries[i][0]--; queries[i][0] *= -1;
        queries[i][1]--;
    }
    sort(queries.begin(), queries.end());
    for(int i = 0; i < q; i++)queries[i][0] *= -1;

    SegTree st(n);
    st.rangeSet(1, ans[n - k], n - k, n - k);
    int x = n-k;
    stack<pii> s;
    s.push({ans[n - k], n - k});
    vector<int> offlineQ(q);

    for(int i = 0; i < q; i++){
        while(x > queries[i][0]){
            x--;
            int y = x;
            while(s.size() && ans[x] < s.top().first){
                y = s.top().second;
                s.pop();
            }
            s.push({ans[x], y});
            st.rangeSet(1, ans[x], x, y);
        }
        offlineQ[queries[i][2]] = st.query(1, queries[i][0], queries[i][1] - k + 1);
    }
    
    for(int r : offlineQ) cout<<r<<endl;
}

#undef int
int main (){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        solver();
    }
    
    return 0;
}
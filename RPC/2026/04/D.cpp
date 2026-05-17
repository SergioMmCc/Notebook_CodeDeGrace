#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pqueue priority_queue
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
#define int long long
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;


struct segtree{
    vector<int> l;
    vector<int> r;
    vector<int> t;
    vector<ii> point;
    int n;
    segtree(ii a, ii b){
        n = 2;
        t.pb(2);
        r.pb(1);
        l.pb(-1);
        point.pb(a);
        t.pb(1);
        r.pb(-1);
        l.pb(-1);
        point.pb(b);
    }

    int size(){
        return n;
    }
    ii get(int no, int rem){
        int lft = 0;
        if(l[no] != -1){
            lft = t[l[no]];
        }
        //cout << no << " " << rem << " " << lft << endl;
        if(rem - lft == 0){
            return point[no];
        }
        if(rem >= lft+1){
            return get(r[no], rem - (lft + 1));
        }else{
            return get(l[no], rem);
        }
    }

    void rightmost(int no, ii pt){
        if(r[no] == -1){
            r[no] = n;
            t[no]++;
            t.pb(1);
            l.pb(-1);
            r.pb(-1);
            point.pb(pt);
            n++;
            return;
        }else{
            rightmost(r[no], pt);
            t[no] = 1;
            if(l[no] != -1){
                t[no] += t[l[no]];
            }
            if(r[no] != -1){
                t[no] += t[r[no]];
            }
        }
    }

    void insert(int no, int rem, ii pt){
        if(rem == n){
            rightmost(no, pt);
            return;
        }
        int lft = 0;
        if(l[no] != -1){
            lft = t[l[no]];
        }
        //cout << no << " " << rem << " " << lft << endl;
        if(rem - lft == 0){
            if(l[no] == -1){
                l[no] = n;
                t[no]++;
                t.pb(1);
                l.pb(-1);
                r.pb(-1);
                point.pb(pt);
                n++;
                return;
            }else{
                rightmost(l[no], pt);
                t[no] = 1;
                if(l[no] != -1){
                    t[no] += t[l[no]];
                }
                if(r[no] != -1){
                    t[no] += t[r[no]];
                }
                return;
            }
        }
        if(rem >= lft+1){
            insert(r[no], rem - (lft + 1), pt);
        }else{
            insert(l[no], rem, pt);
        }
        t[no] = 1;
        if(l[no] != -1){
            t[no] += t[l[no]];
        }
        if(r[no] != -1){
            t[no] += t[r[no]];
        }
    }
}; 


ld eucli(ii a, ii b){
    ld x = abs(a.fi - b.fi);
    ld y = abs(a.se - b.se);
    return sqrt((x * x) + (y * y));
}

int compare(ii a, ii b, ii c){
    ld x = eucli(a, b);
    ld y = eucli(b, c);
    ld z = eucli(c, a);
    if(z > x && z > y){
        return 2;
    }else if(x > y && x > z){
        return 1;
    }else{
        return 0;
    }
}

void solver(){
    int n; cin >> n;
    vector<ii> x;
    for(int i = 0; i < n; ++i){
        int u, v; cin >> u >> v;
        x.pb({u, v});
    }
    if(n == 2){
        cout << eucli(x[0], x[1]) << endl;
        return;
    }
    segtree tree(x[0], x[1]);
    for(int i = 2; i < n; ++i){
        ii left = tree.get(0, 0);
        //cout << left.fi << " " << left.se << endl;
        ii right = tree.get(0, tree.size() - 1);
        //cout << right.fi << " " << right.se << endl;
        int where = compare(left, right, x[i]);
        if(where == 0){
            tree.insert(0, 0, x[i]);
        }else if(where == 2){
            tree.insert(0, tree.size(), x[i]);
        }else{
            int lo = 0, hi = tree.size()-1;
            while(hi - lo > 1){
                int mid = lo + (hi - lo) / 2;
                ii fix = tree.get(0, mid);
                where = compare(left, fix, x[i]);
                if(where == 2){
                    lo = mid;
                }else{
                    hi = mid;
                }
            }
            tree.insert(0, hi, x[i]);
        }
    }
    assert(tree.size() == n);
    //cout << "done" << endl;
    ld ans = 0;
    for(int i = 1; i < n; ++i){
        ans += eucli(tree.get(0, i-1), tree.get(0, i));
    }
    cout << fixed << setprecision(7) << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
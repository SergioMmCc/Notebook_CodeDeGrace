#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
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
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<pii, char> piic;
typedef vector<piic> viic;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef pair<pii, pii> piiii;
typedef vector<piiii> viiii;
typedef pair<char, piiii> pciiii;
typedef vector<pciiii> vciiii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

map<int, char> is;
map<char, int> si;

void haha(){
    is[1] = 'A';
    is[2] = 'B';
    is[3] = 'C';
    is[4] = 'D';
    is[5] = 'E';
    is[6] = 'F';
    is[7] = 'G';
    is[8] = 'H';

    si['A'] = 1;
    si['B'] = 2;
    si['C'] = 3;
    si['D'] = 4;
    si['E'] = 5;
    si['F'] = 6;
    si['G'] = 7;
    si['H'] = 8;
}

bool can(piic u, piic v, set<piic>& a){
    char kind = u.se;

    int xu = u.fi.fi, yu = u.fi.se, xv = v.fi.fi, yv = v.fi.se;

    if(kind == 'K'){
        if(xu + 1 == xv && yu == yv) return 1;
        if(xu + 1 == xv && yu + 1 == yv) return 1;
        if(xu + 1 == xv && yu - 1 == yv) return 1;
        if(xu - 1 == xv && yu == yv) return 1;
        if(xu - 1 == xv && yu + 1 == yv) return 1;
        if(xu - 1 == xv && yu - 1 == yv) return 1;
        if(xu == xv && yu + 1 == yv) return 1;
        if(xu == xv && yu - 1 == yv) return 1;
        return 0;
    }
    else if(kind == 'Q'){
        if(xu == xv){
            for(piic aux : a) if(aux.fi.fi == xu && ((aux.fi.se < yu && aux.fi.se > yv) || (aux.fi.se > yu && aux.fi.se < yv))) return 0;
            return 1;
        }
        if(yu == yv){
            for(piic aux : a) if(aux.fi.se == yu && ((aux.fi.fi < xu && aux.fi.fi > xv) || (aux.fi.fi > xu && aux.fi.fi < xv))) return 0;
            return 1;
        }
        if(xu - xv == yu - yv){
            for(piic aux : a) if(aux.fi.fi - xu == aux.fi.se - yu && ((aux.fi.fi < xu && aux.fi.fi > xv) || (aux.fi.fi > xu && aux.fi.fi < xv))) return 0;
            return 1;
        }
        if(xu - xv == yv - yu){
            for(piic aux : a) if(aux.fi.fi - xu == yu - aux.fi.se && ((aux.fi.fi < xu && aux.fi.fi > xv) || (aux.fi.fi > xu && aux.fi.fi < xv))) return 0;
            return 1;
        }
        return 0;
    }
    else if(kind == 'B'){
        if(xu - xv == yu - yv){
            for(piic aux : a) if(aux.fi.fi - xu == aux.fi.se - yu && ((aux.fi.fi < xu && aux.fi.fi > xv) || (aux.fi.fi > xu && aux.fi.fi < xv))) return 0;
            return 1;
        }
        if(xu - xv == yv - yu){
            for(piic aux : a) if(aux.fi.fi - xu == yu - aux.fi.se && ((aux.fi.fi < xu && aux.fi.fi > xv) || (aux.fi.fi > xu && aux.fi.fi < xv))) return 0;
            return 1;
        }
        return 0;
    }
    else if(kind == 'R'){
        if(xu == xv){
            for(piic aux : a) if(aux.fi.fi == xu && ((aux.fi.se < yu && aux.fi.se > yv) || (aux.fi.se > yu && aux.fi.se < yv))) return 0;
            return 1;
        }
        if(yu == yv){
            for(piic aux : a) if(aux.fi.se == yu && ((aux.fi.fi < xu && aux.fi.fi > xv) || (aux.fi.fi > xu && aux.fi.fi < xv))) return 0;
            return 1;
        }
        return 0;
    }
    else{
        if(xu + 1 == xv && yu + 2 == yv) return 1;
        if(xu + 1 == xv && yu - 2 == yv) return 1;
        if(xu - 1 == xv && yu + 2 == yv) return 1;
        if(xu - 1 == xv && yu - 2 == yv) return 1;
        if(xu + 2 == xv && yu + 1 == yv) return 1;
        if(xu - 2 == xv && yu + 1 == yv) return 1;
        if(xu + 2 == xv && yu - 1 == yv) return 1;
        if(xu - 2 == xv && yu - 1 == yv) return 1;
        return 0;
    }

    return 0;
}

bool solv(set<piic>& a, vciiii& ans){
    if(sz(a) == 1){
        for(int i = 0; i < sz(ans); i++){
            cout<<ans[i].fi<<": "<<is[ans[i].se.fi.fi]<<ans[i].se.fi.se<<" -> "<<is[ans[i].se.se.fi]<<ans[i].se.se.se<<endl;
        }
        return 1;
    }
    viic aux;
    for(piic b : a) aux.pb(b);
    for(int i = 0; i < sz(a); i++){
        for(int j = 0; j < sz(a); j++){
            if(i == j) continue;

            bool cond = can(aux[i], aux[j], a);
            if(cond){
                a.erase(aux[i]);
                a.erase(aux[j]);
                a.insert({aux[j].fi, aux[i].se});
                ans.pb({aux[i].se, {aux[i].fi, aux[j].fi}});
                
                if(solv(a, ans)){
                    return 1;
                }
                else{
                    a.erase({aux[j].fi, aux[i].se});
                    ans.pop_back();
                    a.insert(aux[i]);
                    a.insert(aux[j]);
                }
            }
        }
    }

    return 0;
}

void solver(){
    int n, m; cin>>n>>m;
    set<piic> a;
    for(int i = 0; i < m; i++){
        string aux;
        char x;
        cin>>x>>aux;

        a.insert({{si[aux[0]], aux[1] - '0'}, x});
    }

    vciiii ans;
    if(!solv(a, ans)) cout<<"No solution"<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    haha();
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
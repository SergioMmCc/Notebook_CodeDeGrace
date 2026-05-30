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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<pll> vll;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

map<string, int> T = {{"Mon", 0}, {"Tue", 1}, {"Wed", 2}, {"Thu", 3}, {"Fri", 4}, {"Sat", 5}, {"Sun", 6}};


void solver(){
    string a1, b1, a2, b2; cin>>a1>>b1>>a2>>b2;

    if(a1 == a2 && b1 == b2){
        cout<<"7 days"<<endl;
        return;
    }

    int d1 = T[a1], d2 = T[a2];
    int h1 = (b1[1] - '0') + 10*(b1[0] - '0'), h2 = (b2[1] - '0') + 10*(b2[0] - '0');
    int m1 = (b1[4] - '0') + 10*(b1[3] - '0'), m2 = (b2[4] - '0') + 10*(b2[3] - '0');
    
    int minWeek = 10080, minDay = 1440, minHour = 60;
    int c1 = minDay * d1 + minHour * h1 + m1, c2 = minDay * d2 + minHour * h2 + m2;
    if(c2 < c1) c2 += minWeek;

    int dif = c2 - c1;

    // Diferencia de dias
    int dd = dif / minDay;
    dif %= minDay;

    // Diferencia de horas
    int dh = dif / minHour;
    dif %= minHour;

    // Diferencia de minutos
    int dm = dif;
    

    // Imprimir
    if(!dd && !dh){
        cout<<dm<<" minute";
        if(dm > 1) cout<<'s';
        cout<<endl;
    }
    else if(!dd && !dm){
        cout<<dh<<" hour";
        if(dh > 1) cout<<'s';
        cout<<endl;
    }
    else if(!dh && !dm){
        cout<<dd<<" day";
        if(dd > 1) cout<<'s';
        cout<<endl;
    }
    else if(!dd){
        cout<<dh<<" hour";
        if(dh > 1) cout<<'s';
        cout<<" and "<<dm<<" minute";
        if(dm > 1) cout<<'s';
        cout<<endl;
    }
    else if(!dh){
        cout<<dd<<" day";
        if(dd > 1) cout<<'s';
        cout<<" and "<<dm<<" minute";
        if(dm > 1) cout<<'s';
        cout<<endl;
    }
    else if(!dm){
        cout<<dd<<" day";
        if(dd > 1) cout<<'s';
        cout<<" and "<<dh<<" hour";
        if(dh > 1) cout<<'s';
        cout<<endl;
    }
    else{
        cout<<dd<<" day";
        if(dd > 1) cout<<'s';
        cout<<", "<<dh<<" hour";
        if(dh > 1) cout<<'s';
        cout<<", "<<dm<<" minute";
        if(dm > 1) cout<<'s';
        cout<<endl;
    }
}

int main(){
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
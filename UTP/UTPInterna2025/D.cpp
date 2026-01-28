#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;

int l, r;

bool process(queue<pii>& q, vector<int>& cont, vector<int>& aux){
    int pl = q.front().fi, pr = q.front().se; q.pop();

    // Ninguno coincide
    if(pl != l && pl != r && pr != l && pr != r){
        q.push({pl, pr});
        return 0;
    }

    aux[pl]++; aux[pr]++;

    // Extremos iguales
    if(l == r){
        if(pl == l) l = pr;
        else if(pr == l) l = pl;
    }

    // Extremos diferentes
    else{
        if(pl == r || pr == l) swap(pl, pr);
        
        // Solo una coincidencia
        if(pl == l && pr != r) l = pr;
        else if(pl != l && pr == r) r = pl;

        // Ambas coinciden
        else{
            if(cont[l] < cont[r]) l = pr;
            else if(cont[l] > cont[r]) r = pl;
            else{
                if(l < r) l = pr;
                else r = pl;
            }
        }
    }

    return 1;
}

void solver(){
    vector<int> contA(7), contB(7);
    queue<pii> a, b;
    for(int i = 0; i < 7; i++){
        int u, v; cin>>u>>v;
        a.push({u, v});
    }
    for(int i = 0; i < 7; i++){
        int u, v; cin>>u>>v;
        b.push({u, v});
    }

    int lenA = 7, lenB = 7, notA = 0, notB = 0, play = 0;

    // Primer turno de Alice
    l = a.front().fi, r = a.front().se; 
    a.pop(); lenA--;
    contA[l]++; contA[r]++; contB[l]++; contB[r]++; play++;

    while(lenA > 0 && lenB > 0 && (notA < lenA || notB < lenB)){
        play++;

        // Turno de Alice
        if(play % 2){
            if(play <= 14){
                contA[a.front().fi]++;
                contA[a.front().se]++;
            }
            bool cond = process(a, contA, contB);
            if(cond){
                notA = notB = 0;
                lenA--;
            }
            else notA++;
        }

        // Turno de Bob
        else{
            if(play <= 14){
                contB[b.front().fi]++;
                contB[b.front().se]++;
            }
            bool cond = process(b, contB, contA);
            if(cond){
                notA = notB = 0;
                lenB--;
            }
            else notB++;
        }
    }

    int winner = 0;
    if(!lenA) winner = 1;
    else if(!lenB) winner = 2;

    int pointA = 0, pointB = 0;
    while(!a.empty()){
        pointA += a.front().fi + a.front().se;
        a.pop();
    }
    while(!b.empty()){
        pointB += b.front().fi + b.front().se;
        b.pop();
    }

    if(!winner){
        if(pointA < pointB) winner = 1;
        else if(pointA > pointB) winner = 2;
    }

    if(winner == 1) cout<<"Alice ";
    else if(winner == 2) cout<<"Bob ";
    else cout<<"Draw ";

    cout<<play<<' '<<pointA<<' '<<pointB<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

list <int>::iterator next(list <int> &lista, list <int>::iterator i) {
    i++;
    if(i == lista.end())
        i = lista.begin();
    return i;
}

list <int>::iterator prev(list <int> &lista, list <int>::iterator i) {
    if (i == lista.begin()) 
        i = lista.end();
    i--;
    return i;
}

void solver(int n){
    bool cond = 0;
    int m = 1;
    while(!cond){
        m++;
        list<int> lista;
        for(int i = 2; i <= n; i++) lista.pb(i);

        list<int>::iterator it1 = lista.begin(), it2 = it1;
        while(lista.sz > 1){
            for(int i = 1; i < m; i++) it1 = next(lista, it1);
            it2 = it1;
            it2 = next(lista, it2);
            lista.erase(it1);
            it1 = it2;
        }

        if(*lista.begin() == 2){
            cout<<m<<endl;
            cond = 1;
        }

        lista.erase(lista.begin());
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    // int t = 1;
    // cin>>t;
    int n; cin>>n;
    while(n){
        solver(n);
        cin>>n;
    }

    return 0;
}
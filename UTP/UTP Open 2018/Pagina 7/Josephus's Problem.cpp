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

void solver(int n, int k){
    list<int> lista;
    for(int i = 1; i <= n; i++) lista.pb(i);

    list<int>::iterator it1 = lista.begin(), it2 = it1;
    while(lista.sz > 1){
        for(int i = 1; i < k; i++) it1 = next(lista, it1);
        it2 = it1;
        it2 = next(lista, it2);
        lista.erase(it1);
        it1 = it2;
    }

    cout<<*lista.begin()<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    int n, k;
    while(cin>>n>>k){
        if(n) solver(n, k);
    }

    return 0;
}
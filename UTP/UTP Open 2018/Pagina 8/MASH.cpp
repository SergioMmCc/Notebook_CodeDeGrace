#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

void solver(int n){
    list<int> lista;
    for(int i = 1; i <= n; i++) lista.pb(i);
    int x; cin>>x;
    vector<int> cards(20);
    for(int i = 0; i < 20; i++) cin>>cards[i];

    int card = 0;
    list<int>::iterator it = lista.begin();
    while(card < 20 && n > x){
        int move = cards[card];

        bool cond = 0;
        for(int i = 1; !cond && i < move; i++){
            ++it;
            if(it == lista.end()) cond = 1;
        }

        if(!cond){
            list<int>::iterator aux = it;
            ++it;
            if(it == lista.end()) cond = 1;
            lista.erase(aux);
            n--;
        }

        if(cond){
            it = lista.begin();
            card++;
        }
    }

    for(int i : lista) cout<<i<<' ';
    cout<<endl<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int i = 1, n;
    while(cin>>n){
        cout<<"Selection #"<<i<<endl;
        i++;
        solver(n);
    }

    return 0;
}
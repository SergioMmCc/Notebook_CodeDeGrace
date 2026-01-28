#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

int mcd(int a, int b){
    int temp;
    while(b){
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

list<int>::iterator next(list<int>& lista, list<int>::iterator i){
    i++;
    if(i == lista.end()) i = lista.begin();
    return i;
}

void solver(){
    int n; cin>>n;
    list<int> l;
    for(int i = 2; i <= n; i++) l.pb(i);
    list<int>::iterator it = l.begin();

    while(l.sz > 1){
        int num = *it;
        bool cond = 0;
        while(!cond){
            it = next(l, it);
            int num2 = *it;
            if(mcd(num, num2) > 1){
                list<int>::iterator aux = it;
                it = next(l, it);
                l.erase(aux);
                cond = 1;
            }
        }
    }

    cout<<*l.begin()<<endl;
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
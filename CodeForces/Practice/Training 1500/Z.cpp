#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

const int inf = 1e9;
typedef pair<int, int> pii;

void solver(){
    string s; cin>>s;
    ll pos; cin>>pos;
    ll len = 0;
    int add = s.sz;
    while(len < pos){
        len += add;
        add--;
    }

    add++;
    int posAns = pos - len + add - 1;

    // Letra en la posicion posAns de la palabra de longitud add
    // En total voy a quitar longitud - add letras

    // Guardar en que orden se debe quitar cada letra
    vector<int> changed(s.sz, inf);
    stack<pii> st;
    int changes = 1;
    for(int i = 0; i < s.sz; i++){
        int num = s[i] - 'a';
        while(!st.empty() && st.top().first > num){
            int save = st.top().second;
            st.pop();
            changed[save] = changes;
            changes++;
        }

        st.push({num, i});
    }

    int index = -1;
    int take = s.sz - add;
    int i = -1;
    while(index < posAns){
        i++;
        if(take < changed[i]){
            index++;
        }
    }

    cout<<s[i];
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }
    cout<<endl;

    return 0;
}
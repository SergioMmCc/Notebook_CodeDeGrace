#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define ps push_back
#define sz size()

void solver(){
    string origin, move; cin>>origin>>move;
    int cr = 0, ch = 0, cv = 0;
    for(int i = 0; i < move.sz; i++){
        if(move[i] == 'r') cr++;
        else if(move[i] == 'v') cv++;
        else ch++;
    }

    bool reverse = (cr + ch) % 2;

    if(cr % 2 == 1){
        for(int i = 0; i < origin.sz; i++){
            if(origin[i] == 'b') origin[i] = 'q';
            else if(origin[i] == 'd') origin[i] = 'p';
            else if(origin[i] == 'p') origin[i] = 'd';
            else origin[i] = 'b';
        }
    }

    if(ch % 2 == 1){
        for(int i = 0; i < origin.sz; i++){
            if(origin[i] == 'b') origin[i] = 'd';
            else if(origin[i] == 'd') origin[i] = 'b';
            else if(origin[i] == 'p') origin[i] = 'q';
            else origin[i] = 'p';
        }
    }

    if(cv % 2 == 1){
        for(int i = 0; i < origin.sz; i++){
            if(origin[i] == 'b') origin[i] = 'p';
            else if(origin[i] == 'd') origin[i] = 'q';
            else if(origin[i] == 'p') origin[i] = 'b';
            else origin[i] = 'd';
        }
    }

    if(reverse){
        string aux = origin;
        for(int i = 0; i < origin.sz; i++){
            origin[i] = aux[origin.sz - 1 - i];
        }
    }

    cout<<origin<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back

void solver() {
    int n;
    string a, b;
    cin>>n>>a>>b;
    int ans = 0;
    vector<int> moves(n);
    for(int i = 0; i < n; i++){
        int ai = a[i] - 'a', bi = b[i] - 'a';

        if(ai == bi){
            if(ai == 6 || ai == 19)
                moves[i] = 5;
        }
        else if(25 - ai == bi){
            if((ai + 13) % 26 == bi)
                moves[i] = 4;
            else
                moves[i] = 1;
        }
            
        else if((ai + 13) % 26 == bi)
            moves[i] = 2;
        else{
            int aux = (ai + 13) % 26;
            if(25 - aux == bi)
                moves[i] = 3;
            else{
                cout<<-1<<endl;
                return;
            }
        }
    }

    int lastMove = 0;
    for(int i = 0; i < n; i++){
        if(moves[i] == lastMove)
            continue;
        if(lastMove == 5){
            if(moves[i] != 0)
                ans++;
            lastMove = moves[i];
        }
        else if(lastMove == 4){
            if(moves[i] == 3)
                ans++;
            lastMove = moves[i];
        }
        else if(lastMove == 3){
            if(moves[i] == 5)
                continue;
            lastMove = moves[i];
        }
        else if(lastMove == 2){
            if(moves[i] == 4)
                continue;
            else if(moves[i] == 3 || moves[i] == 1)
                ans++;
            lastMove = moves[i];
        }
        else if(lastMove == 1){
            if(moves[i] == 4)
                continue;
            else if(moves[i] == 3 || moves[i] == 2)
                ans++;
            lastMove = moves[i];
        }
        else{
            if(moves[i] == 4 || moves[i] == 2 || moves[i] == 1)
                ans++;
            else if(moves[i] == 3)
                ans += 2;
            lastMove = moves[i] % 5;
        }
    }

    cout<<ans<<endl;
}

int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--) {
        solver();
    }

    return 0;
}
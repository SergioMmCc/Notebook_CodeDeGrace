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
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solver(){
    int n; cin>>n;
    vector<string> a(n);
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        for(int j = 0; j < n; j++){
            if(a[i][j] == '#') cnt++;
        }
    }

    for(int i = 0; i < n; i++){
        int x = i, y = 0;
        int move = 0, aux = 0;
        while(1){
            if(a[y][x] == '#') aux++;
            if(move){
                if(x == n-1) break;
                x++;
                move = 0;
            }
            else{
                if(y == n-1) break;
                y++;
                move = 1;
            }
        }
        // cout<<"cnt -> "<<cnt<<" aux -> "<<aux<<endl;
        if(aux == cnt){
            cout<<"YES"<<endl;
            return;
        }

        x = i, y = 0;
        move = 1, aux = 0;
        while(1){
            if(a[y][x] == '#') aux++;
            if(move){
                if(x == n-1) break;
                x++;
                move = 0;
            }
            else{
                if(y == n-1) break;
                y++;
                move = 1;
            }
        }
        if(aux == cnt){
            cout<<"YES"<<endl;
            return;
        }

        x = 0, y = i;
        move = 0, aux = 0;
        while(1){
            if(a[y][x] == '#') aux++;
            if(move){
                if(x == n-1) break;
                x++;
                move = 0;
            }
            else{
                if(y == n-1) break;
                y++;
                move = 1;
            }
        }
        if(aux == cnt){
            cout<<"YES"<<endl;
            return;
        }

        x = 0, y = i;
        move = 1, aux = 0;
        while(1){
            if(a[y][x] == '#') aux++;
            if(move){
                if(x == n-1) break;
                x++;
                move = 0;
            }
            else{
                if(y == n-1) break;
                y++;
                move = 1;
            }
        }
        if(aux == cnt){
            cout<<"YES"<<endl;
            return;
        }

/////////////////////////////////////////////////////////////////
        x = i, y = n-1;
        move = 0, aux = 0;
        while(1){
            if(a[y][x] == '#') aux++;
            if(move){
                if(x == n-1) break;
                x++;
                move = 0;
            }
            else{
                if(y == 0) break;
                y--;
                move = 1;
            }
        }
        if(aux == cnt){
            cout<<"YES"<<endl;
            return;
        }

        x = i, y = n-1;
        move = 1, aux = 0;
        while(1){
            if(a[y][x] == '#') aux++;
            if(move){
                if(x == n-1) break;
                x++;
                move = 0;
            }
            else{
                if(y == 0) break;
                y--;
                move = 1;
            }
        }
        if(aux == cnt){
            cout<<"YES"<<endl;
            return;
        }

        x = 0, y = i;
        move = 0, aux = 0;
        while(1){
            if(a[y][x] == '#') aux++;
            if(move){
                if(x == n-1) break;
                x++;
                move = 0;
            }
            else{
                if(y == 0) break;
                y--;
                move = 1;
            }
        }
        if(aux == cnt){
            cout<<"YES"<<endl;
            return;
        }

        x = 0, y = i;
        move = 1, aux = 0;
        while(1){
            if(a[y][x] == '#') aux++;
            if(move){
                if(x == n-1) break;
                x++;
                move = 0;
            }
            else{
                if(y == 0) break;
                y--;
                move = 1;
            }
        }
        if(aux == cnt){
            cout<<"YES"<<endl;
            return;
        }

        /////////////////////////////////////////////////////////
        x = i, y = 0;
        move = 0, aux = 0;
        while(1){
            if(a[y][x] == '#') aux++;
            if(move){
                if(x == 0) break;
                x--;
                move = 0;
            }
            else{
                if(y == n-1) break;
                y++;
                move = 1;
            }
        }
        if(aux == cnt){
            cout<<"YES"<<endl;
            return;
        }

        x = i, y = 0;
        move = 1, aux = 0;
        while(1){
            if(a[y][x] == '#') aux++;
            if(move){
                if(x == 0) break;
                x--;
                move = 0;
            }
            else{
                if(y == n-1) break;
                y++;
                move = 1;
            }
        }
        if(aux == cnt){
            cout<<"YES"<<endl;
            return;
        }

        x = n-1, y = i;
        move = 0, aux = 0;
        while(1){
            if(a[y][x] == '#') aux++;
            if(move){
                if(x == 0) break;
                x--;
                move = 0;
            }
            else{
                if(y == n-1) break;
                y++;
                move = 1;
            }
        }
        if(aux == cnt){
            cout<<"YES"<<endl;
            return;
        }

        x = n-1, y = i;
        move = 1, aux = 0;
        while(1){
            if(a[y][x] == '#') aux++;
            if(move){
                if(x == 0) break;
                x--;
                move = 0;
            }
            else{
                if(y == n-1) break;
                y++;
                move = 1;
            }
        }
        if(aux == cnt){
            cout<<"YES"<<endl;
            return;
        }

        ////////////////////////////////////////
        x = i, y = n-1;
        move = 0, aux = 0;
        while(1){
            if(a[y][x] == '#') aux++;
            if(move){
                if(x == 0) break;
                x--;
                move = 0;
            }
            else{
                if(y == 0) break;
                y--;
                move = 1;
            }
        }
        if(aux == cnt){
            cout<<"YES"<<endl;
            return;
        }

        x = i, y = n-1;
        move = 1, aux = 0;
        while(1){
            if(a[y][x] == '#') aux++;
            if(move){
                if(x == 0) break;
                x--;
                move = 0;
            }
            else{
                if(y == 0) break;
                y--;
                move = 1;
            }
        }
        if(aux == cnt){
            cout<<"YES"<<endl;
            return;
        }

        x = n-1, y = i;
        move = 0, aux = 0;
        while(1){
            if(a[y][x] == '#') aux++;
            if(move){
                if(x == 0) break;
                x--;
                move = 0;
            }
            else{
                if(y == 0) break;
                y--;
                move = 1;
            }
        }
        if(aux == cnt){
            cout<<"YES"<<endl;
            return;
        }

        x = n-1, y = i;
        move = 1, aux = 0;
        while(1){
            if(a[y][x] == '#') aux++;
            if(move){
                if(x == 0) break;
                x--;
                move = 0;
            }
            else{
                if(y == 0) break;
                y--;
                move = 1;
            }
        }
        if(aux == cnt){
            cout<<"YES"<<endl;
            return;
        }
    }

    if(cnt == 4){
        for(int i = 0; i < n-1; i++){
            for(int j = 0; j < n-1; j++){
                if(a[i][j] == '#' && a[i][j+1] == '#' && a[i+1][j] == '#' && a[i+1][j+1] == '#'){
                    cout<<"YES"<<endl;
                    return;
                }
            }
        }
    }

    cout<<"NO"<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
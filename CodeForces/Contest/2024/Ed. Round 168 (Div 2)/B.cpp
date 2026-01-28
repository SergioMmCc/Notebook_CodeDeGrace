#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solver() {
    int n; cin>>n;
    char maze[3][n+2];
    cin>>maze[0]>>maze[1];
    int ans = 0;
    for(int i = 1; i < n-1; i++) {
        if(maze[0][i] == '.' && maze[0][i-1] == 'x' && maze[0][i+1] == 'x'
        && maze[1][i-1] == '.' && maze[1][i] == '.' && maze[1][i+1] == '.')
            ans++;
            
        else if(maze[1][i] == '.' && maze[1][i-1] == 'x' && maze[1][i+1] == 'x'
        && maze[0][i-1] == '.' && maze[0][i] == '.' && maze[0][i+1] == '.')
            ans++;
    }
    cout<<ans<<endl;
}

int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        solver();
    }

    return 0;
}
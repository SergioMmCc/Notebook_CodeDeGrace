
#include <bits/stdc++.h>

using namespace std; 
int r, c; 
string maze[1003]; 

bool visited[1003][102];

bool check(string a, string b, int rotation) {

    for(int i=0; i<c; i++) {
        int actualpos = (rotation + i)%c; 
        if(a[actualpos] == '1' && b[i] == '1'){
            //cout << "false";
            //cout << endl << endl;
            return false;
        }
    }
    // << "true";
    //cout << endl << endl;
    
    return true;
}


bool bfs(int pos, int rotation, string rosca) {
    
    
    if(pos == r+1) return true;

    if(pos < 0) return false; 

    if(visited[pos][rotation]) return false;

    visited[pos][rotation] = true; 

    //cout << "pos: " << pos << "  rotation: " << rotation << endl; 
    if(!check(rosca, maze[pos], rotation)) return false;

    return bfs(pos + 1, rotation, rosca) | bfs(pos, (rotation + 1)%c, rosca) | bfs(pos, (c + rotation - 1)%c, rosca) | bfs(pos - 1, rotation, rosca);
}

int main() {

    string rosca; 
    cin >> r >> c;
    cin >> rosca; 

    string first = ""; 

    for(int i=0; i<c; i++){
        first += "0"; 
    }

    maze[0] = first; 

    for(int i=1; i<=r; i++){
        cin >> maze[i]; 
    }

    if(bfs(0, 0, rosca)) {
        cout << "Y" << endl;
        return 0; 
    }
    reverse(rosca.begin(), rosca.end());
    memset(visited, false, sizeof visited);
    if(bfs(0, 0, rosca)) {
        cout << "Y" << endl;
        return 0; 
    }
    cout << "N" << endl;
}
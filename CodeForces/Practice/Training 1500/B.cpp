#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

int binarySearch (int A[], int i, int j, int k) {
    int m;
    while (i <= j) {
        m = (i + j) >> 1;
        if (A[m] == k)
            return m;
        else if (k > A[m])
            i = m + 1;
        else
            j = m - 1;
    }
    return -i;
}

int binarySearchFirstOccurrence(int A[], int i, int j, int k) {
    int result, result2;
    result = binarySearch(A, i, j, k);
    if (result >= 0) {
        result2 = binarySearch(A, i, result - 1, k);
        while (result2 >= 0) {
            result = result2;
            result2 = binarySearch(A, i, result - 1, k);
        }
    }
    return result;
}

int binarySearchLastOccurrence(int A[], int i, int j, int k) {
    int result, result2;
    result = binarySearch(A, i, j, k);
    if (result >= 0) {
        result2 = binarySearch(A, result + 1, j, k);
        while (result2 >= 0) {
            result = result2;
            result2 = binarySearch(A, result + 1, j, k);
        }
    }
    return result;
}

void solver(){
    int n, k, q; cin>>n>>k>>q;
    int maze[k + 1][n + 1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            cin>>maze[j][i];
            if(i == 1) continue;
            maze[j][i] |= maze[j][i-1];
        }
    }

    while(q--){
        int l = 1, r = n;
        int m; cin>>m;
        while(m--){
            int reg, c; char o;
            cin>>reg>>o>>c;
            if(r < l) continue;

            if(o == '<'){
                int index = binarySearchLastOccurrence(maze[reg], l, r, c - 1);
                if(index < 0) index = -index - 1;
                r = min(r, index);
            }
            else{
                int index = binarySearchFirstOccurrence(maze[reg], l, r, c + 1);
                if(index < 0) index = -index;
                l = max(l, index);
            }
        }

        if(l <= r) cout<<l<<endl;
        else cout<<-1<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
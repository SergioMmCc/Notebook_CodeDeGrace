// Complejidad O(n ^ 2)
// binom[i][j] = (i!) / (j! * (i - j)!)

const int N = 501;
const ll mod = 1e9 + 7;
ll binom[N][N];

void calcBinom(){
    for(int i = 0; i < N; i++) binom[i][0] = binom[i][i] = 1;
    for(int i = 1; i < N; i++){
        for(int j = 1; j < i; j++){
            binom[i][j] = (binom[i-1][j-1] + binom[i-1][j]) % mod;
        }
    }
}
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

/* 
    Digit DP se utiliza en ejercicios en los que se nos pide contar la cantidad de numeros en un rango 
    muy grande (entre 1 y 10^18) cuyos digitos cumplen determinadas condiciones. Lo que se hace es
    un dp a traves de los digitos de cada numero, con una dimension para saber en que digito vamos,
    otra dimension para guardar si ya nos aseguramos que el numero sea menor al mayor numero en rango
    y mas dimensiones dependiendo de las condiciones del ejercicio. Se calcula la respuesta en rango
    ansL = (0, L - 1] y ansR = (0, R] y la respuesta definitiva es ansR - ansL.
    En este ejemplo se quiere calcular la suma de los digitos para cada numero entre L y R, asi que la
    dimension extra es la suma.
*/

// La tercera dimension representa la suma de los digitos, como el numero mayor es 10^18, sabemos que
// a lo sumo la suma de digitos de algun numero sera 19 * 9 = 171, asi que se asigna una talla donde
// entre ese valor.
ll dp[20][2][180]; 
vector<int> num;
int len;

// Se convierte el numero en vector para hacer facilmente comparaciones entre digitos
void intToVec(ll x){
    num.clear();
    len = 0;

    for(int i = 0; i < 20; i++){
        num.pb(x % 10);
        len++;
        x /= 10;
    }

    reverse(num.begin(), num.end());
}

// Se limpia el dp para calcular el resultado para el siguiente numero
void reset(){
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 180; k++){
                dp[i][j][k] = -1;
            }
        }
    }
}

ll calc(int idx, bool under, int sum){
    if(idx == len) return sum; // Si se llega a la longitud maxima, se retorna la suma

    if(dp[idx][under][sum] != -1) return dp[idx][under][sum];

    // Si ya nos aseguramos que estamos viendo un numero menor a R, el siguiente digito
    // agregado puede ser cualquiera, es decir, puede ir de 0 a 9; de lo contrario, debemos
    // asegurarnos que el siguiente digito agregado sea menor o igual al digito de R, pues
    // de lo contrario ya estariamos probando un numero mayor.
    int lim = under ? 9 : num[idx];
    
    ll ans = 0; // Se inicializa la respuesta en 0

    for(int i = 0; i <= lim; i++){
        // Si ya sabemos que estamos analizando numeros menores, o el digito que vamos a agregar es
        // estrictamente menor al de R, haremos el siguiente llamado sabiendo que estamos analizando
        // numeros menores
        bool nUnder = under || i < num[idx];

        // Se llama con el siguiente indice de digito, aclarando si ya nos aseguramos que los numeros 
        // a analizar son menores a R, y a la suma se le agrega el digito que se va a poner
        ans += calc(idx + 1, nUnder, sum + i); 
    }

    dp[idx][under][sum] = ans;
    return ans;
}

ll solver(ll x){
    if(x <= 0) return 0;

    intToVec(x);
    reset();
    return calc(0, 0, 0);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        ll l, r; cin>>l>>r;
        cout<<solver(r) - solver(l-1)<<endl;
    }

    return 0;
}
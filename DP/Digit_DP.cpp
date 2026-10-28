#include "../template.h"

/* 
- Se usa en ejercicios en los que se pide contar la cantidad de numeros 
  en un rango [L, R] muy grande (entre 1 y 10^18) cuyos digitos cumplen 
  determinadas condiciones.
- Se hace un dp a traves de los digitos de cada numero, con una 
  dimension para saber en que digito vamos, otra para guardar si ya nos 
  aseguramos que el numero sea menor al mayor numero en rango y mas 
  dimensiones dependiendo de las condiciones del ejercicio. 
- Se calcula la respuesta en rango: ansL = (0, L - 1] y ansR = (0, R] y 
  la respuesta definitiva es ansR - ansL.
- En este ejemplo se quiere calcular la suma de los digitos para cada 
  numero entre [L, R], asi que la dimension extra es la suma de digitos 
  de un numero, como el numero mayor es 10^18, se sabe que la suma de 
  digitos de algun numero sera 19 * 9 = 171, asi que se asigna una 
  talla donde entre ese valor.
*/

const int digits = 20; // Cantidad de digitos del numero mas grande que nos pueden dar
ll dp[digits][2][180]; 
vi num; // Vector que representa el numero que se esta analizando
int len; // Tamaño del numero que se esta analizando

// Se convierte el numero en vector para hacer facilmente comparaciones entre digitos
void intToVec(ll x){
    // Se limpia lo que se tuviera antes
    num.clear();
    len = 0;

    for0(i,digits){
        num.pb(x % 10);
        len++;
        x /= 10;
    }

    reverse(num.begin(), num.end());
}

// Se limpia el dp para calcular el resultado para el siguiente numero
void reset(){
    for0(i,digits){
        for0(j,2){
            for0(k,180){
                dp[i][j][k] = -1;
            }
        }
    }
}

ll calc(int idx, bool under, int sum){
    if(idx == len) return sum; // Si se llega a la longitud maxima, se retorna la suma

    if(dp[idx][under][sum] != -1) return dp[idx][under][sum]; // Ya fue calculado

    // Si ya nos aseguramos que estamos viendo un numero menor a R, el siguiente digito
    // agregado puede ser cualquiera, es decir, puede ir de 0 a 9; de lo contrario, debemos
    // asegurarnos que el siguiente digito agregado sea menor o igual al digito de R, pues
    // de lo contrario ya estariamos probando un numero mayor.
    int lim = under ? 9 : num[idx];
    
    ll ans = 0; // Se inicializa la respuesta en 0

    for0(i,lim+1){
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

ll func(ll x){
    if(x <= 0) return 0;

    intToVec(x);
    reset();
    return calc(0, 0, 0);
}

void solver(){
    ll l, r; cin>>l>>r;
    cout<<func(r) - func(l-1)<<endl;
}
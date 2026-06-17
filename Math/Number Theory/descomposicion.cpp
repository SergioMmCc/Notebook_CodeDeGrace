/* 
  Descomposicion prima de un numero. O(sqrt(n))
  n = p_1 ^ a_1 * p_2 ^ a_2 * ... * p_k ^ a_k
  donde p_k son los numeros primos que componen n y 
  a_k es la cantidad de veces que está dicho primo.
*/
vi factors(int n){
    vi f;
    for(int x = 2; x*x <= n; x++){
        while(n % x == 0){
            f.pb(x);
            n /= x;
        }
    }

    if(n > 1) f.pb(n);
    return f;
}
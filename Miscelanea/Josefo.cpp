#include "../template.h"

/*
- Hay n personas en 1 circulo. Se empiezan a eliminar de 1 en 1 hasta obtener un ganador.
  Iniciando con la persona 1, se empieza a contar desde 1 hasta p y se elimina a esa persona.
  Luego se cuenta nuevamente iniciando en la persona a la derecha del anterior eliminado.
  Ejemplo: con n = 5 y p = 3, el primer eliminado es el numero 3, el ganador es 4.
*/

/*
Si solo se quiere saber el ganador
- Complejidad: O(n)
- La idea detras de la solucion es que se calcula la respuesta desde n = 1, hasta llegar al
  n del parametro. Al iniciar con un ciruclo de n personas, y eliminar 1, ahora tenemos el
  mismo problema pero con una posicion inicial diferente y con 1 persona menos, asi que por
  eso se reduce el modulo y se cambia la posicion inicial.
*/
int josefo(int n, int p){
    int ans = 0;
    forlr(i,2,n) ans = (ans + p) % i;
    return ans + 1; // Suma para circulo de 1 a n
}

/*
Si se quiere saber el orden en que se van eliminando
- Complejidad: O(n * log(n))
*/
vi josefo(int n, int p){
    indexed_set nums;
    for1(i,n) nums.insert(i);
    vi ans;
    int cur = (p-1) % n;
    while(sz(nums) > 1){
        int num = *nums.find_by_order(cur);
        ans.pb(num);
        nums.erase(num);
        n--;
        cur = (cur + p - 1) % n;
    }
    ans.pb(*nums.begin()); // Ganador
}
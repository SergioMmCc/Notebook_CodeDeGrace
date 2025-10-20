/* 
    Hay n personas en 1 circulo. Se empiezan a eliminar de 1 en 1 hasta obtener un ganador.
    Iniciando con la persona 1, se empieza a contar desde 1 hasta p y se elimina a esa persona.
    Luego se cuenta nuevamente iniciando en la persona a la derecha del anterior eliminado.
    Ejemplo: con n = 5 y p = 3, el primer eliminado es el numero 3, el ganador es 4.

    La idea detras de la solucion es que se calcula la respuesta desde n = 1, hasta llegar al
    n del parametro. Al iniciar con un ciruclo de n personas, y eliminar 1, ahora tenemos el
    mismo problema pero con una posicion inicial diferente y con 1 persona menos, asi que por
    eso se reduce el modulo y se cambia la posicion inicial. De esta manera tenemos que:
    ans = p % 1 + p % 2 + p % 3 + ... + p % n, entonces transformmaos la recursividad planteada 
    por un algoritmo iterativo.
*/
// n <= 1e6, p <= 2^31 - 1
int josefo(int n, int p){
    int ans = 0;
    for(int i = 2; i <= n; i++) ans = (ans + p) % i;
    return ans + 1; // Suma para circulo de 1 a n
}
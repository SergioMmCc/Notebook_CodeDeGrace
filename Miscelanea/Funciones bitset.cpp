#include<bits/stdc++.h>
using namespace std;

/* Metodos bitset */
// Cuando se requiere un vector de bool, un bitset logra la misma funcion
// pero mucho mas eficiente ya que se pueden usar operaciones de bits.
// Internamente se hacen estas operaciones en bloques de 64 (o 32, 
// dependiendo de la arquitectura), asi que la complejidad de lo que sea 
// que se este haciendo se ve reducida en un vector de 64. Por ejemplo en
// un knapsack donde solo quiero saber si puedo lograr cierto valor, la
// complejidad pasaria de ser O(n^2) a ser O(n^2 / 64)

int main(){
    bitset<MAXN> b; // Dentro de "<>" se debe poner una constante que corresponde a la longitud del bitset
    b.test(pos), b[pos] // Retorna si el bit pos es 1
    b[pos1] = 1, b[pos2] = 0;
    b.set() // Pone todos los bits en 1
    b.reset() // Pone todos los bits en 0
    b.flip() // Invierte todos los bits
    b.flip(pos) // Invierte el valor del bit
    b.any() // Pregunta si hay algun bit en 1
    b.none() // Pregunta si todos son 0
    b.all() // Pregunta si todos son 1
    b.count() // Cuenta la cantidad de bits en 1
    string s = b.to_string();
    llu x = b.to_tllong(); // Lo convierte en un entero (solo si cabe)
    sz(b); // Retorna la longitud

    int i = b._Find_first(); // Retorna el indice del primer bit en 1
    i = b._Find_next(i); // Retorna el indice del primer bit en 1 DESPUES de i
    // Si no existe, retorna size

    // Operaciones de bits
    b1 | b2;
    b1 ^ b2;
    b1 & b2;
    b >>= cnt; // Modifica cada bit i como bit i - cnt (Desplazamiento a la derecha)
    b |= (b << add); // Hace que para bit i en 1, el bit i + add tambien sea 1

    return 0;
}
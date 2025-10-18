// Set indexado
// Sin elementos repetidos
// Se puedes simular elementos repetidos usando pii

#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

indexed_set nombre; // Declaracion
nombre.insert(valor); // Insertar
nombre.size() // Numero de elementos
nombre.find_by_order(3) // Iterador al 4to elemento mas pequeño
nombre.order_of_key(6) // Cuenta la cantidad de elementos menores a 6
nombre.erase(valor) // Si lo encuentra lo elimina, sino no hace nada
auto it = nombre.find(valor) // Devuelve un iterador a ese elemento. Si no esta, devuelve un iterador al final
nombre.count(valor) // Retorna un entero, 1 si valor esta, 0 si no esta
nombre.empty()
nombre.clear()
auto it = nombre.begin()
auto it = nombre.end()
auto it = nombre.lower_bound(5) // Retorna un iterador al primer elemento mayor o igual a 5
auto it = nombre.upper_bound(5) // Retorna un iterador al primer elemento mayor a 5
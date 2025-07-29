// - Complejidad O(3^n)
//   Si contamos el numero de pares ordenados (T, S), donde T esta contenido
//   en S, tenemos que cada elemento x tiene 3 opciones: esta en T y en S,
//   esta solo en S, no esta en ninguno. Pues si x estuviera en T y no en S,
//   entonces T no estaria contenido en S. Por lo tanto, cada elemento puede 
//   estar en 3 posibles estados.
// - Cuando se le resta uno a la submascara, el bit en 1 mas a la derecha
//   pasa a ser 0 y todos los bits a su derecha se convierten en 1. Luego se
//   aplica AND para eliminar todos los bits que no estan en la mascara.
//   Finalmente se usa la XOR para recorrer los subconjuntos en orden
//   incremental
// - Source: https://usaco.guide/gold/dp-bitmasks
for(int mask = 0; mask < (1 << n); mask++){
	for(int submask = mask; submask != 0; submask = (submask - 1) & mask){
		int subset = mask ^ submask;
		// do whatever you need to do here
		// submask contiene todo lo que esta en mask pero no en subset
	}
}
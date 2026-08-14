/*
- El diametro de un arbol es la mayor distancia entre cualquier 
  par de nodos en el arbol.
- Tambien funciona para arboles con aristas con pesos positivos.
- Si se tiene que el diametro de un arbol es la distancia entre dos
  vertices u, v, entonces podemos asumir que la mayor distancia para 
  un nodo x hacia cualquier nodo del arbol es  d(x, u) o d(x, v).
- Si el diametro d es par, todo posible camino que forma un diametro
  comparte al menos el nodo que se encuentra en mitad del camino.
  Si el diametro es impar, todo posible camino que forma un diametro 
  comparte al menos la arista que se encuentra en mitad del camino.
- Aristas en al menos un camino que forma un diametro:
  Para una arista u, v (con depth[u] < depth[v]), si la suma entre
  la mayor distancia de v a cualquier nodo en su subarbol, la mayor
  distancia de u a cualquier nodo que no este en el subarbol de v
  es igual a diametro - 1.
- Aristas en todos los caminos que forman un diametro (no tested):
  * Se halla el diametro d y sus extremos u, v.
  * Se halla el conjunto Eu con los nodos que estan a distancia d de v. 
    Y el conjunto Ev con los que estan a distancia d de u.
  * Para cada arista x, y (con depth[x] < depth[y]) si todos los nodos
    de Eu se encuentran en el subarbol de y, y todos los nodos de Ev
    se encuentran fuera del subarbol de x o en x (o viceversa los 
    conjuntos) entonces dicha arista esta en todos los caminos que 
    forman un diametro.
  Todas estas aristas forman un camino.
*/
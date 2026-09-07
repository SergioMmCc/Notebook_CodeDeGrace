# Coeficientes binomiales

Notación: $\binom{n}{k}$

- Se asume que si $k > n$, entonces $\binom{n}{k} = 0$.

- **Suma de fila completa:**
$$\sum_{k=0}^{n} \binom{n}{k} = 2^n$$

- **Identidad de la suma superior (hockey stick):**
$$\sum_{m=0}^{n} \binom{m}{k} = \binom{n+1}{k+1}$$

- **Identidad de Vandermonde:**
$$\sum_{k=0}^{m} \binom{n+k}{k} = \binom{n+m+1}{m}$$

- **Suma de cuadrados:**
$$\sum_{k=0}^{n} \binom{n}{k}^2 = \binom{2n}{n}$$

- **Suma ponderada:**
$$\sum_{k=1}^{n} k\binom{n}{k} = n \cdot 2^{n-1}$$

- **Conexión con Fibonacci:**
$$\sum_{k=0}^{n} \binom{n-k}{k} = F_{n+1}$$


# Números Catalanes

El número catalán $C_n$ se define como la cantidad de expresiones de paréntesis válidas que consisten de $n$ paréntesis de apertura y $n$ paréntesis de cierre.

Por ejemplo, $C_3 = 5$: `()()()`, `()(())`, `(())()`, `(()())`, `((()))`.

$$C_n = \sum_{i=0}^{n-1} C_i \cdot C_{n-i-1}$$

$$C_n = \frac{1}{2n+1} \binom{2n}{n}$$

- Donde $\binom{2n}{n}$ es la cantidad de formas de construir una expresión no necesariamente válida de $n$ paréntesis de apertura y $n$ paréntesis de cierre, mientras que $\binom{2n}{n-1}$ es la cantidad de expresiones inválidas, así que haciendo la resta y despejando, se obtiene la fórmula escrita.

## Interpretaciones de los números catalanes

El número de Catalan $C_n$ es la solución para:

- El número de secuencias de paréntesis correctas que consisten de $n$ paréntesis de apertura y $n$ de cierre.
- El número de árboles binarios completos con raíz que tienen $n+1$ hojas (los vértices no están numerados). Un árbol binario con raíz es *completo* si cada vértice tiene dos hijos o ninguno.
- El número de árboles binarios completos no isomorfos con $n$ nodos internos (es decir, nodos con al menos un hijo).
- El número de árboles binarios de $n$ nodos (tener en cuenta que un árbol root -> left -> left es diferente que un árbol root -> right -> right).
- El número de árboles con raíz de $n+1$ nodos (los vértices no están enumerados), donde si en un árbol la primera rama tiene 1 elemento y la segunda rama tiene 2, mientras que en otro árbol la primera rama tiene 2 y la segunda tiene 1, estos árboles se consideran diferentes; es decir, si se cambia el orden de las ramas y estas tienen estructuras diferentes, se considera un árbol distinto.
- El número de formas de parentesizar completamente $n+1$ factores.
- El número de triangulaciones de un polígono convexo de $n+2$ lados (es decir, el número de particiones del polígono en triángulos disjuntos usando diagonales).
- El número de formas de conectar $2n$ puntos en un círculo para formar $n$ cuerdas que no se crucen entre sí.
- El número de caminos monótonos en una red de $(0,0)$ a $(n,n)$ en una malla cuadrada de tamaño $n \times n$, que no cruzan la diagonal principal (la que conecta $(0,0)$ con $(n,n)$). Tener en cuenta que no se está pasando por los cuadros de la malla sino por los puntos.
- El número de permutaciones de longitud $n$ que pueden ordenarse con una pila (*stack sorted*); es decir, la permutación es stack sorted si y solo si no existe un índice $i < j < k$ tal que $a_k < a_i < a_j$.
- El número de particiones no cruzadas de un conjunto de $n$ elementos. Consiste en imaginar un círculo que en los bordes tiene los elementos de 1 a n en orden, y se quiere separarlos en subconjuntos de modo que al dibujar un arco con los elementos de cada subconjunto, no se haga ningún cruce.
- El número de formas de cubrir la escalera $1, 2, 3, \ldots, n$ usando $n$ rectángulos.
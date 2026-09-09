# Coeficientes binomiales

Notación: $\binom{n}{k}$

- Se asume que si $k > n$, entonces $\binom{n}{k} = 0$.


$$\binom{n}{k} = \frac{n!}{(n-k)!\,k!}$$

$$\binom{n}{k} = \binom{n-1}{k} + \binom{n-1}{k-1}$$

$$\binom{n+1}{k} = \frac{n+1}{n-k+1}\binom{n}{k}$$

$$\binom{n}{k+1} = \frac{n-k}{k+1}\binom{n}{k}$$

$$\binom{n}{k} = \frac{n}{n-k}\binom{n-1}{k}$$

$$\binom{n}{k} = \frac{n-k+1}{k}\binom{n}{k-1}$$


- **Suma de fila completa:**
$$\sum_{k=0}^{n} \binom{n}{k} = 2^n$$

- **Identidad de la suma superior (hockey stick):**
$$\sum_{m=0}^{n} \binom{m}{k} = \binom{n+1}{k+1}$$

- **Variante de la identidad de la suma superior:**
$$\sum_{k=0}^{m} \binom{n+k}{k} = \binom{n+m+1}{m}$$

- **Identidad de Vandermonde:**
$$\sum_{k=0}^{r} \binom{m}{k}\binom{n}{r-k} = \binom{m+n}{r}$$

- **Suma de cuadrados:**
$$\sum_{k=0}^{n} \binom{n}{k}^2 = \binom{2n}{n}$$

- **Suma ponderada:**
$$\sum_{k=1}^{n} k\binom{n}{k} = n \cdot 2^{n-1}$$

- **Conexión con Fibonacci:**
$$\sum_{k=0}^{n} \binom{n-k}{k} = F_{n+1}$$

El número de caminos de $(0, 0)$ hacia $(a, b)$, donde cada paso se da al norte o al este: $\binom{a+b}{a}$.

El número de formas de pintar $n$ objetos con $r$ colores si cada color debe ser utilizado al menos una vez: $\sum_{k=0}^{r}\binom{r}{k}(-1)^{r-k}k^n$ o $\sum_{k=0}^{r}\binom{r}{r-k}(-1)^k(r-k)^n$

El número de tuplas de $k$ números $x_1 + x_2 + ... + x_k$ cuya suma es igual a $n$ (Tener en cuenta que una tupla ${1, 2}$ y otra ${2, 1}$ se consideran diferentes): 
- Si los números deben ser positivos: $\binom{n-1}{k-1}$.
- Si los números deben ser no negativos: $\binom{n+k-1}{n}$
- Si dan lower bounds $x_i >= a_i$, se halla $n' = n - \sum_{i=1}^{k} a_i$ y se calcula: $\binom{n'+k-1}{n'}$
- Si dan un upper bound $x_i <= a$: $\sum_{i=0}^{k} (-1)^i\binom{k}{i}\binom{n+k-1-(a+1)i}{k-1}$ (Tener en cuenta que un coeficiente binomial es igual a 0 si su parte superior es negativa)
- Si me dan upper_bounds $x_i <= a_i$, se halla el resultado sin restricciones y con inclusión-exclusión se restan los casos donde $x_i >= a_i$

El número de tuplas de $k$ números $x_1 + x_2 + ... + x_k$ cuya suma es menor o igual a $n$: $\binom{n+k}{k}$

El número de formas de poner $n$ pelotas en $k$ cajas (similar a decir que tengo que elegir n elementos de un conjunto de tamaño k):
- Si cada caja puede tener maximo una pelota: $\binom{k}{n}$
- Si cada caja puede contener multiples pelotas: $\binom{k+n-1}{n}$
- Si cada caja puede contener maximo una pelota y dos cajas adyacentes no pueden tener una pelota: $\binom{k-n+1}{k-2n+1}$


# Coeficientes multinomiales

El coeficiente multinomial
$$\binom{n}{n_{1}, n_{2}, ..., n_{k}} = M(n_1, n_2, ..., n_{k}) = \frac{n!}{n_{1}!n_{2}!...n_{k}!} $$
es igual a la cantidad de formas en que se pueden dividir $n$ elementos en subconjuntos de tamaño $n_1, n_2, ..., n_k$, donde $n_1 + n_2 + · · · + n_k = n$.

- $$M(a, ..., b, c, ...) = M(a + ... + b, c, ...)M(a, ..., b)$$

- $$(a_1 + ... + a_k)^n = \sum_{n_1+...+n_k=n, n_i>=0}^{} \binom{n}{n_1, ..., n_k}a_1^{n_1}...a_k^{n_k}$$


# Números Catalanes

El número catalán $C_n$ se define como la cantidad de expresiones de paréntesis válidas que consisten de $n$ paréntesis de apertura y $n$ paréntesis de cierre.

Por ejemplo, $C_3 = 5$: `()()()`, `()(())`, `(())()`, `(()())`, `((()))`.

Partiendo desde $C_0$, los primeros números catalanes son: 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900, 2674440, 9694845, 35357670

$$C_n = \sum_{i=0}^{n-1} C_i \cdot C_{n-i-1}$$

$$C_n = \frac{1}{n+1} \binom{2n}{n}$$

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
- El número de caminos monótonos (que cada paso se da al norte o al este) en una red de $(0,0)$ a $(n,n)$ en una malla cuadrada de tamaño $n \times n$, que no cruzan la diagonal principal (la que conecta $(0,0)$ con $(n,n)$). Tener en cuenta que no se está pasando por los cuadros de la malla sino por los puntos.
- El número de permutaciones de longitud $n$ que pueden ordenarse con una pila (*stack sorted*); es decir, la permutación es stack sorted si y solo si no existe un índice $i < j < k$ tal que $a_k < a_i < a_j$.
- El número de particiones no cruzadas de un conjunto de $n$ elementos. Consiste en imaginar un círculo que en los bordes tiene los elementos de 1 a n en orden, y se quiere separarlos en subconjuntos de modo que al dibujar un arco con los elementos de cada subconjunto, no se haga ningún cruce.
- El número de formas de cubrir la escalera $1, 2, 3, \ldots, n$ usando $n$ rectángulos.


# Derangements

La cantidad de derangements de $n$ números, expresada como $D_n$, es la cantidad de permutaciones tal que ningún elemento aparece en su posición original, es decir, donde para todo $i$, $1 \leq i \leq n$, $p_i \neq i$.

Partiendo desde $D_0$, los primeros $D_i$ son: 1, 0, 1, 2, 9, 44, 265, 1854, 14833

- **Calculando con inclusión-exclusión:** $D_n = n!\sum_{k=0}^{n}\frac{(-1)^k}{k!}$
- **Calculando con DP:** $D_0 = 1, \quad D_1 = 0, \quad D_n = (n-1)\left(D_{n-1} + D_{n-2}\right)$

La cantidad de permutaciones con exactamente $k$ indices donde $p_i = i$ es: $\binom{n}{k}D_{n-k}$


## Sumatorias

$$\sum_{k=0}^{n} k = \frac{n(n+1)}{2}$$

$$\sum_{k=a}^{b} k = \frac{(a+b)(b-a+1)}{2}$$

$$\sum_{k=0}^{n} k^2 = \frac{n(n+1)(2n+1)}{6}$$

$$\sum_{k=0}^{n} k^3 = \frac{n^2(n+1)^2}{4}$$

$$\sum_{k=0}^{n} k^4 = \frac{6n^5+15n^4+10n^3-n}{30}$$

$$\sum_{k=0}^{n} k^5 = \frac{2n^6+6n^5+5n^4-n^2}{12}$$

$$\sum_{k=0}^{n} x^k = \frac{x^{n+1}-1}{x-1} \quad \text{(válida solo para } x \neq 1\text{)}$$

$$\sum_{k=0}^{n} kx^k = \frac{x-(n+1)x^{n+1}+nx^{n+2}}{(x-1)^2}$$

$$1+x+x^2+\cdots = \frac{1}{1-x} \quad \text{(válida solo para } |x|<1\text{)}$$
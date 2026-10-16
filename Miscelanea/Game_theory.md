# Juegos imparciales

Notación: $v \to u$ significa que desde el estado $v$ existe un movimiento que lleva al estado $u$.

Se asume que el juego cumple lo siguiente:

- Dos jugadores que se alternan los turnos.
- Los movimientos posibles dependen solo del estado, no de quién juega (juego *imparcial*).
- Información perfecta y sin azar.
- El juego es finito: tarde o temprano alguien no puede mover.
- Juego normal: **pierde quien no puede mover** (gana quien hace el último movimiento). No hay empates.

El juego se puede ver como un grafo dirigido acíclico donde los vértices son los estados y las aristas son los movimientos. Un vértice sin aristas de salida es un estado terminal.

- **Estado ganador:** el jugador que mueve puede forzar la victoria.
$$v \text{ es ganador} \iff \exists\, u \text{ con } v \to u \text{ y } u \text{ perdedor}$$

- **Estado perdedor:** el jugador que mueve pierde si el rival juega bien.
$$v \text{ es perdedor} \iff \forall\, u \text{ con } v \to u,\; u \text{ es ganador}$$
 
Tener en cuenta que un estado terminal es perdedor (no existe ningún $u$, así que la condición se cumple vacíamente). Con estas dos reglas se clasifican todos los estados empezando desde los terminales. Es una recursión: un estado es ganador si alguno de sus movimientos lleva a un estado perdedor, y perdedor en caso contrario.


## Juegos de sustracción

Una sola pila de $n$ fichas y un conjunto $S$ de tamaño $m$ con las cantidades que se pueden quitar en un turno.

- Primero se dice que $g_0 = 0$. Entonces para cada valor $1 \leq i \leq n$, se calcula si algún $g_{i-S_j} = 0$, en caso de que si $g_i = 1$ y se considera un estado ganador y en caso contrario $g_i = 0$ y se considera un esatdo perdedor.

- **Periodicidad:** si en un turno se pueden quitar a lo sumo $k$ fichas, que un estado sea ganador o perdedor depende solo de si los $k$ estados anteriores son ganadores o perdedores. Como solo hay $2^k$ secuencias posibles de largo $k$, la secuencia de estados termina siendo periódica.

- Si $S = {1, 2, 3, ..., m}$, gana el primer jugador si $n \bmod m \gt 0$ y pierde en caso contrario.


# Nim

Hay $n$ pilas y la pila $i$ tiene $x_i$ palitos. En cada turno se elige una pila no vacía y se quita cualquier cantidad positiva de palitos de ella. Gana el jugador que realiza el último movimiento.

- Sea $s$ el xor del tamaño de todas las pilas, el jugador que empieza es ganador si $s \gt 0 $ y perdedor en caso contrario. A este valor $s$ se le dice nim-sum.

- **Cantidad de movimientos ganadores desde un estado ganador:** es la cantidad de pilas $k$ tales que
$$x_k \oplus s < x_k$$

- Si además se permitiera **agregar** palitos a una pila (con reglas que mantengan el juego finito), el resultado del juego no cambia. Si un jugador agrega palitos, el rival simplemente deshace el aumento quitando exactamente lo mismo. Como el juego es finito, alguien tiene que terminar haciendo un movimiento normal de Nim.

- **Escalera:** si se dijera que para cada fila entre $2$ y $n$, desde la fila $i$ se pasa cualquier cantidad positiva de palitos a la fila $i-1$, y la fila $1$ quita cualquier cantidad de palitos, y pierde el jugador que se queda sin movimientos, se halla unicamente el xor del tamaño de las filas con $i$ **impar** ($1, 3, 5, ...$). Si se plantea como un arbol rooteado donde todas las hojas tienen la misma paridad en su profunidad, cada nodo puede pasar palitos a alguno de sus hijos y las hojas quitan cualquier cantidad, se toma el xor de todos los nodos cuya profundidad tiene la misma paridad que el de las hojas.

- Dos estados de Nim con la misma nim-sum son equivalentes. En particular, cualquier Nim se puede reemplazar por una sola pila de tamaño $s$.


## Nim misère

Es el mismo Nim pero **pierde quien quita el último palito**.

Se juega como Nim normal hasta que el siguiente movimiento dejaría todas las pilas con a lo sumo $1$ palito. En ese momento se cambia la regla de paridad:

- Nim normal: dejar una cantidad **par** de pilas con $1$ palito.
- Nim misère: dejar una cantidad **impar** de pilas con $1$ palito.

Esto funciona porque el estado en el que cambia la estrategia siempre aparece en la partida, y es ganador: tiene exactamente una pila con más de un palito, así que su nim-sum es distinta de $0$.

- Si alguna pila tiene $x_i \geq 2$: gana el primero si y solo si $s \neq 0$.
- Si todas las pilas cumplen $x_i \leq 1$: gana el primero si y solo si la cantidad de pilas con $1$ palito es **par**.


# Números de Grundy

El **número de Grundy** (o nimber, o valor de Grundy) de un estado $v$ es:

$$g(v) = \operatorname{mex}\{\, g(u) : v \to u \,\}$$

Si $v$ no tiene movimientos, $g(v) = 0$.


## Propiedades

- $g(v) = 0 \iff v$ es perdedor. Si $g(v) > 0$, el estado es ganador.
- Si $g(v) = 0$, todos los movimientos llevan a estados con Grundy **positivo**.
- Si $g(v) = x > 0$, desde $v$ se puede llegar a estados con cada uno de los valores $0, 1, \ldots, x-1$ (y posiblemente a otros valores mayores que $x$).
- Una pila de Nim con $k$ palitos tiene $g_k = k$.


## Teorema de Sprague-Grundy

Todo juego imparcial, finito, de dos jugadores y con información perfecta (en juego normal) es equivalente a **una sola pila de Nim** de tamaño $g(v)$, donde:

$$g(v) = \operatorname{mex}\{\, g(v_1), g(v_2), \ldots, g(v_k) \,\}$$

siendo $v_1, \ldots, v_k$ los estados alcanzables desde $v$.

Cuándo pensar en Grundy:
- El juego no es Nim directo, pero las reglas de movimiento dependen solo del estado.
- El juego está formado por componentes independientes.
- Clasificar los estados completos sería demasiado lento, pero cada componente es pequeño y se puede precalcular.
- No es Misère, ya que el teorema vale solo para juego normal.

Receta:
1. Definir el estado y los movimientos.
2. Calcular $g$ de los estados pequeños (a mano o con fuerza bruta), empezando por los terminales.
3. Combinar los componentes con XOR.
4. Si el resultado es $0$, el estado es perdedor; si no, es ganador.


# Suma de juegos

Si el juego se compone de $k$ subjuegos independientes y en cada turno el jugador **elige uno de ellos y mueve solo en ese**, el número de Grundy del juego completo es el XOR de los números de Grundy de los subjuegos:

$$g(G_1 + G_2 + \cdots + G_k) = g(G_1) \oplus g(G_2) \oplus \cdots \oplus g(G_k)$$

Cada subjuego se comporta como una pila de Nim cuyo tamaño es su Grundy, así que la estrategia es la misma de Nim: si el XOR es $s \neq 0$, se busca el subjuego $i$ donde $g_i \oplus s < g_i$ y se mueve a un estado de ese subjuego con Grundy $g_i \oplus s$. Siempre existe, porque desde un estado con Grundy $g_i$ se alcanzan todos los valores menores.

## Variantes de la suma de juegos

Si cambia la regla de qué se puede mover en un turno, ya no se usa el XOR. Sean $g_1, \ldots, g_K$ los números de Grundy de la posición actual de cada subjuego:

- **Se eligen algunos subjuegos (al menos uno) y se mueve en todos los elegidos:** el estado es perdedor si y solo si $g_i = 0$ para todo $i$.

- **Se eligen algunos subjuegos (al menos uno, pero no todos) y se mueve en todos los elegidos:** el estado es perdedor si y solo si
$$g_1 = g_2 = \cdots = g_K$$


# Juegos que se parten en subjuegos

A veces un movimiento **divide** el juego en varias partes independientes. Entonces el valor de ese movimiento es el XOR de los números de Grundy de las partes, y el Grundy del estado es el mex de todos esos valores:

$$g(v) = \operatorname{mex}\{\, a_{k,1} \oplus a_{k,2} \oplus \cdots \oplus a_{k,m_k} : k \text{ es un movimiento posible} \,\}$$

donde el movimiento $k$ genera subjuegos con números de Grundy $a_{k,1}, \ldots, a_{k,m_k}$.

## Juego de Grundy

Una pila de $n$ palitos. En cada turno se parte una pila en **dos pilas no vacías de tamaños distintos**, y pierde quien no puede mover. Si $f(n)$ es el número de Grundy de una pila de $n$ palitos:

$$f(n) = \operatorname{mex}\{\, f(a) \oplus f(n-a) : 1 \leq a < n-a \,\}$$

Los casos base son $f(1) = f(2) = 0$ (no se pueden partir). Los primeros valores son:

$$f(1), f(2), \ldots, f(8) = 0, 0, 1, 0, 2, 1, 0, 2$$

Por ejemplo, para $n = 8$ las particiones son $1+7$, $2+6$ y $3+5$:
$$f(8) = \operatorname{mex}\{f(1) \oplus f(7),\; f(2) \oplus f(6),\; f(3) \oplus f(5)\} = \operatorname{mex}\{0, 1, 3\} = 2$$
Como $f(8) \neq 0$, gana el primero, y la jugada ganadora es partir en $1+7$ porque $f(1) \oplus f(7) = 0$.

Tener en cuenta que para este juego no se conoce un patrón general en los valores de Grundy, así que hay que calcular la tabla, por ende la solución más rapida es $O(n^2)$. Hasta $10^6$ el valor más grande para el cual gana el segundo jugador es $1222$.


# Patrones en los números de Grundy

En muchos juegos que parecen difíciles de analizar, los números de Grundy resultan periódicos o con una forma fácil de describir. La forma de aprovecharlo:

1. Calcular $g(n)$ con la definición para valores pequeños de $n$.
2. Imprimir la tabla y buscar periodicidad, dependencia de $n \bmod k$, relación con potencias de $2$, etc.
3. Verificar el patrón por inducción si hace falta.

En la gran mayoría de los casos el patrón que se observa es verdadero. Pero hay juegos muy simples (como el juego de Grundy de arriba) donde no se conoce ninguna regularidad.

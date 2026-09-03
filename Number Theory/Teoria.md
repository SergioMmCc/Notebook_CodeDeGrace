# Propiedades y teoremas

- En promedio los números tienen $n^{1/3}$ divisores.
- Sea $d(i)$ el número de divisores de $i$, la sumatoria de $d(i)$ para $i$ entre $1$ y $n$ es aproximadamente $n \ln(n)$.
- Entre $1$ y $n$ hay aproximadamente $\pi(n) = \dfrac{n}{\ln(n)}$ números primos.
- La distancia promedio entre primos desde $1$ hasta $n$ es $\ln(n)$.
  Para todos los enteros hasta $10^9$, la máxima distancia entre primos es $282$. Hasta $10^{18}$ es $1442$.
- **Teorema de Bertrand:** para todo $n \geq 2$ hay al menos un primo $n < p < 2n$.

## Descomposición prima

Descomposición prima de un número: $n = p_1^{a_1} \cdot p_2^{a_2} \cdots p_k^{a_k}$

- **Número de divisores** de $n$:
$$\tau(n) = \prod_i (a_i + 1)$$

- **Suma de factores** de $n$:
$$\sigma(n) = \prod_i \frac{p_i^{a_i+1} - 1}{p_i - 1}$$

- **Producto de los factores** de $n$:
$$u(n) = n^{\tau(n)/2}$$

- Un número es **perfecto** si $n = \sigma(n) - n$, es decir, si la suma de sus factores entre $1$ y $n-1$ es igual a sí mismo.

- Una función es **multiplicativa** si $a, b$ coprimos implica $f(a \cdot b) = f(a) \cdot f(b)$.
- Las funciones $d(n)$ y $\sigma(n)$ son multiplicativas.

## Función phi de Euler (totient)

$\phi(n)$ da la cantidad de números coprimos con $n$ entre $1$ y $n$.
Ej: $\phi(12) = 4$, ya que $1, 5, 7$ y $11$ son coprimos con $12$.

$$\phi(n) = \prod_i p_i^{a_i - 1}(p_i - 1)$$

- Si $p$ es primo: $\phi(p) = p - 1$
- Si $p$ es primo y $k \geq 1$: $\phi(p^k) = p^k - p^{k-1}$
- Si $a$ y $b$ son coprimos: $\phi(a \cdot b) = \phi(a) \cdot \phi(b)$ (es multiplicativa)
- Para cualquier par $\{a, b\}$ con $d = \gcd(a, b)$:
$$\phi(a \cdot b) = \phi(a) \cdot \phi(b) \cdot \frac{d}{\phi(d)}$$
- Para cualquier número $n$: $\displaystyle\sum_{d \mid n} \phi(d) = n$
  d|n quiere decir que d es divisor de n

**Exponenciación con phi:**
- Para calcular $(a^{b^c}) \bmod m$:
  $m_1 = \phi(m)$, luego $(a^{(b^c \bmod m_1)}) \bmod m$.
- Para calcular $(a^{b^{c^d}}) \bmod m$:
  $m_1 = \phi(m)$, $m_2 = \phi(m_1)$, luego $(a^{(b^{(c^d \bmod m_2)} \bmod m_1)}) \bmod m$.
  Y así sucesivamente para cadenas de potencias.
- **Generalización:** $a^n \bmod m = a^{(n \bmod \phi(m))} \bmod m$

## Teoremas de congruencias

- **Pequeño teorema de Fermat:** $x^{m-1} \bmod m = 1$, siendo $m$ primo y $x, m$ coprimos.
  Además: $x^k \bmod m = x^{(k \bmod (m-1))} \bmod m$
- **Teorema de Euler (generalización):** $x^{\phi(m)} \bmod m = 1$ cuando $x, m$ son coprimos.
- **Inverso modular:** si existe, se calcula como $a^{-1} = a^{\phi(m)-1}$; si $m$ es primo, $x^{-1} = x^{m-2}$.

## Otros teoremas

- **Teorema de los números poligonales de Fermat:** todo número puede representarse como la suma de 3 números triangulares, 4 números cuadrados, 5 números pentagonales, y $n$ números $n$-poligonales.

- **Ternas pitagóricas:** ternas $(a, b, c)$ que satisfacen $a^2 + b^2 = c^2$, es decir, hay un triángulo rectángulo con lados $a$, $b$, $c$ (ej: $3, 4, 5$).
  - Si $(a, b, c)$ es una terna pitagórica, todas las ternas $(ka, kb, kc)$ con $k > 1$ también lo son.
  - Una terna es **primitiva** si $\gcd(a, b, c) = 1$. Todas las ternas pitagóricas pueden generarse a partir de estas usando un factor $k$.
  - **Fórmula de Euclides:** genera todas las ternas primitivas de la forma
    $$(n^2 - m^2,\ 2nm,\ n^2 + m^2)$$
    donde $0 < m < n$, $n$ y $m$ son coprimos y al menos uno de los dos es par.
  - La terna pitagórica primitiva más pequeña es $(3, 4, 5)$.

- **Teorema de Wilson:** un número $n$ es primo si y solo si $(n-1)! \bmod n = n - 1$.

## Fibonacci

- Empieza con $F_0 = 0$, $F_1 = 1$.
- **Fórmula de Binet:**
$$F_n = \frac{\left(\frac{1+\sqrt5}{2}\right)^n - \left(\frac{1-\sqrt5}{2}\right)^n}{\sqrt5}$$
  Sin embargo, es difícil de usar por el redondeo.
- **Con matrices:**
$$\begin{pmatrix}1 & 1\\1 & 0\end{pmatrix}^n = \begin{pmatrix}F_{n+1} & F_n\\F_n & F_{n-1}\end{pmatrix}$$
- **Identidad de Cassini:** $F_{n-1} F_{n-2} - F_n^2 = (-1)^n$
- **Regla de adición:** $F_{n+k} = F_k F_{n+1} + F_{k-1} F_n$
  Cuando $k = n$: $F_{2n} = F_n (F_{n+1} + F_{n-1})$
  Por lo tanto, para cualquier entero positivo $k$, $F_{kn}$ es múltiplo de $F_n$, y si $F_m$ es múltiplo de $F_n$, entonces $m$ es múltiplo de $n$.
- **Identidad del GCD:** $\gcd(F_m, F_n) = F_{\gcd(m,n)}$
- Para cualquier número $p$, existe una secuencia de Fibonacci módulo $p$ que se repite periódicamente, de longitud máxima $p^2$.
- **Teorema de Zeckendorf:** todo entero positivo tiene una única representación como suma de números de Fibonacci tal que ningún par de números es igual ni son dos consecutivos. A partir de esto se calcula el código de Fibonacci.

## Conjeturas (no probadas)

- **Goldbach:** todo entero $> 2$ puede representarse como la suma de 2 números primos.
- **Twin prime:** hay un número infinito de pares $\{p, p+2\}$ donde ambos son primos.
- **Legendre:** siempre hay un primo entre $n^2$ y $(n+1)^2$.
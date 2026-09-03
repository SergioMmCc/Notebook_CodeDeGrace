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
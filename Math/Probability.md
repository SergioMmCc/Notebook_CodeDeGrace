# Probabilidad básica

Notación: $P(A)$ es la probabilidad del evento $A$, $\Omega$ es el espacio muestral.

- Se asume que $0 \le P(A) \le 1$, $P(\Omega) = 1$ y $P(\emptyset) = 0$.

- **Casos equiprobables (caso discreto):**
$$P(A) = \frac{\text{casos favorables}}{\text{casos totales}}$$

- **Probabilidad de un intervalo bajo una densidad (caso continuo):**

Si $X$ tiene densidad $f(x)$, la probabilidad de que caiga en el intervalo $[a, b]$ es el área bajo la curva $f$ en ese intervalo:

$$P(a \le X \le b) = \int_a^b f(x)\,dx$$

Esto funciona porque el área total bajo $f$ es $1$, así que cada trozo representa una fracción de la probabilidad total.

**Ejemplo:** $f(x) = 2x$ en $(0, 1)$ y queremos $P(X < \frac{1}{2})$:

$$P\left(X < \frac{1}{2}\right) = \int_0^{1/2} 2x\,dx = 2 \cdot \frac{x^2}{2}\Bigg|_0^{1/2} = \left(\frac{1}{2}\right)^2 = \frac{1}{4}$$

- **Normalizar la densidad:** si dan la forma de la función $h(x)$ pero no la constante de normalización $c$, se plantea que la función de densidad es $f(x) = c\,h(x)$. Para hallar $c$ se integra $f(x)$ sobre el intervalo $[a, b]$ donde está definida y se despeja $c$ para que el área sea $1$:
$$\int_a^b c\,h(x)\,dx = 1 \quad\Longrightarrow\quad c = \frac{1}{\int_a^b h(x)\,dx}$$

  *Ejemplo:* $h(x) = 1$, entonces $f(x) = c$ en $[a, b]$ (densidad constante, la uniforme).
$$\int_a^b c\,dx = c\,(b-a) = 1 \quad\Longrightarrow\quad c = \frac{1}{b-a} \quad\Longrightarrow\quad f(x) = \frac{1}{b-a}$$

- **Complemento:**
$$P(A^c) = 1 - P(A)$$

- **Unión de dos eventos:**
$$P(A \cup B) = P(A) + P(B) - P(A \cap B)$$

- **Inclusión-exclusión:**
$$P\left(\bigcup_{i=1}^{n} A_i\right) = \sum_{k=1}^{n}(-1)^{k+1}\sum_{i_1<\dots<i_k}P(A_{i_1}\cap\dots\cap A_{i_k})$$

- **Cota de la unión (Boole):**
$$P\left(\bigcup_{i=1}^{n} A_i\right) \le \sum_{i=1}^{n} P(A_i)$$

La probabilidad de que ocurra al menos un éxito en $n$ intentos independientes, cada uno con probabilidad $p$: $1-(1-p)^n$ (se calcula como 1 menos la probabilidad de que no ocurra ninguno).


# Probabilidad condicional

Notación: $P(A \mid B)$ es la probabilidad de $A$ sabiendo que ocurrió $B$.

$$P(A \mid B) = \frac{P(A \cap B)}{P(B)} \quad \text{(válida solo para } P(B) > 0\text{)}$$

- **Regla del producto:**
$$P(A \cap B) = P(A \mid B)\,P(B) = P(B \mid A)\,P(A)$$

- **Regla de la cadena:**
$$P(A_1 \cap A_2 \cap \dots \cap A_n) = P(A_1)\,P(A_2 \mid A_1)\,P(A_3 \mid A_1 \cap A_2)\cdots P(A_n \mid A_1 \cap \dots \cap A_{n-1})$$

- **Probabilidad total** (si $B_1, \dots, B_k$ es una partición de $\Omega$):
$$P(A) = \sum_{i=1}^{k} P(A \mid B_i)\,P(B_i)$$

Que $B_1, \dots, B_k$ sea una partición de $\Omega$ significa que:
  - Son disjuntos: $B_i \cap B_j = \emptyset$ si $i \neq j$.
  - Cubren todo el espacio muestral: $B_1 \cup B_2 \cup \dots \cup B_k = \Omega$.

  Es decir, en cualquier resultado del experimento ocurre exactamente uno de los $B_i$. Un caso común es $B$ y $B^c$, que siempre forman una partición. Se exige para que $A$ se pueda separar en pedazos sin contar dos veces el mismo caso y sin dejar casos por fuera: $P(A) = \sum_{i=1}^{k} P(A \cap B_i)$.

- **Teorema de Bayes:**
$$P(B_j \mid A) = \frac{P(A \mid B_j)\,P(B_j)}{\sum_{i=1}^{k} P(A \mid B_i)\,P(B_i)}$$

- **Bayes con momios (odds):**
$$\frac{P(H \mid E)}{P(H^c \mid E)} = \frac{P(H)}{P(H^c)} \cdot \frac{P(E \mid H)}{P(E \mid H^c)}$$

- **Complemento condicional** ($P(\cdot \mid B)$ es en sí misma una probabilidad):
$$P(A^c \mid B) = 1 - P(A \mid B)$$


# Independencia

- $A$ y $B$ son independientes si y solo si:
$$P(A \cap B) = P(A)\,P(B) \iff P(A \mid B) = P(A)$$

- Los eventos $A_1, \dots, A_n$ son mutuamente independientes si para todo subconjunto $S$ de índices:
$$P\left(\bigcap_{i \in S} A_i\right) = \prod_{i \in S} P(A_i)$$

- **Independencia condicional:**
$$P(A \cap B \mid C) = P(A \mid C)\,P(B \mid C)$$

- **Al menos un evento ocurre (independientes):**
$$1 - \prod_{i=1}^{n}\left(1 - P(A_i)\right)$$

Para tres eventos $A, B, C$, la independencia mutua exige que se cumplan los productos de cada par y también del trío:
$$P(A \cap B \cap C) = P(A)\,P(B)\,P(C)$$

Tener en cuenta que la independencia por pares no implica independencia mutua, y que dos eventos disjuntos con probabilidad positiva no son independientes porque el cumplimiento de uno implica el no cumplimiento del otro.


# Valor esperado

Notación: $E[X]$ o $\mu$ es el valor esperado de la variable aleatoria $X$.

- **Caso discreto:**
$$E[X] = \sum_{x} x\,P(X = x)$$

- **Caso continuo** (con densidad $f$):
$$E[X] = \int_{-\infty}^{\infty} x\,f(x)\,dx$$

- **Desde la función de distribución:** si se conoce $F(x) = P(X \le x)$, la densidad es su derivada:
$$f(x) = F'(x)$$

  Para la uniforme, $F(x) = \frac{x-a}{b-a}$ y al derivar sale $\frac{1}{b-a}$.

- **Esperanza de una función de $X$ (LOTUS):**
$$E[g(X)] = \sum_{x} g(x)\,P(X = x) \quad \text{o} \quad \int g(x)\,f(x)\,dx$$

- **Fórmula de la cola** (para $X$ entera y no negativa):
$$E[X] = \sum_{k=1}^{\infty} P(X \ge k)$$

- **Fórmula de la cola, caso continuo** ($X \ge 0$):
$$E[X] = \int_{0}^{\infty} P(X > t)\,dt$$

## Propiedades

Para constantes $a$, $b$, $c$:

$$E[c] = c \qquad E[X + c] = E[X] + c \qquad E[cX] = c\,E[X] \qquad E[aX + b] = a\,E[X] + b$$

- Si $X \le Y$ siempre, entonces $E[X] \le E[Y]$.
- Si $X$ y $Y$ son independientes: $E[XY] = E[X]\,E[Y]$ (Pero el hecho de que $E[XY] = E[X]\,E[Y]$ no asegura que $X$ y $Y$ sean independientes).
- $E[g(X)] \neq g(E[X])$ en general. Si $g$ es convexa: $g(E[X]) \le E[g(X)]$ (Jensen).

## Desigualdades

- **Markov** ($X \ge 0$, $a > 0$):
$$P(X \ge a) \le \frac{E[X]}{a}$$

- **Chebyshev:**
$$P(|X - \mu| \ge k\sigma) \le \frac{1}{k^2}$$

  Aquí $\mu$ es la media, $\sigma$ la desviación estándar y $k > 0$ (solo aporta información si $k > 1$). Se lee así: la probabilidad de que $X$ esté a $k$ desviaciones estándar o más de la media es a lo sumo $\frac{1}{k^2}$.

# Linealidad de la esperanza

Para variables aleatorias cualesquiera, sin importar si son independientes o no:

$$E[X + Y] = E[X] + E[Y]$$

$$E\left[\sum_{i=1}^{n} c_i X_i\right] = \sum_{i=1}^{n} c_i\,E[X_i]$$

Cuándo pensar en linealidad:
- Calcular $E[X]$ como promedio ponderado es engorroso porque las probabilidades de cada valor son difíciles de hallar.
- $X$ se puede escribir como suma de variables más simples.

Receta: escribir $X = X_1 + X_2 + \dots + X_n$, hallar cada $E[X_i]$ y sumarlas.

- **Identidad de Wald** (si $N$ es aleatorio e independiente de los $X_i$, que están idénticamente distribuidos):
$$E\left[\sum_{i=1}^{N} X_i\right] = E[N]\,E[X_1]$$

## Ejemplo: avance esperado de un caminante

Cada minuto avanza $+1$ con probabilidad $\frac{1}{2}$, se queda quieto con $\frac{1}{3}$ y retrocede $-1$ con $\frac{1}{6}$. En $n$ minutos el avance neto esperado es $n\left(\frac{1}{2}-\frac{1}{6}\right)$, es decir, $20$ para $n = 60$.

# Variables indicadoras
$$\mathbb{1}_A = \begin{cases}1 & \text{si } A \text{ ocurre}\\ 0 & \text{si no}\end{cases} \qquad\Longrightarrow\qquad E[\mathbb{1}_A] = P(A)$$

# Esperanza condicional

- **Caso discreto:**
$$E[X \mid Y = y] = \sum_{x} x\,P(X = x \mid Y = y)$$

- **Condicionando a un evento $A$:**
$$E[X \mid A] = \frac{E[X\,\mathbb{1}_A]}{P(A)}$$

  Aquí $E[X\,\mathbb{1}_A]$ suma solo los valores de $X$ donde ocurre $A$. Dividir entre $P(A)$ reescala ese promedio.

- **Caso continuo** (condicionando a que $X$ caiga en $\chi$):
$$E[X \mid X \in \chi] = \frac{\int_{\chi} x\,f(x)\,dx}{P(X \in \chi)}$$

- **Ley de la esperanza total** (si $A_1, \dots, A_k$ es una partición de $\Omega$):
$$E[X] = \sum_{i=1}^{k} E[X \mid A_i]\,P(A_i)$$

- **Ley de la torre:**
$$E[X] = E\big[E[X \mid Y]\big]$$

  Tener en cuenta que la ley de la torre se usa cuando **uno elige condicionar a $Y$** para simplificar el cálculo, pues en casos donde el cálculo de $E[X]$ directo es complicado, dividir el problema en subcasos puede ser más sencillo. Se debe realizar el cálculo para todo valor posible de $Y$.

  La fórmula completa es:
$$E[X] = \sum_{y} E[X \mid Y = y]\,P(Y = y)$$

  O en caso continuo:
$$E[X] = \int E[X \mid Y = y]\,f_Y(y)\,dy$$


# Método de estados

Para variables que miden el tiempo o número de pasos hasta completar un proceso. Se define $E_s$ como la cantidad esperada de pasos restantes estando en el estado $s$:

$$E_s = 1 + \sum_{s'} P(s \to s')\,E_{s'}, \qquad E_{\text{final}} = 0$$

Tener en cuenta que el $1$ cuenta el paso que se da desde el estado actual. Si el grafo de estados tiene ciclos, se plantea un sistema de ecuaciones lineales.

- **Geométrica** (primer éxito con probabilidad $p$): $E_1 = \frac{1}{p}$

- **Racha de $n$ éxitos consecutivos** (cada intento con probabilidad $p$), con $E_n$ el número esperado de intentos para lograr $n$ éxitos seguidos:
$$E_0 = 0, \qquad E_n = \frac{E_{n-1} + 1}{p} \qquad\Longrightarrow\qquad E_n = \frac{p^{-n} - 1}{1 - p}$$

- **Ruina del jugador:** se avanza $+1$ con probabilidad $p$ y $-1$ con probabilidad $q = 1-p$, empezando en $k$ y parando al llegar a $0$ o a $N$.
  - Si $p = q = \frac{1}{2}$: $E[\text{pasos}] = k(N-k)$
  - Si $p \neq q$: $E[\text{pasos}] = \frac{k}{q-p} - \frac{N}{q-p}\cdot\frac{1-(q/p)^k}{1-(q/p)^N}$

- **Llegar al nivel inferior:** el número esperado de pasos para llegar al nivel inmediatamente inferior a aquel desde el cual se inició, donde en cada paso se baja un nivel con probabilidad $a$ y se sube uno con probabilidad $b < a$:
$$E = \frac{1}{a-b}$$
Para llegar $m$ niveles más abajo el tiempo esperado es $\frac{m}{a-b}$.

- **Coleccionista de cupones:** se quiere coleccionar $n$ tipos de cupones donde en cada compra sale uno al azar con la misma probabilidad. 
Estando en el estado con $i-1$ cupones distintos, sale uno nuevo con probabilidad $\frac{n-(i-1)}{n}$, por lo que ese paso dura en promedio $\frac{n}{n-i+1}$. Por linealidad:

$$E[T] = \sum_{i=1}^{n}\frac{n}{n-i+1}$$


# Varianza y covarianza
La varianza mide qué tan dispersos están los valores de $X$ alrededor de su media $\mu$. Es el promedio de la distancia al cuadrado a la media.

La covarianza mide cómo se mueven juntas dos variables $X$ y $Y$:
Positiva: cuando $X$ está por encima de su media, $Y$ tiende a estarlo también (suben juntas).
Negativa: cuando $X$ sube, $Y$ tiende a bajar.
Cero: no hay relación lineal.

- **Varianza:**
$$\operatorname{Var}(X) = E[(X-\mu)^2] = E[X^2] - E[X]^2$$

- **Escala y traslación:**
$$\operatorname{Var}(aX + b) = a^2\operatorname{Var}(X)$$

- **Covarianza:**
$$\operatorname{Cov}(X, Y) = E[XY] - E[X]\,E[Y]$$

- **Varianza de una suma:**
$$\operatorname{Var}\left(\sum_{i=1}^{n} X_i\right) = \sum_{i=1}^{n}\operatorname{Var}(X_i) + 2\sum_{i<j}\operatorname{Cov}(X_i, X_j)$$
Si las variables son independientes, todas las covarianzas son $0$ y las varianzas se suman.

- **Varianza de una indicadora:**
$$\operatorname{Var}(\mathbb{1}_A) = P(A)\left(1 - P(A)\right)$$

- **Segundo momento de un conteo** ($X = \sum_i \mathbb{1}_{A_i}$):
$$E[X^2] = \sum_i P(A_i) + 2\sum_{i<j} P(A_i \cap A_j)$$

- **Ley de la varianza total:**
$$\operatorname{Var}(X) = E[\operatorname{Var}(X \mid Y)] + \operatorname{Var}(E[X \mid Y])$$


# Distribuciones comunes

Para cada una se muestra $E[X]$ y $\operatorname{Var}(X)$.

- **Bernoulli($p$):** Un solo intento, $X=1$ si hay éxito $X=0$ si no. $E[X] = p$, $\;\operatorname{Var}(X) = p(1-p)$

- **Binomial($n, p$)** (éxitos en $n$ intentos):
$$P(X=k) = \binom{n}{k}p^k(1-p)^{n-k}, \qquad E[X] = np, \qquad \operatorname{Var}(X) = np(1-p)$$

- **Geométrica($p$)** (intento en que ocurre el primer éxito):
$$P(X=k) = (1-p)^{k-1}p, \qquad E[X] = \frac{1}{p}, \qquad \operatorname{Var}(X) = \frac{1-p}{p^2}$$

- **Binomial negativa($r, p$)** (intento en que ocurre el $r$-ésimo éxito):
$$P(X=k) = \binom{k-1}{r-1}p^r(1-p)^{k-r}, \qquad E[X] = \frac{r}{p}, \qquad \operatorname{Var}(X) = \frac{r(1-p)}{p^2}$$

- **Hipergeométrica($N, K, n$)** (éxitos en $n$ extracciones sin reemplazo de una población de $N$ con $K$ éxitos):
$$P(X=k) = \frac{\binom{K}{k}\binom{N-K}{n-k}}{\binom{N}{n}}, \qquad E[X] = n\frac{K}{N}, \qquad \operatorname{Var}(X) = n\,\frac{K}{N}\,\frac{N-K}{N}\,\frac{N-n}{N-1}$$

- **Poisson($\lambda$)** probabilidad de que ocurra $k$ veces un evento en un intervalo fijo, siendo que el promedio de ocurrencias en ese intervalo es $\lambda$:
$$P(X=k) = e^{-\lambda}\frac{\lambda^k}{k!}, \qquad E[X] = \operatorname{Var}(X) = \lambda$$
Ejemplo: llegan en promedio $3$ correos por hora, y la probabilidad de recibir exactamente $5$ en una hora es $e^{-3}\frac{3^5}{5!}$.

- **Uniforme continua en $[a, b]$** (Todos los valores en el intervalo son igual de probables): $E[X] = \frac{a+b}{2}$, $\;\operatorname{Var}(X) = \frac{(b-a)^2}{12}$

- **Exponencial($\lambda$):** $X$ es el tiempo de espera hasta que ocurre un evento que sucede en promedio cada $\frac{1}{\lambda}$ unidades de tiempo.
$\;E[X] = \frac{1}{\lambda}$, $\;\operatorname{Var}(X) = \frac{1}{\lambda^2}$

  Probabilidad de esperar a lo sumo un tiempo $x$:
$$P(X \le x) = 1 - e^{-\lambda x}$$

  Probabilidad de esperar más de un tiempo $x$:
$$P(X > x) = e^{-\lambda x}$$

  No tiene memoria: haber esperado ya un rato no cambia cuánto falta.
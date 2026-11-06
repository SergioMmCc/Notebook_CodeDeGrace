// Algunas notas:
// - La probabilidad de que 2 cadenas tengan el mismo hashing es de n / m
//   siendo n la longitud de la cadena mas larga
// - Si tengo un conjunto de hashes de k cadenas con longitud de maximo n,
//   la probabilidad de que 2 cadenas tengan igual hash es de (k^2 * n) / m
//   Por ende, si k y n son de alrededor de 1e5 y m alrededor de 1e9, es 
//   casi seguro que habra colisiones. Una forma de solucionarlo puede ser 
//   un primo m mas largo, como 2^61 - 1 (2305843009213693951) y usar 
//   enteros de 128 bits para las multiplicaciones, aunque ahora el hashing 
//   y las queries serian un poco mas lentas. (Para hacerlo puedo simplemente
//   poner using ll = __int128; y cambiar el modulo).
// - Al usar doble modulo se estan reduciendo esas probabilidades considerablemente

// Hashing con doble modulo
// En caso de necesitar otro modulo
// 1000234999, 1000567999, 1000111997, 1000777121, 999727999, 1070777777
const int MOD[] = { 1001864327, 1001265673 }, N = 1e6 + 10;
const pii BASE(257, 367), ZERO(0, 0), ONE(1, 1);
inline int add(int a, int b, int mod) { return a+b >= mod ? a+b-mod : a+b; }
inline int sbt(int a, int b, int mod) { return a-b < 0 ? a-b+mod : a-b; }
inline int mul(int a, int b, int mod) { return ll(a) * b % mod;} 
inline ll operator ! (const pii a) { return (ll(a.fi) << 32) | a.se; }
inline pii operator + (const pii& a, const pii& b) {
  return {add(a.fi, b.fi, MOD[0]), add(a.se, b.se, MOD[1])};}
inline pii operator - (const pii& a, const pii& b) {
  return {sbt(a.fi, b.fi, MOD[0]), sbt(a.se, b.se, MOD[1])};}
inline pii operator * (const pii& a, const pii& b) {
  return {mul(a.fi, b.fi, MOD[0]), mul(a.se, b.se, MOD[1])};}

pii base[N]{ONE};
void prepare() { for1(i, N-1) base[i] = base[i-1] * BASE; }
template <class type>
struct hashing {   /// HACELEEE PREPAREEEE en el main!!!
  vii ha;       // ha[i] = t[i]*p0 + t[i+1]*p1 + t[i+2]*p2 + ..
  hashing(type &t): ha(sz(t)+1, ZERO){ // O(n)
    for(int i = sz(t) - 1; i >= 0; --i) ha[i] = ha[i+1] * BASE + pii{t[i], t[i]};
  }
  pii query(int l, int r){ return ha[l] - ha[r+1] * base[r-l+1]; } // [l,r], O(1)
};
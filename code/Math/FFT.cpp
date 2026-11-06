#include "../template.h"

/*
FFT
- Multiplica un polinomio grado 'n' con otro grado 'm'.
- Complejidad, sea N la primer potencia de 2 mayor a n+m-1: 
  temporal: O(N * log(N)), espacial: O(N).
*/

typedef double fd; // double para los datos (más rápido); ld queda para los twiddles
typedef complex<fd> C;

void fft(vector<C>& a){
    int n = sz(a), L = 31 - __builtin_clz(n);
    static vector<complex<ld>> R(2, 1);
    static vector<C> rt(2, 1);
    for(static int k = 2; k < n; k *= 2){
        R.resize(n); rt.resize(n);
        auto x = polar(ld(1), acos(-1.0L) / k);
        forlr(i, k, 2*k-1) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
    }
    vi rev(n);
    for0(i, n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    for0(i, n) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for(int k = 1; k < n; k *= 2)
        for(int i = 0; i < n; i += 2 * k) for0(j, k){
            auto x = (fd *)&rt[j+k], y = (fd *)&a[i+j+k];
            C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);
            a[i + j + k] = a[i + j] - z;
            a[i + j] += z;
        }
}

// c[x] = sum a[i]*b[x-i]   (resultado exacto en enteros)
vl conv(const vl& a, const vl& b) {
    if (a.empty() || b.empty()) return {};
    vl res(sz(a) + sz(b) - 1);
    int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
    vector<C> in(n), out(n);
    copy(all(a), begin(in));
    for0(i, sz(b)) in[i].imag(b[i]);
    fft(in);
    for (C& x : in) x *= x;
    for0(i, n) out[i] = in[-i & (n - 1)] - conj(in[i]);
    fft(out);
    for0(i, sz(res)) res[i] = floor(imag(out[i]) / (4 * n) + 0.5);
    return res;
}

// igual que conv pero módulo M (cualquier M, no solo primos NTT)
vl convMod(const vl& a, const vl& b, int M) {
    if (a.empty() || b.empty()) return {};
    vl res(sz(a) + sz(b) - 1);
    int B = 32 - __builtin_clz(sz(res)), n = 1 << B, cut = int(sqrt(M));
    vector<C> L(n), R(n), outs(n), outl(n);
    for0(i, sz(a)) L[i] = C((int)a[i] / cut, (int)a[i] % cut);
    for0(i, sz(b)) R[i] = C((int)b[i] / cut, (int)b[i] % cut);
    fft(L), fft(R);
    for0(i, n) {
        int j = -i & (n - 1);
        outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
        outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / C(0, 1);
    }
    fft(outl), fft(outs);
    for0(i, sz(res)) {
        ll av = ll(real(outl[i]) + .5), cv = ll(imag(outs[i]) + .5);
        ll bv = ll(imag(outl[i]) + .5) + ll(real(outs[i]) + .5);
        res[i] = ((av % M * cut + bv) % M * cut + cv) % M;
    }
    return res;
}

void solver(){
    int n, m; cin>>n>>m;            // cantidad de coeficientes de A y de B
    vl a(n), b(m);
    for0(i, n) cin >> a[i];   // a[i] = coeficiente de x^i
    for0(i, m) cin >> b[i];
    vl c = conv(a, b);        // tamaño n + m - 1
    for0(i, sz(c)) cout << c[i] << " \n"[i + 1 == sz(c)];
}
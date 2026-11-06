#include "../template.h"

// NO TESTED in a real problem yet

///////////////////////////////////////////
// ELIMINACIÓN DE GAUSS-JORDAN
//
// 1. Gauss modular (mod primo, por defecto 1e9+7): sistemas, rango, det, inversa, espacio nulo.
// 2. Gauss mod 2 con bitset: sistemas XOR (~64x más rápido que vector<bool>).
// 3. Gauss real (long double, pivoteo parcial). Acepta entradas long long.
//
// Convención de status:  1 = solución única | 0 = infinitas | -1 = sin solución
//
// Notas:
//  - Las entradas pueden ser negativas o >= mod: se normalizan internamente.
//  - El módulo DEBE ser primo (se usan inversos modulares). Con 1e9+7 / 998244353 no hay problema.
//  - Nº de soluciones (si existen) = mod^(m - rank)  (XOR: 2^(m - rank)).
//  - Complejidad: O(n * m * min(n, m)).
////////////////////////////////////////

const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;

inline ll norm(ll a, ll m = MOD) { a %= m; return a < 0 ? a + m : a; }
inline ll mulmod(ll a, ll b, ll m = MOD) { return (ll)((__int128)a * b % m); }

// Inverso modular con Euclides extendido iterativo. Devuelve -1 si no existe.
ll mod_inv(ll a, ll m = MOD) {
    a = norm(a, m);
    ll b = m, x0 = 1, x1 = 0;
    while (b) {
        ll q = a / b;
        ll t = a - q * b; a = b; b = t;
        t = x0 - q * x1; x0 = x1; x1 = t;
    }
    if (a != 1) return -1;
    return norm(x0, m);
}

ll binpow(ll b, ll e, ll m = MOD) {
    b = norm(b, m);
    ll r = 1 % m;
    while (e > 0) {
        if (e & 1) r = mulmod(r, b, m);
        b = mulmod(b, b, m);
        e >>= 1;
    }
    return r;
}

// Requiere matriz n*m
struct Matrix {
    int n, m;
    vector<vl> M;
 
    Matrix() : n(0), m(0) {}
    Matrix(int n) : n(n), m(n), M(n, vl(n, 0)) {}
    Matrix(int n, int m) : n(n), m(m), M(n, vl(m, 0)) {}
    Matrix(const vector<vl>& mat) : n(sz(mat)), m(sz(mat) ? sz(mat[0]) : 0), M(mat) {}
 
    vl& operator[](int i) { return M[i]; }
    const vl& operator[](int i) const { return M[i]; }
 
    static Matrix identity(int n) {
        Matrix I(n);
        for (int i = 0; i < n; i++) I.M[i][i] = 1;
        return I;
    }
 
    Matrix add(const Matrix& o, ll mod = MOD) const {
        Matrix r(n, m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) r.M[i][j] = norm(M[i][j] + o.M[i][j], mod);
        return r;
    }
 
    // O(n * k * m)
    Matrix mul(const Matrix& o, ll mod = MOD) const {
        Matrix r(n, o.m);
        for (int i = 0; i < n; i++)
            for (int k = 0; k < m; k++) {
                ll a = norm(M[i][k], mod);
                if (!a) continue;
                for (int j = 0; j < o.m; j++) {
                    ll v = r.M[i][j] + mulmod(a, norm(o.M[k][j], mod), mod);
                    if (v >= mod) v -= mod;
                    r.M[i][j] = v;
                }
            }
        return r;
    }
 
    vl mul(const vl& v, ll mod = MOD) const {
        vl r(n, 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                r[i] = norm(r[i] + mulmod(norm(M[i][j], mod), norm(v[j], mod), mod), mod);
        return r;
    }
 
    Matrix operator+(const Matrix& o) const { return add(o); }
    Matrix operator*(const Matrix& o) const { return mul(o); }
    vl operator*(const vl& v) const { return mul(v); }
 
    // Matriz cuadrada elevada a exp, O(log(exp) * n^3)
    Matrix binpow(ll exp, ll mod = MOD) const {
        Matrix res = identity(n), base = *this;
        while (exp > 0) {
            if (exp & 1) res = res.mul(base, mod);
            base = base.mul(base, mod);
            exp >>= 1;
        }
        return res;
    }
 
    Matrix transpose() const {
        Matrix T(m, n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) T.M[j][i] = M[i][j];
        return T;
    }
 
    friend ostream& operator<<(ostream& os, const Matrix& a) {
        os << "\nMatrix (" << a.n << "x" << a.m << "):\n";
        for (int i = 0; i < a.n; i++) {
            for (int j = 0; j < a.m; j++) os << a.M[i][j] << " ";
            os << "\n";
        }
        return os << "=================\n";
    }
 
    // Declarados aquí, definidos al final del archivo
    ll det(ll mod = MOD) const;
    int get_rank(ll mod = MOD) const;
    pair<bool, Matrix> inv(ll mod = MOD) const;
};


//////////////////////////////////////////////
// 1. GAUSS MODULAR
//////////////////////////////////////////////

// Núcleo: forma escalonada reducida (RREF) in-place, pivoteando solo en las primeras `lim` columnas.
// Las operaciones afectan a TODAS las columnas (permite matriz aumentada).
// where[col] = fila del pivote de esa columna (o -1 si es libre). Devuelve el rango.
int rref_mod(Matrix& a, int lim, vi& where, ll mod = MOD) {
    int n = a.n, m = a.m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) a.M[i][j] = norm(a.M[i][j], mod);

    where.assign(lim, -1);
    int row = 0;
    for (int col = 0; col < lim && row < n; col++) {
        int sel = -1;
        for (int i = row; i < n; i++)
            if (a.M[i][col]) { sel = i; break; }
        if (sel == -1) continue;

        swap(a.M[sel], a.M[row]);
        where[col] = row;

        ll inv = mod_inv(a.M[row][col], mod);
        for (int j = col; j < m; j++) a.M[row][j] = mulmod(a.M[row][j], inv, mod);

        for (int i = 0; i < n; i++) {
            if (i == row) continue;
            ll f = a.M[i][col];
            if (!f) continue;
            for (int j = col; j < m; j++) {
                ll v = a.M[i][j] - mulmod(f, a.M[row][j], mod);
                if (v < 0) v += mod;
                a.M[i][j] = v;
            }
        }
        row++;
    }
    return row;
}

struct SolMod {
    int status;          // 1 única, 0 infinitas, -1 sin solución
    int rank;            // rango de A
    vl x;                // solución particular (variables libres = 0); vacío si no hay solución
    vector<vl> basis;    // base del espacio nulo (m - rank vectores). Solución general = x + combinación
};

// Resuelve A * x = b (mod mod). A es n x m, b de tamaño n.
SolMod solve_mod(const Matrix& A, const vl& b, ll mod = MOD) {
    int n = A.n, m = A.m;
    Matrix aug(n, m + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) aug.M[i][j] = A.M[i][j];
        aug.M[i][m] = b[i];
    }
    vi where;
    int rank = rref_mod(aug, m, where, mod);

    SolMod res;
    res.rank = rank;

    // Filas >= rank son 0 en las primeras m columnas: si su término es != 0, inconsistente
    for (int i = rank; i < n; i++)
        if (aug.M[i][m] != 0) { res.status = -1; return res; }

    res.x.assign(m, 0);
    for (int c = 0; c < m; c++)
        if (where[c] != -1) res.x[c] = aug.M[where[c]][m];

    for (int f = 0; f < m; f++) {
        if (where[f] != -1) continue;
        vl v(m, 0);
        v[f] = 1;
        for (int c = 0; c < m; c++)
            if (where[c] != -1) v[c] = norm(-aug.M[where[c]][f], mod);
        res.basis.push_back(v);
    }

    res.status = (rank == m) ? 1 : 0;
    return res;
}

// Devuelve directamente la solución particular (vector vacío si no hay solución)
vl solve_vector(const Matrix& A, const vl& b, ll mod = MOD) {
    SolMod r = solve_mod(A, b, mod);
    return r.status == -1 ? vl() : r.x;
}

// Determinante de matriz cuadrada, O(n^3)
ll determinant(Matrix a, ll mod = MOD) {
    int n = a.n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) a.M[i][j] = norm(a.M[i][j], mod);

    ll det = 1 % mod;
    for (int i = 0; i < n; i++) {
        int sel = -1;
        for (int j = i; j < n; j++)
            if (a.M[j][i]) { sel = j; break; }
        if (sel == -1) return 0;
        if (sel != i) { swap(a.M[sel], a.M[i]); det = norm(-det, mod); }

        det = mulmod(det, a.M[i][i], mod);
        ll inv = mod_inv(a.M[i][i], mod);
        for (int j = i + 1; j < n; j++) {
            ll f = mulmod(a.M[j][i], inv, mod);
            if (!f) continue;
            for (int c = i; c < n; c++) {
                ll v = a.M[j][c] - mulmod(f, a.M[i][c], mod);
                if (v < 0) v += mod;
                a.M[j][c] = v;
            }
        }
    }
    return det;
}

// Rango de una matriz n x m
int rank_matrix(Matrix a, ll mod = MOD) {
    vi where;
    return rref_mod(a, a.m, where, mod);
}

// Matriz inversa. Retorna {existe, inversa}
pair<bool, Matrix> inverse_matrix(const Matrix& a, ll mod = MOD) {
    int n = a.n;
    Matrix aug(n, 2 * n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) aug.M[i][j] = a.M[i][j];
        aug.M[i][n + i] = 1;
    }
    vi where;
    if (rref_mod(aug, n, where, mod) < n) return {false, Matrix()};
    Matrix res(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) res.M[i][j] = aug.M[i][n + j];
    return {true, res};
}

inline ll Matrix::det(ll mod) const { return determinant(*this, mod); }
inline int Matrix::get_rank(ll mod) const { return rank_matrix(*this, mod); }
inline pair<bool, Matrix> Matrix::inv(ll mod) const { return inverse_matrix(*this, mod); }

//////////////////////////////////////////////
// 2. GAUSS MOD 2 CON BITSET
// Cada ecuación es un bitset: bits 0..m-1 = coeficientes, bit m = término independiente.
// Requiere m < XN.
/////////////////////////////////////////////
const int XN = 2005;
typedef bitset<XN> bs;

// Devuelve status. rank por referencia. ans = solución particular (libres = 0).
int gauss_xor(vector<bs> a, int m, bs& ans, int& rank) {
    int n = sz(a);
    vi where(m, -1);
    int row = 0;
    for (int col = 0; col < m && row < n; col++) {
        int sel = -1;
        for (int i = row; i < n; i++)
            if (a[i][col]) { sel = i; break; }
        if (sel == -1) continue;
        swap(a[sel], a[row]);
        where[col] = row;
        for (int i = 0; i < n; i++)
            if (i != row && a[i][col]) a[i] ^= a[row];
        row++;
    }
    rank = row;
    ans.reset();
    for (int i = row; i < n; i++)
        if (a[i][m]) return -1;
    for (int c = 0; c < m; c++)
        if (where[c] != -1 && a[where[c]][m]) ans[c] = 1;
    return row == m ? 1 : 0;
}

// A (n x m de 0/1) * x = b (mod 2). Devuelve la solución como vb (vacío si no hay).
vb solve_vector_xor(const vector<vb>& A, const vb& b) {
    int n = sz(A), m = n ? sz(A[0]) : 0;
    vector<bs> aug(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) aug[i][j] = A[i][j];
        aug[i][m] = b[i];
    }
    bs ans; int rank;
    if (gauss_xor(aug, m, ans, rank) == -1) return {};
    vb res(m);
    for (int j = 0; j < m; j++) res[j] = ans[j];
    return res;
}

/////////////////////////////////////////
// 3. GAUSS REAL (long double, pivoteo parcial). Entradas long long o ld.
////////////////////////////////////////

// a: matriz aumentada n x (m+1). Devuelve status; rank por referencia.
int gauss_real(vector<vector<ld>> a, vector<ld>& ans, int& rank) {
    int n = sz(a);
    if (n == 0) { ans.clear(); rank = 0; return 0; }
    int m = sz(a[0]) - 1;
    vi where(m, -1);
    int row = 0;
    for (int col = 0; col < m && row < n; col++) {
        int sel = row;
        for (int i = row + 1; i < n; i++)
            if (fabsl(a[i][col]) > fabsl(a[sel][col])) sel = i;
        if (fabsl(a[sel][col]) < EPS) continue;

        swap(a[sel], a[row]);
        where[col] = row;

        ld piv = a[row][col];
        for (int j = col; j <= m; j++) a[row][j] /= piv;
        for (int i = 0; i < n; i++) {
            if (i == row) continue;
            ld f = a[i][col];
            if (fabsl(f) < EPS) continue;
            for (int j = col; j <= m; j++) a[i][j] -= f * a[row][j];
        }
        row++;
    }
    rank = row;
    for (int i = row; i < n; i++)
        if (fabsl(a[i][m]) > EPS) { ans.clear(); return -1; }

    ans.assign(m, 0);
    for (int c = 0; c < m; c++)
        if (where[c] != -1) ans[c] = a[where[c]][m];
    return row == m ? 1 : 0;
}

// A * x = b con A, b en long long. Devuelve {status, x}
pair<int, vector<ld>> solve_real(const vector<vl>& A, const vl& b) {
    int n = sz(A), m = n ? sz(A[0]) : 0;
    vector<vector<ld>> aug(n, vector<ld>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) aug[i][j] = A[i][j];
        aug[i][m] = b[i];
    }
    vector<ld> ans; int rank;
    int st = gauss_real(aug, ans, rank);
    return {st, ans};
}

// Determinante real con pivoteo parcial, O(n^3)
ld determinant_real(vector<vector<ld>> a) {
    int n = sz(a);
    ld det = 1;
    for (int i = 0; i < n; i++) {
        int sel = i;
        for (int j = i + 1; j < n; j++)
            if (fabsl(a[j][i]) > fabsl(a[sel][i])) sel = j;
        if (fabsl(a[sel][i]) < EPS) return 0;
        if (sel != i) { swap(a[sel], a[i]); det = -det; }
        det *= a[i][i];
        for (int j = i + 1; j < n; j++) {
            ld f = a[j][i] / a[i][i];
            for (int c = i; c < n; c++) a[j][c] -= f * a[i][c];
        }
    }
    return det;
}

////////////////////////////////////////////
// EJEMPLO DE USO
///////////////////////////////////////////
void solver() {
    // --- Modular:  2x + y = 5,  x + 3y = 10 ---
    Matrix A({{2, 1}, {1, 3}});
    vl b = {5, 10};

    SolMod r = solve_mod(A, b);
    cout << "status=" << r.status << " rank=" << r.rank << " x: ";
    for (ll v : r.x) cout << v << " ";
    cout << endl;                       // status=1 rank=2 x: 1 3
    cout << "Det: " << A.det() << " Rank: " << A.get_rank() << endl;
    auto [ok, Ainv] = A.inv();
    if (ok) cout << Ainv;

    // --- XOR:  x1 ^ x2 = 1,  x1 = 0 ---
    vector<vb> Ax = {{1, 1}, {1, 0}};
    vb bx = {1, 0};
    vb sx = solve_vector_xor(Ax, bx);
    cout << "XOR: ";
    for (bool v : sx) cout << v << " ";
    cout << endl;                       // 0 1

    // --- Real (entradas long long) ---
    auto [st, xr] = solve_real({{2, 1}, {1, 3}}, {5, 10});
    cout << "Real (status " << st << "): ";
    for (ld v : xr) cout << fixed << setprecision(2) << v << " ";
    cout << endl;                       // 1.00 3.00
}
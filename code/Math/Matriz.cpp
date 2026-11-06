#include "../template.h"

/*
- Algunas funciones para operaciones con matrices perfectas (n x n).
APLICACIONES:
- Se puede hallar el numero de caminos de una longitud especifica 
  'k' elevando su matriz de adyacencia a la potencia 'k'.
  La posicion i,j en dicha matriz dice la cantidad de caminos de
  longitud 'k' que inician en el vertice 'i' y terminan en el 
  vertice 'j'.
  * Sirve tanto para grafos dirigidos como no dirigidos.
  * Soporta loops.
  * Soporta aristas multiples si en la matriz de adyacencia se 
    guarda cuantas aristas hay desde 'i' hasta 'j'.
  * Si se quieren hallar la cantidad de caminos de longitud maximo 
    'k' que inician en 'i', se crea un vertice extra 's' que tiene 
    una arista hacia si mismo y hacia el cual todos los demas 
    vertices tienen una arista. Se hace exponenciacion con potencia
    'k+1'. La cantidad de caminos que inician en 'i' y tienen maximo 
    longitud 'k' queda en la posicion i,s despues de la 
    exponenciacion. (Quedan incluidos los caminos de longitud '0').
*/

struct Matrix {
    int n;
    vector<vl> M;

    Matrix(int n) : n(n), M(n, vl(n, 0)) {}

    // La matrix identidad, donde todo es '0' excepto en la diagonal principal, que es '1' 
    static Matrix identity(int n){
        Matrix I(n);
        for0(i,n) I.M[i][i] = 1;
        return I;
    }

    // Multiplicación de matrices O(n^3)
    Matrix operator*(const Matrix& other) const {
        Matrix result(n);
        for0(i,n){
            for0(k,n){
                if(!M[i][k]) continue;
                for0(j,n) result.M[i][j] = (result.M[i][j] + (M[i][k] * other.M[k][j] % MOD)) % MOD;
            }
        }
        return result;
    }

    // Suma de matrices (n^2)
    Matrix operator+(const Matrix& other) const {
        Matrix result(n);
        for0(i,n) for0(j,n) result.M[i][j] = (M[i][j] + other.M[i][j]) % MOD;
        return result;
    }

    // Exponenciacion de una matrix, usando exponenciacion binaria en O(log(exp) * n^3)
    Matrix binpow(ll exp) const {
        Matrix result = identity(n);
        Matrix base = *this;

        while(exp){
            if(exp & 1) result = result * base;
            base = base * base;
            exp >>= 1;
        }
        return result;
    }

    // Transpuesta de la matriz: T[j][i] = M[i][j], O(n^2)
    Matrix transpose() const {
        Matrix T(n);
        for0(i,n) for0(j,n) T.M[j][i] = M[i][j];
        return T;
    }

    // Debug, muestra la matrix en el cout
    friend ostream &operator<<(ostream &os, const Matrix &matrix){
        os << "\nMatrix: \n";
        for0(i,matrix.n){
            for0(j,matrix.n){
                os << matrix.M[i][j] << " ";
            }
            os << endl;
        }
        os << " =============== \n";
        return os;
    }
};

void solver(){
    // Lectura
    int n; cin>>n;
    Matrix m(n);
    for0(i,n){
        for0(j,n){
            cin>>m.M[i][j];
        }
    }

    ll exp; cin>>exp;
    Matrix ans = m.binpow(exp); // Para llamar una funcion
    cout<<ans; // Imprime la matriz
}

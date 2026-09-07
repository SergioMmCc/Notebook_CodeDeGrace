#include "../template.h"

// Algunas funciones para operaciones con matrices perfectas (n x n)

struct Matrix {
    int n;
    vector<vl> M;

    Matrix(int n) : n(n), M(n, vl(n, 0)) {}

    // La matrix identidad, donde todo es cero excepto en la diagonal principal, que tiene uno 
    static Matrix identity(int n) {
        Matrix I(n);
        for0(i,n) I.M[i][i] = 1;
        return I;
    }

    // Multiplicación de matrices O(n^3)
    Matrix operator*(const Matrix& other) const {
        Matrix result(n);
        for0(i,n){
            for0(k,n){
                if(M[i][k] == 0) continue;
                for0(j,n) result.M[i][j] += M[i][k] * other.M[k][j];
            }
        }
        return result;
    }

    // Suma de matrices (n^2)
    Matrix operator+(const Matrix& other) const {
        Matrix result(n);
        for0(i,n){
            for0(j,n){
                result.M[i][j] = (M[i][j] + other.M[i][j]);
            }
        }
        return result;
    }

    // Exponenciacion de una matrix, usando exponenciacion binaria en O(log(exp))
    Matrix binpow(ll exp) const {
        Matrix result = identity(n);
        Matrix base = *this;

        while(exp){
            if(exp & 1) result = result * base;
            exp >>= 1;
            base = base * base;
        }
        return result;
    }

    // Debug, muestra la matrix en el cout
    friend ostream &operator<<(ostream &os, const Matrix &matrix){
        os << "\nMatrix: \n";
        for0(i,i<matrix.n){
            for0(j,matrix.n){
                os << matrix.M[i][j] << " ";
            }
            os << endl;
        }
        os << " =============== \n";
        return os;
    }
};

void solver(){ // Ejemplo
    Matrix m(6);
    m.M = {
        {1, 1, 1, 1, 1, 1}, 
        {1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0}
    };

    ll x;
    cin>>x;

    Matrix ans = m.binpow(x);
    cout<<ans;
    cout<<ans.M[0][0]<<endl;
}

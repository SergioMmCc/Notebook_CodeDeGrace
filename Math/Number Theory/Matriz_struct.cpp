// ALgunas funciones para operaciones con matrices perfectas (n x n)

struct Matrix {
    int n;
    vector<vl> M;

    Matrix(int n) : n(n), M(n, vl(n, 0)) {}

    /*
    La matrix identidad, donde todo es cero excepto en la primera diagonal, que tiene uno
    */  
    static Matrix identity(int n) {
        Matrix I(n);
        for (int i = 0; i < n; i++) I.M[i][i] = 1;
        return I;
    }

    // Multiplicación de matrices O(n^3)
    Matrix operator*(const Matrix& other) const {
        Matrix result(n);
        for(int i=0; i<n; i++) {
            for(int k=0; k<n; k++){
                if(M[i][k] == 0) continue;
                for(int j=0; j<n; j++) {
                    result.M[i][j] += M[i][k] * other.M[k][j];
                }
            }
        }
        return result;
    }

    // Suma de matrices (n^2)
    Matrix operator+(const Matrix& other) const {
        Matrix result(n);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                result.M[i][j] = (M[i][j] + other.M[i][j]);
            }
        }
        return result;
    }

    // Exponenciacion de una matrix, usando exponenciacion binaria en O(nlogn)
    Matrix binpow(ll exp) const {
        Matrix result = identity(n);
        Matrix base = *this;

        while(exp){
            if (exp & 1) {
                result = result * base;
            }

            exp >>= 1;
            base = base * base;
        }
        return result;
    }

    // Debug, muestra la matrix en el cout
    friend ostream &operator<<(ostream &os, const Matrix &matrix) {
        os << "\nMatrix: \n";
        for(int i=0; i<matrix.n; i++) {
            for(int j=0; j<matrix.n; j++) {
                os << matrix.M[i][j] << " ";
            }
            os << endl;
        }
        os << " =============== \n";
        return os;
    }
};



// EJEMPLO ==========

int main(){
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

    return 0;
}

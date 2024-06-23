#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7; //Este ejercicio tiene modularidad debido a que son valores muy grandes
typedef vector<vector<long long>> matrix;

//Multiplicación de matrices
matrix multMatrix (const matrix &A, const matrix &B) {
    int len = A.size();
    matrix result(len, vector<long long>(len, 0));
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            for (int k = 0; k < len; k++) 
                result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % mod;
        }
    }
    return result;
}

//Potencia de una matriz
matrix potMatrix (matrix A, long long expo) {
    int len = A.size();
    matrix result(len, vector<long long>(len, 0));
    for (int i = 0; i < len; i++)
        result[i][i] = 1;
    while (expo > 0) {
        if (expo % 2 == 1)
            result = multMatrix(result, A);
        A = multMatrix(A, A);
        expo /= 2;
    }
    return result;
}

long long gcd (long long a, long long b) {
    long long temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

//Para este ejercicio un vertice i se conecta con un vertice j si gcd(i, j) == 1
//La matriz A representa la matriz de adyacencia del grafo
//La matriz B representa la matriz de adyacencia del grafo elevada a la n-1
//La potencia de la matriz de adyacencia del grafo es la cantidad de caminos de longitud n entre los vertices
//Si quiero saber el número de caminos de longitud n, debo elevar la matriz de adyacencia a la n-1
int main() {
    int k;
    long long n;
    cin >> k >> n;
    matrix A(k, vector<long long>(k, 0));
    A[0][0] = 1;
    
    for (int i = 1; i < k; i++) {
        for (int j = i+1; j <= k; j++) {
            if (gcd(i, j) == 1) 
                A[i-1][j-1] = A[j-1][i-1] = 1;
        }
    }
    matrix B(k, vector<long long>(k, 0));
    B = potMatrix(A, n-1);
    long long result = 0;
    
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            result = (result + B[i][j]) % mod;
        }
    }
    cout << result << endl;
    
    return 0;
}
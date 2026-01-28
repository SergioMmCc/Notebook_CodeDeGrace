#include <bits/stdc++.h>
#define myInfinite 2147483647

using namespace std;

typedef struct {
    int number;
    int id;
} customer;

void myMerge (vector<customer>& A, int p, int q, int r) {
    int n1 = q-p+1, n2 = r-q, i, j, k;
    vector <customer>L; L.reserve(n1+2);
    vector <customer>R; R.reserve(n2+2);
    for (i=1; i<=n1; i++)
        L[i] = A[p+i-1];
    for (j=1; j<=n2; j++)
        R[j] = A[q+j];
    L [n1+1].number = myInfinite;
    R [n2+1].number = myInfinite;
    i=1;
    j=1;
    for (k=p; k<=r; k++) {
        if (L[i].number <= R[j].number) {
            A[k] = L [i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
    }
}

void MergeSort (vector<customer>& A, int p, int r) {
    int q;
    if (p<r) {
        q = (p+r)/2;
        MergeSort (A, p, q);
        MergeSort (A, q+1, r);
        myMerge (A, p, q, r);
    }
}

int binarySearch (vector<customer>& A, int i, int j, int k) {
    int m;
    while (i <= j) {
        m = (i + j) >> 1;
        if (A[m].number == k)
           return m;
        else if (k > A[m].number)
             i = m + 1;
           else
                j = m - 1;
    }
    return -i -1;
}

int main() {  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int customers, save;cin >> customers;
    vector<customer> arrive;arrive.reserve(1005);
    arrive[0].number = 0;arrive[0].id = 0;
    
    vector<customer> out;out.reserve(1005);

    vector <int> arreglar(1005, 0);
    string salida;
   
    int contador = 0;
    int contador2 = 0;
    for (int i = 1; i <= 2*customers; i++) {
        cin >> save;
        if (save > 0) {
            contador++;
            arrive[contador].number = save;
            arrive[contador].id = contador;
        }
        else {
            contador2++;
            out[contador2].number = -save;
        }
    }
   
    if(customers == 1) {
        cout << "G\n";
        return 0;
    }
   
    MergeSort (arrive, 1, customers);
    
    for (int i = 1; i <= customers; i++) {
        save = binarySearch (arrive, 1, customers, out[i].number);
        out[i].id = arrive[save].id;
    }
        
    for (int i = customers; i > 1; i--) {
        for (int j = i - 1; j > 0; j--) {
            if (out[i].id > out[j].id) {
                if (arreglar[out[i].id] % 2 == arreglar[out[j].id] % 2) {
                    if (arreglar[out[i].id] >= 2 && arreglar[out[j].id] >= 2) {
                        cout << "*\n";
                        return 0;
                    }
                    
                    if (arreglar[out[i].id] < 2 && arreglar[out[j].id] < 2) {
                        arreglar[out[i].id] = 2;
                        arreglar[out[j].id] = 3;
                    }
                    
                    else if (arreglar[out[i].id] < 2) 
                        arreglar[out[i].id] = (-2*(arreglar[out[j].id] % 2)) + arreglar[out[j].id] + 1;
                        
                    else if (arreglar[out[j].id] < 2) 
                        arreglar[out[j].id] = -(2*(arreglar[out[i].id] % 2)) + arreglar[out[i].id] + 1;
                }
                else 
                    if (arreglar[out[i].id] % 2 == 0) {
                        arreglar[out[j].id] = 3;
                        arreglar[out[i].id] = 2;
                    }
                    else {
                        arreglar[out[j].id] = 2;
                        arreglar[out[i].id] = 3;
                    }
            }
            else if (arreglar[out[j].id] < 2)arreglar[out[j].id] = arreglar[out[i].id] % 2;
        }
    }
    
    for (int i = 1; i <= customers; i++) {
        if (arreglar[i] % 2 == 0)salida += 'G';
        else salida += 'S';
    }
    
    cout << salida << "\n";
   
    return 0;
}
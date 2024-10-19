#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define myInfinite 2147483647
#define MAXT 100

long long int inv = 0;

void myMerge (vector<int>& A, int p, int q, int r) {
    int n1 = q-p+1, n2 = r-q, i, j, k;
    vector<int> L(n1+2), R(n2+2);
    for (i=1; i<=n1; i++)
        L[i] = A[p+i-1];
    for (j=1; j<=n2; j++)
        R[j] = A[q+j];
    L[n1+1] = myInfinite;
    R[n2+1] = myInfinite;
    i=1;
    j=1;
    for (k=p; k<=r; k++) {
        if (L[i] <= R[j]) {
            A[k] = L [i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
            inv += n1 - i + 1;
        }
    }
}

void MergeSort (vector<int>& A, int p, int r) {
    int q;
    if (p<r) {
        q = (p+r)/2;
        MergeSort (A, p, q);
        MergeSort (A, q+1, r);
        myMerge (A, p, q, r);
    }
}


int main () {
    vector<int> A(MAXT + 1);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>A[i];
    
    for (int i=1; i<n; i++)
        cout<<A[i]<<' ';
    cout<<A[n]<<endl;
    
    MergeSort (A, 1, n);
    
    for (int i=1; i<n; i++)
        cout<<A[i]<<' ';
    cout<<A[n]<<endl;
    return 0;
}

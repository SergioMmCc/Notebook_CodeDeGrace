#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define myInfinite 2147483647
#define MAXN 500000

int BinarySearch (int A [], int i, int j, int k) {
    int m;
    
    if (i>j)
       return -1*i -1;
    else {
         m = (i+j) / 2;
         if (A[m] == k) 
            return m;
            else {
                 if (k >A[m])
                    return BinarySearch (A, m+1, j, k);
                 else
                     return BinarySearch (A, i, m-1, k);
                 }
         }
}

void myMerge (int A[], int p, int q, int r)
{
    int i, j, k, n1 = q - p + 1, n2 = r - q;
    int L [n1 + 2], R[n2 + 2];
    
    for (i = 1; i <= n1; i++)
    L[i] = A[p + i - 1];
    
    for (j = 1; j <= n2; j++)
    R[j] = A[q+j];
    
    L[n1+1] = myInfinite;
    R[n2+1] = myInfinite;
    i=1;
    j=1;
    
    for(k=p; k<=r; k++)
    {
    
    if (L[i] <= R[j])
    {
        A[k] = L [i];
        i++;
    }
    
    else 
    {
        A[k] = R [j];
        j++;
    }
    
  }
    
}

void MergeSort (int A[], int p, int r)
{
    int q;
    if (p < r)
    {
        q = (p + r) / 2;
        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        myMerge(A, p, q, r);
    }
}

int main() 
{
    int A[MAXN + 1], n, q, s, element, position;
    int idQuery, idElement, i;
    long long int result;
    
    scanf("%d %d", &n, &q);
    for (idElement = 1; idElement <= n; idElement++)
        scanf("%d", &A[idElement]);
        
    MergeSort(A, 1, n);
    
    for(idQuery = 1; idQuery <= q; idQuery++)
    {
        scanf("%d", &s);
        result = 0;
        for(i = 1; i < n; i++)
        {
            element = s - A[i];
            if (element > A[i]) {
                position = BinarySearch (A, i+1, n, element);
                if (position < 0) 
                    position = -1 * (position+2);
                result += position-i;
            }
            else
                break;
        }
        
        printf("%lld\n", result);
    }

    return 0;
}

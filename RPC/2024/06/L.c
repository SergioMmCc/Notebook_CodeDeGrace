#include <stdio.h>
int L[1000010], R[1000010], N, result;

int swapsort(int ar[], int n){
    int i = 1;
    int aux, k = 0;
    while(i <= n){
        if(ar[i] != i){
            aux = ar[ar[i]];
            ar[ar[i]] = ar[i];
            ar[i] = aux;
            k++;
        }else{
        i++;
        }
    }
    return k;
}

int main() {
    //ios_base::sync_with_stdio(false);cin.tie(0);
    scanf("%d\n", &N);
    
    for(int i = 1; i <= N; i++)
        scanf("%d", &L[i]);
    
    
    for(int i = 1; i <= N; i++)
        scanf("%d", &R[i]);
        
    result = swapsort(L,N) + swapsort(R, N);
    printf("%d\n", result);
    return 0;
}

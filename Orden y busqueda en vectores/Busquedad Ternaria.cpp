#include<bits/stdc++.h>
using namespace std;

int ternarySearch(vector<int>& A, int i, int j, int s) {
    int l, r;
    while(i <= j) {
        l = i + (j-i)/3, r = j - (j-i)/3;
        if(A[l] == s)
            return l;
        if(A[r] == s)
            return r;
        if(A[l] > s)
            i = r+1;
        else if(A[r] > s) {
            i = l+1;
            j = r-1;
        }
        else
            j = l-1;
    }
    return -i -1;
}
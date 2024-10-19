#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int binarySearch (vector<int>& A, int i, int j, int k) {
    int m;
    while (i <= j) {
        m = (i + j) >> 1;
        if (A[m] == k)
            return m;
        else if (k > A[m])
            i = m + 1;
        else
            j = m - 1;
    }
    return -i -1;
}

int main () {
    vector<int> A(101);
    int n, index, q, k, position;
    
    while (cin>>n) {
        for (index = 1; index<=n; index++)
            cin>>A[index];
              
        cin>>q;
        for (index = 1; index <= q; index++) {
            cin>>k;
            position = binarySearch (A, 1, n, k);
            if (position >= 0)
                cout<<"\nThe element "<<k<<" is in the position "<<position<<" in the array."<<endl;
            else {
                cout<<"\nThe element "<<k<<" is not in the array."<<endl;
                cout<<"The insertion point is: "<<-1*position - 1<<endl;
            }
        }
    }
    return 0;
}

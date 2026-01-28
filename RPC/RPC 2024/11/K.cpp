#include<bits/stdc++.h>
using namespace std;
#define endl '\n'


int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);

    long long n, k; 

    cin >> n >> k ;

    // for(long long a = n/k; true; a--) {
    //     if((n-a*k)%2 == 0) {
    //         cout << n-a*k << endl;
    //         return 0; 
    //     }
    // }


    long long midN = (n+1)/2; 
    long long midK = (k+1)/2; 

    long long cant = ((midN - midK)%k)*2; 

    if(cant%k == 0) cout << 0 << endl;
    else cout << cant << endl;
}
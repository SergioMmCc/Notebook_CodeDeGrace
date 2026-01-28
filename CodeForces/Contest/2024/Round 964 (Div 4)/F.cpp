#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int mod = 1e9 + 7;
vector<long long> factorial(200001);

void calcFactorial () {
    factorial[0] = 1;
    for(long long i = 1; i <= 200000; i++)
        factorial[i] = (factorial[i-1] * i) % mod;
}

long long mod_inverse(long long a, long long n) {
    long long i = n, v = 0, d = 1;
    while(a > 0) {
        long long t = i/a, x = a;
        a = i%x;
        i = x;
        x = d;
        d = v - t*x;
        v = x;
    }
    v %= n;
    if(v < 0)
        v += n;
    return v;
}

void solver() {
    long long n, len, k, count0 = 0, count1 = 0, result = 0;
    cin>>n>>len;
    k = len/2 + 1;
    char save;
    for(int i = 0; i < n; i++) {
        cin>>save;
        if(save == '1')count1++;
        else count0++;
    }
    if(count1 < k) {
        cout<<'0'<<endl;
        return;
    }
    long long factC1 = factorial[count1];
    for(long long i = k; i <= len && i <= count1; i++) {
        long long l = len - i;
        if(l > count0)
            continue;
        long long t1, t2;
        t1 = (factC1 % mod) * (mod_inverse(factorial[i] * factorial[count1 - i], mod)) % mod;
        t2 = (factorial[count0] % mod) * (mod_inverse(factorial[l] * factorial[count0 - l], mod)) % mod;
        result = ((result % mod) + ((t1*t2) % mod)) % mod;
    }
    
    cout<<result<<endl;
}

int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    calcFactorial();
    int t;
    cin>>t;
    while(t--) {
        solver();
    }

    return 0;
}
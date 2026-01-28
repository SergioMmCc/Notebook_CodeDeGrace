#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

vector<long long> pot3;

void calcularPot3 () {
    pot3.push_back(0);
    long long i = 1;
    while(i <= 600000) {
        pot3.push_back(i);
        i*=3;
    }
}

long long binarySearch (long long r) {
    long long m;
    long long i = 0, j = pot3.size()-1;
    while(i <= j) {
        m = (i+j)/2;
        if(pot3[m] == r)
            return m;
        if(pot3[m] > r)
            j = m-1;
        else 
            i = m+1;
    }
    
    return -i -1;
}

void solver() {
    long long l, r;cin>>l>>r;
    long long result = 0;
    long long pos = binarySearch(l);
    if(pos < 0) 
        pos = -pos - 2;
    
    result += pos*2;
    long long next;
    l++;
    while(r > pot3[pos]) {
        next = min(r, pot3[pos+1]-1);
        result += pos*(next-l+1);
        pos++;
        l = pot3[pos];
    }
    pos = binarySearch(r);
    if(pos > 0) {
        result += pos;
    }
    
    cout<<result<<endl;
}

int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    calcularPot3();
    int t;
    cin>>t;
    while(t--) {
        solver();
    }

    return 0;
}
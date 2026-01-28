#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

typedef pair<int, int> pii;

void testNum(int n, int num, int nCif, int cifras, vector<pii>& ans, int *total){
    int a = cifras / nCif + 1, b = nCif - (cifras % nCif);
    while(a <= 10000 && b <= 10000){
        int z = n * a - b;
        if(z == num){
            (*total)++;
            ans.pb({a, b});
        }

        a++;
        b += nCif;
    }
}

void solver(){
    int n; cin>>n;
    vector<pii> ans;
    int total = 0;
    if(n / 10 == 0){ // Caso en el que n tiene una cifra
        int num = 0;
        for(int cifras = 1; cifras <= 6; cifras++){
            num = 10*num + n;
            testNum(n, num, 1, cifras, ans, &total);
        }
    }

    else if(n / 100 == 0){ // Caso en el que n tiene dos cifras
        int num = 0;
        for(int cifras = 1; cifras <= 6; cifras++){
            if(cifras % 2 == 1) num = 10*num + (n/10);
            else num = 10*num + (n%10);
            testNum(n, num, 2, cifras, ans, &total);
        }
    }

    else{ // Caso en el que n == 100
        int num = 0;
        for(int cifras = 1; cifras <= 6; cifras++){
            num *= 10;
            if(cifras % 3 == 1) num++;
            testNum(n, num, 3, cifras, ans, &total);
        }
    }

    cout<<total<<endl;
    for(pii i : ans){
        cout<<i.first<<' '<<i.second<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

int gcd2 (int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void solver(){
    int n; cin>>n;
    set<int> divisors;
    divisors.insert(1);
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            divisors.insert(i);
            divisors.insert(n / i);
        }
    }

    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin>>a[i];

    if(n == 1){
        cout<<1<<endl;
        return;
    }

    int ans = 1;
    for(int num : divisors){
        int test = 0;
        for(int i = 1; i <= num; i++){
            int aux = 0;
            for(int j = i + num; j <= n; j += num){
                if(a[j] == a[j - num]) continue;
                if(!aux) aux = abs(a[j] - a[j - num]);
                aux = gcd2(aux, abs(a[j] - a[j - num]));
            }

            if(!aux) continue;
            if(!test) test = aux;
            test = gcd2(test, aux);
        }

        if(test != 1) ans++;
    }

    cout<<ans<<endl;
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
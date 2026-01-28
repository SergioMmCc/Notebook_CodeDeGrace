#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

const int inf = 2e9;

int gcd2 (int a, int b) {
    ll temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void solver(){
    int n, a, b; cin>>n>>a>>b;
    int gc = gcd2(a, b);
    vector<int> numbers(n);
    for(int i = 0; i < n; i++){
        cin>>numbers[i];
        numbers[i] %= gc;
    }

    sort(numbers.begin(), numbers.end());
    int ans = inf;
    int maxi = numbers[n-1];
    for(int i = 0; i < n; i++){
        int aux = maxi - numbers[i];
        maxi = numbers[i] + gc;
        ans = min(ans, aux);
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
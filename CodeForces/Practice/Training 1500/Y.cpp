#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

void solver(){
    int n; cin>>n;
    multiset<int> numbers;
    for(int i = 0; i < n; i++){
        int save; cin>>save;
        numbers.insert(save);
    }

    ll ans = 0;
    ll x = 0;
    while(!numbers.empty()){
        multiset<int>::iterator lowest = numbers.begin(), biggest = numbers.end(); --biggest;

        if(lowest == biggest){
            if(*biggest == 1) ans++;
            else ans += (*biggest - x + 1) / 2 + 1;
            numbers.erase(biggest);
        }

        else if(x + *lowest == *biggest){
            ans += *lowest + 1;
            x = 0;
            numbers.erase(lowest); numbers.erase(biggest);
        }

        else if(x + *lowest > *biggest){
            ans += *biggest - x + 1;
            int aux = *lowest - *biggest + x;
            numbers.erase(lowest); numbers.insert(aux); numbers.erase(biggest);
            x = 0;
        }

        else{
            x += *lowest;
            ans += *lowest;
            numbers.erase(lowest);
        }
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
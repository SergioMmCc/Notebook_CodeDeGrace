#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

void solver(){
    int pos, num; cin>>pos>>num;
    if(num > pos){
        cout<<0<<endl;
        return;
    }

    set<int> count;
    int resta = pos - num;
    if(!(resta % 2)){
        for(int k = 1; k * k <= resta; k++){
            if(resta % k == 0){
                if(k % 2 == 0 && k / 2 + 1 >= num) count.insert(k / 2 + 1);
                if((resta / k) % 2 == 0 && resta / k / 2 + 1 >= num) count.insert(resta / k / 2 + 1);
            }
        }
    }

    int suma = pos + num - 2;
    if(!(suma % 2)){
        suma /= 2;
        for(int k = 1; k * k <= suma; k++){
            if(suma % k == 0){
                if(k + 1 >= num) count.insert(k + 1);
                if(suma / k + 1 >= num) count.insert(suma / k + 1); 
            }
        }
    }

    if(*count.begin() == 1) count.erase(1);
    cout<<count.sz<<endl;
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
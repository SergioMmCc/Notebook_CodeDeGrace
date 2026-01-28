#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back

typedef pair<int, int> pii;
const int inf = 2e9;

void solver(){
    int n; cin>>n;
    vector<int> a(n+1);
    set<int> numbers;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        if(!a[i]) continue;
        numbers.insert(a[i]);
    }

    // Si todo son 0s se retorna una permutacion ascendente de 1 a n
    if(numbers.empty()){
        cout<<1;
        for(int i = 2; i <= n; i++) cout<<' '<<i;
        cout<<endl;
        return;
    }

    // Sube
    int last = 0;
    bool cond = 0;
    queue<pii> up;
    for(int i = 1; i <= n; i++){
        if(a[i] == 0){
            cond = 1;
            continue;
        }
        if(cond && a[i] > last){
            last = a[i];
            up.push({a[i], i});
        }
    }

    // Baja
    last = 0;
    cond = 0;
    queue<pii> down;
    for(int i = n; i > 0; i--){
        if(a[i] == 0){
            cond = 1;
            continue;
        }
        if(cond && a[i] > last){
            last = a[i];
            down.push({a[i], i});
        }
    }

    // Two pointers
    // Ubicar l y r en el primer 0 de izquierda a derecha y de derecha a izquierda, respectivamente
    int l = 1, r = n, lastL = 0, lastR = 0;
    while(a[l]) l++;
    if(l == 1) lastL = 0;
    else lastL = a[l - 1];
    while(a[r]) r--;
    if(r == n) lastR = 0;
    else lastR = a[r + 1];

    // Rellenar
    for(int i = 1; i <= n; i++){
        if(numbers.find(i) != numbers.end()) continue;
        if(lastR > i){
            a[l] = i;
            l++;
            while(!up.empty() && l == up.front().second){
                lastL = a[l];
                l++;
                up.pop();
            }
            if(up.empty()) up.push({inf, inf});
        }
        else if(lastL > i){
            a[r] = i;
            r--;
            while(!down.empty() && r == down.front().second){
                lastR = a[r];
                r--;
                down.pop();
            }
            if(down.empty()) down.push({inf, inf});
        }
        else if(up.front().first < down.front().first){
            a[l] = i;
            l++;
            while(!up.empty() && l == up.front().second){
                lastL = a[l];
                l++;
                up.pop();
            }
            if(up.empty()) up.push({inf, inf});
        }
        else if(up.front().first > down.front().first){
            a[r] = i;
            r--;
            while(!down.empty() && r == down.front().second){
                lastR = a[r];
                r--;
                down.pop();
            }
            if(down.empty()) down.push({inf, inf});
        }
        else { // down.front().first == up.front().first
            if(lastR > i){
                a[l] = i;
                l++;
                while(!up.empty() && l == up.front().second){
                    lastL = a[l];
                    l++;
                    up.pop();
                }
                if(up.empty()) up.push({inf, inf});
            }
            else if(lastL > i){
                a[r] = i;
                r--;
                while(!down.empty() && r == down.front().second){
                    lastR = a[r];
                    r--;
                    down.pop();
                }
                if(down.empty()) down.push({inf, inf});
            }
            else if(up.front().second - l < r - down.front().second){
                a[l] = i;
                l++;
                while(!up.empty() && l == up.front().second){
                    lastL = a[l];
                    l++;
                    up.pop();
                }
                if(up.empty()) up.push({inf, inf});
            }
            else{
                a[r] = i;
                r--;
                while(!down.empty() && r == down.front().second){
                    lastR = a[r];
                    r--;
                    down.pop();
                }
                if(down.empty()) down.push({inf, inf});
            }
        }
    }

    // Comprobar que esta bien formada
    bool goingUp = 1, possible = 1;
    last = 0;
    for(int i = 1; i <= n; i++){
        if(goingUp && a[i] < last) goingUp = 0;
        else if(!goingUp && a[i] > last) possible = 0;
        last = a[i];
    }

    // Imprimir
    if(!possible) cout<<'*'<<endl;
    else{
        for(int i = 1; i <= n; i++){
            if(i > 1) cout<<' ';
            cout<<a[i];
        }
        cout<<endl;
    }
}

int main(){
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
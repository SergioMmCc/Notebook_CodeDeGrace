#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

void solver(){
    int n, m; cin>>n>>m;
    vector<ll> p(n + m + 1), t(n + m + 1);
    vector<bool> pt(n + m + 1); // Si es programmer 1, sino 0
    int firstP = 0;
    int countP = 0, countT = 0;
    int indexExtraP = 0, indexExtraT = 0;
    ll sumP = 0, sumT = 0, extraP = 0, extraT = 0;
    for(int i = 0; i <= n + m; i++) cin>>p[i];
    for(int i = 0; i <= n + m; i++) cin>>t[i];
    for(int i = 0; i <= n + m; i++){
        if(p[i] > t[i]){
            if(countP < n){
                countP++;
                sumP += p[i];
                pt[i] = 1;
            }
            else if(countP == n){
                if(!firstP) firstP = 1;
                extraP = p[i];
                countP++;
                indexExtraP = i;
                if(countT == m){
                    extraT = t[i];
                    countT++;
                    indexExtraT = i;
                }
                else if(countT < m){
                    countT++,
                    sumT += t[i];
                }
            }
            else{ //CountP > n
                if(countT == m){
                    if(!firstP) firstP = 2;
                    countT++;
                    extraT = t[i];
                    indexExtraT = i;
                }
                else if(countT < m){
                    countT++,
                    sumT += t[i];
                }
            }
        }
        else{ //t[i] > p[i]
            if(countT < m){
                countT++;
                sumT += t[i];
            }
            else if(countT == m){
                if(!firstP) firstP = 2;
                extraT = t[i];
                countT++;
                indexExtraT = i;
                if(countP == n){
                    extraP = p[i];
                    countP++;
                    indexExtraP = i;
                }
                else if(countP < n){
                    countP++;
                    sumP += p[i];
                    pt[i] = 1;
                }
            }
            else{
                if(countP == n){
                    if(!firstP) firstP = 1;
                    countP++;
                    extraP = p[i];
                    indexExtraP = i;
                }
                else if(countP < n){
                    countP++;
                    sumP += p[i];
                    pt[i] = 1;
                }
            }
        }
    }

    if(indexExtraT == indexExtraP){ //EL extra esta en la posicion n + m
        for(int i = 0; i < n + m; i++){
            if(pt[i]) cout<<sumP + extraP - p[i] + sumT<<' ';  //Programador
            else cout<<sumT + extraT - t[i] + sumP<<' ';
        }

        cout<<sumP + sumT<<endl;
    }

    else if(firstP == 1){
        for(int i = 0; i <= n + m; i++){
            if(i > 0) cout<<' ';
            if(i == indexExtraP) cout<<sumP + (sumT - t[i] + extraT);
            else if(i == indexExtraT) cout<<sumP + sumT;
            else if(pt[i]) cout<<(sumP + extraP - p[i]) + (sumT - t[indexExtraP] + extraT); 
            else cout<<sumP + (sumT + extraT - t[i]);
        }
        cout<<endl;
    }
    
    else{
        for(int i = 0; i <= n + m; i++){
            if(i > 0) cout<<' ';
            if(i == indexExtraT) cout<<sumT + (sumP + extraP - p[i]);
            else if(i == indexExtraP) cout<<sumT + sumP;
            else if(!pt[i])cout<<(sumT + extraT - t[i]) + (sumP + extraP - p[indexExtraT]);
            else cout<<sumT + (sumP + extraP - p[i]);
        }
        cout<<endl;
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
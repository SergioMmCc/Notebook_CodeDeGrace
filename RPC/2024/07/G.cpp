#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

vector<ll> pot10;

void calcPot10(){
    pot10.push_back(1);
    ll add = 1;
    for(int i = 1; i <= 18; i++){
        add *= 10;
        pot10.push_back(add);
    }
}

int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    
    calcPot10();
    
    ll a, b, r; bool add = false;
    ll ansA, ansB, ansR;
    char sign, eq;
    cin>>a>>sign>>b>>eq>>r;
    if(sign == '+')add = true;
    
    ll findCifras = 1;
    int cifrasA = 0;
    while(findCifras < a){
        findCifras *= 10;
        cifrasA++;
    }
    findCifras = 1;
    int cifrasB = 0;
    while(findCifras < b){
        findCifras *= 10;
        cifrasB++;
    }
    findCifras = 1;
    int cifrasR = 0;
    while(findCifras < r){
        findCifras *= 10;
        cifrasR++;
    }
    
    bool ansFound = false;
    for(int i = 1; !ansFound && i <= cifrasA; i++){
        ll testA = a % pot10[cifrasA - i];
        for(int j = 1; !ansFound && j <= cifrasB; j++){
            ll testB = b % (pot10[cifrasB - j]);
            testB += (a / pot10[cifrasA - i]) * pot10[cifrasB - j];
            ll addA = testA + ((b / pot10[cifrasB - j]) * pot10[cifrasA - i]);
            
            if(add){
                if(addA + testB == r){
                    ansFound = true;
                    ansA = addA; ansB = testB; ansR = r;
                }
            }
            else{
                if(addA * testB == r){
                    ansFound = true;
                    ansA = addA; ansB = testB; ansR = r;
                }
            }
        }
    }
    
    for(int i = 1; !ansFound && i <= cifrasA; i++){
        ll testA = a % pot10[cifrasA - i];
        for(int k = 1; !ansFound && k <= cifrasR; k++){
            ll testR = r % (pot10[cifrasR - k]);
            testR += (a / pot10[cifrasA - i]) * pot10[cifrasR - k];
            ll addA = testA + ((r / pot10[cifrasR - k]) * pot10[cifrasA - i]);
            
            if(add){
                if(addA + b == testR){
                    ansFound = true;
                    ansA = addA; ansB = b; ansR = testR;
                }
            }
            else{
                if(addA * b == testR){
                    ansFound = true;
                    ansA = addA; ansB = b; ansR = testR;
                }
            }
        }
    }
    
    for(int j = 1; !ansFound && j <= cifrasB; j++){
        ll testB = b % pot10[cifrasB - j];
        for(int k = 1; !ansFound && k <= cifrasR; k++){
            ll testR = r % (pot10[cifrasR - k]);
            testR += (b / pot10[cifrasB - j]) * pot10[cifrasR - k];
            ll addB = testB + ((r / pot10[cifrasR - k]) * pot10[cifrasB - j]);
            
            if(add){
                if(a + addB == testR){
                    ansFound = true;
                    ansA = a; ansB = addB; ansR = testR;
                }
            }
            else{
                if(a * addB == testR){
                    ansFound = true;
                    ansA = a; ansB = addB; ansR = testR;
                }
            }
        }
    }
    
    if(add)
        cout<<ansA<<" + "<<ansB<<" = "<<ansR<<endl;
    else
        cout<<ansA<<" * "<<ansB<<" = "<<ansR<<endl;
    
    return 0;
}
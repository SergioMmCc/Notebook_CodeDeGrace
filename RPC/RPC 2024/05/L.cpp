#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int r, k, limite;
    vector<int> rule;
    cin >> r >> k;
    string anterior, next, ruleString, aux = "...";
    cin >> anterior;
    next = anterior;
    limite = anterior.size();
    
    //Convertir a binario
    for (int i = 0; r >= 1; i++){
        rule.push_back(r%2);
        r /= 2;
    }
    
    for (int i = rule.size(); i <= 8; i++)
        rule.push_back(0);
        
    for (int i = 0; i < 8; i++) {
        if (rule[i] == 0)ruleString += '.';
        else ruleString += 'X';
    }
    
    for (int j = 1; j <= k; j++) {
    
        aux[0] = '.';
        aux[1] = anterior[0];
        if (limite > 1)
            aux[2] = anterior[1];
        else
            aux[2] = '.';
            
        if (aux == "...")next[0] = ruleString[0];
        else if (aux == "..X")next[0] = ruleString[1];
        else if (aux == ".X.")next[0] = ruleString[2];
        else if (aux == ".XX")next[0] = ruleString[3];
        else if (aux == "X..")next[0] = ruleString[4];
        else if (aux == "X.X")next[0] = ruleString[5];
        else if (aux == "XX.")next[0] = ruleString[6];
        else next[0] = ruleString[7];
          
        for (int i = 1; i < limite - 1; i++) {
            aux[0] = anterior[i-1];
            aux[1] = anterior[i];
            aux[2] = anterior[i+1];
            
            if (aux == "...")next[i] = ruleString[0];
            else if (aux == "..X")next[i] = ruleString[1];
            else if (aux == ".X.")next[i] = ruleString[2];
            else if (aux == ".XX")next[i] = ruleString[3];
            else if (aux == "X..")next[i] = ruleString[4];
            else if (aux == "X.X")next[i] = ruleString[5];
            else if (aux == "XX.")next[i] = ruleString[6];
            else next[i] = ruleString[7];
        }
        
        if (limite > 1)
            aux[0] = anterior[limite-2];
        else
            aux[0] = '.';
        aux[1] = anterior[limite-1];
        aux[2] = '.';
        if (aux == "...")next[limite-1] = ruleString[0];
        else if (aux == "..X")next[limite-1] = ruleString[1];
        else if (aux == ".X.")next[limite-1] = ruleString[2];
        else if (aux == ".XX")next[limite-1] = ruleString[3];
        else if (aux == "X..")next[limite-1] = ruleString[4];
        else if (aux == "X.X")next[limite-1] = ruleString[5];
        else if (aux == "XX.")next[limite-1] = ruleString[6];
        else next[limite-1] = ruleString[limite-1];
        
        
        cout << next << "\n";
        anterior = next;
    }
        
    return 0;
}

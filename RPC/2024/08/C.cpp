#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int i = 1;
string a;

int findMax(){
    int open = 1, maxN = 1, aux = 1;
    while(open > 0){
        if(a[i] == '('){
            i++;
            aux = findMax();
        }
        else if(a[i] == ')'){
            open--;
            i++;   
        }
        else if(a[i] == '+'){
            i+=2;
            aux = max(aux, findMax());
        }
        else { //a[i] == '*'
            i+=2;
            aux += findMax();
        }
    }

    maxN = max(aux, maxN);
    return maxN;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    cin>>a;
    cout<<findMax()<<endl;

    return 0;
}
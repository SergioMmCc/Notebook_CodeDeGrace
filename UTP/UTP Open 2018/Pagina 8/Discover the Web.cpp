#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

void solver(){
    stack<string> backward, forward;
    string current = "http://www.lightoj.com/";
    string op;
    while(cin>>op){
        if(op == "QUIT") break;

        if(op == "VISIT"){
            backward.push(current);
            while(!forward.empty()) forward.pop();
            cin>>current;
        }
        else if(op == "BACK"){
            if(backward.empty()){
                cout<<"Ignored"<<endl;
                continue;
            }

            forward.push(current);
            current = backward.top();
            backward.pop();
        }
        else{ // op == "FORWARD"
            if(forward.empty()){
                cout<<"Ignored"<<endl;
                continue;
            }

            backward.push(current);
            current = forward.top();
            forward.pop();
        }

        cout<<current<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    cin>>t;
    for(int i = 1; i <= t; i++){
        cout<<"Case "<<i<<":"<<endl;
        solver();
    }

    return 0;
}
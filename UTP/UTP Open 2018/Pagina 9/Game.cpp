#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;

void solver(){
    int n; cin>>n;
    priority_queue <int> e, o;
    for(int i = 0; i < n; i++){
        int save; cin>>save;
        e.push(save);
    }
    for(int i = 0; i < n; i++){
        int save; cin>>save;
        o.push(-1 * save);
    }

    int op = 0;
    while(!e.empty() && !o.empty()){
        op++;
        int n1 = e.top(); e.pop();
        int n2 = o.top(); o.pop(); n2 *= -1;
        int sum = n1 + n2;

        if(sum % 2) o.push(-1 * sum);
        else e.push(sum / 2); 
    }

    cout<<op<<' ';
    if(o.empty()) cout<<"Emma"<<endl;
    else cout<<"Otto"<<endl;
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
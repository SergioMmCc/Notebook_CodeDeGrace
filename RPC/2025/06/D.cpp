#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;
const int top=1e6, INF=1e9;
int vec[top+7];

void solver(){
    long long sum=0, t=0, num;
    for(int i=0; i<10; i++){
        cin>>num;
        if(i & 1){
            sum += t*num;
            t = 0;
        }else{
            t = num;
        }
    }
    sum /= 5;
   
    long long a, b;
    cin>>a>>b;

    long long ans = (a*sum)/b;

    cout<<ans<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);

        solver();
    

    return 0;
}
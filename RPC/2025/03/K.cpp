#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()
typedef pair<int, int> pii;
const int top=1000;
int vec[top+7];
int vis[top+7];


int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>vec[i];
    }

    int c=0, i=1;
    while(!vis[i]){
        vis[i]++;
        c++;
        i = vec[i];
    }
    cout<<c<<"\n";


    

    return 0;
}
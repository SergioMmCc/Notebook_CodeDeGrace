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


int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    for(int i=1; i<top; i++){
        vec[i] = i*i;
    }
    int a, b;
    cin>>a>>b;

    int r = upper_bound(vec, vec+top, b) - vec - 1;
    int l = lower_bound(vec, vec+top, a) - vec;

    cout<<15*(r-l+1)<<"\n";

    return 0;
}
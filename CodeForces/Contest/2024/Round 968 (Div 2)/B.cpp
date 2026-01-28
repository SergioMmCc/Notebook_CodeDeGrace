#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solver (){
    int n;cin>>n;
    vector<int> numbers(n);
    for(int i = 0; i < n; i++)
        cin>>numbers[i];
    sort(numbers.begin(), numbers.end());
    cout<<numbers[n/2]<<endl;
}

int main () {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        solver();
    }
    
    return 0;
}
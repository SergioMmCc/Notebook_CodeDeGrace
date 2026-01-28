#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    int q; cin>>q;
    multiset<int> numbers;
    while(q--){
        int op; cin>>op;
        if(op == 1){
            int save; cin>>save;
            numbers.insert(save);
        }
        else if(op == 2){
            int del; cin>>del;
            multiset<int>::iterator it = numbers.find(del);
            if(it == numbers.end()) continue;
            numbers.erase(it);
        }
        else{
            int n = numbers.size();
            if(!n) cout<<"Empty!"<<endl;
            else if(n % 2 == 0){
                multiset<int>::iterator it = numbers.begin();
                for(int i = 1; i < n/2; i++)++it;
                int ans = *it;
                ++it;
                ans += *it;
                cout<<ans / 2<<endl;
            }
            else{
                multiset<int>::iterator it = numbers.begin();
                for(int i = 0; i < n/2; i++) ++it;
                int ans = *it;
                cout<<ans<<endl;
            }
        }
    }
    
    return 0;
}
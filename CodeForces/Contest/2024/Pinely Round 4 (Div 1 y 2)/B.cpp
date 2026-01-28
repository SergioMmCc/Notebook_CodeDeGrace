#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solver() {
    int n;cin>>n;
    vector<int> numbers(n), ans(n);
    for(int i = 0; i < n-1; i++) 
        cin>>numbers[i];
    ans[0] = numbers[0];
    int last = ans[0], next;
    for(int i = 0; i < n-1; i++) {
        next = numbers[i];
        int test = next & last;
        if(test == next){
            ans[i+1] = next;
            last = next;
        }
        else {
            // cout<<"Next -> "<<next<<endl;
            int auxLast = ans[i-1], auxNext = ans[i], change = ans[i] | next;
            for(int j = 1073741824; j > 0; j/=2) {
                if(auxLast >= j && auxNext < j && change >= j) {
                    cout<<"-1"<<endl;
                    return;
                }
                if(auxLast >= j)
                    auxLast-=j;
                if(auxNext >= j)
                    auxNext-=j;
                if(change >= j)
                    change-=j;
            }
            
            ans[i] |= next;
            ans[i+1] = next;
            last = next;
        }
    }
    for(int i = 0; i < n; i++) {
        if(i>0) cout<<" ";
        cout<<ans[i];
    }
    cout<<endl;
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
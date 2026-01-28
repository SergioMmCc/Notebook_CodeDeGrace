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

void solver(){
    int n; cin>>n;
    set<int> num1, num2;
    for(int i = 1; i <= 2*n; i++){
        num1.insert(i);
        num2.insert(i);
    }

    vector<int> order(n);
    for(int i = 0; i < n; i++){
        cin>>order[i];
        num1.erase(order[i]);
        num2.erase(order[i]);
    }

    int mini = 0;
    for(int i = 0; i < n; i++){
        int s = order[i];
        set<int>::iterator it = num1.upper_bound(s);
        if(it == num1.end()){
            mini++;
            num1.erase(num1.begin());
        }

        else num1.erase(it);
    }

    int maxi = 0;
    for(int i = 0; i < n; i++){
        int s = order[i];
        set<int>::iterator it = num2.lower_bound(s);
        if(it == num2.begin()){
            set<int>::iterator it2 = num2.end(); --it2;
            num2.erase(it2);
        }
        else{
            maxi++;
            --it;
            num2.erase(it);
        }
    }

    cout<<mini<<' '<<maxi<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
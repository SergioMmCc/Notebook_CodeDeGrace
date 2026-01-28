#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define pb push_back
#define sz size()

typedef pair<int, int> pii;

int pointTo(map<int, int>& info, int num){
    if(info.find(num) == info.end()) return num;
    info[num] = pointTo(info, info[num]);
    return info[num];
}

void solver(){
    int n; cin>>n;
    map<int, int> info;
    set<int> ans;
    int num; cin>>num; num++;
    ans.insert(num);
    info[num] = num - 1;

    for(int i = 2; i <= n; i++){
        cin>>num; num += i;
        int add;
        if(info.find(num) == info.end()) add = num;
        else add = pointTo(info, num);

        info[add] = add - 1;

        ans.insert(add);
    }

    for(set<int>::iterator it = ans.end(); it != ans.begin(); ){
        --it;
        cout<<*it<<' ';
    }
    cout<<endl;
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
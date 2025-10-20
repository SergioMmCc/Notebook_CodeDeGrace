#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int top=2e5, INF=1e9;
int vec[top];

void solver(){
    int n;
    cin>>n;

    while(n){
        int maxx=-INF;
        int minn=0;
        for(int i=1; i<=n; i++){
            cin>>vec[i];
            minn = min(minn, vec[i]);
            maxx = max(maxx, vec[i]);
            if(vec[i] > 0) vec[i] = 1;
            if(vec[i] < 0) vec[i] = -1;
            vec[i] += vec[i-1];
        }

        //for(int i=1; i<=n; i++)cout<<vec[i]<<" ";cout<<"\n";

        map<int, int> f;
        f[0] = 0;
        int r=0;
        for(int i=1; i<=n; i++){
            if(f.find(vec[i]) == f.end()){
                f[vec[i]] = i;
            }
            r = max(r, i - f[vec[i]]);
        }
        maxx = max(0, maxx);
        minn = min(0, minn);

        cout<<maxx<<" "<<minn<<" "<<r<<"\n";//cout<<"------\n";

        cin>>n;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

        solver();
    

    return 0;
}
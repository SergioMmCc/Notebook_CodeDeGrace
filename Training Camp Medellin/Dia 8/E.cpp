#include <bits/stdc++.h>
#define ll long long
#define all(x) (x).begin(), (x).end()
using namespace std;
int INF=1E9, MOD=1E9+7;

int table[33];
int reco[9];


void solve(){
    int n, k;
    cin>>n>>k;

    int val[5];
    
    cout<<"or 1 2"<<endl;
    cin>>val[4];

    cout<<"and 1 2"<<endl;
    cin>>val[3];

    cout<<"or 1 3"<<endl;
    cin>>val[2];

    cout<<"and 1 3"<<endl;
    cin>>val[1];

    cout<<"or 2 3"<<endl;
    cin>>val[0];

    auto at = [](int x, int p){
        return (x>>p) & 1;
    };

    int x=0;
    for(int i=0; i<31; i++){
        int v=0;
        for(int j=4; j>=0; j--){
            v |= at(val[j], i) << j;
            //cout<<at(val[j], i)<<" ";
        }
        //cout<<" | "<<i<<" -> "<<v<<endl;
        x |= table[v] << i;

    }

    //cout<<"first: "<<x<<endl;

    int b=0, c=0;



    for(int i=0; i<31; i++){
        b |= reco[(at(x, i) << 2) | (at(val[3], i) << 1) | at(val[4], i)] << i;
        c |= reco[(at(x, i) << 2) | (at(val[1], i) << 1) | at(val[2], i)] << i;
    }

    //cout<<"second: "<<b<<endl;
    //cout<<"third: "<<c<<endl;

    vector<int> vec(n+1);
    vec[1] = x;
    vec[2] = b;
    vec[3] = c;

    for(int i=4; i<=n; i++){
        cout<<"or 1 "<<i<<endl;
        cin>>b;
        cout<<"and 1 "<<i<<endl;
        cin>>c;

        int v=0;
        for(int i=0; i<31; i++){
            v |= reco[(at(vec[1], i) << 2) | (at(c, i) << 1) | at(b, i)] << i;
        }
        vec[i] = v;
    }

    //for(int i=1; i<=n; i++){cout<<"vec["<<i<<"]: "<<vec[i]<<endl;}

    sort(vec.begin()+1, vec.end());
    cout<<"finish "<<vec[k]<<endl;

}

int main() {
    table[20] = table[23] = table[29] = table[31] = 1;
    reco[1] = reco[7] = 1;

    solve();
    return 0;
}
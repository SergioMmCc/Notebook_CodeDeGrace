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
    int min1 = -1, min2 = -1, min3 = -1, min4 = -1, min5 = -1;
    int h = 0, her = 0, hest = 0;
    for(int i = 0; i < n; i++){
        int n1, n2, n3, n4, n5; cin>>n1>>n2>>n3>>n4>>n5;
        int count = 0;
        if(n1 > min1){
            count++;
            min1 = n1;
        }
        if(n2 > min2){
            count++;
            min2 = n2;
        }

        if(n3 > min3){
            count++;
            min3 = n3;
        }

        if(n4 > min4){
            count++;
            min4 = n4;
        }

        if(n5 > min5){
            count++;
            min5 = n5;
        }

        if(count == 3) h++;
        else if(count == 4) her++;
        else if(count == 5) hest++; 
    }

    cout<<h<<' '<<her<<' '<<hest<<endl;
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
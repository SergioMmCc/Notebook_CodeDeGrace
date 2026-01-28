#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define ps push_back
#define sz size()

#define int long long

void solver(){
  int n, h; cin>>n>>h;
  bool cond = 1;
  int ans = 0;
  for(int i = 1; i <= n; i++){
    int a, b, c;
    cin>>a>>b>>c;
    if(!cond) continue;
    int min1, min2, min3;
    if(a < b){
      if(a < c){
        min1 = a;
        if(b < c){
          min2 = b;
          min3 = c;
        }
        else{
          min2 = c;
          min3 = b;
        }  
      }
      else{
        min1 = c;
        min2 = a;
        min3 = b;
      }
    }
    else {
      if(b < c){
        min1 = b;
        if(a < c){
          min2 = a;
          min3 = c;
        }
        else{
          min2 = c;
          min3 = a;
        }
      }
      else{
        min1 = c;
        min2 = b;
        min3 = a;
      }
    }

    if(min1 > h) cond = 0;
    else if(min3 <= h|| min2 <= h) ans += min1;
    else ans += min2;
  }

  if(cond) cout<<ans<<endl;
  else cout<<"impossible"<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}
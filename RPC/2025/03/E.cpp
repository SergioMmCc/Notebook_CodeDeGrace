#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int top=1e5, big=500, MOD=1e9+7;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int C, M, Y, K, vc, vm, vy, vk;
    cin>>C>>M>>Y>>K;
    cin>>vc>>vm>>vy>>vk;

    int n, m;
    cin>>n>>m;

    string s;
    long long ans=0;
    int ck=0;
    for(int i=0; i<n; i++){
        cin>>s;
        for(char c : s){
            switch (c)
            {
            case 'W':
                //nothing
                break;
            case 'C':
                ans += C;
                vc--;
                break;
            case 'M':
                ans += M;
                vm--;
                break;
            case 'Y':
                ans += Y;
                vy--;
                break;
            
            case 'R':
                ans += M+Y;
                vm--; 
                vy--;
                break;
            case 'G':
                ans += C+Y;
                vc--;
                vy--;
                break;
            case 'B':
                ans += C+M;
                vc--;
                vm--;
                break;

            case 'K':
                ck++;
                break;

            default:
                break;
            }
        }
    }

    while(ck--){
        if((vc > 0 && vm > 0 && vy > 0) && (vk>0)){
            if(K <= M+Y+C){
                ans += K;
                vk--;
            }else{
                ans += M+Y+C;
                vm--; vy--; vc--;
            }
        }else if((vc > 0 && vm > 0 && vy > 0)){
                ans += M+Y+C;
                vm--; vy--; vc--;
        }else{
            ans += K;
                vk--;
        }
    }

    cout<<ans<<"\n";


}

// ld a ld b
// la-lb > 0
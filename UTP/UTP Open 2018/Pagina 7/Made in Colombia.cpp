#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ld = long double;

typedef pair<ld, int> pdi;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int n;
    while(cin>>n && n != 0){
        multiset<pdi> numbers;
        ld ans, save;
        cin>>ans;
        numbers.insert({ans, 0});
        auto it = numbers.begin();
        
        for(int i = 1; i < n; i++){
            cin>>save;
            numbers.insert({save, i});
            ld median = (*it).first;
            if(i % 2 == 1 && save < median)
                --it;
            else if(i % 2 == 0 && save >= median)
                ++it;
            ans += (*it).first;
        }

        ans /= (ld)n;
        cout<<fixed<<setprecision(2)<<ans<<endl;
    }
    return 0;
}
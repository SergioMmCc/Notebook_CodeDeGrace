#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ld = long double;
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef pair<int, int> pii;

void solver(){
    int q, x, op, median;
    cin >> q;
    multiset<int> left, right;
    int sl = 0, sr = 0;
    while(q-- && cin>>op){
        if(op == 1){
            cin >> x;
            if(!sl){
                left.insert(x);
                sl++;
            } else {
                auto it = left.end();
                it--;
                if (x <= *it){
                    left.insert(x);
                    sl++;
                } else {
                    right.insert(x);
                    sr++;
                }

                if(sr > sl){
                    auto pss = right.begin();
                    left.insert(*pss); sl++;
                    right.erase(pss); sr--;
                } else if (sl > sr + 1){
                    auto it = left.end(); it--;
                    right.insert(*it); sr++;
                    left.erase(it); sl--;
                }
            }
        } else if (op == 2){
            cin >> x;
            if (sl){
                auto it = left.end();
                it--;
                if (x <= *it){
                    auto found = left.find(x);
                    if(found!=left.end()){
                        left.erase(found);
                        sl--;
                    }
                } else {
                    auto found = right.find(x);
                    if(found!=right.end()){
                        right.erase(found);
                        sr--;
                    }
                }

                if(sr > sl){
                    auto pss = right.begin();
                    left.insert(*pss); sl++;
                    right.erase(pss); sr--;
                } else if (sl > sr + 1){
                    auto it = left.end(); it--;
                    right.insert(*it); sr++;
                    left.erase(it); sl--;
                }
            }

        } else{
            if(!sl)
                cout << "Empty!";
            else{
                auto it = left.end();
                it--;
                auto r = right.begin();
                if (sl == sr) median = (*it + *r)/2;
                else median = *it;
                cout << median;
            } 
            cout << endl;
        }
    }
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
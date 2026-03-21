#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

bool eq (char a, char b){
    return tolower(a) == tolower(b);
}

bool isCapital (char a){
    return ('A' <= a && a <= 'Z');
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    string read;
    getline(cin, read);

    char last = read[0];
    bool lastCapital = false;
    int ans = 1;
    if(isCapital(read[0])){
        ans++;
        lastCapital = true;
    }

    for(int i = 1; i < read.size(); i++) {
        if(read[i] == ' ') {
            if(last != ' ')
                ans++;
            last = ' ';
            continue;
        }

        if(!eq(last, read[i])) 
            ans++;
        if(!isCapital(read[i]))
            lastCapital = false;
        else{
            if(!lastCapital){
                ans++;
                lastCapital = true;
            }
        }
        last = read[i];
    }
    cout<<ans<<endl;
}
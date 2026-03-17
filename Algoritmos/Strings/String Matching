/* Algunas notas:
Este algortimo sirve para encontrar todos los prefijos en un array
algo de caja negra, haga un pull request de expandir esta info lol
aun tratando de entender el KMP completamente, by felipe sanchez
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
int INF=1E9, MOD=1E9+7;
 
 
void solve(){
    string s, t;
    cin >> s >> t;
    int m = t.size();
 
    s = t + "#" + s;
    // This make the Pattern Search KMP array
    int n = s.size();
    vector<int> lps(n);
    for(int i=1; i<n; i++){
        int j = lps[i-1];
        while(j > 0 && s[i] != s[j])
            j = lps[j-1];
        if(s[i] == s[j])
            j++;
        lps[i] = j;
    }

/* Esto serviria si buscaramos un patron de string t en s.
    int ans=0;
    for(int i = m; i < n; i++){
        ans += (lps[i] == m);
    }
    cout<< ans << "\n";
*/
    return;
}
 
int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}

#include "../template.h"
 
/* Algunas notas:
Este algortimo sirve para encontrar todos los prefijos en un array
algo de caja negra, haga un pull request de expandir esta info lol
aun tratando de entender el KMP completamente, by felipe sanchez
*/

void solve(){
    string s, t;
    cin >> s >> t;
    int m = sz(t);
 
    s = t + "#" + s;
    // This make the Pattern Search KMP array
    int n = sz(s);
    vi lps(n);
    for1(i,n-1){
        int j = lps[i-1];
        while(j > 0 && s[i] != s[j]) j = lps[j-1];
        if(s[i] == s[j]) j++;
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
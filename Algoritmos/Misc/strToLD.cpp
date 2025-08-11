// En las pruebas que hice fue bastante mas eficiente leer 
// como cadena y pasar a ld, que leer directamente como ld
ld strToLD(string s){
    ld aux = 1.0, ans = 0.0;
    int len = s.sz;
    for(int i = 0; i < len; i++){
        if(s[i] == '.') continue;
        int num = s[i] - '0';
        ans += (ld)num * aux;
        aux *= 0.1;
    }

    return ans;
}
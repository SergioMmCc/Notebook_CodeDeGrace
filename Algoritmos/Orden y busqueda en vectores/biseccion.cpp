// Con avance r = m, l = m + 1 (Hallar el menor que cumple)
while(l < r){
    int m = (l + r) / 2;
    if(check(m)) r = m;
    else l = m + 1;
}

// Con avance r = m - 1, l = m (Hallar el mayor que cumple)
while(l < r){
    int m = (l + r + 1) / 2;
    if(check(m)) l = m;
    else r = m - 1;
}
#include "../template.h"

// Con avance r = m, l = m + 1 (Hallar el menor que cumple)
// La respuesta se guarda en cualquiera de l o r
while(l < r){
    int m = l + (r - l) / 2;
    if(can(m)) r = m;
    else l = m + 1;
}

// Con avance r = m - 1, l = m (Hallar el mayor que cumple)
// La respuesta se guarda en cualquiera de l o r
while(l < r){
    int m = l + (r - l + 1) / 2;
    if(can(m)) l = m;
    else r = m - 1;
}
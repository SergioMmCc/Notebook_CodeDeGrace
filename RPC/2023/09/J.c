#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void eclipse (ds, ys, dm, ym) {
     int ns, nm;
     ns=ys-ds;
     nm=ym-dm;
     while (ns!=nm) {
           if (ns<nm)
              ns+=ys;
           if (nm<ns)
              nm+=ym;
     }
     printf ("%d\n", ns);
}

int main () {
    int ds, ys, dm, ym;
    scanf ("%d %d %d %d", &ds, &ys, &dm, &ym);     
    eclipse (ds, ys, dm, ym);
    return 0;
}  

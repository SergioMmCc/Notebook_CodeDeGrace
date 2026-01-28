#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    char word[50001];
    int l1, l2, m, longitud, A[50001] = {0}, T[50001] = {0}, G[50001] = {0}, C[50001] = {0}, na, nt, ng, nc;

    scanf ("%s", word);
    longitud = strlen(word);
    for (int i = 0; i < longitud; i++) {
        A[i+1] = A[i];
        T[i+1] = T[i];
        G[i+1] = G[i];
        C[i+1] = C[i];
        if (word[i] == 'A')
            A[i+1]++;
        else if (word[i] == 'T')
            T[i+1]++;
        else if (word[i] == 'G')
            G[i+1]++;
        else 
            C[i+1]++;
    }
    scanf ("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf ("%d %d", &l1, &l2);
        na = A[l2] - A[l1-1];
        nt = T[l2] - T[l1-1];
        ng = G[l2] - G[l1-1];
        nc = C[l2] - C[l1-1];

        if (na >= nt && nt >= ng && ng >= nc)
            printf ("ATGC\n");

        else if (na >= nt && nt >= nc && nc > ng)
            printf ("ATCG\n");

        else if (na >= ng && ng > nt && nt >= nc)
            printf ("AGTC\n");

        else if (na >= ng && ng >= nc && nc > nt)
            printf ("AGCT\n");

        else if (na >= nc && nc > nt && nt >= ng)
            printf ("ACTG\n");

        else if (na >= nc && nc > ng && ng > nt)
            printf ("ACGT\n");

//-------------------------------------------------------------
        else if (nt > na && na >= ng && ng >= nc)
            printf ("TAGC\n");

        else if (nt > na && na >= nc && nc > ng)
            printf ("TACG\n");

        else if (nt >= ng && ng > na && na >= nc)
            printf ("TGAC\n");

        else if (nt >= ng && ng >= nc && nc > na)
            printf ("TGCA\n");

        else if (nt >= nc && nc > na && na >= ng)
            printf ("TCAG\n");

        else if (nt >= nc && nc > ng && ng > na)
            printf ("TCGA\n");
    //---------------------------------------------------------
        else if (ng > na && na >= nt && nt >= nc)
            printf ("GATC\n");

        else if (ng > na && na >= nc && nc > nt)
            printf ("GACT\n");

        else if (ng > nt && nt > na && na >= nc)
            printf ("GTAC\n");

        else if (ng > nt && nt >= nc && nc > na)
            printf ("GTCA\n");

        else if (ng >= nc && nc > na && na >= nt)
            printf ("GCAT\n");

        else if (ng >= nc && nc > nt && nt > na)
            printf ("GCTA\n");
//--------------------------------------------------------------
        else if (nc > na && na >= nt && nt >= ng)
            printf ("CATG\n");

        else if (nc > na && na >= ng && ng > nt)
            printf ("CAGT\n");

        else if (nc > nt && nt > na && na >= ng)
            printf ("CTAG\n");

        else if (nc > nt && nt >= ng && ng > na)
            printf ("CTGA\n");

        else if (nc > ng && ng > na && na >= nt)
            printf ("CGAT\n");

        else if (nc > ng && ng > nt && nt > na)
            printf ("CGTA\n");
    }
    return 0;
}
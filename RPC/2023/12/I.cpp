#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    int globalTime = 0, cores, aCores, mJobs, Jobs[100005], maxTime = 0, actualJob = -1, nCores[100005], indexCore = -1, myInfinite = 2147483647;
    scanf ("%d %d", &mJobs, &cores);
    for (int index = 0; index < mJobs; index++)
        scanf ("%d", &Jobs[index]);
    memcpy (nCores, &myInfinite, sizeof(int) * 100005);
    aCores = cores;
    do {
        for (int i = 0; i <= indexCore; i++) {
            if (nCores[i] != myInfinite) {
                Jobs[nCores[i]]--;
                if (Jobs[nCores[i]] == 0) {
                    globalTime = 0;
                    aCores++;
                    nCores[i] = myInfinite;
                    if (actualJob < (mJobs - 1)) {
                        actualJob++;
                        nCores[i] = actualJob;
                        aCores--;
                    }
                }
            }
        }
        while (aCores > 0 && actualJob < (mJobs - 1)) {
            actualJob++;
            indexCore++;
            nCores[indexCore] = actualJob;
            aCores--;
        }
        globalTime++;
        if (globalTime > maxTime)
            maxTime = globalTime;
    } while (aCores < cores);
    printf ("%d\n", maxTime);
    return 0;
}

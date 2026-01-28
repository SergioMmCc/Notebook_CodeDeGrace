#include<bits/stdc++.h>
using namespace std;

int main () {
    vector<int> positives, negatives;
    int nTests, nIndex, pIndex, n, k, aux;
    long long distance;
    scanf ("%d", &nTests);
    while (nTests--) {
        distance = 0;
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++) {
            scanf ("%d", &aux);
            if (aux > 0) positives.push_back(aux);
            else negatives.push_back(-aux);
        }
        sort(negatives.begin(), negatives.end());
        sort(positives.begin(), positives.end());
        nIndex = negatives.size() - 1;
        pIndex = positives.size() - 1;
        if (negatives.empty() && positives.empty()) {
            printf("0\n");
            continue;
        }
        if ((!negatives.empty() && positives.empty()) || (!negatives.empty() && !positives.empty() && negatives[nIndex] > positives[pIndex])) {
            distance += negatives[nIndex];
            nIndex -= k;
        } else {
            distance += positives[pIndex];
            pIndex -= k;
        }
        for (nIndex; nIndex >= 0; nIndex -= k)
            distance += (negatives[nIndex] << 1);
        for (pIndex; pIndex >= 0; pIndex -= k)
            distance += (positives[pIndex] << 1);
        printf ("%lld\n", distance);
        positives.clear();
        negatives.clear();
    }
}
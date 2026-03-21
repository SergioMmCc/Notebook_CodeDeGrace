#include <stdio.h>

int main() {
    int customers, currentTime = 0, index, arrival, service, patience;
    scanf ("%d", &customers);
    while (customers > 0) {
        scanf ("%d %d %d %d", &index, &arrival, &service, &patience);
        if (arrival > currentTime)
            currentTime = arrival;
        if (arrival + patience >= currentTime) {
            currentTime += service;
            printf ("%d\n", index);
        }
        customers--;
    }
    return 0;
}

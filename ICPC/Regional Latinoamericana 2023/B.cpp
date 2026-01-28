#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define EQUALIZER 1
#define CARLINHOS 0

using namespace std;

int main () {
    int frequency [200001], saveNumber, n, result;
    memset (frequency, 0, sizeof frequency);
    cin >> n;
    
    for (int index = 1; index <= 3*n; index++) {
        cin >> saveNumber;
        if (saveNumber < 0)
            saveNumber = abs (saveNumber) + 100000;
        frequency [saveNumber]++;
    }
    result = EQUALIZER;
    
    for (int index = 0; index <= 200000; index++) {
        if (frequency[index] % 3 != 0) {
            result = CARLINHOS;
            break;
        }
            
    }
    
    if (result == CARLINHOS)
        cout << "Y\n";
    else
        cout << "N\n";

    return 0;
}

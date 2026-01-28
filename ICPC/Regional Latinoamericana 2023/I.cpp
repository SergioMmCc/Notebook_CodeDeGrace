#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define m 1000000007
 
using namespace std;
 
int main () {
    long long int rightFrequencies[30], leftFrequencies[30], left = 0, right = 0, saveLetter, length, result, n, nplus1, nminus1;
    string word;
 
    memset (rightFrequencies, 0, sizeof rightFrequencies);
    memset (leftFrequencies, 0, sizeof leftFrequencies);
    cin >> word;
    cin >> n;
    nplus1 = n + 1;
    nminus1 = n - 1;
    length = word.size () - 1;
 
    for (int letterIndex = 0; letterIndex <= length; letterIndex++) {
        saveLetter = (int)word[letterIndex] - 96;
        for (int frequencyIndex = saveLetter; frequencyIndex < 26; frequencyIndex++)
            leftFrequencies[frequencyIndex]++;
 
        left += leftFrequencies[saveLetter - 1];
    }
 
    for (int letterIndex = length; letterIndex >= 0; letterIndex--) {
        saveLetter = (int)word[letterIndex] - 96;
        for (int frequencyIndex = saveLetter; frequencyIndex < 26; frequencyIndex++)
            rightFrequencies[frequencyIndex]++;
 
        right += rightFrequencies[saveLetter - 1];
    }
 
    if (n % 2 == 0) 
        n /= 2;
 
    else {
    	nplus1 /= 2;
    	nminus1 /= 2;
	}
 
    result = ((n%m) * (((right%m)*(nplus1%m)%m) + ((left%m) * (nminus1%m)%m)%m)) %m;    

    cout << result << "\n";
 
    return 0;
}

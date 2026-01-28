#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXT 4000
#define FALSE 0
#define TRUE 1

int findLetter (char lookForLetter, char word []) {
    int index;
   
    for (index = 0; index < 5; index++) {
        if (word [index] == lookForLetter)
            return TRUE;
    }
    return FALSE;
}

int main () {
    int nWords, nAnswers, index, wIndex, result, coincidences;
    char words [MAXT + 5][6], answer [6], saveCode [MAXT + 5][6];
   
    scanf ("%d", &nWords);
    for (index = 0; index < nWords; index++)
        scanf ("%s", words [index]);

    for (index = 0; index < nWords; index++) {
        for (wIndex = 0; wIndex < 5; wIndex++) {
            result = FALSE;
            if (words [index][wIndex] == words [0][wIndex])
                saveCode [index][wIndex] = '*';
            else {
               
                result = findLetter (words [index][wIndex], words [0]);
                if (result == TRUE)
                    saveCode [index][wIndex] = '!';
                else
                    saveCode [index][wIndex] = 'X';
            }
        }
    }
   
    scanf ("%d", &nAnswers);
   
    while (nAnswers--) {
        coincidences = 0;
        scanf ("%s", answer);
        for (index = 0; index < nWords; index++) {
            if (strcmp (answer, saveCode [index]) == 0)
                coincidences ++;
        }
        printf ("%d\n", coincidences);
    }
   
    return 0;
}

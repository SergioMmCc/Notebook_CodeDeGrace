#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    char message[370], encrypt[20][20];
    char patron[ ] = "XURDDLLUUURRRDDDDLLLLUUUUURRRRRDDDDDDLLLLLLUUUUUUURRRRRRRDDDDDDDDLLLLLLLLUUUUUUUUURRRRRRRRRDDDDDDDDDDLLLLLLLLLLUUUUUUUUUUURRRRRRRRRRRDDDDDDDDDDDDLLLLLLLLLLLLUUUUUUUUUUUUURRRRRRRRRRRRRDDDDDDDDDDDDDDLLLLLLLLLLLLLLUUUUUUUUUUUUUUURRRRRRRRRRRRRRRDDDDDDDDDDDDDDDDLLLLLLLLLLLLLLLLUUUUUUUUUUUUUUUUURRRRRRRRRRRRRRRRRDDDDDDDDDDDDDDDDDDLLLLLLLLLLLLLLLLLLUUUUUUUUUUUUUUUUUUURRRRRRRRRRRRRRRRRRRDDDDDDDDDDDDDDDDDDDDLLLLLLLLLLLLLLLLLLLL";
    int n, idRow, idColumn, idLetter, lengthMessage;

    for(idRow = 0; idRow <= 19; idRow++)
        for(idColumn = 0; idColumn <= 19; idColumn++)
            encrypt[idRow][idColumn] = '#';

    scanf("%d %s", &n, message);
    lengthMessage = strlen(message) - 1;
    idRow = n / 2 + 1;
    idColumn = n / 2 + 1;

    encrypt[idRow][idColumn] = message[0];

    for(idLetter = 1; idLetter <= lengthMessage; idLetter++)
    {
        if(patron[idLetter] == 'U')
            idRow--;
        else
        {
            if(patron[idLetter] == 'R')
                idColumn++;
            else
            {
                if(patron[idLetter] == 'D')
                    idRow++;
                else
                    idColumn--;
            }
        }
        encrypt[idRow][idColumn] = message[idLetter];
    }

    for(idRow = 1; idRow <= n; idRow++)
    {
        for(idColumn = 1; idColumn <= n; idColumn++)
        {
            if(encrypt[idRow][idColumn] != '#')
                printf("%c", encrypt[idRow][idColumn]);
        }
    }

    printf("\n");

    return 0;
}

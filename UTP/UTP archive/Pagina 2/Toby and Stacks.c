#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAXS 1000000

struct node {
    int key;
    struct node *next;
};

struct node *Push (struct node *top, int element) {
    struct node *newNode = (struct node*) malloc (sizeof (struct node));
    newNode->key = element;
    newNode->next = top;
    return newNode;
}

void Pop (struct node **top) {
    struct node *actualNode = *top;
    *top = actualNode->next;
    free(actualNode);
}

int main() {
    struct node *stacks[MAXS + 1];
    int operation, idStack, totalOperations, element, stackSize[MAXS + 1];
    stacks[0] = NULL;
    stackSize[0] = 0;
    scanf ("%d", &totalOperations);
    for (int i = 1; i <= totalOperations; i++) {
        scanf("%d %d", &idStack, &operation);
        if (operation == 0) {
            scanf ("%d", &element);
            stacks[i] = Push (stacks[idStack], element);
            stackSize[i] = stackSize[idStack] + 1;
            printf ("%d\n", stackSize[i]);
        } else {
            if (stacks[idStack] == NULL) {
                printf ("-1\n");
                stackSize[i] = 0;
            }
            else {
                element = stacks[idStack]->key;
                stacks[i] = stacks[idStack]->next;
                stackSize[i] = stackSize[idStack] - 1;
                printf ("%d\n", element);
            }
        }
    }
    return 0;
}
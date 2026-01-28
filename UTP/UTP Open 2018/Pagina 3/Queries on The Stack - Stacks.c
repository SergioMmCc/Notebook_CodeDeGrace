#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

struct node
{
    int key, max, min;
    struct node *next;
};

//Funcion para agregar un elemento a la pila
struct node *push (struct node *top, int element) {
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof (struct node));
    newNode->key = element;
    
    if (top == NULL) {
        newNode->min = element;
        newNode->max = element;
    }
    else {
        if (top->min < element)
            newNode->min = top->min;
        else
            newNode->min = element;
        
        if (top->max > element)
            newNode->max = top->max;
        else
            newNode->max = element;
    }
    
    newNode->next = top;
    top = newNode;
    return top;
}

//Funcion para eliminar un elemento de la pila
int pop (struct node **top) {
    struct node *actualNode;
    int element;
    actualNode = *top;
    element = actualNode->key;
    *top = actualNode->next;
    free (actualNode);
    return element;
}


int stackEmpty (struct node *top) {
    if (top == NULL)
        return TRUE;
    else
        return FALSE;
}

int main () {
    int cases, queries, operation, element;
    struct node *top = NULL;
    scanf ("%d", &cases);
    
    while (cases--) {
        scanf ("%d", &queries);
        while (queries--) {
            scanf ("%d", &operation);
            if (operation == 1) {
                scanf ("%d", &element);
                top = push (top, element);
            }
            else if (operation == 2) {
                if (top != NULL)
                    element = pop (&top);
            }
            else {
                if (top == NULL)
                    printf ("Empty!\n");
                else
                    printf ("%d\n", top->max - top->min);    
            }
        }
        while (top != NULL)
            element = pop (&top);
    }
    
    return 0;
}

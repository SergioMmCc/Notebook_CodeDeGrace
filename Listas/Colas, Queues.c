#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define TRUE 1
#define FALSE 0

struct node
{
    int key;
    struct node *next;
};


//Funcion para agregar un nodo a una cola
struct node *enqueue (struct node *tail, int element) {
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof (struct node));
    newNode->key = element;
    if (tail == NULL) {
        newNode->next = newNode;
        tail = newNode;
    }
    else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
    return tail;
}

//Funcion para extraer un elemento de la cola
int dequeue (struct node **tail) {
    struct node *firstNode;
    int element;
    if (*tail == (*tail)->next) {
        element = (*tail)->key;
        free (*tail);
        *tail = NULL;
    }
    else {
        firstNode = (*tail)->next;
        element = firstNode->key;
        (*tail)->next = firstNode->next;
        free (firstNode);
    }
    return element;
}

//Funcion para averiguar si una cola esta vacia
int queueEmpty (struct node *tail) {
    if (tail == NULL)
        return TRUE;
    else 
        return FALSE;
}

//Funcion para imprimir una cola
void printQueue (struct node *tail)
{
	struct node *actualNode;
	if (tail == NULL)
		printf ("The queue is empty.\n");
		
	else {
		actualNode = tail->next;
		while (actualNode != tail) {
			printf ("%d -> ", actualNode->key);
			actualNode = actualNode->next;
		}
		printf ("%d ->...\n", tail->key);
	}
}

int main()
{
    struct node *tail;
    int operation, element;
    tail = NULL;
    
    while (scanf ("%d", &operation) != EOF) {
        if (operation == 1) { //enqueue
            scanf ("%d", &element);
            tail = enqueue (tail, element);
            printQueue (tail);
        }
        else if (operation == 2) { //dequeue
            if (queueEmpty (tail) != TRUE) {
                element = dequeue (&tail);
                printf ("Element: %d\n", element);
                printQueue (tail);
            }
            else 
                printf ("The queue is empty\n");
        }
        else
            printf ("Bad use\n1. Enqueue\n2. Dequeue\n");
    }

    return 0;
}

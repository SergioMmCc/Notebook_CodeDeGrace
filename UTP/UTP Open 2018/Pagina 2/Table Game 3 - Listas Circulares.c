#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define myPositiveInfinite 2147483647
#define myNegativeInfinite -2147483647
#define TRUE 1
#define FALSE 0
#define MAXT 10000

typedef struct
{
    int money, position;
} players;

struct node
{
    players key;
    struct node *next;
    struct node *prev;
};

struct node *insertElementInCircularDoublyLinkedList (struct node *tail, players element)
{
    struct node *newNode ;
    newNode = (struct node *) malloc (sizeof (struct node));
    newNode->key = element;
    if(tail == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = tail->next;
        newNode->next->prev = newNode;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    return tail;
}

struct node *deleteFirstNodeInCircularDoublyLinkedList (struct node *tail)
{
    struct node *firstNode;
    if(tail == NULL)
        printf ("The circular doubly linked list is empty.\n");
    else
    {
        if(tail == tail->next)
        {
            free (tail);
            tail = NULL;
        }
        else
        {
            firstNode = tail->next;
            tail->next = firstNode->next ;
            tail->next->prev = tail;
            free (firstNode);
        }
    }
    return tail;
}

typedef struct {
    int position, money;
} queue;

int Parent (int i) {
    return i / 2;
}

int Left (int i) {
    return 2 * i;
}

int Right (int i) {
    return 2 * i + 1;
}

void MinHeapify (queue Q[],int i, int heapSize) {
    int l, r, least;
    queue temp;
    l = Left(i);
    r = Right(i);
    if((l <= heapSize) && (Q[l].position < Q[i].position))
        least = l;
    else 
        least = i;
    if((r <= heapSize) && (Q[r].position < Q[least].position))
        least = r;
    if(least != i) {
        temp = Q[i];
        Q[i] = Q[least];
        Q[least] = temp;
        MinHeapify(Q, least, heapSize);
        
    }
}

queue MinPQ_Minimum (queue Q[]) {
    return Q[1];
}

queue MinPQ_Extract (queue Q[], int *heapSize) {
    queue min;
    min.position = myNegativeInfinite;
    if (*heapSize < 1)
        printf("Heap underflow.\n");
    else {
        min = Q[1];
        Q[1] = Q[*heapSize];
        *heapSize = *heapSize - 1;
        MinHeapify(Q, 1, *heapSize);
    }
    return min;
} 

void MinPQ_DecreaseKey (queue Q[], int i, queue key) {
    queue temp;
    if (key.position > Q[i].position)
        printf("New key is higher than currente key.\n");
    else {
        Q[i] = key;
        while ((i > 1) && (Q[Parent(i)].position > Q[i].position)) {
            temp = Q[i];
            Q[i] = Q[Parent(i)];
            Q[Parent(i)] = temp;
            i = Parent(i);
        }
    }
}

void MinPQ_Insert (queue Q[], queue key, int *heapSize) {
    *heapSize = *heapSize + 1;
    Q[*heapSize].position = myPositiveInfinite;
    MinPQ_DecreaseKey(Q, *heapSize, key);
}

int main () {
    int n, startingMoney, index, redDice, blueDice, diceIndex, heapSize;
    char direction;
    struct node *tail;
    tail = NULL;
    players newPlayer;
    queue Q [MAXT + 1], addPlayer, printPlayer;
    
    while (scanf ("%d %d", &n, &startingMoney) != EOF) {
        heapSize = 0;
        
        for (index = 1; index <= n; index++) {
            newPlayer.position = index;
            newPlayer.money = startingMoney;
            tail = insertElementInCircularDoublyLinkedList (tail, newPlayer);
        }
        
        tail = tail->next;
        
        for (index = 1; index < n; index++) {
            scanf (" %c %d %d", &direction, &redDice, &blueDice);
            
            if (tail != tail->next) {
                if (direction == 'C') {
                    for (diceIndex = 1; diceIndex < redDice; diceIndex++)
                        tail = tail->next;
                }
                else {
                    for (diceIndex = 1; diceIndex <= redDice + 1; diceIndex++)
                        tail = tail->prev; 
                }
                
                tail->next->key.money += blueDice;
                
                if (tail->next->key.money % 2 == 1) {
                    addPlayer.position = tail->next->key.position;
                    addPlayer.money = tail->next->key.money;
                    MinPQ_Insert (Q, addPlayer, &heapSize);
                    
                    //printf ("%d %d\n", tail->next->key.position, tail->next->key.money);
                    tail = deleteFirstNodeInCircularDoublyLinkedList (tail);
                    
                    if (direction == 'C')
                       tail = tail->next;
                    
                }
                else {
                    tail = tail->prev;
                    tail = deleteFirstNodeInCircularDoublyLinkedList (tail);
                    if (tail != tail->next) {
                        tail = tail->next;
                        tail = deleteFirstNodeInCircularDoublyLinkedList (tail);
                    }
                    
                } 
            }   
        }
        addPlayer.position = tail->key.position;
        addPlayer.money = tail->key.money;
        MinPQ_Insert (Q, addPlayer, &heapSize);
        //printf ("%d %d\n", tail->key.position, tail->key.money);
        free (tail);
        tail = NULL;
        
        while (heapSize > 0) {
            printPlayer = MinPQ_Extract (Q, &heapSize);
            printf ("%d %d\n", printPlayer.position, printPlayer.money);
        }
    }
    
    return 0;
}

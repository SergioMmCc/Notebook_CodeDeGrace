#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct node
{
	int key;
	struct node *next;
};

struct node *InsertElementInAscendentLinkedList (struct node *head, int element)
{
	struct node *newNode, *previousNode, *actualNode;
	newNode = (struct node *)malloc(sizeof (struct node));
	newNode->key= element;
	
	if (head == NULL) {
		newNode->next = head;
		head = newNode;
	}
	else if (element <= head->key) {
		newNode->next = head;
		head = newNode;
	}
	else {
		previousNode = head;
		actualNode = head->next;
		
		while ((actualNode != NULL) && (actualNode->key < element)) {
			previousNode = actualNode;
			actualNode = actualNode->next;
		}
		
		previousNode->next = newNode;
		newNode->next = actualNode;
	}
	
	return head;
}

void PrintAscendentLinkedList (struct node *head)
{
	struct node *actual;
	actual = head;
	while (actual != NULL)
	{
		printf ("%d -> ", actual->key);
		actual = actual->next;
	}
	printf ("NULL\n");
}

struct node *DeleteElementOfAscendentLinkedList (struct node *head, int element) 
{
	struct node *previousNode, *actualNode;
	if (head == NULL)
		printf ("The linked list is empty.\n");
	
	else if (element == head->key) {
		actualNode = head;
		head = head->next;
		free (actualNode);
		printf ("Deleted the element %d\n", element);
	}
	else {
		previousNode = head;
		actualNode = head->next;
		
		while ((actualNode != NULL) && (actualNode->key < element)) {
			previousNode = actualNode;
			actualNode = actualNode->next;
		}
		if (actualNode == NULL) 
			printf ("The element %d is not in the linked list\n", element);
			
		else if (actualNode->key != element)
			printf ("The element %d is not in the linked list\n", element);
			
		else {
			previousNode->next = actualNode->next;
			free (actualNode);
			printf ("Deleted the element %d\n", element);
		}
	}
	
	return head;	
}

int main () {
	int operation, element;
	struct node *head;
	head = NULL;
	
	while (scanf (" %d %d", &operation, &element) != EOF) {
	
		if (operation == 1) {
			head = InsertElementInAscendentLinkedList (head, element);
			PrintAscendentLinkedList (head);
		}
		else if (operation == 2) {
			head = DeleteElementOfAscendentLinkedList (head, element);
			PrintAscendentLinkedList (head);
		}
		else
			printf ("Bad use.\n1. Insert\n2. Delete\n");	
	}
		
	return 0;
}













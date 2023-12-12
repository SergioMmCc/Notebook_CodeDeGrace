# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# define TRUE 1
# define FALSE 0

struct node
{
	int key ;
	struct node * next ;
	struct node * prev ;
};

struct node * insertElementInCircularDoublyLinkedList ( struct node *tail , int element )
{
	struct node * newNode ;
	newNode = (struct node *) malloc (sizeof (struct node));
	newNode -> key = element ;
	if( tail == NULL )
	{
		newNode -> next = newNode ;
		newNode -> prev = newNode ;
		tail = newNode ;
	}
	else
	{
		newNode -> next = tail -> next ;
		newNode ->next -> prev = newNode ;
		newNode -> prev = tail ;
		tail -> next = newNode ;
		tail = newNode ;
	}
	return tail ;
}

struct node * deleteFirstNodeInCircularDoublyLinkedList ( struct node * tail )
{
	struct node * firstNode ;
	if( tail == NULL )
		printf ("The circular doubly linked list is empty.\n");
	else
	{
		if( tail == tail -> next )
		{
			free ( tail ) ;
			tail = NULL ;
		}
		else
		{
			firstNode = tail -> next ;
			tail -> next = firstNode -> next ;
			tail ->next -> prev = tail ;
			free ( firstNode );
		}
	}
	return tail ;
}

void printFromFirstToLastCircularDoublyLinkedList ( struct node * tail )
{
	struct node * actualNode ;
	if( tail == NULL )
		printf ("NULL \n");
	else
	{
		actualNode = tail -> next ;
		while ( actualNode != tail )
		{
			printf ("%d -> ", actualNode -> key ) ;
			actualNode = actualNode -> next ;
		}
		printf ("%d ...\n", tail -> key );
	}
}

void printFromLastToFirstCircularDoublyLinkedList ( struct node * tail )
{
	struct node * actualNode ;
	if( tail == NULL )
		printf ("NULL \n");
	else
	{
		actualNode = tail ;
		while ( actualNode != tail -> next )
		{
			printf ("%d -> ", actualNode -> key ) ;
			actualNode = actualNode -> prev ;
		}
		printf ("%d ...\n", tail ->next -> key );
	}
}

struct node * deleteElementOfCircularDoublyLinkedList ( struct node *tail , int element )
{
	struct node * actualNode ;
	int flag = FALSE ;
	if( tail == NULL )
		printf (" The circular doubly linked list is empty .\n");
	else
	{
		actualNode = tail -> next ;
		while (( actualNode != tail ) && ( flag == FALSE ))
		{
			if( actualNode -> key == element )
			{
			flag = TRUE ;
			break ;
			}
			else
			actualNode = actualNode -> next ;
		}
		if( flag == FALSE )
		{
			if(tail -> key == element )
			{
				flag = TRUE ;
				actualNode = tail ;
			}
		}
		if( tail == tail -> next )
		{
			if( flag == TRUE )
			{
				free ( tail ) ;
				tail = NULL ;
			}
			else
				printf (" The %d is not in the circular doubly linked list .\n", element );
		}
		else
		{
			if( flag == FALSE )
				printf (" The %d is not in the circular doubly linked list .\n", element );
			else
			{
				actualNode ->next -> prev = actualNode -> prev ;
				actualNode ->prev -> next = actualNode -> next ;
				if( actualNode == tail )
					tail = tail -> prev ;
				free ( actualNode );
			}
		}
	}
	return tail ;
}

int main () {
	return 0;
}

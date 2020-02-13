# Circular Linked List in C

A circular linked list is a linked list in which the last node points to the head or front node making the data structure to look like a circle. 
A circularly linked list node can be implemented using singly linked or doubly linked list.

## Application of Circular Linked List
The real life application where the circular linked list is used is our Personal Computers, where multiple applications are running. All the running applications are kept in a circular linked list and the OS gives a fixed time slot to all for running. The Operating System keeps on iterating over the linked list until all the applications are completed.
Another example can be Multiplayer games. All the Players are kept in a Circular Linked List and the pointer keeps on moving forward as a player's chance ends.
Circular Linked List can also be used to create Circular Queue. In a Queue we have to keep two pointers, FRONT and REAR in memory all the time, where as in Circular Linked List, only one pointer is required.


## Node Creation

```c

void create()
{
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	printf("\nEnter the node value : ");
	scanf("%d",&newnode->info);
	newnode->next=NULL;
	if(rear==NULL)
	front=rear=newnode;
	else
	{
		rear->next=newnode;
		rear=newnode;
	}
	
	rear->next=front;
}
```
## Node Deletion

```c
void del()
{
	temp=front;
	if(front==NULL)
		printf("\nUnderflow :");
	else
	{
		if(front==rear)
		{
			printf("\n%d",front->info);
			front=rear=NULL;
		}
		else
		{
			printf("\n%d",front->info);
			front=front->next;
			rear->next=front;
		}
 
	temp->next=NULL;
	free(temp);
	}
}
```
## Traversing the Circular Linked list
```c

void display()
{
	temp=front;
	if(front==NULL)
		printf("\nEmpty");
	else
	{
		printf("\n");
		for(;temp!=rear;temp=temp->next)
			printf("\n%d address=%u next=%u\t",temp->info,temp,temp->next);
			printf("\n%d address=%u next=%u\t",temp->info,temp,temp->next);
	}
}
```

## Putting it all  together ( Without errors hopefully) 
```c
#include<stdio.h>
#include<stdlib.h>
 
typedef struct Node
 
{
	int info;
	struct Node *next;
}node;
 
node *front=NULL,*rear=NULL,*temp;
 
void create();
void del();
void display();
 
int main()
{
	int chc;
	do
	{
 	printf("\nMenu\n\t 1 to create the element : ");
	printf("\n\t 2 to delete the element : ");
	printf("\n\t 3 to display the queue : ");
	printf("\n\t 4 to exit from main : ");
	printf("\nEnter your choice : ");
	scanf("%d",&chc);
	
		switch(chc)
		{
			case 1:
	 		create();
			break;
	 	
		 	case 2:
	 		del();
	 		break;
	 
	 		case 3:
	 		display();
	 		break;
	 
	 		case 4:
	 		return 1;
	 		
			default:
	 			printf("\nInvalid choice :");
	 	}
	}while(1);
 
	return 0;
}
 
void create()
{
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	printf("\nEnter the node value : ");
	scanf("%d",&newnode->info);
	newnode->next=NULL;
	if(rear==NULL)
	front=rear=newnode;
	else
	{
		rear->next=newnode;
		rear=newnode;
	}
	
	rear->next=front;
}
 
void del()
{
	temp=front;
	if(front==NULL)
		printf("\nUnderflow :");
	else
	{
		if(front==rear)
		{
			printf("\n%d",front->info);
			front=rear=NULL;
		}
		else
		{
			printf("\n%d",front->info);
			front=front->next;
			rear->next=front;
		}
 
	temp->next=NULL;
	free(temp);
	}
}
 
void display()
{
	temp=front;
	if(front==NULL)
		printf("\nEmpty");
	else
	{
		printf("\n");
		for(;temp!=rear;temp=temp->next)
			printf("\n%d address=%u next=%u\t",temp->info,temp,temp->next);
			printf("\n%d address=%u next=%u\t",temp->info,temp,temp->next);
	}
}
```
### Example Output:
```
Menu
	 1 to create the element : 
	 2 to delete the element : 
	 3 to display the queue : 
	 4 to exit from main : 
Enter your choice : 1

Enter the node value : 54

Menu
	 1 to create the element : 
	 2 to delete the element : 
	 3 to display the queue : 
	 4 to exit from main : 
Enter your choice : 1

Enter the node value : 67

Menu
	 1 to create the element : 
	 2 to delete the element : 
	 3 to display the queue : 
	 4 to exit from main : 
Enter your choice : 1

Enter the node value : 22

Menu
	 1 to create the element : 
	 2 to delete the element : 
	 3 to display the queue : 
	 4 to exit from main : 
Enter your choice : 3


54 address=140579480 next=140579496	
67 address=140579496 next=140579512	
22 address=140579512 next=140579480	

```

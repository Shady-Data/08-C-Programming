![image](https://user-images.githubusercontent.com/47218880/74446318-54bf0d80-4e3d-11ea-9e3f-7a68a3fd4eef.png)
### adding to the front
```c
void addAtFront(struct Node** head_ref, int new_data) //inserts a new node on the front of the list. 
{ 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));   // allocate node 
    new_node->data = new_data; //add in the data  
    new_node->next = (*head_ref); // change next of new node as head and previous as NULL 
    new_node->prev = NULL; 
    if ((*head_ref) != NULL)  // modify prev of head node to new node 
        (*head_ref)->prev = new_node; 
    (*head_ref) = new_node;   // change the head to point to the new node 
}
```
### adding at a given section
```c

void addAt(struct Node* prev_node, int new_data) 
{ 
    if (prev_node == NULL) { 
        printf("the given previous node cannot be NULL");  // check if the given prev_node is NULL 
        return; 
    } 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));  // allocate new node 
    new_node->data = new_data;  // add in the data  
    new_node->next = prev_node->next;    // change next of new node as next of prev_node 
    prev_node->next = new_node;   // modify the next of prev_node as new_node
    new_node->prev = prev_node;   // Make prev_node as previous of new_node 
    if (new_node->next != NULL) 
        new_node->next->prev = new_node;  // Change previous of new_node's next node 
} 

```
# adding to the end 
```c
void addAtEnd(struct Node** head_ref, int new_data) 
{ 
    
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
    struct Node* last = *head_ref; //used in traversing
    new_node->data = new_data; // add in the data
    new_node->next = NULL; // the added node will be the last, this is what it will point to.
    if (*head_ref == NULL) { 
        new_node->prev = NULL; 
        *head_ref = new_node; // overalll checking for emptiness 
        return; 
    } 
  
    while (last->next != NULL) // go through the list until you reach the last node
        last = last->next; 
    last->next = new_node; // modify the next of final node
    new_node->prev = last;  modify the final node as previous of the new one
    return; 
} 

```
# Delete from the front
```c
void RemoveFirstNode()
{
    struct node * NodeToDel;
    if(stnode == NULL)
    {
        printf(" Delete is not possible. No data in the list.\n");
    }
    else
    {
        NodeToDel = stnode;
        stnode = stnode->nextptr;   // move the next address of starting node to 2 node
        stnode->preptr = NULL;      // set previous address of staring node is NULL
        free(NodeToDel);            // delete the first node from memory
    }
}

```
# Delete from the end
```c
void DeleteLastNode()
{
    struct node * NodeToDel;
 
    if(ennode == NULL)
    {
        printf(" Delete is not possible. No data in the list.\n");
    }
    else
    {
        NodeToDel = ennode;
        ennode = ennode->preptr;    // move the previous address of the last node to 2nd last node
        ennode->nextptr = NULL;     // set the next address of last node to NULL
        free(NodeToDel);            // delete the last node
    }
}


```
# Delete from 


# VARIOUS EXAMPLES OF  DOUBLY LINKED LISTS
# Doubly Linked List Example 1
```c
/* Doubly Linked List implementation */
#include<stdio.h>
#include<stdlib.h>

struct Node  {
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* head; // global variable - pointer to head node.

//Creates a new Node and returns pointer to it. 
struct Node* GetNewNode(int x) {
	struct Node* newNode
		= (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

//Inserts a Node at head of doubly linked list
void InsertAtHead(int x) {
	struct Node* newNode = GetNewNode(x);
	if(head == NULL) {
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head; 
	head = newNode;
}

//Inserts a Node at tail of Doubly linked list
void InsertAtTail(int x) {
	struct Node* temp = head;
	struct Node* newNode = GetNewNode(x);
	if(head == NULL) {
		head = newNode;
		return;
	}
	while(temp->next != NULL) temp = temp->next; // Go To last Node
	temp->next = newNode;
	newNode->prev = temp;
}

//Prints all the elements in linked list in forward traversal order
void Print() {
	struct Node* temp = head;
	printf("Forward: ");
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

//Prints all elements in linked list in reverse traversal order. 
void ReversePrint() {
	struct Node* temp = head;
	if(temp == NULL) return; // empty list, exit
	// Going to last Node
	while(temp->next != NULL) {
		temp = temp->next;
	}
	// Traversing backward using prev pointer
	printf("Reverse: ");
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

int main() {

	/*Driver code to test the implementation*/
	head = NULL; // empty list. set head as NULL. 
	
	// Calling an Insert and printing list both in forward as well as reverse direction. 
	InsertAtTail(2); Print(); ReversePrint();
	InsertAtTail(4); Print(); ReversePrint();
	InsertAtHead(6); Print(); ReversePrint();
	InsertAtTail(8); Print(); ReversePrint();
	
}

```
## Doubly Linked List Example 2
```c
#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *prev;
   struct node *next;
};

struct node *head = NULL;
struct node *last = NULL;

struct node *current = NULL;

//Create Linked List
void add(int data) {
   // Allocate memory for new node;
   struct node *link = (struct node*) malloc(sizeof(struct node));

   link->data = data;
   link->prev = NULL;
   link->next = NULL;

   // If head is empty, create new list
   if(head==NULL) {
      head = link;
      return;
   }

   current = head;
   
   // move to the end of the list
   while(current->next!=NULL)
      current = current->next;

   // Insert link at the end of the list
   current->next = link;
   last = link;
   link->prev = current;
}

//display the list
void display() {
   struct node *ptr = head;

   printf("\n[head] <=>");

   //start from the beginning
   while(ptr->next != NULL) {        
      printf(" %d <=>",ptr->data);
      ptr = ptr->next;
   }
   
   printf(" %d <=>",ptr->data);
   printf(" [head]\n");
}

int main() {
   add(1);
   add(2);
   add(3);
   add(10);
   add(20);
   add(30); 

   display();
   return 0;
}
```
Example # 3

```c
#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *prev;
   struct node *next;
};

struct node *head = NULL;
struct node *last = NULL;

struct node *current = NULL;

//Create Linked List
void add(int data) {
   // Allocate memory for new node;
   struct node *link = (struct node*) malloc(sizeof(struct node));

   link->data = data;
   link->prev = NULL;
   link->next = NULL;

   // If head is empty, create new list
   if(head==NULL) {
      head = link;
      return;
   }

   current = head;
   
   // move to the end of the list
   while(current->next!=NULL)
      current = current->next;

   // Insert link at the end of the list
   current->next = link;
   last = link;
   link->prev = current;
}

//display the list
void display() {
   struct node *ptr = head;

   printf("\n[head] <=>");

   //start from the beginning
   while(ptr->next != NULL) {        
      printf(" %d <=>",ptr->data);
      ptr = ptr->next;
   }
   
   printf(" %d <=>",ptr->data);
   printf(" [head]\n");
}

int main() {
   add(1);
   add(2);
   add(3);
   add(10);
   add(20);
   add(30); 

   display();
   return 0;
}
```
Example #4

```c
#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *prev;
   struct node *next;
};

struct node *head = NULL;
struct node *last = NULL;

struct node *current = NULL;

//display the list
void display() {
   struct node *ptr = head;

   printf("\n[head] <=>");
   //start from the beginning
   while(ptr != NULL) {        
      printf(" %d <=>",ptr->data);
      ptr = ptr->next;
   }

   printf(" [last]\n");
}

//display the list
void displayBackward() {
   struct node *ptr = last;

   printf("\n[head] <=>");
   //start from the beginning
   while(ptr != NULL) {        
      printf(" %d <=>",ptr->data);
      ptr = ptr->prev;
   }

   printf(" [last]\n");
}

//Create Linked List
void add(int data) {
   // Allocate memory for new node;
   struct node *link = (struct node*) malloc(sizeof(struct node));

   link->data = data;
   link->prev = NULL;
   link->next = NULL;

   // If head is empty, create new list
   if(head==NULL) {
      head = link;
      return;
   }

   current = head;
   
   // move to the end of the list
   while(current->next!=NULL)
      current = current->next;

   // Insert link at the end of the list
   current->next = link;
   last = link;
   link->prev = current;
}

int main() {
   add(1);
   add(2);
   add(3);
   add(4);
   add(5);
   add(6); 

   display();
   displayBackward();
   
   return 0;
}
```

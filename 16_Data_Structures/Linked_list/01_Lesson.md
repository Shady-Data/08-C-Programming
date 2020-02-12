
## Linked List

A linked list is a series of connected "nodes" that contains the "address" of the next node. 
Each node can store a data point which may be a number, a string or any other type of data.

## Starting and Ending
You have to start somewhere, so we give the address of the first node a special name called HEAD.

Also, the last node in the linkedlist can be identified because its next portion points to NULL.

### Node Structure

Some pointers are involved. Let's think about what each node contains:
```
A data item
An address of another node
```
We wrap both the data item and the next node reference in a struct as:
```c
struct node
{
  int data;
  struct node *next;
};
```
Understanding the structure of a linked list node is the key to having a grasp on it.

Simply put, here is an example of creating three nodes:

```c
/* Initialize nodes */
struct node *head;
struct node *one = NULL;
struct node *two = NULL;
struct node *three = NULL;

/* Allocate memory */
one = malloc(sizeof(struct node));
two = malloc(sizeof(struct node));
three = malloc(sizeof(struct node));

/* Assign data values */
one->data = 1;
two->data = 2;
three->data=3;

/* Connect nodes */
one->next = two;
two->next = three;
three->next = NULL;

/* Save address of first node in head */
head = one;
```
## Good uses of linked lists

The power of linkedlist comes from the ability to break the chain and rejoin it. E.g. if you wanted to put an element 4 between 1 and 2, the steps would be:
```
Create a new struct node and allocate memory to it.
Add its data value as 4
Point its next pointer to the struct node containing 2 as data value
Change next pointer of "1" to the node we just created.
```
Doing something similar in an array would have required shifting the positions of all the subsequent elements.

## Linked List Example
```c
#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

//display the list
void printList() {

   struct node *ptr = head;

   printf("\n[head] =>");
   //start from the beginning
   while(ptr != NULL) {        
      printf(" %d =>",ptr->data);
      ptr = ptr->next;
   }

   printf(" [null]\n");
}

//insert link at the first location
void insert(int data) {
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));

   //link->key = key;
   link->data = data;

   //point it to old first node
   link->next = head;

   //point first to new first node
   head = link;
}

int main() {
   insert(10);
   insert(20);
   insert(30);
   insert(1);
   insert(40);
   insert(56); 

   printList();
   return 0;
}
```
### Output:
```
[head] => 56 => 40 => 1 => 30 => 20 => 10 => [null]

```

## Other things you can do to a Linked List


### Traversing

Displaying the contents of a linked list is very simple. We keep moving the temp node to the next one and display its contents.

When temp is NULL, we know that we have reached the end of linked list so we get out of the while loop.
```c
struct node *temp = head;
printf("\n\nList elements are - \n");
while(temp != NULL)
{
     printf("%d --->",temp->data);
     temp = temp->next;
}
```
The output of this program will be:
```
List elements are - 
1 --->2 --->3 --->

```
## Adding to the Linked List

You can add elements to either beginning, middle or end of linked list.

### Add to the start
```
Allocate memory for new node
Store data
Change next of new node to point to head
Change head to point to recently created node
```
```c
struct node *newNode;
newNode = malloc(sizeof(struct node));
newNode->data = 4;
newNode->next = head;
head = newNode;
```
### Add to the end
```
Allocate memory for new node
Store data
Traverse to last node
Change next of last node to recently created node
```
```c
struct node *newNode;
newNode = malloc(sizeof(struct node));
newNode->data = 4;
newNode->next = NULL;
struct node *temp = head;
while(temp->next != NULL){
  temp = temp->next;
}
temp->next = newNode;
```
### Add somewhere in the middle
```
Allocate memory and store data for new node
Traverse to node just before the required position of new node
Change next pointers to include new node in between
```
```c
struct node *newNode;
newNode = malloc(sizeof(struct node));
newNode->data = 4;
struct node *temp = head;
for(int i=2; i < position; i++) {
    if(temp->next != NULL) {
        temp = temp->next;
    }
}
newNode->next = temp->next;
temp->next = newNode;
```

## Removing from the list

You can delete either from beginning, end or from a particular position.

### Delete from the start
```
Point head to the second node
```
```c
head = head->next;
```
### Delete from the end
```
Traverse to second last element
Change its next pointer to null
```
```c
struct node* temp = head;
while(temp->next->next!=NULL){
  temp = temp->next;
}
temp->next = NULL;
```
### Delete from somewhere in the middle
```
Traverse to element before the element to be deleted
Change next pointers to exclude the node from the chain
```
```c
for(int i=2; i< position; i++) {
    if(temp->next!=NULL) {
        temp = temp->next;
    }
}
temp->next = temp->next->next;
```
## Linked List example of these operations
```c
#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};
void display(struct node* head)
{
      struct node *temp = head;
      printf("\n\nList elements are - \n");
      while(temp != NULL)
      {
   printf("%d --->",temp->data);
   temp = temp->next;
      }
}
void insertAtMiddle(struct node *head, int position, int value) {
    struct node *temp = head;
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = value;
    
    int i;
    for(i=2; inext != NULL) {
        temp = temp->next;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void insertAtFront(struct node** headRef, int value) {
    struct node* head = *headRef;
    
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    
    *headRef = head;
}
void insertAtEnd(struct node* head, int value){
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    
    struct node *temp = head;
    while(temp->next != NULL){
      temp = temp->next;
    }
    temp->next = newNode;
}
void deleteFromFront(struct node** headRef){
    struct node* head =  *headRef;
    head = head->next;
    *headRef = head;
}
void deleteFromEnd(struct node* head){
    struct node* temp = head;
    while(temp->next->next!=NULL){
      temp = temp->next;
    }
    temp->next = NULL;
}
void deleteFromMiddle(struct node* head, int position){
    struct node* temp = head;
    int i;
    for(i=2; inext != NULL) {
    temp = temp->next;
    }
}
temp->next = temp->next->next;
}
int main() {
  /* Initialize nodes */
  struct node *head;
  struct node *one = NULL;
  struct node *two = NULL;
  struct node *three = NULL;
  /* Allocate memory */
  one = malloc(sizeof(struct node));
  two = malloc(sizeof(struct node));
  three = malloc(sizeof(struct node));
  /* Assign data values */
  one->data = 1;
  two->data = 2;
  three->data = 3;
  /* Connect nodes */
  one->next = two;
  two->next = three;
  three->next = NULL;
  /* Save address of first node in head */
  head = one;
  display(head); // 1 --->2 --->3 --->     
  insertAtFront(&head, 4);
  display(head); // 4 --->1 --->2 --->3 --->     
  deleteFromFront(&head);
  display(head); // 1 --->2 --->3 ---> 
  insertAtEnd(head, 5);
  display(head); // 1 --->2 --->3 --->5 --->   
  deleteFromEnd(head);
  display(head); // 1 --->2 --->3 --->       
  int position = 3;
  insertAtMiddle(head, position, 10);
  display(head); // 1 --->2 --->10 --->3 --->      
  deleteFromMiddle(head, position);
  display(head); // 1 --->2 --->3 --->     
}
```
### Expected Output:
```
List elements are -                                                                                                                                                       
1 --->2 --->3 --->     
   
List elements are -                                                                                                                                                       
4 --->1 --->2 --->3 --->                                                                                                                                                                              
List elements are -                                                                                                                                                       
1 --->2 --->3 --->                                                                                                                                                                                     
List elements are -                                                                                                                                                       
1 --->2 --->3 --->5 --->                                                                                                                                                                           
List elements are -                                                                                                                                                       
1 --->2 --->3 --->                                                                                                                                                                              
List elements are -                                                                                                                                                       
1 --->2 --->10 --->3 --->  

List elements are - 
1 --->2 --->3 ---> 
```























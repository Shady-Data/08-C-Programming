## Complete the Linked List program

```c

#include<stdio.h> 
#include<stdlib.h> 
  
/* Node Structure */
struct Node 
{ 
  int data; 
  struct Node *next; 
}; 
  
  //First Function
/* displays a linked list in reverse manner */
void Part1(struct Node* head) 
{ 
 
 
 
} 
  //Second Function
/* displays alternate nodes of a Linked List, first  
  from head to end, and then from end to head. */
void Part2(struct Node* start) 
{ 





} 
  
// Functions to run Part1() and Part2() 
/* Given a reference (pointer to pointer) to the head 
  of a list and an int, push a new node on the front 
  of the list. */
void push(struct Node** head_ref, int new_data) 
{ 
  // allocate node 
  struct Node* new_node = 
          (struct Node*) malloc(sizeof(struct Node)); 
   
  // put in the data  
  new_node->data  = new_data; 
   
  // link the old list off the new node 
  new_node->next = (*head_ref); 
   
  // move the head to point to the new node 
  (*head_ref)    = new_node; 
} 
   
// Driver program to test above functions 
int main() 
{ 
  // Begin with the empty list 
  struct Node* head = NULL; 
  
  /* Using push() to construct below list 
    1->2->3->4->5  */
  push(&head, 5); 
  push(&head, 4); 
  push(&head, 3); 
  push(&head, 2); 
  push(&head, 1);    
   
  printf("Show work of Part1() for list 1->2->3->4->5 \n"); 
  Part1(head); 
  
  printf("\nShow work of Part2() for list 1->2->3->4->5 \n");  
  Part2(head); 
          
  getchar(); 
  return 0; 
} 
```
## Expected Output
```
 Show work of Part1() for list 1->2->3->4->5 
5 4 3 2 1 
Show work Part2() for list 1->2->3->4->5 
1 3 5 5 3 1 
```


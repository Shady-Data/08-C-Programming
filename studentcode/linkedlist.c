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
  struct Node * work_ptr = head; // declare and initialize a working pointer to the head node pointer
  struct Node * stop_ptr = NULL; // declare and initialize a second pointer to a NULL pointer

  while (stop_ptr != head){ // while the second pointer is not the head pointer
    while (work_ptr->next != stop_ptr){ // while the current work node's next pointer is not the second pointer
      work_ptr = work_ptr->next; // set the work pointer to the node's next pointer
    } // end inner while loop
    printf("%d ", work_ptr->data); // print the working node's data
    stop_ptr = work_ptr; // set the second pointer to the current work pointer
    work_ptr = head; // reset the work pointer to the head pointer
  } // end outer while loop
} 
  //Second Function
/* displays alternate nodes of a Linked List, first  
  from head to end, and then from end to head. */
void Part2(struct Node* start) 
{ 
  struct Node * work_ptr = start; // declare and initialize a working pointer to the head/start node pointer

  while (work_ptr != NULL){ // while the work_ptr != NULL
    printf("%d ", work_ptr->data); // print the current work node's data
    if (work_ptr->next == NULL){ // if the current work node's next pointer is a NULL pointer
      work_ptr = work_ptr->next; // set the the work pointer to the current node's next pointer
    } // end if codeblock
    else { // if the next node pointer is NOT a NULL pointer
      work_ptr = work_ptr->next; // set the work pointer to the current node's next pointer
      work_ptr = work_ptr->next; // set the work pointer to the current node's next pointer again (skips 1 node)
    } // end else codeblock
  } // end while loop for print data every other node starting with the start node
  work_ptr = start; // reset the work pointer to the head/start pointer
  struct Node * stop_ptr = NULL; // declare and initialize a second pointer to a NULL pointer (tracks stop point)
  struct Node * temp_ptr = NULL; // declare and initialize a third pointer to a NULL pointer (stores temporary node pointers)

  while (stop_ptr != start){ // while the stop pointer is not equal to head/start node pointer
    while (work_ptr->next != stop_ptr){ // while the current work node's next pointer is not equal to the stop pointer 
      work_ptr = work_ptr->next; // set the work pointer to the current node's next pointer
      if (temp_ptr == stop_ptr){ // if the temp pointer is equal to the stop pointer
        temp_ptr = start; // set the temp pointer to the head/start node's pointer
      } // end if codeblock
      else { // otherwise
        temp_ptr = work_ptr; // set the temp pointer to the current work node (the skipped node)
      } // end else codeblock for if/else temp_ptr codeblocks
      if (work_ptr->next != NULL){ // if the current node's next node pointer is not a NULL pointer
        work_ptr = work_ptr->next; // set the work pointer to the current node's next pointer
      } // end if codeblock for node next NULL pointer
    } // end inner while loop 
    printf("%d ", work_ptr->data); // print the current work node's data
    stop_ptr = temp_ptr; // set the stop_ptr to the temp (skipped) pointer
    work_ptr = start; // reset the work pointer to the head/start node pointer
  } // end outer while loop
  printf("%d\n", start->data); // print the start node's data value
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
/*
```
## Expected Output
```
 Show work of Part1() for list 1->2->3->4->5 
5 4 3 2 1 
Show work Part2() for list 1->2->3->4->5 
1 3 5 5 3 1 
```
Show work of Part1() for list 1->2->3->4->5 
5 4 3 2 1 
Show work of Part2() for list 1->2->3->4->5 
1 3 5 5 3 1

*/

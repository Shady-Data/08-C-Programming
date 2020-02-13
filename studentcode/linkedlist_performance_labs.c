/*
# Performance Labs

## 1. (Creating a Linked List, Then Reversing Its Elements) Write a program that creates a linked list of 10 characters,
then creates a copy of the list in reverse order.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct SingleLinkNode{
   char data;
   struct SingleLinkNode * next;
} snode;

void push(snode** head_ptr, char data) 
{ 
  // allocate node 
  snode* new_node = (snode*) malloc(sizeof(snode)); 
   
  // put in the data  
  new_node->data  = data; 
   
  // link the old list off the new node 
  new_node->next = (*head_ptr); 
   
  // move the head to point to the new node 
  (*head_ptr) = new_node; 
} 

void append(snode** head_ptr, char data)
{
   // allocate node 
   snode* new_node = (snode*) malloc(sizeof(snode)); 
   
   // put in the data  
   new_node->data  = data; 
   
   // set the new_node next pointer to NULL 
   new_node->next = NULL; 
   
   // declare and initialize a pointer to travers to the end of the list
   snode * traverse_ptr = (*head_ptr);
   // while the traversing pointer's current node's next pointer is not NULL (last node in the list)
   while (traverse_ptr->next != NULL){
      // set the traversing pointer to the current nodes next pointer
      traverse_ptr = traverse_ptr->next;
   }
   // set the last node's next pointer to the new node's pointer
   traverse_ptr->next = new_node;
}

snode * reverse_copy(snode ** head_ptr)
{
   snode * work_ptr = (*head_ptr); // declare and initialize a work pointer the head pointer
   snode * copy_head = NULL; // declare a head pointer to the head of the copied list

   while (work_ptr != NULL){ // while the work pointer is not a NULL pointer (empty)
      push(&copy_head, work_ptr->data); // push a node containing the current work node's data to the list copy (Push adds nodes to the fron of a list)
      work_ptr = work_ptr->next; // set the work pointer to the current node's next pointer
   } // end while loop

   return copy_head; // return the pointer to the head of th copy
}

void clean_list(snode ** head_ptr){
   snode * work_ptr = (*head_ptr);
   snode * stop_ptr = NULL;

   while (stop_ptr != (*head_ptr)){ // while the second pointer is not the head pointer
    while (work_ptr->next != NULL){ // while the current work node's next pointer is not a NULL
      work_ptr = work_ptr->next; // set the work pointer to the node's next pointer
    } // end inner while loop
    stop_ptr = work_ptr; // set the second pointer to the current work pointer
    free(work_ptr); // free the memory allocation of the current node
    work_ptr = (*head_ptr); // reset the work pointer to the head pointer
  } // end outer while loop
}

/*
## 2. (using the program you previously created) check if a word is a palindrome. 
*/

int isPalindrome(snode ** head_ptr)
{
   snode * reversed_list = reverse_copy(head_ptr);
   snode * forward_ptr = (*head_ptr);
   snode * reverse_ptr = reversed_list;

   while ((forward_ptr != NULL) && (reverse_ptr != NULL)){
      if (forward_ptr->data != reverse_ptr->data){
         clean_list(&reversed_list);
         return 0;
      }
      forward_ptr = forward_ptr->next;
      reverse_ptr = reverse_ptr->next;
   }
   clean_list(&reversed_list);
   return 1;
}

/*
## 3. Create an investment list.
```
Investment Portfolio
Symbol   Shares   Price    Value
GOOG     1000     1801.19  1801189.94
APPLE    1000     1128.77  1128770.02

```
*/

/*
## 4. Write a linked-list that creates a queue process for checking-in. 
   Example output: 
   
```
1: ADD
2: REMOVE
3: DISPLAY BOARD
0: QUIT

Enter your choice: 1
Name: Cyber

1: ADD
2: REMOVE
3: DISPLAY BOARD
0: QUIT

Enter your choice: 1
Name: Warrior

1: ADD
2: REMOVE
3: DISPLAY BOARD
0: QUIT

Enter your choice: 3
BOARD:
1. Cyber
2. Warrior

1: ADD
2: REMOVE
3: DISPLAY BOARD
0: QUIT

Enter your choice: 0

root@VM:~#

```
*/

/*
## 5. Write a program to create a doubly linked list and perform insertions and deletions in all
cases
*/

typedef struct DoubleLinkedNode{
   char data;
   struct DoubleLinkedNode * next;
   struct DoubleLinkedNode * prev;
} dnode;

void dlist_push(dnode ** head_ptr, char data)
{
   dnode * new_node = malloc(sizeof(new_node));

   new_node->data = data;
   new_node->prev = NULL;
   new_node->next = (*head_ptr);
   (*head_ptr) = new_node;
}

void dlist_append(dnode ** head_ptr, dnode ** tail_ptr, char data)
{
   dnode * new_node = malloc(sizeof(new_node));

   new_node->data = data;
   new_node->next = NULL;

   if (tail_ptr == NULL){
      dnode * traverse_ptr = (*head_ptr);
      while (traverse_ptr->next != NULL){
         traverse_ptr = traverse_ptr->next;
      }
      new_node->prev = traverse_ptr;
      traverse_ptr->next = new_node;
      (*tail_ptr) = new_node;
   }
   else {
      new_node->prev = (*tail_ptr);
      (*tail_ptr) = new_node;
   }
}

void dlist_insert(dnode ** head_ptr, dnode ** tail_ptr, int index, char data)
{
   if (index == 0){
      dlist_push(head_ptr, data);
   }
   else if (index == -1){
      dlist_append(head_ptr, tail_ptr, data);
   }
   dnode * newnode = malloc(sizeof(dnode));
   newnode->data = data;
   dnode * work_ptr;
   if ((index < -1) && (tail_ptr != NULL)){
      work_ptr = (*tail_ptr);
      for (int i = index; i < 0; i++){
         if (work_ptr->prev != NULL){
            work_ptr = work_ptr->prev;
         }
      }
      newnode->prev = work_ptr->prev;
      newnode->next = work_ptr;
      work_ptr->prev = newnode;
      if (work_ptr == (*head_ptr)){
         (*head_ptr) = newnode;
      }
   } 
   else if ((index < -1) && (tail_ptr == NULL)){
      int node_count = 0;
      work_ptr = (*head_ptr);
      while (work_ptr != NULL){
         work_ptr = work_ptr->next;
         node_count++;
      }
      work_ptr = (*head_ptr);
      for (int i = (node_count + index); i > 0; i--){
         work_ptr = work_ptr->next;
      }
      newnode->prev = work_ptr->prev;
      newnode->next = work_ptr;
      work_ptr->prev = newnode;
   }
   else{
      work_ptr = (*head_ptr);
      for (int i = index; i > 0; i--){
         if (work_ptr->next != NULL){
            work_ptr = work_ptr->next;
         }
      }
      newnode->prev = work_ptr->prev;
      newnode->next = work_ptr;
      work_ptr->prev = newnode;
   }
}

/*
6. Problem Write a program to sort the names stored in a list into alphabetical order. Print the unsorted and sorted names.
Method (Requirements)

Input the names into a list.

Display the unsorted names.

Sort the names in alphabetical order.

Display the sorted names

Create a file with the sorted names.
Data ( at least)

get at least 11 names.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLENGTH 64

typedef struct NameNode{
   char data[MAXLENGTH];
   int sortval;
   struct NameNode * next;
   struct NameNode * prev;
} name;

void name_push(name ** head_ptr, name ** tail_ptr, char * data)
{
   name * newnode = malloc(sizeof(name));
   strncpy(newnode->data, data, MAXLENGTH);
   newnode->sortval = *data;
   newnode->prev = NULL;
   newnode->next = (*head_ptr);
   (*head_ptr) = newnode;
   if (tail_ptr == NULL){
      (*tail_ptr) = newnode->next;
   }
}

void print_names_list(name ** head_ptr)
{
   name * work_ptr = (*head_ptr);
   puts("\tNames Listing:\n");
   while (work_ptr->next != NULL){
      puts(work_ptr->data);
      work_ptr = work_ptr->next;
   }
}

void sort_names_list(name ** head_ptr, name ** tail_ptr)
{
   name * sorted_ptr = (*head_ptr);
   name * curr_ptr = (*head_ptr);
   name * search_ptr = (*head_ptr);
   name * unsorted_ptr = NULL;
   name * prevnode_ptr = NULL;
   name * nextnode_ptr = NULL;
   search_ptr = search_ptr->next;

   while (curr_ptr->next != NULL){
      if (sorted_ptr->sortval < curr_ptr->sortval){
         sorted_ptr = curr_ptr;
      }
      curr_ptr = curr_ptr->next;
   }
   
   sorted_ptr->next = (*head_ptr);
   sorted_ptr->prev = NULL;
   (*head_ptr)->prev = sorted_ptr;
   (*head_ptr) = sorted_ptr;

   nextnode_ptr = curr_ptr->next;
   prevnode_ptr = curr_ptr->prev;

   while (sorted_ptr->next != NULL){
      curr_ptr = sorted_ptr->next;
      search_ptr = curr_ptr->next;
      while (search_ptr->next != NULL){
         if (search_ptr->sortval < curr_ptr->sortval){
            curr_ptr = search_ptr;
         }
         else if (search_ptr->sortval == curr_ptr->sortval){
            if (strncmp(search_ptr->data, curr_ptr->data, MAXLENGTH) < 0){
               curr_ptr = search_ptr;
            }
         }
         search_ptr = search_ptr->next;
      }
      unsorted_ptr = sorted_ptr->next;
      nextnode_ptr = curr_ptr->next;
      prevnode_ptr = curr_ptr->prev;
      prevnode_ptr->next = nextnode_ptr;
      nextnode_ptr->prev = prevnode_ptr;
      sorted_ptr->next = curr_ptr;
      curr_ptr->prev = sorted_ptr;
      sorted_ptr = curr_ptr;
      sorted_ptr->next = unsorted_ptr;
   }
   (*tail_ptr) = sorted_ptr;
}

int save_list(name ** head_ptr, char * filepath)
{
   FILE * outfile = fopen(filepath, "w");
   if (outfile == NULL){
      puts("\tFILE NOT SAVED\nError, file pointer failed to open. Returning");
      return -1;
   }
   name * work_ptr = (*head_ptr);
   fprintf(outfile, "\tNames Listing:\n");
   while (work_ptr != NULL){
      fprintf(outfile, "%s\n", work_ptr->data);
      work_ptr = work_ptr->next;
   }

   return 0;
}

int main(void)
{
   name * head = NULL;
   name * tail = NULL;
   int i = 0;
   char * names[] = {"John Doe", "Joe Smith", "Alice Numb", "Fred Flintstone", "Barney Rubble", "George Jeston",
                     "GlaDOS", "Wheatley", "Morganna", "Wednesday Adams", "Pugsley Adams", "NoName"};
   for (char ** n = names; i < 12; n++, i++){
      // printf("%s\n", *n);
      name_push(&head, &tail, *n);
   }
   print_names_list(&head);
   sort_names_list(&head, &tail);
   print_names_list(&head);
}
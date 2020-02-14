#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

typedef struct list
{
    node *head;
    node *tail;
} list;

void print_list(list *list_ptr)
{
    // Traverses the entire list and prints out the data of each node
    node * curr_ptr = list_ptr->head; // declare and initialize a node pointer to the list head pointer
    while (curr_ptr != NULL) // while the pointer is not NULL
    {
        printf("%d -> ", curr_ptr->data); // print the current node's data
        curr_ptr = curr_ptr->next; // set the current pointer to the next pointer value
    }
    printf("\n"); // print a newline at the end for readability
}

void push(int data, list *list_ptr)
{
    // Adds a node to the beginning of a list
    node * newnode = (node*) malloc(sizeof(node)); // allocate memory for a for node
    
    newnode->data = data; // set the node's data value to contain the passed data
    newnode->next = list_ptr->head; // set the node's next pointer to the current list head pointer
    newnode->prev = NULL; // set the node's prev pointer to NULL
    if (list_ptr->tail == NULL){ // if the list's tail pointer is unset/NULL
        list_ptr->tail = newnode; // set the tail to to the new node
    }
    else { // otherwise
        list_ptr->head->prev = newnode; // set the head pointer's prev pointer to the newnode
    }
    list_ptr->head = newnode; // set the headpointer to be the newnode
}

void append(int data, list *list_ptr)
{
    // Adds a node to the end of the list
    if (list_ptr->head == NULL){ // if the head pointer is unset/NULL
        push(data, list_ptr); // call the push function with the data and list
    }
    else{
        node * newnode = (node*) malloc(sizeof(node)); // allocate memory for a newnode
        newnode->data = data; // set the node's data value to contain the passed data
        newnode->next = NULL; // set the node's next pointer to NULL
        list_ptr->tail->next = newnode; // set the current tail node's next pointer to the new node
        newnode->prev = list_ptr->tail; // set the new node's prev pointer to the current list tail pointer
        list_ptr->tail = newnode; // set the list's tail pointer to the new node
    }
}

int search(int key, list *list_ptr)
{
    // Searches the list for the given key and returns the index or -1 if not found
    node * curr_ptr = list_ptr->head; // declare and initialize a pointer to the list's head pointer
    int index = 0; // declare and initialize a counter
    while (curr_ptr != NULL && curr_ptr->data != key){ // while the current pointer is not null and the node's data is not equal to the key
        curr_ptr = curr_ptr->next; // set the current pointer to the node's next pointer
        index++; // increment the index counter
    }
    if (curr_ptr != NULL){ // if the current pointer is not a NULL pointer
        return index; // the key was found, return the index counter of the node containing the key data
    }
    return -1; // return -1 if the function completed without a previous return
}

void remove_at(int index, list *list_ptr)
{
    // Removes the node found at the given position
    if (index <= 0 || list_ptr->head->next == NULL){ // if the index passed in is less than or equal to 0 , or the list's head node next pointer is NULL (1 item in the list)
        list_ptr->head = list_ptr->head->next; // set the head pointer to the head node next pointer
        if (list_ptr->head == NULL){ // if the list's head pointer is NULL
            list_ptr->tail = NULL; // set the list's tail pointer to be NULL
        } // end inner if code block
        else{ // otherwise
            list_ptr->head->prev = NULL; // list's head node prev pointer to NULL
        } // end inner if/else codeblock
    }
    else{ // if the outer if code block conditions where not met (i.e. index > 0 and list's head next pointer is not NULL)
        node * curr_ptr = list_ptr->head; // declare and initialize a pointer to the list's head pointer
        while (index > 1 && curr_ptr->next->next != NULL){ // while the index is greater than 1 and the current node's next node's next pointer is not a NULL pointer
            curr_ptr = curr_ptr->next; // set the current pointer to the current node's next pointer
            index--; // decrement the index
        }
        if (curr_ptr->next == list_ptr->tail){ // if the current node's next pointer is the tail
            list_ptr->tail = curr_ptr; // set the list's tail pointer to the current node
        }
        else{ // otherwise
            curr_ptr->next->next->prev = curr_ptr; // set the current node's next node's, next node's, prev pointer to be the current pointer
        }
        curr_ptr->next = curr_ptr->next->next; // set the current node's next pointer to the next node's next pointer (removes next node from the list)
    }
}

int pop(list *list_ptr)
{
    // Removes the last item in the list and returns its value
    int removed_item = list_ptr->tail->data; // declare and initialize a variable with the list's tail node's data
    list_ptr->tail = list_ptr->tail->prev; // set the list's tail node to be the current tail's prev pointer
    if (list_ptr->tail == NULL) // if the list's tail is a NULL pointer
    {
        list_ptr->head = list_ptr->tail; // 
    }
    else
    {
        list_ptr->tail->next = NULL;
    }
    return removed_item;
}

int list_length(list *list_ptr)
{
    // Returns the number of items in the list
    node *curr = list_ptr->head;
    int count = 0;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    return count;
}

void anagram(list *list1_ptr, list *list2_ptr)
{
    // takes a linked list item and checks if they are anagrams of each other
    // prints the result to the terminal
    if (list_length(list1_ptr) != list_length(list2_ptr))
    {
        printf("Not an anagram");
        return;
    }
    else
    {
        while (list_length(list1_ptr) != 0)
        {
            int index = search(pop(list1_ptr), list2_ptr);
            if (index == -1)
            {
                printf("Not an anagram");
                return;
            }
            else
            {
                remove_at(index, list2_ptr);
            }
        }
        printf("That is an anagram");
    }
}

int main(void)
{
    // set up the lists
    list list_ptr = {NULL, NULL};
    list list2_ptr = {NULL, NULL};
    // get user input
    printf("Enter the first word\n");
    char c = getchar();
    while (c != '\n')
    {
        append(c, &list_ptr);
        c = getchar();
    }
    printf("Enter the second word\n");
    c = getchar();
    while (c != '\n')
    {
        append(c, &list2_ptr);
        c = getchar();
    }
    // check if they are anagrams
    anagram(&list_ptr, &list2_ptr);
    return 0;
}
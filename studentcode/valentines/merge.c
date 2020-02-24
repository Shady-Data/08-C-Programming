#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char data[256];
    struct node *next;
    struct node *prev;
} node;

typedef struct list
{
    node *head;
    node *tail;
} list;

void printList(list *list1)
{
    // Traverses the entire list and prints out the data of each node
    node *ptr = list1->head;
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf(" End\n");
}

void prepend(char* data, list *list1)
{
    // Adds a node to the beginning of the list
    node *link = (node*) malloc(sizeof(node));
    
    strcpy(link->data, data);
    link->next = list1->head;
    link->prev = NULL;
    if (list1->tail == NULL)
    {
        (*list1).tail = link;
    }
    else
    {
        (*list1).head->prev = link;
    }
    (*list1).head = link;
}

void append(char* data, list *list1)
{
    // Adds a node to the end of the list
    if (list1->head == NULL)
    {
        prepend(data, list1);
    }
    else
    {
        node *link = (node*) malloc(sizeof(node));
        strcpy(link->data, data);
        link->next = NULL;
        (*list1).tail->next = link;
        link->prev = list1->tail;
        (*list1).tail = link;
    }
}

int find(char* key, list *list1)
{
    // Searches the list for the given key and returns the index or -1 if not found
    node *curr = list1->head;
    int index = 0;
    while (curr != NULL && strcmp(curr->data, key) != 0)
    {
        curr = curr->next;
        index++;
    }
    if (curr != NULL)
    {
        return index;
    }
    return -1;
}

void remove_item(char* key, list *list1)
{
    // Traverses the list and removes the first found instance of the given key
    if (list1->head->data == key)
    {
        (*list1).head = list1->head->next;
        if (list1->head == NULL)
        {
            (*list1).tail = NULL;
        }
        else
        {
            (*list1).head->prev = NULL;
        }
    }
    else
    {
        node *curr = list1->head;
        node *prev = NULL;
        while (curr != NULL && strcmp(curr->data, key) != 0)
        {
            prev = curr;
            curr = curr->next;
        }
        if (curr != NULL)
        {
            prev->next = curr->next;
            if (curr == list1->tail)
            {
                (*list1).tail = prev;
            }
            else
            {
                prev->next->prev = prev;
            }
        }
        else
        {
            printf("Did not find an element with data %d\n", key);
        }
    }
}

void swap(node* first, node* second)
{
    // swaps the values in the specified nodes
    char temp[256];
    strcpy(temp, first->data);
    strcpy(first->data, second->data);
    strcpy(second->data, temp);
}

int isBigger(char* first, char* second)
{
    // recursive function to check which string is bigger
    // should have just used strcmp now that i know it isn't just true/false
    if (*first > *second)
    {
        return 1;
    }
    else if (*first < *second)
    {
        return 0;
    }
    else
    {
        if (*(first+1) == 0)
        {
            return 1;
        }
        else if (*(second+1) == 0)
        {
            return 0;
        }
        else
        {
            return isBigger(first+1, second+1);
        }
    }
}

void sort(list *list1)
{
    // bubble sorts the items in the given linked list
    node* i = list1->head;
    while (i->next != NULL)
    {
        node* j = list1->head;
        while (j->next != NULL)
        {
            if (isBigger(j->data, j->next->data))
            {
                swap(j, j->next);
            }
            j = j->next;
        }
        i = i->next;
    }
}

int count(char* key, list *list1)
{
    // Traverses the list and returns a count of the nodes with the given data
    node *curr = list1->head;
    int count = 0;
    while (curr != NULL)
    {
        if (strcmp(curr->data, key) == 0)
        {
            count++;
        }
        curr = curr->next;
    }
    return count;
}

void merge(list *list1, list *list2)
{
    // merges the two lists together, removing all duplicates, then calls the sort function before finally writing the results to a file
    list merged = {NULL, NULL};
    node *curr = list1->head;
    while (curr != NULL)
    {
        if (count(curr->data, list1) > 1)
        {
            node *temp = curr->next;
            remove_item(curr->data, list1);
            curr = temp;
        }
        else
        {
            while (find(curr->data, list2) > -1)
            {
                remove_item(curr->data, list2);
            }
            append(curr->data, &merged);
            curr = curr->next;
        }
    }
    curr = list2->head;
    while (curr != NULL)
    {
        if (count(curr->data, list2) > 1)
        {
            node *temp = curr->next;
            remove_item(curr->data, list2);
            curr = temp;
        }
        else
        {
            while (find(curr->data, list1) > -1)
            {
                remove_item(curr->data, list1);
            }
            append(curr->data, &merged);
            curr = curr->next;
        }
    }
    sort(&merged);
    FILE * file_ptr3 = fopen("names3.txt", "w");
    if (file_ptr3 == NULL)
    {
        printf("Couldn't open at least one file");
        return;
    }
    curr = merged.head;
    while (curr != NULL)
    {
        fputs(curr->data, file_ptr3);
        curr = curr->next;
    }
    fclose(file_ptr3);
}

int main(void)
{
    // set up the lists
    list list1 = {NULL, NULL};
    list list2 = {NULL, NULL};
    // open the files
    FILE * file_ptr1 = fopen("names1.txt", "r");
    FILE * file_ptr2 = fopen("names2.txt", "r");
    // check for errors
    if (file_ptr1 == NULL || file_ptr2 == NULL)
    {
        printf("Couldn't open at least one file");
        return -1;
    }
    // pull the data from each file, putting them into the lists, then close the files
    char c[256] = {0};
    char * temp = c;
    temp = fgets(c, 256, file_ptr1);
    while (temp != NULL)
    {
        append(temp, &list1);
        temp = fgets(c, 256, file_ptr1);
    }
    fclose(file_ptr1);
    c[0] = 0;
    temp = fgets(c, 256, file_ptr2);
    while (temp != NULL)
    {
        append(temp, &list2);
        temp = fgets(c, 256, file_ptr2);
    }
    fclose(file_ptr2);
    // merge the lists together
    merge(&list1, &list2);
    return 0;
}
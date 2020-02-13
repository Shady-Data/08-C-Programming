/* This file contains useful function declarations for myself */

// #include "myhead.c"

extern void print_binary(int num);
extern void clear_input();

#ifdef SingleLinkedList
typedef struct SingleLinkedNode{
    int data;
    struct SingleLinkedNode * next;
} node;

#endif

#ifdef DoubleLinkedList
typedef struct DoubleLinkedNode{
    int data;
    struct DoubleLinkedNode * next;
    struct DoubleLinkedNode * prev;
} d_link_node;
#endif
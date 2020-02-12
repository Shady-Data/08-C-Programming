
# QUEUE

A Queue is a linear data structure that stores a collection of elements. The queue operates on first in first out (FIFO) algorithm.

In programming terms, putting an item in the queue is called an "enqueue" and removing an item from the queue is called "dequeue".

## Queue functions:
A queue is an object or more specifically an abstract data structure(ADT) that allows the following operations:
```
Enqueue: Add element to end of queue
Dequeue: Remove element from front of queue
IsEmpty: Check if queue is empty
IsFull: Check if queue is full
Peek: Get the value of the front of queue without removing it
```

#### The mechanics of a Queue
A Queue work as:
```
Two pointers called FRONT and REAR are used to keep track of the first and last elements in the queue.
When initializing the queue, we set the value of FRONT and REAR to -1.
On enqueing an element, we increase the value of REAR index and place the new element in the position pointed to by REAR.
On dequeueing an element, we return the value pointed to by FRONT and increase the FRONT index.
Before enqueing, we check if queue is already full.
Before dequeuing, we check if queue is already empty.
When enqueing the first element, we set the value of FRONT to 0.
When dequeing the last element, we reset the values of FRONT and REAR to -1.
```

## QUEUE EXAMPLE PROGRAM

```c
#include<stdio.h>
#define SIZE 5
void enQueue(int);
void deQueue();
void display();
int items[SIZE], front = -1, rear = -1;
int main()
{
    //deQueue is not possible on empty queue
    deQueue();
    
    //enQueue 5 elements
    enQueue(1);
    enQueue(2);
    enQueue(3);
    enQueue(4);
    enQueue(5);
    
    //6th element can't be added to queue because queue is full
    enQueue(6);
    
    display();
    
    //deQueue removes element entered first i.e. 1
    deQueue();
    
    //Now we have just 4 elements
    display();
    
    return 0;
    
}
void enQueue(int value){
    if(rear == SIZE-1)
        printf("\nQueue is Full!!");
    else {
        if(front == -1)
            front = 0;
        rear++;
        items[rear] = value;
        printf("\nInserted -> %d", value);
    }
}
void deQueue(){
    if(front == -1)
        printf("\nQueue is Empty!!");
    else{
        printf("\nDeleted : %d", items[front]);
        front++;
        if(front > rear)
            front = rear = -1;
    }
}
void display(){
    if(rear == -1)
        printf("\nQueue is Empty!!!");
    else{
        int i;
        printf("\nQueue elements are:\n");
        for(i=front; i<=rear; i++)
            printf("%d\t",items[i]);
    }
}
```
### OUTPUT:

```
Queue is Empty!!
Inserted -> 1
Inserted -> 2
Inserted -> 3
Inserted -> 4
Inserted -> 5
Queue is Full!!
Queue elements are:
1    2    3    4    5    
Deleted : 1
Queue elements are:
2    3    4    5
```

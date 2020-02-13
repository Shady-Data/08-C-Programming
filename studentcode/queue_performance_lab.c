/*
# Performance Labs 

## Write a program to implement a queue using an array

## Write a program that implements a Queue as shown below:
```
--Enqueue elements--
Enter a number to enqueue:1
1
Enter a number to enqueue:2
2 1
Enter a number to enqueue:3
3 2 1
Enter a number to enqueue:4
4 3 2 1
Enter a number to enqueue:5
5 4 3 2 1
Queue is full
 
--Dequeue elements --
dequeue element 1
5 4 3 2
dequeue element 2
5 4 3
dequeue element 3
5 4
dequeue element 4
5
dequeue element 5
 
Queue is empty
```
*/

#include<stdio.h>
#define SIZE 5 // defined size of the queue

struct Queue{
    int items[SIZE];
    int front;
    int rear;
};

void enQueue(struct Queue *queue, int value){
    // add a value into the queue
    if(queue->rear == SIZE-1) // if the queue rear is equal to size - 1
        printf("Queue is Full!!\n"); // the queue is full
    else { // otherwise
        if(queue->front == -1) // if the front is -1, the queue is empty
            queue->front = 0; // set the front to 0 to show that the queue is no longer empty
        queue->rear++; // increment the rear to the next element
        queue->items[queue->rear] = value; // add the value to the rear of the queue 
        // printf("\nInserted -> %d", value);
    }
}

int deQueue(struct Queue *queue){
    // removes the first element in the queue
    if(queue->front == -1) // if the front is -1
        printf("Queue is Empty!!\n"); // display that the queue is empty
    else{ // otherwise
        int removed_value = queue->items[queue->front]; // store the front item in a variable to be returned
        for (int i = queue->front; i < queue->rear; i++){ // for each element in the queue up to the rear index value
            queue->items[i] = queue->items[i + 1]; // set the current ith item to the value of the next item in the queue (i + 1)
        } // end for loop
        queue->rear--; // decrement the rear index value by 1
        if (queue->rear < queue->front){ //if the rear value, after decrementing is less then the front index value (-1)
            queue->front = queue->rear = -1; // set the front and rear to -1 to show that the queue is empty
        }
        return removed_value; // return the value removed from the queue
    }
}

void display(struct Queue *queue){
    // displays all of the remaining elements in the queue
    if(queue->rear == -1) // if the rear is -1
        printf("\nQueue is Empty!!!"); // display that the queue is empty
    else{ // otherwise
        printf("\nQueue elements are:\n"); // display a queue header if desired
        for(int i=queue->front; i<=queue->rear; i++) // for each index starting from the front until greater than the rear index(while less than or equal to) incementing i for each loop iteration
            printf("%d\t",queue->items[i]); // display the ith value of the queue
    }
    printf("\n");
}


int main()
{
    struct Queue my_queue;
    my_queue.front = -1;
    my_queue.rear = -1;

    //deQueue is not possible on empty queue
    deQueue(&my_queue);
    
    //enQueue 5 elements
    enQueue(&my_queue, 1);
    enQueue(&my_queue, 2);
    enQueue(&my_queue, 3);
    enQueue(&my_queue, 4);
    enQueue(&my_queue, 5);
    
    //6th element can't be added to queue because queue is full
    enQueue(&my_queue, 6);
    
    display(&my_queue);
    
    //deQueue removes element entered first i.e. 1
    printf("removed %d from the queue", deQueue(&my_queue));
    
    //Now we have just 4 elements
    display(&my_queue);
    
    return 0;
    
}


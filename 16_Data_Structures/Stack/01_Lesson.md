
## Stack 
A stack is a useful data structure in programming. It is just like a pile of plates kept on top of each other.

Think about the things you can do with such a pile of plates

Put a new plate on top
Remove the top plate

If you want the plate at the bottom, you have to first remove all the plates on top. 
Such kind of arrangement is called **Last In First Out** - the last item that was placed is the first item to go out.



## Stack Specification
A stack is an object or more specifically an abstract data structure(ADT) that allows the following operations:

Push: Add element to top of stack
Pop: Remove element from top of stack
IsEmpty: Check if stack is empty
IsFull: Check if stack is full
Peek: Get the value of the top element without removing it

## How stack works
The operations work as follows:

A pointer called TOP is used to keep track of the top element in the stack.
When initializing the stack, we set its value to -1 so that we can check if the stack is empty by comparing TOP == -1.
On pushing an element, we increase the value of TOP and place the new element in the position pointed to by TOP.
On popping an element, we return the element pointed to by TOP and reduce its value.
Before pushing, we check if stack is already full
Before popping, we check if stack is already empty

## Use of stack
Although stack is a simple data structure to implement, it is very powerful. The most common uses of a stack are:

**To reverse a word** - Put all the letters in a stack and pop them out. Because of LIFO order of stack, you will get the letters in reverse order.

**In compilers**- Compilers use stack to calculate the value of expressions like 2+4/5*(7-9) by converting the expression to prefix or postfix form.

**In browsers** - The back button in a browser saves all the urls you have visited previously in a stack. Each time you visit a new page, it is added on top of the stack. When you press the back button, the current URL is removed from the stack and the previous url is accessed.

peek() − get the top data element of the stack, without removing it.

isFull() − check if stack is full.

isEmpty() − check if stack is empty.


### peek()
Algorithm of peek() function
```
begin procedure peek
   return stack[top]
end procedure
```
### peek() function 
```c
int peek() {
   return stack[top];
}

```
### isfull()
Algorithm of isfull() function
```
begin procedure isfull

   if top equals to MAXSIZE
      return true
   else
      return false
   endif
   
end procedure
```
### Implementation of isfull() function 

```c
bool isfull() {
   if(top == MAXSIZE)
      return true;
   else
      return false;
}
```
### isempty()
Algorithm of isempty() function
```
begin procedure isempty

   if top less than 1
      return true
   else
      return false
   endif
   
end procedure
```
```
bool isempty() {
   if(top == -1)
      return true;
   else
      return false;
}
```

```c
#include <stdio.h>

int MAXSIZE = 8;       
int stack[8];     
int top = -1;            

int isempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}
   
int isfull() {

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

int peek() {
   return stack[top];
}

int pop() {
   int data;
	
   if(!isempty()) {
      data = stack[top];
      top = top - 1;   
      return data;
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

int push(int data) {

   if(!isfull()) {
      top = top + 1;   
      stack[top] = data;
   } else {
      printf("Could not insert data, Stack is full.\n");
   }
}

int main() {
   // push items on to the stack 
   push(3);
   push(5);
   push(9);
   push(1);
   push(12);
   push(15);

   printf("Element at top of the stack: %d\n" ,peek());
   printf("Elements: \n");

   // print stack data 
   while(!isempty()) {
      int data = pop();
      printf("%d\n",data);
   }

   printf("Stack full: %s\n" , isfull()?"true":"false");
   printf("Stack empty: %s\n" , isempty()?"true":"false");
   
   return 0;
}
```
Example Output:

```
Element at top of the stack: 15
Elements:
15
12
1 
9 
5 
3 
Stack full: false
Stack empty: true
```

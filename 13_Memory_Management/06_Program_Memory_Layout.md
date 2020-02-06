# Program Memory Layout

When a program runs, it needs memory space to store data.
For a typical C program, its memory is divided into five segments, each with its own purpose.
Figure below depicts the five segments in a process’s memory layout.

![image](https://user-images.githubusercontent.com/47218880/73849189-20b96c00-47ef-11ea-9ab7-476565a5f2bf.png)



## Text segment:
stores the executable code of the program. This block of memory is usually
read-only.

## Data segment:
stores static/global variables that are initialized by the programmer. For
example, the variable a defined in static int a = 3 will be stored in the Data
segment.

## BSS segment:
stores uninitialized static/global variables. This segment will be filled
with zeros by the operating system, so all the uninitialized variables are initialized with
zeros. For example, the variable b defined in static int b will be stored in the BSS
segment, and it is initialized with zero.

## Heap:
The heap is used to provide space for dynamic memory allocation. This area is
managed by malloc, calloc, realloc, free, etc.

## Stack:
The stack is used for storing local variables defined inside functions, as well as
storing data related to function calls, such as return address, arguments, etc. 


```c
int x = 100;
int main()
{
    // data stored on stack
    int a=2;
    float b=2.5;
    static int y;
    
    // allocate memory on heap
    int *ptr = (int *) malloc(2*sizeof(int));

    // values 5 and 6 stored on heap
    ptr[0]=5;
    ptr[1]=6;

    // deallocate memory on heap
    free(ptr);
    return 1;
}
```
In the above program, the variable x is a global variable initialized inside the program;
this variable will be allocated in the Data segment. The variable y is a static variable that is
uninitialized, so it is allocated in the BSS segment. The variables a and b are local variables,
so they are stored on the program’s stack. The variable ptr is also a local variable, so it is
also stored on the stack. However, ptr is a pointer, pointing to a block of memory, which is
dynamically allocated using malloc(); therefore, when the values 5 and 6 are assigned to
ptr[1] and ptr[2], they are stored in the heap segment.


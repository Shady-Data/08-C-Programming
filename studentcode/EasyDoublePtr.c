/*Create a program to use pointer to pointer
Code a C program to exhibit the use of pointer to a pointer.

	Demonstrate use of pointer to a pointer
 */

#include <stdio.h>

void print_values(int x, int * x_ptr, int ** x_dblptr) // prints the integer value stored in x, and the referenced valus of a pointer and a double pointer
{
    printf("\nValue of num  = %d\n", x);
    printf("Value pointed by ptr  = %d\n", *x_ptr);
    printf("Value Value pointed by dPtr  = %d\n", **x_dblptr);
}

int main()
{
    // Integer variable
    int num = 0;
    // Pointer to integer
    int * num_ptr = &num; // pointer to the address of num
    // Pointer to integer pointer
    int **num_dblptr = &num_ptr; // pointer to the address of the pointer to the address of num

    /* Change the value of num directly */
    num = 10;
    print_values(num, num_ptr, num_dblptr);

    /* Assigns 100 using pointer to integer */
    *num_ptr = 100;
    print_values(num, num_ptr, num_dblptr);

    /* Assigns 1000 using pointer to integer pointer */
    **num_dblptr = 1000;
    print_values(num, num_ptr, num_dblptr);

    return 0;
}


/*
 Example Output -

Value of num   = 10
Value pointed by ptr  = 10
Value pointed by dPtr = 10

Value of num   = 100
Value pointed by ptr  = 100
Value pointed by dPtr = 100

Value of num   = 1000
Value pointed by ptr  = 1000
Value pointed by dPtr = 1000
*/
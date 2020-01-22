/*
* 
*  name: Robert Chunn
*  date: 22 Jan 2020
*  project: Performance Lab 26
* 
*/

#include <stdio.h>

#define PRINT_MACRO(x) printf(#x " is %d at %p\n", x, &x)
#define PRINT_PTR(x) printf(#x " is %p at %p\n", x, &x)

int main(void)
{
    int userInput = 0, tempValue = 0;
    int * input_ptr;

    printf("Enter a number: ");
    scanf("%d", &userInput);

    input_ptr = &userInput;
    tempValue = *input_ptr;
    
    PRINT_MACRO(userInput);
    PRINT_MACRO(tempValue);
    PRINT_PTR(input_ptr);

    return 0;
}
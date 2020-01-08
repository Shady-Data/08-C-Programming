/* 
* 
*  name: Robert Chunn
*  date: 08 Jan 2020
*  project: Performance Lab 6
*
*  URL: https://github.com/CyberTrainingUSAF/08-C-Programming/blob/master/04_IO_part_1/performance_labs/lab6/lab6.md
*
*/

#include <stdio.h>

int main(void)
{
    // declare and initialize a variable for getc() to store its result
    int userInput = 0;
    // Request input from the user
    printf("Enter a character: ");
    // assign the input to the variable
    userInput = getc(stdin);
    // Display the result
    printf("The previous character is: ");
    // subtract 1 from the getc() result to place the previous char
    putc(userInput - 1, stdout);
    // print a newline for readability
    printf("\n");

    return 0;
}
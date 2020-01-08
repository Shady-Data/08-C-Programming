/* 
* 
*  name: Robert Chunn
*  date: 08 Jan 2020
*  project: Performance Lab 5
*
*  URL: https://github.com/CyberTrainingUSAF/08-C-Programming/blob/master/04_IO_part_1/performance_labs/lab5/lab5.md
*
*/

#include <stdio.h>

int main(void)
{
    // declare and initialize a variable for getchar() to store its result
    int userInput = 0;
    // Request input from the user
    printf("Enter a character: ");
    // assign the input to the variabe
    userInput = getchar();
    // Display the result
    printf("The next character is: ");
    // add 1 to the getchar() result to place the next char
    putchar(userInput + 1);
    // print a newline for readability
    printf("\n");

    return 0;
}
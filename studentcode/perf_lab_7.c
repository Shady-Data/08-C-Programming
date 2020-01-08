/* 
* 
*  name: Robert Chunn
*  date: 08 Jan 2020
*  project: Performance Lab 7
*
*  URL: https://github.com/CyberTrainingUSAF/08-C-Programming/blob/master/04_IO_part_1/performance_labs/lab7/lab7.md
*
*/

#include <stdio.h>

int main(void)
{
    // declare and initialize an array for fgets() to store its result
    char userInput[10] = {0};
    // Request input from the user
    printf("Enter string: ");
    fgets(userInput, sizeof(userInput), stdin);        // Stores user string
    // Display the result
    printf("Your string was: ");                       // Prefaces output
    fputs(userInput, stdout);                          // Writes to stdout
    printf("\n");

    return 0;
}
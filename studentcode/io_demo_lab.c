/* 
* 
*  name: Robert Chunn
*  date: 08 Jan 2020
*  project: I/O Demo Lab
*
*  URL: https://github.com/CyberTrainingUSAF/08-C-Programming/blob/master/04_IO_part_1/03_getchar-putchar.md
*
*/

#include <stdio.h>

int main(void)
{
    int userInput = 0;                // Will store user input
    printf("Enter a character: ");    // Prompts user
    userInput = getchar();            // Stores user input
    printf("Your character was: %d: ", userInput);   // Prefaces output
    putchar(userInput);               // Prints output
    printf("\n");

    return 0;
}
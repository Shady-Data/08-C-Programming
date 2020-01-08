/* 
* 
*  name: Robert Chunn
*  date: 08 Jan 2020
*  project: I/O Demo Lab 2
*
*  URL: https://github.com/CyberTrainingUSAF/08-C-Programming/blob/master/04_IO_part_1/04_getc-putc.md
*
*/

#include <stdio.h>

int main(void)
{

    int userInput = 0;                // Will store user input
    printf("Enter a character: ");    // Prompts user
    userInput = getc(stdin);            // Stores user input
    printf("Your character was: %d: ", userInput);   // Prefaces output
    putc(userInput, stdout);               // Prints output
    printf("\n");

    return 0;
}
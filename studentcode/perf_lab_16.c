/* 
* 
*  name: Robert Chunn
*  date: 13 Jan 2020
*  project: Performance Lab 16
*
*  URL: https://github.com/CyberTrainingUSAF/08-C-Programming/blob/master/07_Control_flow/performance_labs/Lab16.md
*
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    // declare and initialize a char Array containing multiple phrases
    char phrases[] = "I hate individually assigning array elements.\nWe're questioning how to accomplish the lab.\nHow do we accomplish this task?\n\0";
    // test the phrase with puts
    puts(phrases);

    // add 2 newlines to seperate the output
    fprintf(stdout, "\n\n");

    // declare and initialize an int variable counter for reading individual chars from the phrases char array and a newline counter
    int ind = 0;
    // while the char at index position is not a NUL '\0' char
    while (phrases[ind] != '\0' && phrases[ind] != '\n')
    {
        putchar(phrases[ind]); // print the current char
        ind++; // increment the index
    }
    fprintf(stdout, "\n");
    
    return 0;
}
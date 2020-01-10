/* 
* 
*  name: Robert Chunn
*  date: 10 Jan 2020
*  project: Performance Lab 10
*  Perf Lab URL: https://github.com/CyberTrainingUSAF/08-C-Programming/blob/master/06_Bitwise_operators/performance_labs/lab10.md
*/

#include <stdio.h>

int main(void)
{
    //declare an unsignd 32-bit integer to store user input
    __uint32_t userInput = 0;
    // prompt the user for input
    printf("Enter a postive integer: ");
    fscanf(stdin, "%ul", &userInput);

    // declare and initialize a bitchecker
    __uint32_t bitChecker = 0x01;
    // move the 1 set bit in bitChecker to the left most bit in the 32-bit unsigned integer
    bitChecker <<= 31;

    // declare and initialize a spacer accumalator
    int spacer = 0;
    // while bitchecker is greater than 0 
    while (bitChecker > 0)
    {
        // if spacer has accumalated to 4
        if ( spacer == 4)
        {
            // print a space a specific bit places to create 4 bit groupings
            fprintf(stdout, " ");
            // reset the spacer to 0
            spacer = 0;
        }
        // print 1 (true) if the result of userinput AND bitchecker is > 0 or 0 (False) if not
        fprintf(stdout, "%d", (userInput & bitChecker) > 0);
        // move the bitchecker one bit to the right
        bitChecker >>= 1;
        // add 1 to spacer at the end of each loop
        spacer++;
    }
    // print a newline for readability
    fprintf(stdout, "\n");

    return 0;
}
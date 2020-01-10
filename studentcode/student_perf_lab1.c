/* 
* 
*  name: Robert Chunn
*  date: 10 Jan 2020
*  project: Student Performance Lab 1
*  
*  1. Write a program to shift the number entered by 3 bits left and display the result.
*  2. Write a program to shift the number entered by 5 bits right and display the result.
* 
*/

#include <stdio.h>

int main(void)
{
    // declare varibles to store the users input
    __uint32_t shiftLeft, shiftRight;
    // initialize and zeroize the variables if desired
    shiftLeft = 0;
    shiftRight = 0;

    // prompt the user for the numbe to be shifted left
    fprintf(stdout, "Enter a number to be shifted left: ");
    fscanf(stdin, "%u", &shiftLeft);

    // prompt the user for the numbe to be shifted right
    fprintf(stdout, "Enter a number to be shifted right: ");
    fscanf(stdin, "%u", &shiftRight);

    // Display the original number and the result of the bit shifting
    fprintf(stdout, "\n\t%u after shifting 3 bits to the left is %u\n", shiftLeft, shiftLeft << 3);
    fprintf(stdout, "\t%u after shifting 5 bits to the right is %u\n\n", shiftRight, shiftRight >> 5);

    return 0;
}
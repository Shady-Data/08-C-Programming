/* 
* 
*  name: Robert Chunn
*  date: 13 Jan 2020
*  project: Performance Lab 12
*  Perf Lab URL: https://github.com/CyberTrainingUSAF/08-C-Programming/blob/master/07_Control_flow/performance_labs/Lab12.md
*/

#include <stdio.h>

int print_binary(int num)
{
    // declare and initialize a local bit checker variable with only 1 bit set 
    __uint32_t bitVar = 0x01;
    // shift the bit to the leftmost position in a 32 bit integer
    bitVar <<= 31;

    // for readability declare and intialize a counter to seperate the prints into 4 bit groups
    int space = 0;
    fprintf(stdout, "%12d : ", num);
    // while the bitchecker variable is greater then 0
    while (bitVar > 0)
    {
        if (space == 4)
        {
            fprintf(stdout, " ");
            //reset the space counter after each space is printed
            space = 0;
        }
        // print the result of the input num AND the bitchecker variable > 0
        fprintf(stdout, "%d", (num & bitVar) > 0);
        // shift the bitchecker variable 1 right after each loop
        bitVar >>= 1;
        space++;
    }
    //print a newline
    fprintf(stdout, "\n");
    // return 0
    return 0;
}

int main(void)
{
    // Declare and initialize a signed int to 0
    int user_input = 0;

    // Prompt user for input
    fprintf(stdout, "Enter a number : ");
    scanf("%d", &user_input);

    // set a bitchecker var
    __uint32_t bitchecker = 0x01;
    // shift the bitchecker to the leftmost position (31 bits left in a 32 bit integer)
    bitchecker <<= 31;

    {
        // if the leftmost bit is on for user input, then the number is negative
        if (bitchecker & user_input)
        {
            // indicate that the number is negative
            fprintf(stdout, "The number is already negative.\n");
        }
        else
        {
            // print the original number in binary
            print_binary(user_input);
            // flip the first bit to make it negative
            user_input |= bitchecker;
            // print the new number in binary
            print_binary(user_input);
        }
        
    }


    return 0;
}
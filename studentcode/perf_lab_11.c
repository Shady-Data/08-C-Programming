/* 
* 
*  name: Robert Chunn
*  date: 13 Jan 2020
*  project: Performance Lab 11
*  Perf Lab URL: https://github.com/CyberTrainingUSAF/08-C-Programming/blob/master/07_Control_flow/performance_labs/Lab11.md
*/

#include <stdio.h>

int main(void)
{
    // declare, initialize and zeroize a char array to store user input
    char user_input[256] = {0};

    // Prompt the user for input
    fprintf(stdout, "Enter a string: ");
    fgets(user_input, 255, stdin);

    // Echo the input if the first element of the char array is greater than or equal to 32 AND less than 126
    if (user_input[0] >= 32 && user_input[0] < 126)
    {
        fprintf(stdout, "%s", user_input);
    }


    return 0;
}
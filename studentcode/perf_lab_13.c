/* 
* 
*  name: Robert Chunn
*  date: 13 Jan 2020
*  project: Performance Lab 13
*  Perf Lab URL: https://github.com/CyberTrainingUSAF/08-C-Programming/blob/master/07_Control_flow/performance_labs/Lab13.md
*/

#include <stdio.h>

int main(void)
{
    // declare 3 unsignd integer (uint32_t) variables
    __uint32_t num1 = 0, num2 = 0, num3 = 0;
    
    // Prompt the user for input
    fprintf(stdout, "Enter 2 numbers seperated by ', ' : ");
    fscanf(stdin, "%d, %d", &num1, &num2);

    {
        if (num1 == num2)
        {
            fprintf(stdout, "ERROR!\n");
        }
        else if (num1 > num2)
        {
            num1 ^= num3; // set num1 to be the XOR of num1 and num3
            num3 ^= num1; // set num3 to be the the XOR of num3 and the new num1 (num3 becomes what num1 was originally)
            num1 ^= num3; // set num1 to be the XOR of num1 and num3 again (num1 becomes the original value of num3)
        }
        else
        {
            num2 ^= num3;
            num3 ^= num2;
            num2 ^= num3;
        }
    }
    if (num1 + num2 + num3 > 2)
    {
        fprintf(stdout, "First num: %d; Second num: %d; Third num: %d\n", num1, num2, num3);
    }
    return 0;
}
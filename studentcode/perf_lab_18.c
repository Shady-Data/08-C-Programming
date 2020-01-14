/* 
* 
*  name: Robert Chunn
*  date: 14 Jan 2020
*  project: Performance Lab 18
*
*  URL: https://github.com/CyberTrainingUSAF/08-C-Programming/blob/master/07_Control_flow/performance_labs/Lab18.md
*
*/

#include <stdio.h>

int main(void)
{
    // declare and initialize an unsigned int to store user input
    __uint32_t x = 0;
    // declare and initialize a counter for numbers printed and an incrementer
    int counter = 0, inc = 0;
    // continuoulsy request and process user input until x > 999
    do
    {
        // prompt user for input
        fprintf(stdout, "\nEnter a Positive number to find the first 10 evenly evenly divisible numbers: ");
        fscanf(stdin, "%u", &x);

        // process user input until inc is greater than the user input and the counter is less than 10
        do
        {
            // if user input is > 1000
            if (x >= 1000)
            {
                // immediately break out of the current loop
                break;
            }
            // if the inc variable is 0
            else if (inc == 0)
            {
                // print the start of the output
                fprintf(stdout, "\n%u factors: ", x);
                // increment inc by 1
                inc++;
                // end the current loop iteration and start the next loop iteration
                continue;
            }
            // if the user input is evenly divisible by the current increment
            if (x % inc == 0)
            {
                // if its the first printed inc: This is for output readability
                if (counter == 0)
                {
                    // print the first inc value
                    fprintf(stdout, "%d", inc);
                }
                // otherwise
                else
                {
                    // print a ', ' and the next value
                    fprintf(stdout, ", %d", inc);
                }
                // increment the counter
                counter++;
            }
            // increment the inc var
            inc++;
        // terminate the loop if either inc > x or counter is > 10
        } while (inc <= x && counter < 10);

        // reset the inc and counter variables for the next loop
        inc = 0;
        counter = 0;
    // terminate the loop if x > 999
    } while (x < 1000);

    return 0;
}
/* 
* 
*  name: Robert Chunn
*  date: 14 Jan 2020
*  project: Performance Lab 19
*
*  URL: https://github.com/CyberTrainingUSAF/08-C-Programming/blob/master/07_Control_flow/performance_labs/Lab19.md
*
*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    // declare and initialize a variable to store user input
    char user_input = 0;
    int checker = -1, ch;

    // continuously run until the checker value is changed from -1
    while (checker == -1)
    {
        // Prompt the user for input
        fprintf(stdout, "\nDisplay Evens or Odds :");
        // set user_input to be the first char in stdin
        user_input = getchar();
        // clear stdin by grabbing each char in the buffer until a newline '\n' is grabbed or the EOF is grabbed 
        while((ch = getchar()) != '\n' && ch != EOF);
        // take the toupper() or tolower() of the character input to reduce cases
        user_input = toupper(user_input);
        // switch depending user input
        switch (user_input)
        {
            // if the char in user_input is 'E' or 'e'
            case ('E'):
                // set the checker value to 0
                checker = 0;
                break;
            // if the char in user_input is 'O' or 'o'
            case ('O'):
                // set the checker value to 1
                checker = 1;
                break;
            // if neither case is met
            default:
                // print an error and rerun the loop code
                fprintf(stdout, "Error!\n");
                break;
        }
    }

    // print even or odd to start the output print statement
    if (checker == 0)
    {
        fprintf(stdout, "Evens: ");
    }
    else
    {
        fprintf(stdout, "Odds: ");
    }
    
    // for each number in 0-100, incrementing
    for (int i = 0, n = 1; i <= 100; i++)
    {
        // check if the remainder of the iterating number (i) divided by 2 is equal to the checker value (0 = even, 1 = odd)
        if (i % 2 == checker)
        {
            // on the first run only, for readability
            if (n)
            {
                // print the first number on its own
                fprintf(stdout, "%d", i);
                n--;
            }
            // otherwise
            else
            {
                // print every number after the first with a ", " in front of the current number
                fprintf(stdout, ", %d", i);
            }
        }
    }
    // print a newline '\n' to close the line
    fprintf(stdout, "\n");

    return 0;
}
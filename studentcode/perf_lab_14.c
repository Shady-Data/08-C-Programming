/* 
* 
*  name: Robert Chunn
*  date: 13 Jan 2020
*  project: Performance Lab 14
*  Perf Lab URL: https://github.com/CyberTrainingUSAF/08-C-Programming/blob/master/07_Control_flow/performance_labs/Lab14.md
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    // declare and intitialize the variable to store user input
    int num1 = 0, num2 = 0;
    char operator = 0;

    // Prompt for user input
    fprintf(stdout, "Enter the 'Simple' Expression to evaluate: ");
    fscanf(stdin, "%d %c %d", &num1, &operator, &num2);

    // switch based on what operator was passed in input
    switch (operator)
    {
        case ('+'):  // if operator == '+'
            fprintf(stdout, "\n\t%d + %d = %d\n\n", num1, num2, num1 + num2); // Output the sum of the 2 numbers
            break; // break out of the switch case code block
        case ('-'):  // if operator == '-'
            fprintf(stdout, "\n\t%d - %d = %d\n\n", num1, num2, num1 - num2); // Output the difference of the 2 numbers
            break; // break out of the switch case code block
        case ('*'):  // if operator == '*'
            fprintf(stdout, "\n\t%d * %d = %d\n\n", num1, num2, num1 * num2); // Output the product of the 2 numbers
            break; // break out of the switch case code block
        case ('/'):  // if operator == '/'
            fprintf(stdout, "\n\t%d / %d = %.2f\n\n", num1, num2, num1 / (double)num2); // Output the double casted quotient of the 2 numbers displaying up to 2 decimal places
            break; // break out of the switch case code block
        case ('%'):  // if operator == '%'
            fprintf(stdout, "\n\t%d %% %d = %d\n\n", num1, num2, num1 % num2); // Output the remainder of the 2 numbers
            break; // break out of the switch case code block
        case ('^'):  // if operator == '%'
            fprintf(stdout, "\n\t%d^%d = %d\n\n", num1, num2, (int)pow(num1, num2)); // Output the remainder of the 2 numbers
            break; // break out of the switch case code block
        default: // is operator not list
            fprintf(stdout, "ERROR\n"); // Output an Error
            break; // break out of the switch case code block
    }

    return 0;
}
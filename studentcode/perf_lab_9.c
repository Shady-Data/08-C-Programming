/* 
* 
*  name: Robert Chunn
*  date: 09 Jan 2020
*  project: Performance Lab 9
*  Perf Lab URL: https://github.com/CyberTrainingUSAF/08-C-Programming/blob/master/05_Operators_expressions/performance_labs/Lab9.md
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    double a, b, h; // Declare the variables to store the 2 sides and the calculated hypotenuse

    // Prompt for the length of the first side
    printf("Enter the length of the first side : ");
    // store the user input into the first variable
    scanf("%lf", &a);

    // Prompt for the length of the other side
    printf("Enter the length of the second side : ");
    // store the user input into the second variable
    scanf("%lf", &b);

    // if both a and b are non-zero numbers
    if ((a != 0.0) && (b != 0.0))
    {
        // calculate the hypotenuse by taking the squareroot of the sum of the first side squared and the second side squared
        h = sqrt(a*a + b*b);  // if "undefined reference to 'sqrt'" error from gcc, add -lm to the end of the gcc command
        // print the result
        printf("Length of hypotenuse is %f\n", h);
    }

    return 0;
}
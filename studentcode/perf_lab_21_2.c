/*
* 5.39--> (recursive greatest common divisor) 
* 	The greatest common divisor of integers (x) and (y) is the largest integer that evenly divides both (x) and (y).
*     Write a function (gcd) that returns the greatest common divisor of (x) and (y).
* 	The (gcd) of (x) and (y) is defined recursively as follows: if (y) is equal to 0, then (gcd(x, y)) is (x);
*     otherwise (gcd (x) and (y)) is (gcd (y, x % y)), where % is the remainder operator.
*/
#include <stdio.h>

int gcd(int x, int y) // returns the first (greatest) common divisor between x and y
{
    if (x % y == 0) // base case: if the remainder of x / y is 0
    {
        return y; // return y as the greatest common divisor
    }
    else // recursive case: otherwise
    {
        return gcd(y, x % y); // return the recursive gcd call arguments x and the remainder of x / y
    }
    
}

void main(void)
{
    // declare and initialize/zeroize two integers to store user input in
    int num1 = 0, num2 = 0;
    // Prompt the user to enter 2 numbers
    fprintf(stdout, "Enter two numbers to find their greatest common divisor (x, y): ");
    // store the numbers entered in x, y format and to the previously declared integer variables
    fscanf(stdin, "%d, %d", &num1, &num2);
    // print the result of the recursive gcd() function
    fprintf(stdout, "The greatest common divisor (gcd) of %d and %d is %d\n", num1, num2, gcd(num1, num2));
}
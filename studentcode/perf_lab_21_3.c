/*
* 
*  name: Robert Chunn
*  date: 16 Jan 2020
*  project: Performance Lab 21_3
* 
* 5.40--> (recursive main) 
* 	Can main be called recursively? Write a program containing a function   (main).
*     Include (static) local variable count initialized to 1.
*     Post-increment and print the value of count each time main is called.
*     What happens when your program runs?
*/

#include <stdio.h>

int main(void)
{
    // declare and initialze a static integer variable to 1
    static int counter = 1; // a static variable is used to prevent the variable from being redeclared and assigned a value of 1 for the recursive main() calls 

    // establish a base case to prevent infinite recursion
    if (counter == 20) { // base case: if the variable is 20 
        fprintf(stdout, "main() called %d times\n", counter); // print the variable value
        fprintf(stdout, "\tProgram Terminating.\n"); // print a terminatig statement if desired
        return 0; // return 0 or the variable as desired
    }
    else if (counter == 1){ // unnecessary case for slight modification of printed statement
        fprintf(stdout, "\nmain() called %d time\n", counter++); // print and increment the value of the variable
        return main(); // return the main() for recursion until the sentinel value (set in the base case) is met.
    }
    else { // recursive case
        fprintf(stdout, "main() called %d times\n", counter++); // print and increment the value of the variable
        return main(); // return the main() for recursion until the sentinel value (set in the base case) is met.
    }
}
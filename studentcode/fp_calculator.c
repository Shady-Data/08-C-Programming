/*
* 
*  name: Robert Chunn
*  date: 23 Jan 2020
*  project: Function Pointer Calculator Demo Lab
* 
*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#define ERROR_CODE ((double)98245.1653) // Defined error code for preprocessor replacement

double add(double firstNumber, double secondNumber); // function prototype for the add function (declaration)
double subtract(double firstNumber, double secondNumber); // function prototype for the subtract function (declaration)
double multiply(double firstNumber, double secondNumber); // function prototype for the multiply function (declaration)
double divide(double firstNumber, double secondNumber); // function prototype for the divide function (declaration)

int main(void)
{
	double(*mathFun_ptr)(double x, double y); // declared function pointer to use for standardized function callback
	// declare and zeroize variables to store user input
    double num1 = 0;
	char mathOperator = 0; 
	double num2 = 0;
    // declare and zeroize a variable to store the result
	double returnValue = 0;

    // Prompt the user for input
	printf("Enter two ints and/or doubles separated by a math operator\n");
	printf("e.g., 1.2 + 3.4, 5.6 - 7.8, 9.10 * 2.3, 4.5 / 6.7\n");
	_flushall(); // clear/flush all buffers
	scanf("%lf %c %lf", &num1, &mathOperator, &num2); // store the user input in their respective variables
	
    // assign the mathFun_ptr to the appropriate function based on the user input in mathOperator
	if (mathOperator == '+')
	{
		mathFun_ptr = &add; // if the mathOperator is '+', set the mathFun_ptr function pointer to the memory address of the start of the add() function
	}
	else if (mathOperator == '-')
	{
		mathFun_ptr = &subtract; // if the mathOperator is '-', set the mathFun_ptr function pointer to the memory address of the start of the subtract() function
	}
	else if (mathOperator == '*')
	{
		mathFun_ptr = &multiply; // if the mathOperator is '*', set the mathFun_ptr function pointer to the memory address of the start of the multiply() function
	}
	else if (mathOperator == '/')
	{
		mathFun_ptr = &divide; // if the mathOperator is '/', set the mathFun_ptr function pointer to the memory address of the start of the divide() function
	}
	else
	{
		puts("Something went wrong!"); // if the character stored in the mathOperator variable is not any of the previous characters checked print an error message
		return -1; // return -1 and terminate/exit the program
	}

	if (mathFun_ptr) // if the mathFun_ptr funtion pointer is set/initialized to a value
	{
		returnValue = mathFun_ptr(num1, num2); // set the returnValue variable to the result of the function called from the address stored in mathFun_ptr with the user input numbers as the required arguments
		printf("The result is:\t%lf\n", returnValue);
	}
	else
	{
		puts("Something went wrong!"); // if the mathFun_ptr is not set/initialized and the program is still running, print an error message
		return -1; // return -1 and terminate/exit the program
	}

	getchar(); getchar(); // grab 2 characters from user input, an attempt to clear the stdin buffer of any remaing newline characters, may require a second enter press to satisfy the function calls
	return 0; // return 0 and exit the program
}

double add(double firstNumber, double secondNumber) // initializes the add function with 2 double precision number parameters required
{
	return firstNumber + secondNumber; // return the sum of the two parameters
}

double subtract(double firstNumber, double secondNumber) // initializes the subtract function with 2 double precision number parameters required
{
	return firstNumber - secondNumber; // return the difference of the two parameters
}

double multiply(double firstNumber, double secondNumber) // initializes the multiply function with 2 double precision number parameters required
{
	return firstNumber * secondNumber; // return the product of the two parameters
}

double divide(double firstNumber, double secondNumber) // initializes the divide function with 2 double precision number parameters required
{
	if (secondNumber) // if the value of the 2nd parameter is not 0
	{
		return firstNumber / secondNumber; // return the quotient of the two parameters
	}
	else
	{
		return ERROR_CODE; // otherwise, return the ERROR_CODE defined above to prevent a zero division error
	}
}
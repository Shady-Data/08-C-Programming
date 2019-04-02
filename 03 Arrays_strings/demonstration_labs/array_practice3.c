#include <stdio.h>

int main(void)
{
	////////////////////////////////////////////////////////////////////////
	// Declare and initialize the following arrays:
	// Data Type	Name			Dimension	Initialize to:
	// ---------------------------------------------------------------------
	// int			myIntArray		10			100 (every index)
	// float		myFloatArray	5			1 - 5
	// char			myCharArray		256			0
	////////////////////////////////////////////////////////////////////////
	int myIntArray[10] = { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100 }; // Option #1
//	int myIntArray[] = { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100 }; // Option #2

	float myFloatArray[5] = { 1, 2, 3, 4, 5 }; // Option #1
//	float myFloatArray[] = { 1, 2, 3, 4, 5 }; // Option #2

	char myCharArray[256] = { 0 }; // Most efficient option

	////////////////////////////////////////////////////////////////////////
	// Print the 3rd element of each array
	////////////////////////////////////////////////////////////////////////
	printf("The third element of my int array is:  %d\n", myIntArray[2]);
	printf("The third element of my float array is:  %f\n", myFloatArray[2]);
	printf("The third element of my char array is:  %c\n", myCharArray[2]);

	////////////////////////////////////////////////////////////////////////
	// Perform the following manipulations on your arrays:
	// Array Name
	// ---------------------------------------------------------------------
	// myIntArray		Set all elements to x if y = index # and x = (y + 1) * 10
	// myFloatArray		Set all elements to x if y = value of the index and x = y * 1.1
	// myCharArray		Fill in the beginning elements with your last name starting with index 0
	////////////////////////////////////////////////////////////////////////
	// Option #1 - Static assignment
	myIntArray[0] = 10; // Value is set to x where x = (y + 1) * 10 if y = index #
	myIntArray[1] = 20; // Value is set to x where x = (y + 1) * 10 if y = index #
	myIntArray[2] = 30; // Value is set to x where x = (y + 1) * 10 if y = index #
	myIntArray[3] = 40; // Value is set to x where x = (y + 1) * 10 if y = index #
	myIntArray[4] = 50; // Value is set to x where x = (y + 1) * 10 if y = index #
	myIntArray[5] = 60; // Value is set to x where x = (y + 1) * 10 if y = index #
	myIntArray[6] = 70; // Value is set to x where x = (y + 1) * 10 if y = index #
	myIntArray[7] = 80; // Value is set to x where x = (y + 1) * 10 if y = index #
	myIntArray[8] = 90; // Value is set to x where x = (y + 1) * 10 if y = index #
	myIntArray[9] = 100; // Value is set to x where x = (y + 1) * 10 if y = index #
	// Option #2 - Calculated assignment
	/*
	myIntArray[0] = (0 + 1) * 10; // Value is set to x where x = (y + 1) * 10 if y = index #
	myIntArray[1] = (1 + 1) * 10; // Value is set to x where x = (y + 1) * 10 if y = index #
	myIntArray[2] = (2 + 1) * 10; // Value is set to x where x = (y + 1) * 10 if y = index #
	myIntArray[3] = (3 + 1) * 10; // Value is set to x where x = (y + 1) * 10 if y = index #
	myIntArray[4] = (4 + 1) * 10; // Value is set to x where x = (y + 1) * 10 if y = index #
	myIntArray[5] = (5 + 1) * 10; // Value is set to x where x = (y + 1) * 10 if y = index #
	myIntArray[6] = (6 + 1) * 10; // Value is set to x where x = (y + 1) * 10 if y = index #
	myIntArray[7] = (7 + 1) * 10; // Value is set to x where x = (y + 1) * 10 if y = index #
	myIntArray[8] = (8 + 1) * 10; // Value is set to x where x = (y + 1) * 10 if y = index #
	myIntArray[9] = (9 + 1) * 10; // Value is set to x where x = (y + 1) * 10 if y = index #
	*/
	// Option #3 - For loop
	/*
	int i = 0; // Used to iterate through a for loop
	for (i = 0; i < 10; i++) // Executes the following code using i with values 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
	{
		myIntArray[i] = (i + 1) * 10; // Variable i represents the current index
	}
	*/
	// Option #1 - Static assignment
	myFloatArray[0] = 1 * 1.1; // Value is set to x where x = y * 1.1 if y = current index value
	myFloatArray[1] = 2 * 1.1; // Value is set to x where x = y * 1.1 if y = current index value
	myFloatArray[2] = 3 * 1.1; // Value is set to x where x = y * 1.1 if y = current index value
	myFloatArray[3] = 4 * 1.1; // Value is set to x where x = y * 1.1 if y = current index value
	myFloatArray[4] = 5 * 1.1; // Value is set to x where x = y * 1.1 if y = current index value
	// Option #2 - Calculated assignment
	/*
	myFloatArray[0] = myFloatArray[0] * 1.1; // Value is set to x where x = y * 1.1 if y = current index value
	myFloatArray[1] = myFloatArray[1] * 1.1; // Value is set to x where x = y * 1.1 if y = current index value
	myFloatArray[2] = myFloatArray[2] * 1.1; // Value is set to x where x = y * 1.1 if y = current index value
	myFloatArray[3] = myFloatArray[3] * 1.1; // Value is set to x where x = y * 1.1 if y = current index value
	myFloatArray[4] = myFloatArray[4] * 1.1; // Value is set to x where x = y * 1.1 if y = current index value
	*/
	// Option #3 - For loop
	/*
	int i = 0; // Used to iterate through a for loop
	for (i = 0; i < 5; i++) // Executes the following code using i with values 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
	{
		myFloatArray[i] = myFloatArray[i] * 1.1; // Variable i represents the current index
	}
	*/

	// Most efficient method
	myCharArray[0] = 72;	// H
	myCharArray[1] = 97;	// a
	myCharArray[2] = 114;	// r
	myCharArray[3] = 107;	// k
	myCharArray[4] = 108;	// l
	myCharArray[5] = 101;	// e
	myCharArray[6] = 114;	// r
	myCharArray[7] = 111;	// o
	myCharArray[8] = 97;	// a
	myCharArray[9] = 100;	// d

	printf("\n");
	printf("The third element of my modified int array is:  %d\n", myIntArray[2]);
	printf("The third element of my modified float array is:  %f\n", myFloatArray[2]);
	printf("The third element of my modified char array is:  %c\n", myCharArray[2]);
//	printf("My last name is %s\n", myCharArray);
	getchar();

	return 0;
}

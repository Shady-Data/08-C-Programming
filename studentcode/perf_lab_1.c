/* Prints various variable types and their respective sizes
*
*  name: Robert Chunn
*  date: 06 Jan 2020
*  project: Performance Lab 1
*/

#include <stdio.h>

int main(void)
{
	int port = 65535; // declare and initialize an integer variable called port
	float pricePerItem = 19.99; // declare and initialize a single precision float variable called pricePerItem
	double pi = 3.1415926535897932; // declare and initialize a double precision float variable called pi
	char someChar = 'X'; // declare and initialize a character variable called someChar

	
	printf("Your integer is %d , which has a size of %ld\n", port, sizeof(port));
	printf("Your float is %f , which has a size of %ld\n", pricePerItem, sizeof(pricePerItem));
	printf("Your double is %.15f , which has a size of %ld\n", pi, sizeof(pi));
	printf("Your char is %c , which has a size of %ld\n", someChar, sizeof(someChar));

	return 0;
}
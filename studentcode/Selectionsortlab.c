/*	Test driver for sorting solutions. 
	   Written by:  90cos
	   Date: 2018

*/
#include <stdio.h>

//	Constants
#define cMax_Ary_Size 15
// const int cMax_Ary_Size = 15;

/*	Prototype Declarations */
int selectionSort (int* list, int last);
	
int main ( void ) 
{
/*	Local Declarations */
	int countExch;
	int	ary[cMax_Ary_Size] = {89, 72, 3,  15, 21, \
	                           57, 61, 44, 19, 98, \
	                            5,  77, 39, 59, 61};

/*	Statements */
	printf( "Unsorted array: ");
	for (int i = 0; i < cMax_Ary_Size; i++ )
		printf( "%3d", ary[ i ] );
		
	countExch = selectionSort ( ary, cMax_Ary_Size - 1);

	printf( "\nSorted array:   " );
	for (int i = 0; i < cMax_Ary_Size; i++)
		printf( "%3d", ary[ i ] );
	printf( "\n" );
	
	printf("Total exchanges: %d\n", countExch);
	return 0;
}	/* main */

/*	============ selectionSort ===============
	Sorts list[0...last] by selecting smallest element 
	in unsorted portion of array and exchanging it with 
	element at the beginning of the unsorted list.
	   Pre    list must contain at least one item
	          last contains index to last element 
	   Post   list rearranged smallest to largest
	   Return count of exchanges
*/
int selectionSort (int* list, int last)
{
	// declare and zeroize the return value variable
	int count = 0;
	// insert code here //
  	int i, j, temp, index_min; // i = start index of the unsorted list segment, j = index iterator vor list value checking, temp = location for temporary storage, index_min = index of the lowest value in the unsorted list segment
  	for (i = 0; i < last; i++){ // for each index of the elements in the array, incrementing the index value for each iteration, until the index is greater than the last index of the array
	  	index_min = i; // set the index_min to be the current i value (index) being iterated
		// count++;
		for (j = i + 1; j <= last; j++){ // for each index after the current i value (i + 1), incrementing by 1 until the end of the array (last index value)
		  	if (list[index_min] > list[j]){ // if the value at index_min's index is greater than the value at the current j index
			  	index_min = j; // set the index_min index to be the current j index value
				// count++;
		  	} // end of the if statement codeblock
	  	} // end of the j value for loop codeblock
	  	if (index_min != i){ // after the loop completes, is the index_min index is not the current i index value
			  temp = list[i]; // set the the temp variable to the value in the current i index position
			  list[i] = list[index_min]; // set the i index position's value to the value at the index_min index
			  list[index_min] = temp; // set the value at the index_min index to be the temp value (swap values in i and index_min positions)
			  count += 3; // increment the count by the number of exchanges (3 per swap)
	  	} // end of the if statement codeblock
  	} // end of the i value for loop codeblock
	return count; // return the count
}	// selectionSort

/*
Results:
Unsorted array:  89 72  3 15 21 57 61 44 19 98  5 77 39 59 61
Sorted array:     3  5 15 19 21 39 44 57 59 61 61 72 77 89 98
Total exchanges: 42
*/
// 3 72 89 15 21 57 61 44 19 98 5 77 39 59 61 exchange 1  :  3, 89
// 3 5 89 15 21 57 61 44 19 98 72 77 39 59 61 exchange 2  :  5, 72
// 3 5 15 89 21 57 61 44 19 98 72 77 39 59 61 exchange 3  : 15, 89
// 3 5 15 19 21 57 61 44 89 98 72 77 39 59 61 exchange 4  : 19, 89
// 3 5 15 19 21 39 61 44 89 98 72 77 57 59 61 exchange 5  : 39, 57
// 3 5 15 19 21 39 44 61 89 98 72 77 57 59 61 exchange 6  : 44, 61
// 3 5 15 19 21 39 44 57 89 98 72 77 61 59 61 exchange 7  : 57, 61
// 3 5 15 19 21 39 44 57 59 98 72 77 61 89 61 exchange 8  : 59, 89
// 3 5 15 19 21 39 44 57 59 61 72 77 98 89 61 exchange 9  : 61, 98
// 3 5 15 19 21 39 44 57 59 61 61 77 98 89 72 exchange 10 : 61, 72
// 3 5 15 19 21 39 44 57 59 61 61 72 98 89 77 exchange 11 : 72, 77
// 3 5 15 19 21 39 44 57 59 61 61 72 77 89 98 exchange 12 : 77, 98 sort complete

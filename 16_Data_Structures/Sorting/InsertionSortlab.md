```c

/*	Test driver for sorting solutions. 
	   Written by: 90cos
	   Date: 2018
	
*/
#include <stdio.h>

//	Constants
const int cMax_Ary_Size = 15;

/*	Prototype Declarations */
int insertionSort (int* list, int last);
	
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
		
	countExch = insertionSort ( ary, cMax_Ary_Size - 1);

	printf( "\nSorted array:   " );
	for (int i = 0; i < cMax_Ary_Size; i++)
		printf( "%3d", ary[ i ] );
	printf( "\n" );
	
	printf("Total exchanges: %d\n", countExch);
	return 0;
}	/* main */

/*	================== insertionSort ==================== 
	Sort list using Insertion Sort. The list is divided 
	into sorted and unsorted lists. With each pass,  
	first element in unsorted list is inserted into 
	sorted list.
	   Pre    list must contain at least one element
	          last is index to last element in the list
	   Post   list rearranged, exchange counted
	   Return count of exchanges
*/
int insertionSort (int* list, int last) 
{

/// insert code here 

}	// insertionSort

/*
Results:
Unsorted array:  89 72  3 15 21 57 61 44 19 98  5 77 39 59 61
Sorted array:     3  5 15 19 21 39 44 57 59 61 61 72 77 89 98
Total exchanges: 76


```

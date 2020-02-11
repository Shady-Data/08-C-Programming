```c
/*	Test driver for sorting solutions. 
	   Written by: 90cos
	   Date: 2018

*/
#include <stdio.h>
#include <stdbool.h>

//	Constants
const int cMax_Ary_Size = 15;

/*	Prototype Declarations */
void quickSort      (int *data,     int left, int right, int* count);
void quickInsertion (int* sortData, int  first, 
                     int  last,     int* count);
void medianLeft     (int* sortData, int  left,
                     int  right,    int* count);
	
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
		
	countExch = 0;
	quickSort (ary, 0, cMax_Ary_Size, &countExch);
	
	printf( "\nSorted array:   " );
	for (int i = 0; i < cMax_Ary_Size; i++)
		printf( "%3d", ary[ i ] );
	printf( "\n" );
	
	printf("Total exchanges: %d\n", countExch);
	return 0;
}	/* main */

/*	================== quickSort =====================
	Array  data[left..right] sorted using recursion.
	   Pre    data is array to be sorted
	          left identifies first element in data
	          right identifies last element in data
	          count is exchange accumulator 
	   Post   array sorted
*/
void quickSort (int *data, int left, int right, int* count)
{
//// inser code here //////**********************************************************
	return;
}	// end quickSort

/*	================== quickInsertion ================== 
	Sort list[first...last] using insertion sort. The 
	list is divided into sorted and unsorted lists. With 
	each pass, first element in the unsorted list is 
	inserted into the sorted list using a variation 
	of insertion sort modified for use in quick sort.
	   Pre      list must contain at least one element
	            first is index to first element 
	            last is index to last element
	            count holds the number of exchanges
	   Post     list rearranged.
*/
void quickInsertion (int* sortData, int  first, 
                     int  last,     int* count)

{
///// insert code here /////*******************************************************************
	return;
}	// end quickInsertion

/*	=================== medianLeft ==================== 
	Find median value in array, sortData[left..right], 
	and place it in the location sortData[left].
	   Pre    sortData is array of at least 3 elements
	          left and right are boundaries of the array
	   Post   median value  placed at sortData[left 
	          count holds the number of exchanges
*/
void medianLeft (int* sortData, int  left,
                 int  right,    int* count)
{
///// insert code here //////***************************************************************
	return;
}	// medianLeft

/*
Results:
Unsorted array:  89 72  3 15 21 57 61 44 19 98  5 77 39 59 61
Sorted array:     2  3  5 15 19 21 39 44 57 59 61 61 72 77 89
Total exchanges: 52
*/
```

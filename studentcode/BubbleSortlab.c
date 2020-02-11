/*	Test driver for sorting solutions. 
	   Written by: 90cos
	   Date: 2018

*/
#include <stdio.h>
#include <stdbool.h>

//	Constants
#define cMax_Ary_Size 15
// const int cMax_Ary_Size = 15;

/*	Prototype Declarations */
int bubbleSort (int* list, int last);
int swap(int *a_ptr, int *b_ptr);
	
int main ( void ) 
{
/*	Local Declarations */
	int countExch;
	int	ary[cMax_Ary_Size] = {89, 72, 3,  15, 21, \
	                           57, 61, 44, 19, 98, \
	                            5,  77, 39, 59, 61};

/*	Statements */
	printf( "Unsorted list: ");
	for (int i = 0; i < cMax_Ary_Size; i++ )
		printf( "%3d", ary[ i ] );
		
	countExch = bubbleSort (ary, cMax_Ary_Size - 1);

	printf( "\nSorted list:   " );
	for (int i = 0; i < cMax_Ary_Size; i++)
		printf( "%3d", ary[ i ] );
	printf( "\n" );
	
	printf("Total exchanges: %d\n", countExch);
	return 0;
}	/* main */

/*	=================== bubbleSort ====================
	Sort list using bubble sort. Adjacent elements are
	compared and exchanged until list is sorted.
	   Pre    list must contain at least one item 
	          last contains index to last element 
	   Post   list rearranged in sequence low to high 
	   Return number of exchanges 
*/

int bubbleSort (int* list, int last)
{
	//insert code here//
	int count = 0;
	for (int i = 0; i < last; i++){
		for (int j = 0; j < last-i; j++){
			if (list[j] > list[j + 1]){
				count += swap(&list[j], &list[j+1]);
			}
		}
	}
	return count;
}	// bubbleSort 

int swap(int *a_ptr, int *b_ptr)
{
    int temp = *a_ptr;
    *a_ptr = *b_ptr;
    *b_ptr = temp;
	return 3;
}
/*
Results:
Unsorted list:  89 72  3 15 21 57 61 44 19 98  5 77 39 59 61
Sorted list:     3  5 15 19 21 39 44 57 59 61 61 72 77 89 98
Total exchanges: 144
*/


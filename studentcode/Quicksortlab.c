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
    if (left < right)
    {
        quickInsertion(data, left, right, count);

        quickSort(data, left, (left + right) / 2, count);  // Before the partition index
        quickSort(data, ((left + right) / 2) + 1 , right, count); // After the partition index
    }
	return;
}	// end quickSort

// int partition(int * array, int low, int high)
// {
//     // pivot (Element to be placed at right position)
//     int pivot = array[high];  
 
//     int i = (low - 1);  // Index of smaller element

//     for (int j = low; j <= high - 1; j++)
//     {
//         // If current element is smaller than the pivot
//         if (array[j] < pivot)
//         {
//             i++;    // increment index of smaller element
//             swap(&array[i], &array[j]);
//         }
//     }
//     swap(&array[i + 1], &array[high]);
//     return (i + 1);
// }
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
	int i, j;
	for (i = first; i < last; i++){
		for (j = i + 1; j < last; j++){
			if (sortData[j] < sortData[i]){
				medianLeft(sortData, i, j+1, count);
			}
		}
	}
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
	int median = (left + right) / 2;
	int temp = sortData[left]; // *count += 1;
	sortData[left] = sortData[median]; // *count += 1;
	sortData[median] = temp; // *count += 1;
	*count += 1;
	return;
}	// medianLeft

/*
Results:
Unsorted array:  89 72  3 15 21 57 61 44 19 98  5 77 39 59 61
Sorted array:     3  5 15 19 21 39 44 57 59 61 61 72 77 89 98
Total exchanges: 52
*/

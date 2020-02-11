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
void quickInsertion (int* sortData, int first, int  last, int* count);
void medianLeft     (int* sortData, int left, int  right,    int* count);
	
int main ( void ) 
{
/*	Local Declarations */
	int countExch;
	int	ary[cMax_Ary_Size] = {89, 72, 3,  15, 21, \
	                           57, 61, 44, 19, 98, \
	                            5,  77, 39, 59, 61};

/*	Statements */
    printf( "Unsorted array: ");
	for (int i = 0; i < cMax_Ary_Size; i++ ) printf( "%3d", ary[ i ] );
		
	countExch = 0;
	quickSort (ary, 0, cMax_Ary_Size - 1, &countExch);
	
	printf( "\nSorted array:   " );
	for (int i = 0; i < cMax_Ary_Size; i++) printf( "%3d", ary[ i ] );
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
#define MIN_SIZE 4

//	Local Definitions
	int sortLeft;
	int sortRight;
	int pivot;
	int hold;

//	Statements
	if ((right - left) > MIN_SIZE){
	    medianLeft (data, left, right, count);
	    pivot     = data [left];
	    (*count)++;
	    sortLeft  = left + 1;
	    sortRight = right;
	    while (sortLeft <= sortRight)
	       {
	        // Find key on left that belongs on right 
	        while (data [sortLeft] < pivot) sortLeft++;
	        // Find key on right that belongs on left 
	        while (data[sortRight] >= pivot) sortRight--;
	        if (sortLeft <= sortRight){
	             hold            = data[sortLeft];
	             (*count)++;
	             data[sortLeft]  = data[sortRight];
	             (*count)++;
	             data[sortRight] = hold;
	             (*count)++;
	             sortLeft++;
	             sortRight--;
	            } // if 
	       } // while 

	    // Prepare for next phase 
	    data [left] = data [sortLeft - 1];
	    (*count)++;
	    data [sortLeft - 1] = pivot;
	    (*count)++;
	    if  (left < sortRight) quickSort (data, left, sortRight - 1, count);
	    if (sortLeft < right) quickSort (data, sortLeft, right, count);
	   } // if > minimum elements
	else quickInsertion (data, left, right, count);
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
void quickInsertion (int* sortData, int first, int  last, int* count)
{
//	Local Definitions
	int hold;
	int walker;

//	Statements 
	for (int current = first + 1; 
	         current <= last; 
	         current++)
	   {
	    hold      = sortData[current];
	    (*count)++;
	    walker    = current - 1;
	    while (walker >= first 
	        && hold < sortData[walker])
	       {
	        sortData[walker + 1] = sortData[walker];
	        (*count)++;
	        walker--;
	       } // while 
	    sortData[walker + 1] = hold;
	    (*count)++;
	   } // for
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
//	Local Definitions 
	int mid;
	int hold;

//	Statements 
	//   Rearrange sortData so median is in middle 
	mid = (left + right) / 2;
	if (sortData[left] > sortData[mid])
	   {
	    hold            = sortData[left];
	    sortData[left]  = sortData[mid];
	    sortData[mid]   = hold;
	    *count += 3;
	   } // if 
	if (sortData[left] > sortData[right])
	   {
	    hold             = sortData[left];
	    sortData[left]   = sortData[right];
	    sortData[right]  = hold;
	    *count += 3;
	   } // if 
	if (sortData[mid]  > sortData[right])
	   {
	    hold             = sortData[mid];
	    sortData[mid]    = sortData[right];
	    sortData[right]  = hold;
	    count += 3;
	   } // if 
	// Median is in middle. Exchange with left  
	hold            = sortData[left];
	sortData[left]  = sortData[mid];
	sortData[mid]   = hold;
	count += 3;

	return;
}	// medianLeft

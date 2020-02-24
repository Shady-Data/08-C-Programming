#include <stdio.h>


/*


** NOTE: THE SOLUTION FOR THIS PROBLEM IS BASED ON A SPECICALLY DEFINED ALGORITHM EXPLAINED BELOW. ALTHOUGH THE AUTOMATED TESTS
** MAY BE SUCCESSFUL, YOUR SOLUTION WILL RECEIVE A MANUAL REVIEW FOR FINAL DETERMINATION OF PASS/FAIL

Bubble Sort
--------------
Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.

Example:
First Pass:
( 5 1 4 2 8 ) -> ( 1 5 4 2 8 ), Here, algorithm compares the first two elements, and swaps since 5 > 1.
( 1 5 4 2 8 ) ->  ( 1 4 5 2 8 ), Swap since 5 > 4
( 1 4 5 2 8 ) ->  ( 1 4 2 5 8 ), Swap since 5 > 2
( 1 4 2 5 8 ) -> ( 1 4 2 5 8 ), Now, since these elements are already in order (8 > 5), algorithm does not swap them.

Second Pass:
( 1 4 2 5 8 ) -> ( 1 4 2 5 8 )
( 1 4 2 5 8 ) -> ( 1 2 4 5 8 ), Swap since 4 > 2
( 1 2 4 5 8 ) -> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) ->  ( 1 2 4 5 8 )

Third Pass:
( 1 2 4 5 8 ) -> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) -> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) -> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) -> ( 1 2 4 5 8 )

Fourth Pass:
( 1 2 4 5 8 ) -> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) -> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) -> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) -> ( 1 2 4 5 8 )
*/



/*
The function bubbleSort receives a pointer to a function�either function ascending or function descending�as an argument, in addition to an integer array and the size of the array.
The parameter compare is a pointer to the comparison function that determines sorting order.
The function returns an integer pointer to the sorted array.
*/

int* bubbleSort(int elements[], size_t length, int(*compare)(int a, int b))
{
	int i, j; // declare counters for the for loop s
	for (i = 0; i < length; i++){ // for each value of i up the the length of the array
		for (j = i + 1; j < length; j++){ // for each value of j up to the length - i 
			if (compare(elements[i], elements[j])){ // if the return of the compare function is true
				elements[j] ^= elements[i]; // XOR elements[j] value with elements[i] value to get a combined value
				elements[i] ^= elements[j]; // XOR elements[i] with the combined value in elements[j] to get the original value of elements[j] at elements[i] position
				elements[j] ^= elements[i]; // XOR the combined elements[j] value with the new elements[i] value (originally elements[j] value) to get elements[i] original value at elements[j] position
			}
		}
	}
	return elements; // return the array
}


// @brief Determine whether elements are out of order for an ascending order sort
// @return Boolean indicating whether the two elements should be swapped
int ascending(int a, int b)
// returns true (1) if a > b to indicate that the elements need to be swapped otherwise, returns false (0)
{
	if (a > b){
		return 1;
	}
	return 0;         
}

// @brief Determine whether elements are out of order for a descending order sort
// @return Boolean indicating whether the two elements should be swapped
int descending(int a, int b)
// returns true (1) if a < b to indicate that the elements need to be swapped otherwise, returns false (0)
{
	if (a < b){
		return 1;
	}
	return 0;      
}

int main(void)
{
    int my_array[] = {5, 1, 4, 2, 8};

    for (int i = 0; i < sizeof(my_array)/sizeof(my_array[0]); i++){
        printf("%d ", my_array[i]);
    }

    bubbleSort(my_array, sizeof(my_array)/sizeof(my_array[0]), ascending);
    printf("\t");

    for (int i = 0; i < sizeof(my_array)/sizeof(my_array[0]); i++){
        printf("%d ", my_array[i]);
    }
    printf("\n");

    return 0;
}
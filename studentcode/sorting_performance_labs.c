/*
# Sorting Performance labs 

## Write a C program that implements the bubble sort algorithm

``` Example output:

Enter the number of elements in the array : 10
Enter the elements: 8 9 6 7 5 4 2 3 1 10
The array sorted in ascending order is :
1 2 3 4 5 6 7 8 9 10

```
*/
#include <stdio.h>
#include <stdlib.h>
#include "myhead.h"

void swap(int *a_ptr, int *b_ptr)
{
    int temp = *a_ptr;
    *a_ptr = *b_ptr;
    *b_ptr = temp;
}

void bubble_sort(int * array, int array_size)
{
    for (int i = 0; i < array_size-1; i++){
        for (int j = 0; j < array_size-i-1; j++){
            if (array[j] > array[j + 1]){
                swap(&array[j], &array[j+1]);
            }
        }
    }
}

void print_array(int * array, int array_size)
{
    printf("The array sorted in ascending order is :\n");
    for (int i = 0; i < array_size; i++, array++){
        printf("%d ", *array);
    }
    printf("\n");
}

int lab_1(void)
{
    int num_elements = 0;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &num_elements);
    clear_input();

    int * user_input = malloc(num_elements * sizeof(int));
    int * work_ptr = user_input;

    int inputs = 0;

    printf("Enter the elements: ");
    while (inputs < num_elements){
        scanf(" %d", work_ptr++);
        inputs++;
    }

    bubble_sort(user_input, num_elements);

    print_array(user_input, num_elements);

    free(user_input);
    return 0;
}

/*
## Write a C program that implements the insertion sort algorithm

``` Example output:
Enter the number of elements in the array : 5
Enter the elements of the array: 500 1 50 23 76
The sorted array is:
1 50 23 76 500 

```
*/

void insertionSort (int* array, int array_size) 
{
    // for each element after the first up to the size of the array
	for (int i = 1; i < array_size ; i++)
	{
        // assign the current element to be a key
		int key = array[i];
        // set j to be one less than i
		int j = i - 1;
        // while the elements within the array before the element used as the key are greater than the key element and j is not negative 
		while (key < array[j] && j >= 0)
		{
            // assign the next to j's reference (j + 1) to be j's reference value (starts at i's reference which has a temp copy stored in the key variable) 
			array[j + 1] = array[j];
            // decrement j for the next loop iteration
			--j;
		}
        // assign the key back to j +1 element ( already decremented from the last loop iteration )
		array[j + 1] = key;
	}
}

int lab_2(void)
{
    int num_elements = 0;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &num_elements);
    clear_input();

    int * my_array = malloc(num_elements * sizeof(int));
    int * work_ptr = my_array;


    int inputs = 0;

    printf("Enter the elements: ");
    while (inputs < num_elements){
        scanf(" %d", work_ptr++);

        inputs++;
    }

    insertionSort(my_array, num_elements);

    print_array(my_array, num_elements);

    free(my_array);

    return 0;
}

/*
## Write a C program that implements the quick sort algorithm that takes in an array ( int arr[] = {80, 26, 37, 98, 50, 7};) and sorts it:
Example output
```
Sorted array: 7 26 37 50 80 98

```
*/

int partition(int * array, int low, int high)
{
    // pivot (Element to be placed at right position)
    int pivot = array[high];  
 
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (array[j] < pivot)
        {
            i++;    // increment index of smaller element
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(int * array, int low_ind, int high_ind)
{
    if (low_ind < high_ind)
    {
        int part_ind = partition(array, low_ind, high_ind);

        quickSort(array, low_ind, part_ind - 1);  // Before the partition index
        quickSort(array, part_ind + 1, high_ind); // After the partition index
    }
}

int lab_3(void)
{
    int arr[] = {80, 26, 37, 98, 50, 7};
    int array_size = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, array_size - 1);

    print_array(arr, array_size);

    return 0;
}

int main(void)
{
    // lab_1();
    // lab_2();
    lab_3();

    return 0;
}
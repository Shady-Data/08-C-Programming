/*
## Searching Exerecises

1. Create a program to search this array: {4, 6, 1, 2, 5, 3} and search for a particular number in the array. 

### Example Output
```
If the input array is {4, 6, 1, 2, 5, 3}
and if the element searched is 6,
then the expected output will be Position 2.
```
*/
#include <stdio.h>
#include <stdlib.h>

int int_array_search(int * array, int element2find, int array_size)
{
    // finds and returns the position (index + 1) of the first instance found of the element2find in the array
    for (int i = 0; i < array_size; i++, array++)
    {
        // if the element at the ith index is the same value as the element2find variable
        if (*array == element2find){
            // return i for the position of the found element within the array
            return i;
        }
    }
    // if the for loop completes, element2find could not be in the array return -1
    return -1;
}

int exercise_1(void)
{
    // declare and initialize the array to be searched
    int my_array[] = {4, 6, 1, 2, 5, 3};
    // declare a variable for the value to be searched, can be assigned by user input if desired
    int find_this = 6;
    // find the size of the array by dividing the total size of the array by the sizeof the first element
    int array_size = sizeof(my_array) / sizeof(my_array[0]);
    // get the result of the search
    int search_result = int_array_search(my_array, find_this, array_size);

    // if the return of the search function is -1
    if (search_result == -1){
        // display that the element could not be found
        printf("Unable to find %d in the array.\n", find_this);
    }
    // otherwise
    else{
        // print the position (index + 1) of the found element in the array
        printf("Found %d at position %d in the array.\n", find_this, search_result + 1);
    }

    return 0;
}

/*
2. Find the difference between arrays:
### example Output:

``` 
Enter length of first array:4
Enter 4 elements of first array
1
2
3
4
Enter length of second array:4
Enter 4 elements of second array
2
4
5
6
The difference of the two array is:
1
3
```
*/

int exercise_2(void)
{
    int array_1[] = {1, 2, 3, 4};
    int array_2[] = {2, 4, 5, 6};

    int * arr1_ptr = array_1;
    int * arr2_ptr = array_2;

    int array1_size = sizeof(array_1) / sizeof(array_1[0]);
    int array2_size = sizeof(array_2) / sizeof(array_2[0]);

    int notSame = 1;

    printf("The the values in the first array and not in the second array are:\n");
    for (int x = 0; x < array1_size; arr1_ptr++, x++){
        notSame = 1;
        arr2_ptr = array_2;
        for (int y = 0; y < array2_size; arr2_ptr++, y++){
            if (*arr1_ptr == *arr2_ptr){
                notSame = 0;
                break;
            }
        }
        if (notSame){
            printf("\t%d\n", *arr1_ptr);
        }
    }

    return 0;
}

/*
3.  Locate unique elements in the array:

### example output
```
Enter the length of the array:5
Enter 5 elements in the array
1
2
3
2
1

The unique elements in the array are:
1
2
3
```
*/
int print_array_unique(int * array, int array_size)
// Prints the unique elements in the array
{
    // declare a pointer variable to the memory alocated for an array of upto the passed array's size
    int * return_array = malloc(array_size * sizeof(array[0]));
    // declare and initialize a pointer to the current position of the array to change
    int * current_pos_ptr = return_array;
    // declare and initialize a work_ptr for iterating through the return_array to check for duplicates
    int * work_ptr = return_array;
    // declare and initialize a flag to determine whether to add to the return array or not
    int flag = 1;
    // iterate through each element in the passed array, up to the size of the array, incrementing the passed array's pointer and i each loop completion
    for (int i = 0; i < array_size; array++, i++){
        // ensure the flag is reset for each iteration
        flag = 1;
        // for every iteration after the first
        if (i > 0){
            // iterate through the return_array with the work pointer, incrementing the work pointer each loop
            for (work_ptr = return_array; work_ptr != current_pos_ptr; work_ptr++){
                // if the value stored in the current array pointer location is the same as the value stored in the work pointer location
                if (*array == *work_ptr){
                    // set the flag to 0 to pass the addition of the value to the return array
                    flag = 0;
                    // stop iterating this for loop (the return array enumeration) and exit
                    break;
                }
            }
            // if the flag is still 1
            if (flag){
                // set the value of the current_pos_ptr to the current array position's value
                *current_pos_ptr = *array;
                // increment the current_pos_ptr to point to the next location
                current_pos_ptr++;
            }
        }
        // for the first iteration (posssible to remove this from the for loop)
        else{
            // set the value of the current_pos_ptr to the current array position's value
            *current_pos_ptr = *array;
            // increment the current_pos_ptr to point to the next location
            current_pos_ptr++;
        }
    }
    // print the first line of the return
    printf("The unique elements in the array are:\n");
    // using the work_ptr, iterate through the return_array until the work_ptr hits the current_pos_ptr
    for (work_ptr = return_array; work_ptr != current_pos_ptr; work_ptr++){
        // print the value at the work position pointer
        printf("%d\n", *work_ptr);
    }
    // free the return array to clear the malloc
    free(return_array);
    return 0;
}

int exercise_3(void)
{
    // declare and initialize the array to be iterating through
    int my_array[] = { 1, 2, 3, 2, 1};
    // get the size of the array
    int array_size = sizeof(my_array) / sizeof(my_array[0]);
    // call the print_array_unique function with the array and array size
    print_array_unique(my_array, array_size);

    return 0;
}


/*
4. Change a word in a file with a different word
```
Example text: I am trying to create a file. it is through programming in C. 
It is very cold tonight, and it is snowing. do you like football? It might stop snowing. Hello, and good bye
```
### Example Output
```
Enter a string to be replaced: is
Enter the new string was
I am trying to create a file. it was through programming in C. 
It was very cold tonight, and it was snowing. do you like football? It might stop snowing. Hello, and good bye
```
*/



int main(void)
{
    // exercise_1();
    exercise_2();
    // exercise_3();

    return 0;
}